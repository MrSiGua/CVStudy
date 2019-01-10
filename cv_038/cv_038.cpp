// cv_038.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*OpenCV-day-038

拉普拉斯金字塔

对输入图像实现金字塔的reduce操作就会生成不同分辨率的图像、对这些图像进行金字塔expand操作，然后使用reduce减去expand之后的结果就会得到图像拉普拉斯金字塔图像。

举例如下：
输入图像G(0)
金字塔reduce操作生成 G(1), G(2), G(3)
拉普拉斯金字塔：
L0 = G(0)-expand(G(1))
L1 = G(1)-expand(G(2))
L2 = G(2)–expand(G(3))

reduce 缩小
expand 放大

G(0)减去expand(G(1))得到的结果就是两次高斯模糊输出的不同，所以L0称为DOG（高斯不同）、它约等于LOG所以又称为拉普拉斯金字塔。
所以要求的图像的拉普拉斯金字塔，首先要进行金字塔的reduce操作，然后在通过expand操作，最后相减得到拉普拉斯金字塔图像。*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void pyramin_up(Mat& image, vector<Mat>& pyramid_images, int level);
void laplaian_demo(vector<Mat>& pyramin_images, Mat& image);

int main()
{
	Mat src = imread("master.jpg");
	if (src.empty())
	{
		cout << "could not load image..." << endl;
		return -1;
	}
	imshow("input", src);

	vector<Mat> p_images;
	pyramin_up(src, p_images, 3);
	laplaian_demo(p_images, src);

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

void laplaian_demo(vector<Mat>& pyramin_images, Mat& image)
{
	for (int i = pyramin_images.size() - 1; i > -1; i--)
	{
		Mat dst;
		if (i - 1 < 0)	// i == 0; 最底层， 重构原图
		{
			pyrUp(pyramin_images[i], dst, image.size());
			subtract(image, dst, dst);
			//dst = dst + Scalar(127, 127, 127);
			imshow(format("laplaian_layer_%d", i), dst);
		}
		else
		{
			pyrUp(pyramin_images[i], dst, pyramin_images[i - 1].size());
			subtract(pyramin_images[i - 1], dst, dst);
			//dst = dst + Scalar(127, 127, 127);
			imshow(format("laplaian_layer_%d", i), dst);
		}
	}
}
