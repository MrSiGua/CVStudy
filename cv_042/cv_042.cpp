// cv_042.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*OpenCV-day-042

OpenCV中图像二值寻找算法 – OTSU

图像二值化，除了我们上次分享的手动阈值设置与根据灰度图像均值的方法之外，
还有几个根据图像直方图实现自动全局阈值寻找的方法，OpenCV中支持的有OTSU与Triangle两种直方图阈值寻找算法。
其中OTSU的是通过计算类间最大方差来确定分割阈值的阈值选择算法，OTSU算法对直方图有两个峰，中间有明显波谷的直方图对应图像二值化效果比较好，
而对于只有一个单峰的直方图对应的图像分割效果没有双峰的好。

OpenCV中OTSU算法使用只需要在
threshold函数的type类型声明THRESH_OTSU即可*/

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

	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	double t = threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
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
