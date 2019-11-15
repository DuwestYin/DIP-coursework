#include "yyj04.h"
#include "stdafx.h"
#include <vector>

using std::vector;
const double pi = 3.141592;

//RGB��HSI��ת��
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
			if (R == G && R == B)          //�ų����ף����ںͻҶ�ֵ�����
			{
				img2[0][i][j] = 0;         //ֱ�ӽ�ɫ���ͱ��Ͷȸ�ֵΪ0
				img2[1][i][j] = 0;
			}
			else     //�������
			{
				theta = acos(((2 * R - G - B) / 2) / sqrt((R - G) * (R - G) + (R - B) * (G - B)));     //ɫ���Ƕ�
				if (B <= G)
					img2[0][i][j]= theta;              //ɫ��
				else
					img2[0][i][j] = 2 * pi - theta;    //ɫ��
				double min = 0; //Ѱ��RGB�е���Сֵ
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
				img2[1][i][j] = 1 - (3 * min / (R + G + B));   //���Ͷ�
			}
				
			img2[2][i][j] = (R + G + B) / 3;  //ǿ��
		}
}

//HSI��RGB��ת��
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
			if (H == 0 && S == 0)               //�ų��Ҷ���ɫ�����
			{
				img2[0][i][j] = I;              //�Ҷ�ֵ��RGB����������ǿ��
				img2[1][i][j] = I;
				img2[2][i][j] = I;
			}
			else
			{
				if (H >= 0 && H < 2 * pi / 3)                //H��0-120��
				{
					img2[2][i][j] = I * (1 - S);
					img2[0][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[1][i][j] = 3 * I - img2[0][i][j] - img2[2][i][j];
				}
				else if (H >= 2 * pi / 3 && H < 4 * pi / 3)   //H��120-240��
				{
					H = H - 2 * pi / 3;
					img2[0][i][j] = I * (1 - S);
					img2[1][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[2][i][j] = 3 * I - img2[0][i][j] - img2[1][i][j];
				}
				else if (H >= 4 * pi / 3 && H < 2 * pi)       //H��240-360��
				{
					H = H - 4 * pi / 3;
					img2[1][i][j] = I * (1 - S);
					img2[2][i][j] = I * (1 + S * cos(H) / cos(pi / 3 - H));
					img2[0][i][j] = 3 * I - img2[1][i][j] - img2[2][i][j];
				}
			}
			
		}
}

//ֱ��ͼ���⻯��������
auto histogram_equalization(const vector<vector<double>>& image)-> const vector<vector<double>>
{
	vector<vector<double>> image_jun;     //�洢��ֵ�����ͼ��
	image_jun = image;
	const int h = image.size();        //ͼ��߶�
	const int w = image[0].size();     //ͼ����
	vector<double> htm_num(256, 0);    //ԭͼ��ֱ��ͼ
	vector<double> htm_num_2(256, 0);  //���⻯��Ľ��
	for (auto x : image)               //ͳ��ͼ���и��Ҷ�ֵ������
		for (auto c : x)
			++(htm_num[c]);

	for (int i = 0; i <= 255; ++i)       //���⻯
	{
		double temp = 0;
		for (int j = 0; j <= i; ++j)
		{
			temp += 255 * htm_num[j] / (h * w);    //���
		}
		htm_num_2[i] = temp;
	}

	for (auto& x : image_jun)         //ͼ��Ҷ��޸�
		for (auto& c : x)
			c = htm_num_2[c];

	return image_jun;                //���ؾ��⻯���ͼ��
}

//���ֵ
double mean(vector<double> nums)
{
	int n = nums.size();
	double a = 0;
	for (auto c : nums)
		a += c / n;
	return a;
}

//���׼��
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