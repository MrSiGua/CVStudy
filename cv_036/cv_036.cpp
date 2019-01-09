// cv_036.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*OpenCV-day-036

Canny边缘检测器

1986年，JOHN CANNY 提出一个很好的边缘检测算法，被称为Canny编边缘检测器。Canny边缘检测器是一种经典的图像边缘检测与提取算法，应用广泛，主要是因为Canny边缘检测具备以下特点：
1.	有效的噪声抑制
2.	更强的完整边缘提取能力

Canny算法是如何做到精准的边缘提取的，主要是靠下面五个步骤
1.	高斯模糊 – 抑制噪声
2.	梯度提取得到边缘候选
3.	角度计算与非最大信号抑制
4.	高低阈值链接、获取完整边缘
5.	输出边缘

OpenCV中Canny边缘检测的API如下：
void cv::Canny(
	InputArray image,
	OutputArray edges,
	double threshold1,
	double threshold2,
	int apertureSize = 3,
	bool L2gradient = false
)
threshold1 是Canny边缘检测算法第四步中高低阈值链接中低阈值
threshold2 是Canny边缘检测算法第四步中高低阈值链接中高阈值、高低阈值之比在2:1～3:1之间
最后一个参数是计算gradient的方法L1或者L2*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("master.jpg");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("input", src);

	Mat edges;
	Canny(src, edges, 100, 300, 3, false);
	imshow("edge image", edges);

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
