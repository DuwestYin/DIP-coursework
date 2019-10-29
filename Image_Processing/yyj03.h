#pragma once

#include <string>
#include <vector>
#include <complex>

using std::vector;
using std::string;
using std::complex;


//第三次作业
complex<double> euler_fun(double x);    //欧拉公式
void normalize(vector<vector<double>>& img);
void fft(const vector<vector<double>>& img, vector<vector<double>>& result); //傅立叶变换

