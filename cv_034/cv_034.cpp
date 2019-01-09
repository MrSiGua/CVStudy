// cv_034.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*OpenCV-day-034

图像锐化

图像卷积的主要有三功能分别是
	1. 图像的模糊/去噪、
	2. 图像梯度/边缘发现、
	3. 图像锐化/增强，
前面的两个功能我们以前通过相关知识点的分享加以了解，学习了相关API的使用。图像锐化的本质是图像拉普拉斯滤波加原图权重像素叠加的输出 ：

-1		-1		-1
-1		 C		-1
-1		-1		-1

当C值大于8时候表示图像锐化、越接近8表示锐化效果越好
当C值等于8时候图像的高通滤波
当C值越大，图像锐化效果在减弱、中心像素的作用在提升*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("test.png");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("input", src);

	Mat sharpen_op = (Mat_<char>(3, 3) << 0, -1, 0,
		- 1, 5, -1,
		0, -1, 0);

	Mat result;
	filter2D(src, result, CV_32F, sharpen_op);
	convertScaleAbs(result, result);
	imshow("resut", result);

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
