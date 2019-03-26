// cv_044.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
OpenCV-day-044

OpenCV中图像二化自适应阈值算法

OpenCV中的自适应阈值算法主要是基于均值实现，
根据计算均值的方法不同分为盒子模糊均值与高斯模糊均值，
然后使用原图减去均值图像，得到的差值图像进行自适应分割，
相关的API如下：
void cv::adaptiveThreshold(
InputArray src,
OutputArray dst,
double maxValue,
int adaptiveMethod,
int thresholdType,
int blockSize,
double C
)
其中blockSize取值必须是奇数，C取值在10左右  10 - 25(视情况)

自适应方法类型：
ADAPTIVE_THRESH_GAUSSIAN_C = 1
ADAPTIVE_THRESH_MEAN_C = 0

当阈值操作类型thresholdType为：THRESH_BINARY
二值图像 = 原图 – 均值图像 > -C ? 255 : 0

当阈值操作类型thresholdType为：THRESH_BINARY_INV
二值图像 = 原图 – 均值图像 > -C ? 0 : 255*/

#include "pch.h"
#include <iostream>
#include <opcv341.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("../pic/text1.png");
	if (src.empty())
	{
		printf("could not load image..\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// 自动阈值寻找与二值化
	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	adaptiveThreshold(gray, binary, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 25, 8);

	imshow("binary", binary);
	//imwrite("D:/binary.png", binary);

	waitKey(0);
	return 0;
    std::cout << "Hello World!\n"; 
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
