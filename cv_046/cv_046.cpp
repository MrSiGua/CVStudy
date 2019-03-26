﻿// cv_046.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
OpenCV-day-046

二值图像 联通组件寻找

连通组件标记算法介绍
连接组件标记算法(connected component labeling algorithm)是图像分析中最常用的算法之一，
算法的实质是扫描二值图像的每个像素点，对于像素值相同的而且相互连通分为相同的组(group),
最终得到图像中所有的像素连通组件。扫描的方式可以是从上到下，从左到右，对于一幅有N个像素的图像来说，
最大连通组件个数为N/2。扫描是基于每个像素单位，
OpenCV中进行连通组件扫码调用的时候必须保证背景像素是黑色、前景像素是白色。
最常见的连通组件扫码有如下两类算法：

1. 一步法，基于图的搜索算法
2. 两步法、基于扫描与等价类合并算法

OpenCV中支持连通组件扫描的API有两个，一个是带统计信息一个不带统计信息。
不带统计信息的API及其解释如下：
int cv::connectedComponents(
InputArray image, // 输入二值图像，黑色背景
OutputArray labels, // 输出的标记图像，背景index=0
int connectivity = 8, // 连通域，默认是8连通
int ltype = CV_32S // 输出的labels类型，默认是CV_32S
)
*/

#include "pch.h"
#include <iostream>
#include <opcv341.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

RNG rng(12345);
void connected_component_demo(Mat &image);
int main()
{
	Mat src = imread("../pic/rice.png");
	if (src.empty()) {
		printf("could not load image...\n");
	}
	imshow("input", src);
	connected_component_demo(src);

	waitKey(0);

    std::cout << "Hello World!\n"; 
}

void connected_component_demo(Mat &image) {
	// extract labels
	Mat gray, binary;
	GaussianBlur(image, image, Size(3, 3), 0);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	Mat labels = Mat::zeros(image.size(), CV_32S);
	int num_labels = connectedComponents(binary, labels, 8, CV_32S);
	printf("total labels : %d\n", (num_labels - 1));
	vector<Vec3b> colors(num_labels);

	// background color
	colors[0] = Vec3b(0, 0, 0);

	// object color
	for (int i = 1; i < num_labels; i++) {
		colors[i] = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
	}

	// render result
	Mat dst = Mat::zeros(image.size(), image.type());
	int w = image.cols;
	int h = image.rows;
	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int label = labels.at<int>(row, col);
			if (label == 0) continue;
			dst.at<Vec3b>(row, col) = colors[label];
		}
	}
	imshow("ccla-demo", dst);
	//imwrite("D:/ccla_dst.png", dst);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
