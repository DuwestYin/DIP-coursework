#include "yyj05.h"
#include "stdafx.h"
#include <vector>

using std::vector;

//����ȫ����ֵ�ָ�
void base_segmentation(vector<vector<double>>& img, const int& delta) 
{
	int m = img.size();           //��ȡͼ���С
	int n = img[0].size();
	double T1 = 0, T2 = 0;
	int MN = m * n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			T1 += img[i][j] / (MN);      //ȷ����ʼ�ָ���ֵ
	
	while (1)
	{
		double s1 = 0, s2 = 0;               //��������ֵ��
		int n1 = 0, n2 = 0;                  //�������ظ���
		double m1 = 0, m2 = 0;                  //���ߵľ�ֵ
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
		m1 = s1 / n1;              //��ֵ
		m2 = s2 / n2;
		T2 = (m1 + m2) / 2;        //�µ���ֵ

		if (abs(T2 - T1) <= delta)  
			break;                  //�˳�����
		T1 = T2;
	}
	
	for (int i = 0; i < m; ++i)       
		for (int j = 0; j < n; ++j)
			if (img[i][j] <= T2)      //��ֵ��
				img[i][j] = 0;
			else
				img[i][j] = 1;
}


//��󷽲�ָ�
void otsu_segmentation(vector<vector<int>>& img)
{
	int m = img.size();     //��ȡͼ���С
	int n = img[0].size();
	int MN = m * n;
	vector<double> hist;    //����ֱ��ͼ
	hist.resize(256);
	for (auto c : img)
		for (auto x : c)
			++hist[x];
	for (auto& c : hist)   //�õ������ܶ�
		c /= MN;
	vector<double> delta_bs;  //���治ͬkֵ����䷽��
	delta_bs.resize(256);
	for (int k = 0; k <= 255; ++k)
	{
		double P1 = 0;                 //�ۼƺ�
		for (int i = 0; i <= k; ++i)
			P1 += hist[i];
		double mk = 0;                 //�ۼƾ�ֵ
		for (int i = 0; i <= k; ++i)
			mk += i * hist[i];
		double mg = 0;                 //ȫ�־�ֵ
		for (int i = 0; i <= 255; ++i)
			mg += i * hist[i];
		double delta_b = 0;            //��䷽��
		if(P1 != 0)
			delta_b = (mg * P1 - mk) * (mg * P1 - mk) / (P1 * (1 - P1));    
		delta_bs[k] = delta_b;
	}
	int best_k = 0;
	double max_delta_b = 0;
	for(int i=0;i<=255;i++)
		if (delta_bs[i] > max_delta_b)    //Ѱ��������䷽��
		{
			best_k = i;
			max_delta_b = delta_bs[i];
		}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (img[i][j] <= best_k)      //��ֵ��
				img[i][j] = 0;
			else
				img[i][j] = 255;
}