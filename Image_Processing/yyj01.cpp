#include "yyj01.h"
#include "stdafx.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

///////////////////////////////////////////////////////////////////////////////////////
//第一次作业
//1. 降低空间分辨率
void reduce_spatial_resolution(vector<vector<double>>& image, int step)
{
	int h = image.size();           //图像高度
	int w = image[0].size();        //图像宽度

	for (int i = 0; i + step <= h; i += step)      //以步长step遍历图像
		for (int j = 0; j + step <= w; j += step)
		{
			for (int m = 0; m < step; ++m)         //将 step*step 大小的方格所有像素统一赋值为方格左上角的像素灰度
				for (int n = 0; n < step; ++n)
				{
					if (!(n == 0 && m == 0))
					{
						image[i + m][j + n] = image[i][j];
					}
				}
		}
}

//2. 降低灰度分辨率
void reduce_grayscale_resolution(vector<vector<double>>& image, int step)
{
	int h = image.size();        //图像高度
	int w = image[0].size();     //图像宽度

	for (int i = 0; i < h; ++i)   //遍历图像
		for (int j = 0; j < w; ++j)
		{
			int jian = static_cast<int>(image[i][j]) % step;     //灰度值对step取余数
			if (jian) image[i][j] -= jian;                       //若余数不为零则减去余数
			image[i][j] = int(image[i][j]) * 255 / (256 - step); //缩放到0-255
		}
}


//3. 叠加去噪
void superimposed_denoising(vector<vector<vector<double>>>& images)
{
	int times = images.size();     //用于叠加的图像数
	int h = images[0].size();      //图像高度
	int w = images[0][0].size();   //图像宽度
	vector<vector<double>> temp(h, vector<double>(w, 0));    //定义存储结果的临时容器

	for (int k = 0; k < times; ++k)                   //求平均值
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				temp[i][j] += (images[k][i][j] / times);

	for (int i = 0; i < h; ++i)                  //将结果赋值给第一幅图像
		for (int j = 0; j < w; ++j)
			images[0][i][j] = temp[i][j];
}

//4. 差分增强
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2)
{
	int h = image1.size();       //图像高度
	int w = image1[0].size();    //图像宽度
	vector<vector<double>> temp(h, vector<double>(w, 0));  //定义存储结果的临时容器

	for (int i = 0; i < h; ++i)                  //两幅图像做差
		for (int j = 0; j < w; ++j)
			temp[i][j] = image1[i][j] - image2[i][j];

	double min = 0, max = 0;         //定义存储像素灰度最大值和最小值的变量
	for (auto& ig : temp)            //求像素灰度最小值
		for (auto& c : ig)
			if (c < min) min = c;
	for (auto& ig : temp)            //将做差后的负灰度加上最小值，使之为非负数
		for (auto& c : ig)
			c += min;
	for (auto& ig : temp)            //求像素灰度最大值
		for (auto& c : ig)
			if (c < max) max = c;
	for (auto& ig : temp)           //缩放到0-255
		for (auto& c : ig)
		{
			c *= 255.0 / max;
			c = 255 - c;
		}
	for (int i = 0; i < h; ++i)     //将结果赋值给原图像
		for (int j = 0; j < w; ++j)
			image1[i][j] = temp[i][j];
}
