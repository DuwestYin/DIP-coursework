#include "yyj04.h"
#include "stdafx.h"
#include <vector>

using std::vector;
const double pi = 3.141592;

//RGB到HSI的转换
void rgb2hsi(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2)
{
	const int h = img1[0].size();
	const int w = img1[0][0].size();

	for(int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			double R = img1[0][i][j];
			double G = img1[1][i][j];
			double B = img1[2][i][j];
			double theta = 0;
			if (R == G && R == B)          //排除纯白，纯黑和灰度值的情况
			{
				img2[0][i][j] = 0;         //直接将色调和饱和度赋值为0
				img2[1][i][j] = 0;
			}
			else     //正常情况
			{
				theta = acos(((2 * R - G - B) / 2) / sqrt((R - G) * (R - G) + (R - B) * (G - B)));     //色调角度
				if (B <= G)
					img2[0][i][j]= theta;              //色调
				else
					img2[0][i][j] = 2 * pi - theta;    //色调
				double min = 0; //寻找RGB中的最小值
				if (R <= G)
				{
					min = R;
					if (B <= R)
						min = B;
				}
				else
				{
					min = G;
					if (B <= G)
						min = B;
				}
				img2[1][i][j] = 1 - (3 * min / (R + G + B));   //饱和度
			}
				
			img2[2][i][j] = (R + G + B) / 3;  //强度
		}
}

//HSI到RGB的转换
void hsi2rgb(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2)
{
	const int h = img1[0].size();
	const int w = img1[0][0].size();

	for(int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			double H = img1[0][i][j];
			double S = img1[1][i][j];
			double I = img1[2][i][j];
			if (H == 0 && S == 0)               //排除灰度颜色的情况
			{
				img2[0][i][j] = I;              //灰度值的RGB分量都等于强度
				img2[1][i][j] = I;
				img2[2][i][j] = I;
			}
			else
			{
				if (H >= 0 && H < 2 * pi / 3)                //H在0-120度
				{
					img2[2][i][j] = I * (1 - S);
					img2[0][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[1][i][j] = 3 * I - img2[0][i][j] - img2[2][i][j];
				}
				else if (H >= 2 * pi / 3 && H < 4 * pi / 3)   //H在120-240度
				{
					H = H - 2 * pi / 3;
					img2[0][i][j] = I * (1 - S);
					img2[1][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[2][i][j] = 3 * I - img2[0][i][j] - img2[1][i][j];
				}
				else if (H >= 4 * pi / 3 && H < 2 * pi)       //H在240-360度
				{
					H = H - 4 * pi / 3;
					img2[1][i][j] = I * (1 - S);
					img2[2][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[0][i][j] = 3 * I - img2[1][i][j] - img2[2][i][j];
				}
			}
			
		}
}

//直方图均衡化函数重载
auto histogram_equalization(const vector<vector<double>>& image)-> const vector<vector<double>>
{
	vector<vector<double>> image_jun;     //存储均值化后的图像
	image_jun = image;
	const int h = image.size();        //图像高度
	const int w = image[0].size();     //图像宽度
	vector<double> htm_num(256, 0);    //原图像直方图
	vector<double> htm_num_2(256, 0);  //均衡化后的结果
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

//求均值
double mean(vector<double> nums)
{
	int n = nums.size();
	double a = 0;
	for (auto c : nums)
		a += c / n;
	return a;
}

//求标准差
double std_deviation(vector<double> nums)
{
	int n = nums.size();
	double mean = 0;
	double std_dev = 0;
	for (auto c : nums)
		mean += c / n;
	for (auto c : nums)
		std_dev += (c - mean) * (c - mean) / n;
	std_dev = sqrt(std_dev);
	return std_dev;
}