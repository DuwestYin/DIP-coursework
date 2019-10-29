#pragma once

#include <string>
#include <vector>
#include <complex>

using std::vector;
using std::string;
using std::complex;


//��������ҵ
complex<double> euler_fun(double x);    //ŷ����ʽ
void normalize(vector<vector<double>>& img);
void fft(const vector<vector<double>>& img, vector<vector<double>>& result); //����Ҷ�任

