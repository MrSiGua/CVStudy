// cv_037.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
OpenCV-day-037

图像金字塔

图像金字塔概念
图像金字塔是对一张输入图像先模糊再下采样为原来大小的1/4（宽高缩小一半）、不断重复模糊与下采样的过程就得到了不同分辨率的输出图像，
叠加在一起就形成了图像金字塔、所以图像金字塔是图像的空间多分辨率存在形式。
这里的模糊是指高斯模糊，所以这个方式生成的金字塔图像又称为高斯金字塔图像。高斯金字塔图像有两个基本操作

reduce 是从原图生成高斯金字塔图像、生成一系列低分辨图像
expand是从高斯金字塔图像反向生成高分辨率图像

规则：
1.	图像金字塔在redude过程或者expand过程中必须是逐层
2.	reduce过程中每一层都是前一层的1/4

相关API
reduce 操作 pyrDown
expand操作 pyrUp*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void pyramin_up(Mat& image, vector<Mat> &pyramin_images, int level);
void pyramin_down(vector<Mat> &pyramid_images);

int main()
{
	Mat	src = imread("master.jpg");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}

	imshow("input", src);

	vector<Mat> p_images;
	pyramin_up(src, p_images, 3);
	pyramin_down(p_images);

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

void pyramin_up(Mat & image, vector<Mat>& pyramin_images, int level)
{
	Mat temp = image.clone();
	Mat dst;
	for (int i = 0; i < level; i++)
	{
		pyrDown(temp, dst);
		//imshow(format("pyramin_up_%d", i), dst);
		temp = dst.clone();
		pyramin_images.push_back(temp);
	}
}

void pyramin_down(vector<Mat>& pyramid_images)
{
	for (int t = pyramid_images.size() - 1; t > -1; t--)
	{
		Mat dst;
		pyrUp(pyramid_images[t], dst);
		imshow(format("pyramid_down_%d", t), dst);
	}
}
