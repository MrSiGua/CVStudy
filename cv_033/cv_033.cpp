// cv_033.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*OpenCV-day-033

## 图像梯度 – 拉普拉斯算子(二阶导数算子)

图像的一阶导数算子可以得到图像梯度局部梯度相应值，二阶导数可以通过快速的图像像素值强度的变化来检测图像边缘，
其检测图像边缘的原理跟图像的一阶导数有点类似，只是在二阶导数是求X、Y方向的二阶偏导数，对图像来说：

X方向的二阶偏导数就是 dx = f(x+1, y) + f(x-1, y) – 2*f(x, y)
Y方向的二阶偏导数就是 dy = f(x, y+1) + f(x, y-1) – 2*f(x, y)

对X方向与Y方向进行叠加最终就得到delta对应的二阶导数算子，看第一张图像最下面的部分就是对应的四邻域的二阶导数算子，我们可以进一步扩展增强为八邻域的算子。

OpenCV中Laplacian滤波函数就是二阶导数发现边缘的函数：
void cv::Laplacian(
	InputArray src,
	OutputArray dst,
	int ddepth,			// 深度默认是-1表示输入与输出图像相同
	int ksize = 1,		// 必须是奇数， 等于1是四邻域算子，大于1改用八邻域算子
	double scale = 1,
	double delta = 0,	// 对输出图像加上常量值
	int borderType = BORDER_DEFAULT
)

Python:
dst	= cv.Laplacian(src, ddepth[, dst[, ksize[, scale[, delta[, borderType]]]] )

PS:
拉普拉斯算子是一种特别容易受到噪声干扰的边缘发现算子，所以经常对要处理的图像首先进行一个高斯模糊，然后再进行拉普拉斯算子的边缘提取，
而且在一些场景中会把这两步合并成为一步，就是我们经常听说的LOG算子。
*/

#include "pch.h"
#include <iostream>
#include <opcv342.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("test.png");
	if (image.empty())
	{
		cout << "could not load image...\n";
		return -1;
	}
	imshow("input", image);

	Mat blured, dst;
	GaussianBlur(image, blured, Size(3, 3), 0);
	Laplacian(blured, dst, CV_32F, 3, 1.0, 127.0, BORDER_DEFAULT);
	convertScaleAbs(dst, dst);
	imshow("dst", dst);

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
