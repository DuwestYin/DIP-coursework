#include "yyj01.h"
#include "stdafx.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

///////////////////////////////////////////////////////////////////////////////////////
//��һ����ҵ
//1. ���Ϳռ�ֱ���
void reduce_spatial_resolution(vector<vector<double>>& image, int step)
{
	int h = image.size();           //ͼ��߶�
	int w = image[0].size();        //ͼ����

	for (int i = 0; i + step <= h; i += step)      //�Բ���step����ͼ��
		for (int j = 0; j + step <= w; j += step)
		{
			for (int m = 0; m < step; ++m)         //�� step*step ��С�ķ�����������ͳһ��ֵΪ�������Ͻǵ����ػҶ�
				for (int n = 0; n < step; ++n)
				{
					if (!(n == 0 && m == 0))
					{
						image[i + m][j + n] = image[i][j];
					}
				}
		}
}

//2. ���ͻҶȷֱ���
void reduce_grayscale_resolution(vector<vector<double>>& image, int step)
{
	int h = image.size();        //ͼ��߶�
	int w = image[0].size();     //ͼ����

	for (int i = 0; i < h; ++i)   //����ͼ��
		for (int j = 0; j < w; ++j)
		{
			int jian = static_cast<int>(image[i][j]) % step;     //�Ҷ�ֵ��stepȡ����
			if (jian) image[i][j] -= jian;                       //��������Ϊ�����ȥ����
			image[i][j] = int(image[i][j]) * 255 / (256 - step); //���ŵ�0-255
		}
}


//3. ����ȥ��
void superimposed_denoising(vector<vector<vector<double>>>& images)
{
	int times = images.size();     //���ڵ��ӵ�ͼ����
	int h = images[0].size();      //ͼ��߶�
	int w = images[0][0].size();   //ͼ����
	vector<vector<double>> temp(h, vector<double>(w, 0));    //����洢�������ʱ����

	for (int k = 0; k < times; ++k)                   //��ƽ��ֵ
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				temp[i][j] += (images[k][i][j] / times);

	for (int i = 0; i < h; ++i)                  //�������ֵ����һ��ͼ��
		for (int j = 0; j < w; ++j)
			images[0][i][j] = temp[i][j];
}

//4. �����ǿ
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2)
{
	int h = image1.size();       //ͼ��߶�
	int w = image1[0].size();    //ͼ����
	vector<vector<double>> temp(h, vector<double>(w, 0));  //����洢�������ʱ����

	for (int i = 0; i < h; ++i)                  //����ͼ������
		for (int j = 0; j < w; ++j)
			temp[i][j] = image1[i][j] - image2[i][j];

	double min = 0, max = 0;         //����洢���ػҶ����ֵ����Сֵ�ı���
	for (auto& ig : temp)            //�����ػҶ���Сֵ
		for (auto& c : ig)
			if (c < min) min = c;
	for (auto& ig : temp)            //�������ĸ��Ҷȼ�����Сֵ��ʹ֮Ϊ�Ǹ���
		for (auto& c : ig)
			c += min;
	for (auto& ig : temp)            //�����ػҶ����ֵ
		for (auto& c : ig)
			if (c < max) max = c;
	for (auto& ig : temp)           //���ŵ�0-255
		for (auto& c : ig)
		{
			c *= 255.0 / max;
			c = 255 - c;
		}
	for (int i = 0; i < h; ++i)     //�������ֵ��ԭͼ��
		for (int j = 0; j < w; ++j)
			image1[i][j] = temp[i][j];
}
