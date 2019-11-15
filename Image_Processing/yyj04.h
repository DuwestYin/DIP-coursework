#pragma once

#include <vector>
using std::vector;

void rgb2hsi(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2);   //RGB到HSI的转换
void hsi2rgb(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2);   //HSI到RGB的转换
auto histogram_equalization(const vector<vector<double>>& image)-> const vector<vector<double>>;  //直方图均衡化函数重载
double mean(vector<double> nums);            //求均值
double std_deviation(vector<double> nums);   //求标准差