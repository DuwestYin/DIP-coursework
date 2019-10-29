#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;


//第二次作业
void histogram2(vector<double> p, vector<vector<int>>& hist);
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist); //直方图显示
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>;     //直方图均衡化
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz);   //直方图规定化
void mean_filtering(vector<vector<double>>& image, const int& size);     //均值滤波
void median_filtering(vector<vector<double>>& image, const int& size);   //中值滤波