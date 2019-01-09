// CV_032.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
OpenCV-day-032

图像梯度 – 更多梯度算子

图像的一阶导数算子除了sobel算子之外，常见的还有robert算子与prewitt算子，它们也都是非常好的可以检测图像的梯度边缘信息，
通过OpenCV中自定义滤波器，使用自定义创建的robert与prewitt算子就可以实现图像的rober与prewitt梯度边缘检测，OpenCV中的自定义算子滤波函数如下：

filter2D(
	InputArray src,
	OutputArray dst,
	int ddepth,
	InputArray 	kernel,
	Point anchor = Point(-1,-1),
	double delta = 0,
	int borderType = BORDER_DEFAULT
)

Python:
dst	=cv.filter2D(src, ddepth, kernel[, dst[, anchor[, delta[, borderType]]]])

PS: 第三张图为原图，后面两张图像分别是robert与prewitt图像梯度检测效果！*/

#include "pch.h"
#include <opcv342.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat	src = imread("test.png");
	if (src.empty())
	{
		cout << "could not load image...";
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat robert_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);
	Mat robert_y = (Mat_<int>(2, 2) << 0, -1, 1, 0);

	Mat prewitt_x = (Mat_<char>(3, 3) << -1, 0, 1,
		-1, 0, 1,
		-1, 0, 1);
	Mat prewitt_y = (Mat_<char>(3, 3) << -1, -1, -1,
		0, 0, 0,
		1, 1, 1);

	Mat robert_grad_x, robert_grad_y, prewitt_grad_x, prewitt_grad_y;
	filter2D(src, robert_grad_x, CV_16S, robert_x);
	filter2D(src, robert_grad_y, CV_16S, robert_y);
	convertScaleAbs(robert_grad_x, robert_grad_x);
	convertScaleAbs(robert_grad_y, robert_grad_y);
	imshow("robet_grad_x", robert_grad_x);
	imshow("robet_grad_y", robert_grad_y);

	filter2D(src, prewitt_grad_x, CV_32F, prewitt_x);
	filter2D(src, prewitt_grad_y, CV_32F, prewitt_y);
	convertScaleAbs(prewitt_grad_x, prewitt_grad_x);
	convertScaleAbs(prewitt_grad_y, prewitt_grad_y);

	imshow("prewitt_grad_x", prewitt_grad_x);
	imshow("prewitt_grad_y", prewitt_grad_y);

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
