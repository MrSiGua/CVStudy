// cv_031.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
OpenCV-day-031

图像梯度 – Sobel算子

卷积的作用除了实现图像模糊或者去噪，还可以寻找一张图像上所有梯度信息，这些梯度信息是图像的最原始特征数据，进一步处理之后就可以生成一些比较高级的特征用来表示一张图像实现基于图像特征的匹配，图像分类等应用。Sobel算子是一种很经典的图像梯度提取算子，其本质是基于图像空间域卷积，背后的思想是图像一阶导数算子的理论支持。OpenCV实现了基于Sobel算子提取图像梯度的API，表示与解释如下：
void cv::Sobel(
	InputArray src,		// 输入图像
	OutputArray dst,	// 输出结果
	int ddepth,			// 图像深度CV_32F
	int dx,				// 1，X方向 一阶导数
	int dy,				// 1，Y方向 一阶导数
	int ksize = 3,		// 窗口大小
	double scale = 1,	// 放缩比率，1 表示不变
	double delta = 0,	// 对输出结果图像加上常量值
	int borderType = BORDER_DEFAULT
)
Python:
dst = cv.Sobel(src, ddepth, dx, dy[, dst[, ksize[, scale[, delta[, borderType]]]]])
*/

#include "pch.h"
#include <opcv342.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("lena.bmp");
	if (src.empty())
	{
		cout << "could not load image ..\n";
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat grad_x, grad_y;
	Mat dst;
	Sobel(src, grad_x, CV_32F, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_32F, 0, 1, 3, 1, 0, BORDER_DEFAULT);

	// 归一化
	convertScaleAbs(grad_x, grad_x);
	convertScaleAbs(grad_y, grad_y);
	imshow("Sobel_x", grad_x);
	imshow("Sobel_y", grad_y);

	add(grad_x, grad_y, dst, Mat(), CV_16S);
	convertScaleAbs(dst, dst);

	imshow("Sobel_x+y", dst);

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
