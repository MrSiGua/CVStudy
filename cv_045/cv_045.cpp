// cv_045.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
OpenCV-day-045

图像二值化与去噪

对于一张需要二值化的图像，我们有两种选择
选择一
直接对输入图像转换为灰度图像，然后二值化
选择二
首先对输入图像进行降噪，去除噪声干扰，然后再二值化

在进行去噪声的时候，还记得前面我们分享的几种去噪声方法，可以选择的有
均值模糊去噪声
高斯模糊去噪声
双边/均值迁移模糊去噪声
非局部均值去噪声

下面的三张图，
第一张图是输入图像直接转换为二值图像
第二张图是输入图像先高斯模糊去噪声，然后二值化图像
第三张图是输入图像先均值迁移去噪声，然后二值化的图像*/

#include "pch.h"
#include <iostream>
#include <opcv341.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../pic/coins.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	// 去噪声与二值化
	Mat dst, gray, binary;
	pyrMeanShiftFiltering(src, dst, 10, 100);		// 均值偏移滤波
	//GaussianBlur(src, dst, Size(3, 3), 0, 0);
	cvtColor(dst, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
	imshow("binary", binary);
	imwrite("D:/binary.png", binary);

	waitKey(0);
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
