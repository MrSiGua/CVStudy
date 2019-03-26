// cv_043.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
OpenCV-day-043

OpenCV中图像二值寻找算法 – TRIANGLE

图像二值化，除了我们上次分享的手动阈值设置与根据灰度图像均值的方法之外，还有几个根据图像直方图实现自动全局阈值寻找的方法，
OpenCV中支持的有OTSU与Triangle两种直方图阈值寻找算法。
上次分享提到OTSU基于类内最小方差实现阈值寻找, 它对有两个波峰之间有一个波谷的直方图特别好,
但是有时候图像的直方图只有一个波峰,这个时候使用TRIANGLE方法寻找阈值是比较好的一个选择。

OpenCV中TRIANGLE算法使用只需要在
threshold函数的type类型声明THRESH_TRIANGLE即可*/

#include "pch.h"
#include <iostream>
#include <opcv341.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../pic/lena.bmp");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("input", src);

	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	double t = threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);
	cout << "threshold : " << t << endl;

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
