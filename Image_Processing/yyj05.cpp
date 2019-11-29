#include "yyj05.h"
#include "stdafx.h"
#include <vector>

using std::vector;

//基本全局阈值分割
void base_segmentation(vector<vector<double>>& img, const int& delta) 
{
	int m = img.size();           //获取图像大小
	int n = img[0].size();
	double T1 = 0, T2 = 0;
	int MN = m * n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			T1 += img[i][j] / (MN);      //确定初始分割阈值
	
	while (1)
	{
		double s1 = 0, s2 = 0;               //两边像素值和
		int n1 = 0, n2 = 0;                  //两边像素个数
		double m1 = 0, m2 = 0;                  //两边的均值
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (img[i][j] <= T1)
				{
					s1 += img[i][j];
					++n1;
				}
				else
				{
					s2 += img[i][j];
					++n2;
				}
					
			}
		m1 = s1 / n1;              //均值
		m2 = s2 / n2;
		T2 = (m1 + m2) / 2;        //新的阈值

		if (abs(T2 - T1) <= delta)  
			break;                  //退出迭代
		T1 = T2;
	}
	
	for (int i = 0; i < m; ++i)       
		for (int j = 0; j < n; ++j)
			if (img[i][j] <= T2)      //二值化
				img[i][j] = 0;
			else
				img[i][j] = 1;
}


//最大方差分割
void otsu_segmentation(vector<vector<int>>& img)
{
	int m = img.size();     //获取图像大小
	int n = img[0].size();
	int MN = m * n;
	vector<double> hist;    //保存直方图
	hist.resize(256);
	for (auto c : img)
		for (auto x : c)
			++hist[x];
	for (auto& c : hist)   //得到概率密度
		c /= MN;
	vector<double> delta_bs;  //保存不同k值的类间方差
	delta_bs.resize(256);
	for (int k = 0; k <= 255; ++k)
	{
		double P1 = 0;                 //累计和
		for (int i = 0; i <= k; ++i)
			P1 += hist[i];
		double mk = 0;                 //累计均值
		for (int i = 0; i <= k; ++i)
			mk += i * hist[i];
		double mg = 0;                 //全局均值
		for (int i = 0; i <= 255; ++i)
			mg += i * hist[i];
		double delta_b = 0;            //类间方差
		if(P1 != 0)
			delta_b = (mg * P1 - mk) * (mg * P1 - mk) / (P1 * (1 - P1));    
		delta_bs[k] = delta_b;
	}
	int best_k = 0;
	double max_delta_b = 0;
	for(int i=0;i<=255;i++)
		if (delta_bs[i] > max_delta_b)    //寻找最大的类间方差
		{
			best_k = i;
			max_delta_b = delta_bs[i];
		}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (img[i][j] <= best_k)      //二值化
				img[i][j] = 0;
			else
				img[i][j] = 255;
}