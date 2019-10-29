#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;


//�ڶ�����ҵ
void histogram2(vector<double> p, vector<vector<int>>& hist);
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist); //ֱ��ͼ��ʾ
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>;     //ֱ��ͼ���⻯
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz);   //ֱ��ͼ�涨��
void mean_filtering(vector<vector<double>>& image, const int& size);     //��ֵ�˲�
void median_filtering(vector<vector<double>>& image, const int& size);   //��ֵ�˲�