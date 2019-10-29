#include "yyj02.h"
#include "stdafx.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

void histogram2(vector<double> p, vector<vector<int>>& hist)
{
	const int h = hist.size();        //ͼ��߶�
	const int w = hist[0].size();     //ͼ����

	vector<double> htm_num(256, 0);

	for (int i = 0; i < 256; ++i)
		htm_num[i] = h * p[i] * w;

	for (auto& x : hist)           //ֱ��ͼ��������Ϊ��ɫ
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //�ϲ�4�����ڵȼ�Ϊһ���µȣ��ܹ�64��
	vector<int> htm_num_2;                   //�����������洢�µȼ���Ӧ�ĻҶ���
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);

	const int pix_num = w / (level_num + 1) / 2;   //��ÿ���ȼ���Ҫ�����ؿ�ȣ�����Խ�����һ��

	int max = 0, min = 0;           //�ҵ��Ҷ���Сֵ�����ֵ
	for (auto c : htm_num_2)
		if (min > c)
			min = c;
	for (auto c : htm_num_2)
		if (max < c)
			max = c;

	for (auto& c : htm_num_2)       //��ͼ�����߶�Ϊͼ��߶ȵ�3/4
		c = (c - min) * (h * 3 / 4) / (max - min);

	for (int i = 0; i < level_num; ++i)    //��ͼ
		for (int j = 0; j < pix_num; ++j)
			for (int z = 0; z < htm_num_2[i]; ++z)
				hist[(h - 1 - z)][i * 2 * pix_num + j] = 0;
}

//�ڶ�����ҵ
//ֱ��ͼ��ʾ
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist)
{
	const int h = hist.size();        //ͼ��߶�
	const int w = hist[0].size();     //ͼ����

	vector<double> htm_num(256, 0);

	for (auto x : image)           //ͳ��ͼ���и��Ҷ�ֵ������
		for (auto c : x)
			++(htm_num[c]);

	for (auto& x : hist)           //ֱ��ͼ��������Ϊ��ɫ
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //�ϲ�4�����ڵȼ�Ϊһ���µȣ��ܹ�64��
	vector<int> htm_num_2;                   //�����������洢�µȼ���Ӧ�ĻҶ���
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);

	const int pix_num = w / (level_num + 1) / 2;   //��ÿ���ȼ���Ҫ�����ؿ�ȣ�����Խ�����һ��

	int max = 0, min = 0;           //�ҵ��Ҷ���Сֵ�����ֵ
	for (auto c : htm_num_2)
		if (min > c)
			min = c;
	for (auto c : htm_num_2)
		if (max < c)
			max = c;

	for (auto& c : htm_num_2)       //��ͼ�����߶�Ϊͼ��߶ȵ�3/4
		c = (c - min) * (h * 3 / 4) / (max - min);

	for (int i = 0; i < level_num; ++i)    //��ͼ
		for (int j = 0; j < pix_num; ++j)
			for (int z = 0; z < htm_num_2[i]; ++z)
				hist[(h - 1 - z)][i * 2 * pix_num + j] = 0;

	for (auto& c : htm_num)
		c = c / h / w;

	return htm_num;
}

//ֱ��ͼ���⻯
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>
{
	vector<vector<int>> image_jun;     //�洢��ֵ�����ͼ��
	image_jun = image;
	const int h = image.size();        //ͼ��߶�
	const int w = image[0].size();     //ͼ����
	vector<double> htm_num(256, 0);    //ԭͼ��ֱ��ͼ
	vector<int> htm_num_2(256, 0);     //���⻯��Ľ��
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

//ֱ��ͼ�涨��
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz1)
{
	const int h = image.size();        //ͼ��߶�
	const int w = image[0].size();     //ͼ����
	vector<int> Gz(256, 0);            //�ο�ֱ��ͼ���⻯
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

//��ֵ�˲�
void mean_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();          //ͼ��߶�
	const int w = image[0].size();       //ͼ����
	auto temp = image;                   //����洢�������ʱ����

	for (int i = size / 2; i < h - size / 2; ++i)                 //ȡsize*size��С�ľ�ֵ����ֵ��temp�ж�Ӧ��λ��
		for (int j = size / 2; j < w - size / 2; ++j)
		{
			double val = 0;
			for (int k = -size / 2; k <= size / 2; ++k)
				for (int l = -size / 2; l <= size / 2; ++l)
					val += image[i + k][j + l] / size / size;
			temp[i][j] = val;
		}

	for (int i = 0; i < size / 2; ++i)           //��δ����ı߽縳ֵ255
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

	image = temp;           //����ʱͼ��ֵ��ԭͼ��

}

//��ֵ�˲�
void median_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();        //ͼ��߶�
	const int w = image[0].size();     //ͼ����
	auto temp = image;                 //����洢�������ʱ����

	for (int i = size / 2; i < h - size / 2; ++i)        //ȡsize*size��С��ֵ����ֵ��temp�ж�Ӧ��λ��
		for (int j = size / 2; j < w - size / 2; ++j)
		{
			vector<double> maopao;                          //��������ð�����������
			for (int k = -size / 2; k <= size / 2; ++k)
				for (int l = -size / 2; l <= size / 2; ++l)
					maopao.push_back(image[i + k][j + l]);  //��size*size��С�������ƽ�����

			for (int k = 0; k < maopao.size() - 1; ++k)     //ð������
				for (int g = 0; g < maopao.size() - 1 - k; ++g)
					if (maopao[g] > maopao[g + 1])
					{
						double b = 0;
						b = maopao[g];
						maopao[g] = maopao[g + 1];
						maopao[g + 1] = b;
					}
			temp[i][j] = maopao[size * size / 2];         //ȡ��ֵ
		}

	for (int i = 0; i < size / 2; ++i)               //��δ����ı߽縳ֵ255
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

	image = temp;                //����ʱͼ��ֵ��ԭͼ��
}


