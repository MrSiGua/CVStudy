// cv_039.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*OpenCV-day-039

图像模板匹配

模板匹配被称为最简单的模式识别方法、同时也被很多人认为是最没有用的模式识别方法。
这里里面有很大的误区，就是模板匹配是工作条件限制比较严格，只有满足理论设置的条件以后，
模板匹配才会比较好的开始工作，而且它不是基于特征的匹配，所以有很多弊端，
但是不妨碍它成为入门级别模式识别的方法，通过它可以学习到很多相关的原理性内容，为后续学习打下良好的基础。

OpenCV中模板匹配的API为
void cv::matchTemplate (
	InputArray image,
	InputArray templ,
	OutputArray result,
	int method,
	InputArray mask = noArray()
)		
Python:
result = cv.matchTemplate(	image, templ, method[, result[, mask]] )

其中method表示模板匹配时候采用的计算像素相似程度的方法，常见有如下
TM_SQDIFF = 0
TM_SQDIFF_NORMED = 1
平方不同与平方不同的归一化版本

TM_CCORR = 2
TM_CCORR_NORMED = 3
相关性，值越大相关性越强，表示匹配程度越高。
归一化版本值在0～1之间，1表示高度匹配，0表示完全不匹配

TM_CCOEFF = 4
TM_CCOEFF_NORMED = 5
相关因子，值越大相关性越强，表示匹配程度越高。
归一化版本值在0～1之间，1表示高度匹配，0表示完全不匹配*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const float t = 0.95;

int main()
{
	Mat src = imread("../pic/llk.jpg");
	Mat tpl = imread("../pic/llk_tpl.png");
	if (src.empty() || tpl.empty())
	{
		cout << "could not load image...\n" << endl;
		return -1;
	}

	imshow("input", src);
	imshow("tpl", tpl);

	int result_h = src.rows - tpl.rows + 1;
	int result_w = src.cols - tpl.cols + 1;

	Mat result = Mat::zeros(Size(result_w, result_h), CV_32FC1);
	matchTemplate(src, tpl, result, TM_CCOEFF_NORMED);
	imshow("result image", result);

	int h = result.rows;
	int w = result.cols;

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			float v = result.at<float>(row, col);
			if (v > t)
			{
				rectangle(src, Point(col, row), Point(col + tpl.cols, row + tpl.rows), Scalar(255, 0, 0));
			}
		}
	}

	imshow("template matched result", src);

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
