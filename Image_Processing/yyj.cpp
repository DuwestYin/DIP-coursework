#include "yyj.h"
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
void differential_enhancement(vector<vector<double>>& image1 ,vector<vector<double>>& image2)
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

//第二次作业
//均值滤波
void mean_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();          //图像高度
	const int w = image[0].size();       //图像宽度
	auto temp = image;                   //定义存储结果的临时容器

	for(int i = size/2;i<h-size/2;++i)                 //取size*size大小的均值，赋值给temp中对应的位置
		for (int j = size / 2; j < w - size / 2; ++j)
		{
			double val = 0;
			for (int k = -size / 2; k <= size / 2; ++k)
				for (int l = -size / 2; l <= size / 2; ++l)
					val += image[i + k][j + l] / size / size;
			temp[i][j] = val;
		}

	for (int i = 0; i < size / 2; ++i)           //将未处理的边界赋值255
		for (int j = 0; j < w; ++j)
			temp[i][j] = 255;
	for (int i = h - size / 2; i < h; ++i)
		for (int j = 0; j < w; ++j)
			temp[i][j] = 255;
	for (int i = 0; i < size / 2; ++i)
		for (int j = 0; j < h; ++j)
			temp[j][i] = 255;
	for (int i = w - size / 2; i < w; ++i)
		for (int j = 0; j < h; ++j)
			temp[j][i] = 255;

	image = temp;           //将临时图像赋值给原图像

}

//中值滤波
void median_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();        //图像高度
	const int w = image[0].size();     //图像宽度
	auto temp = image;                 //定义存储结果的临时容器

	for (int i = size / 2; i < h - size / 2; ++i)        //取size*size大小中值，赋值给temp中对应的位置
		for (int j = size / 2; j < w - size / 2; ++j)
		{
			vector<double> maopao;                          //定义用于冒泡排序的容器
			for (int k = -size / 2; k <= size / 2; ++k)
				for (int l = -size / 2; l <= size / 2; ++l)
					maopao.push_back(image[i + k][j + l]);  //将size*size大小的像素推进容器

			for (int k = 0; k < maopao.size() - 1; ++k)     //冒泡排序
				for (int g = 0; g < maopao.size() - 1 - k; ++g)
					if (maopao[g] > maopao[g + 1])
					{
						double b = 0;
						b = maopao[g];
						maopao[g] = maopao[g + 1];
						maopao[g + 1] = b;
					}
			temp[i][j] = maopao[size * size / 2];         //取中值
		}

	for (int i = 0; i < size / 2; ++i)               //将未处理的边界赋值255
		for (int j = 0; j < w; ++j)
			temp[i][j] = 255;
	for (int i = h - size / 2; i < h; ++i)
		for (int j = 0; j < w; ++j)
			temp[i][j] = 255;
	for (int i = 0; i < size / 2; ++i)
		for (int j = 0; j < h; ++j)
			temp[j][i] = 255;
	for (int i = w - size / 2; i < w; ++i)
		for (int j = 0; j < h; ++j)
			temp[j][i] = 255;

	image = temp;                //将临时图像赋值给原图像
}

//直方图显示
void histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist)
{
	const int h = hist.size();        //图像高度
	const int w = hist[0].size();     //图像宽度

	vector<double> htm_num(256, 0);
	
	for (auto x : image)           //统计图像中各灰度值的数量
		for (auto c : x)
			++(htm_num[c]);

	for (auto& x : hist)
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //合并4个相邻等级为一个新等，总共64级
	vector<int> htm_num_2;                   //定义容器来存储新等级对应的灰度数
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);
	
	const int pix_num = w / (level_num + 1) / 2;   //画每个等级需要的像素宽度，避免越界多算一个

	int max = 0, min = 0;
	for (auto c : htm_num_2)
		if (min > c)
			min = c;
	for (auto c : htm_num_2)
		if (max < c)
			max = c;

	for (auto& c : htm_num_2)
		c = (c - min) * (h * 3 / 4) / (max - min);

	for (int i = 0; i < level_num; ++i)
		for (int j = 0; j < pix_num; ++j)
			for (int z = 0; z < htm_num_2[i]; ++z)
				hist[(h - 1 - z)][i * 2 * pix_num + j] = 0;
}

//直方图均衡化
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>
{
	vector<vector<int>> image_jun;     //存储均值化后的图像
	image_jun = image;
	const int h = image.size();        //图像高度
	const int w = image[0].size();     //图像宽度
	vector<double> htm_num(256, 0);
	vector<int> htm_num_2(256, 0);
	for (auto x : image)               //统计图像中各灰度值的数量
		for (auto c : x)
			++(htm_num[c]);

	for (int i = 0; i <= 255; ++i)
	{
		double temp = 0;
		for (int j = 0; j <= i; ++j)
		{
			temp += 255 * htm_num[j] / (h * w);
		}
		htm_num_2[i] = temp;
	}

	for (auto& x : image_jun)
		for (auto& c : x)
			c = htm_num_2[c];

	return image_jun;

}

		