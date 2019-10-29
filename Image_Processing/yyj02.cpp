#include "yyj02.h"
#include "stdafx.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

void histogram2(vector<double> p, vector<vector<int>>& hist)
{
	const int h = hist.size();        //图像高度
	const int w = hist[0].size();     //图像宽度

	vector<double> htm_num(256, 0);

	for (int i = 0; i < 256; ++i)
		htm_num[i] = h * p[i] * w;

	for (auto& x : hist)           //直方图背景设置为白色
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //合并4个相邻等级为一个新等，总共64级
	vector<int> htm_num_2;                   //定义容器来存储新等级对应的灰度数
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);

	const int pix_num = w / (level_num + 1) / 2;   //画每个等级需要的像素宽度，避免越界多算一个

	int max = 0, min = 0;           //找到灰度最小值和最大值
	for (auto c : htm_num_2)
		if (min > c)
			min = c;
	for (auto c : htm_num_2)
		if (max < c)
			max = c;

	for (auto& c : htm_num_2)       //画图的最大高度为图像高度的3/4
		c = (c - min) * (h * 3 / 4) / (max - min);

	for (int i = 0; i < level_num; ++i)    //画图
		for (int j = 0; j < pix_num; ++j)
			for (int z = 0; z < htm_num_2[i]; ++z)
				hist[(h - 1 - z)][i * 2 * pix_num + j] = 0;
}

//第二次作业
//直方图显示
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist)
{
	const int h = hist.size();        //图像高度
	const int w = hist[0].size();     //图像宽度

	vector<double> htm_num(256, 0);

	for (auto x : image)           //统计图像中各灰度值的数量
		for (auto c : x)
			++(htm_num[c]);

	for (auto& x : hist)           //直方图背景设置为白色
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //合并4个相邻等级为一个新等，总共64级
	vector<int> htm_num_2;                   //定义容器来存储新等级对应的灰度数
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);

	const int pix_num = w / (level_num + 1) / 2;   //画每个等级需要的像素宽度，避免越界多算一个

	int max = 0, min = 0;           //找到灰度最小值和最大值
	for (auto c : htm_num_2)
		if (min > c)
			min = c;
	for (auto c : htm_num_2)
		if (max < c)
			max = c;

	for (auto& c : htm_num_2)       //画图的最大高度为图像高度的3/4
		c = (c - min) * (h * 3 / 4) / (max - min);

	for (int i = 0; i < level_num; ++i)    //画图
		for (int j = 0; j < pix_num; ++j)
			for (int z = 0; z < htm_num_2[i]; ++z)
				hist[(h - 1 - z)][i * 2 * pix_num + j] = 0;

	for (auto& c : htm_num)
		c = c / h / w;

	return htm_num;
}

//直方图均衡化
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>
{
	vector<vector<int>> image_jun;     //存储均值化后的图像
	image_jun = image;
	const int h = image.size();        //图像高度
	const int w = image[0].size();     //图像宽度
	vector<double> htm_num(256, 0);    //原图像直方图
	vector<int> htm_num_2(256, 0);     //均衡化后的结果
	for (auto x : image)               //统计图像中各灰度值的数量
		for (auto c : x)
			++(htm_num[c]);

	for (int i = 0; i <= 255; ++i)       //均衡化
	{
		double temp = 0;
		for (int j = 0; j <= i; ++j)
		{
			temp += 255 * htm_num[j] / (h * w);    //求和
		}
		htm_num_2[i] = temp;
	}

	for (auto& x : image_jun)         //图像灰度修改
		for (auto& c : x)
			c = htm_num_2[c];

	return image_jun;                //返回均衡化后的图像

}

//直方图规定化
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz1)
{
	const int h = image.size();        //图像高度
	const int w = image[0].size();     //图像宽度
	vector<int> Gz(256, 0);            //参考直方图均衡化
	for (int i = 0; i <= 255; ++i)
	{
		double temp = 0;
		for (int j = 0; j <= i; ++j)
		{
			temp += Pz1[j];
		}
		temp *= 255;
		Gz[i] = temp;
	}

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			int n = 0;
			while (true)
			{
				if (Gz[n] >= image[i][j] || n >= 255)
					break;
				++n;
			}
			image2[i][j] = Gz[n];
		}
}

//均值滤波
void mean_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();          //图像高度
	const int w = image[0].size();       //图像宽度
	auto temp = image;                   //定义存储结果的临时容器

	for (int i = size / 2; i < h - size / 2; ++i)                 //取size*size大小的均值，赋值给temp中对应的位置
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


