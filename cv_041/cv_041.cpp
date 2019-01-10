// cv_041.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
OpenCV-day-041

OpenCV中的基本阈值操作

假设我们已经寻找到合适的阈值T，那么对图像二值化分割可以看成是一种基本的阈值化操作，
其实OpenCV除了支持正常的二值化阈值分割操作之外，还支持一些其它的阈值操作，OpenCV中支持的阈值操作的API如下：
double cv::threshold(
	InputArray src,
	OutputArray dst,
	double thresh,
	double maxval,
	int type
)
其中type表示阈值分割的方法，支持如下五种：
THRESH_BINARY = 0  二值分割
THRESH_BINARY_INV = 1 反向二值分割
THRESH_TRUNC = 2 截断
THRESH_TOZERO = 3 取零
THRESH_TOZERO_INV = 4 反向取零
enum ThresholdTypes {
	THRESH_BINARY     = 0, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{maxval}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
	THRESH_BINARY_INV = 1, //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{maxval}}{otherwise}\f]
	THRESH_TRUNC      = 2, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{threshold}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]
	THRESH_TOZERO     = 3, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{src}(x,y)}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
	THRESH_TOZERO_INV = 4, //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]
	THRESH_MASK       = 7,
	THRESH_OTSU       = 8, //!< flag, use Otsu algorithm to choose the optimal threshold value
	THRESH_TRIANGLE   = 16 //!< flag, use Triangle algorithm to choose the optimal threshold value
};
*/

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

	int T = 127;
	Mat gray, binary;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	for (int i = 0; i < 5; i++)
	{
		threshold(gray, binary, T, 255, i);
		imshow(format("binary_%d", i), binary);
	}

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
