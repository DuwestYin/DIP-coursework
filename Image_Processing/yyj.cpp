#include "yyj.h"
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
void differential_enhancement(vector<vector<double>>& image1 ,vector<vector<double>>& image2)
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

//�ڶ�����ҵ
//��ֵ�˲�
void mean_filtering(vector<vector<double>>& image, const int& size)
{
	const int h = image.size();          //ͼ��߶�
	const int w = image[0].size();       //ͼ����
	auto temp = image;                   //����洢�������ʱ����

	for(int i = size/2;i<h-size/2;++i)                 //ȡsize*size��С�ľ�ֵ����ֵ��temp�ж�Ӧ��λ��
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

//ֱ��ͼ��ʾ
void histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist)
{
	const int h = hist.size();        //ͼ��߶�
	const int w = hist[0].size();     //ͼ����

	vector<double> htm_num(256, 0);
	
	for (auto x : image)           //ͳ��ͼ���и��Ҷ�ֵ������
		for (auto c : x)
			++(htm_num[c]);

	for (auto& x : hist)
		for (auto& c : x)
			c = 255;

	const int level_num = 256 / 4;           //�ϲ�4�����ڵȼ�Ϊһ���µȣ��ܹ�64��
	vector<int> htm_num_2;                   //�����������洢�µȼ���Ӧ�ĻҶ���
	for (int i = 0; i < level_num; ++i)
		htm_num_2.push_back(htm_num[i * 4] + htm_num[i * 4 + 1] + htm_num[i * 4 + 2] + htm_num[i * 4 + 3]);
	
	const int pix_num = w / (level_num + 1) / 2;   //��ÿ���ȼ���Ҫ�����ؿ�ȣ�����Խ�����һ��

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

//ֱ��ͼ���⻯
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>
{
	vector<vector<int>> image_jun;     //�洢��ֵ�����ͼ��
	image_jun = image;
	const int h = image.size();        //ͼ��߶�
	const int w = image[0].size();     //ͼ����
	vector<double> htm_num(256, 0);
	vector<int> htm_num_2(256, 0);
	for (auto x : image)               //ͳ��ͼ���и��Ҷ�ֵ������
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

		