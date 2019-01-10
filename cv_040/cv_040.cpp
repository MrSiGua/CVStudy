// cv_040.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
OpenCV-day-040

二值图像介绍

二值图像就是只有黑白两种颜色表示的图像，其中0 – 表示黑色， 1 – 表示白色(255) 。
二值图像处理与分析在机器视觉与机器人视觉中非常重要，涉及到非常多的图像处理相关的知识，
常见的二值图像分析包括轮廓分析、对象测量、轮廓匹配与识别、形态学处理与分割、各种形状检测与拟合、投影与逻辑操作、轮廓特征提取与编码等。
此外图像二值化的方法也有很多，OpenCV主要是支持几种经典的二值化算法。

从编程与代码角度，OpenCV中二值图像单通道的、字节类型的Mat对象、对于任意的输入图像首先需要把图像转换为灰度、然后通过二值化方法转换为二值图像。
本质上，从灰度到二值图像，是对数据的二分类分割，所以很多数据处理的方法都可以使用，但是图像是特殊类型的数据，
它有很多限制条件，决定了只有一些合适的方法才会取得比较好的效果。这些算法的最主要的一个任务就是寻找合理的分割阈值T、对于给定任意一个像素点灰度值
P(x, y) > T ? 255 :  0

多数人接触二值图像都是从下面的这个程序实现二值分割的，就是使用T=127作为阈值，对灰度图像进行二值分割。*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../pic/master.jpg");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	imshow("input", src);

	int t = 127;
	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	Scalar m = mean(src);

	//t = m[0];
	binary = Mat::zeros(src.size(), CV_8UC1);

	int height = src.rows;
	int width = src.cols;
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			int pv = gray.at<uchar>(row, col);
			if (pv > t)
			{
				binary.at<uchar>(row, col) = 255;
			}
			else
			{
				binary.at<uchar>(row, col) = 0;
			}
		}
	}

	imshow("binary", binary);

	waitKey();

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
