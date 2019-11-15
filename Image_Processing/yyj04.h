#pragma once

#include <vector>
using std::vector;

void rgb2hsi(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2);   //RGB��HSI��ת��
void hsi2rgb(const vector<vector<vector<double>>>& img1, vector<vector<vector<double>>>& img2);   //HSI��RGB��ת��
auto histogram_equalization(const vector<vector<double>>& image)-> const vector<vector<double>>;  //ֱ��ͼ���⻯��������
double mean(vector<double> nums);            //���ֵ
double std_deviation(vector<double> nums);   //���׼��