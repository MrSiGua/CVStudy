// cv_035.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*OpenCV-day-035

USM 锐化增强算法

图像卷积处理实现锐化有一种常用的算法叫做Unsharpen Mask方法，这种锐化的方法就是对原图像先做一个高斯模糊，
然后用原来的图像减去一个系数乘以高斯模糊之后的图像，然后再把值Scale到0～255的RGB像素值范围之内。
基于USM锐化的方法可以去除一些细小的干扰细节和噪声，比一般直接使用卷积锐化算子得到的图像锐化结果更加真实可信。

USM锐化公式表示如下：
（源图像– w*高斯模糊）/（1-w）；其中w表示权重（0.1～0.9），默认为0.6

OpenCV中的代码实现步骤
1.	高斯模糊
2.	权重叠加
3.	输出结果*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("test.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	Mat blur_img, usm;
	GaussianBlur(src, blur_img, Size(0, 0), 25);
	//blur(src, blur_img, Size(25, 25));
	addWeighted(src, 1.5, blur_img, -0.5, 0, usm);

	imshow("mask image", usm);

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
