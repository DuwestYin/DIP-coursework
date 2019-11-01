#pragma once

#include <string>
#include <vector>
#include <complex>

using std::vector;
using std::string;
using std::complex;


//��������ҵ
complex<double> euler_fun(double x);    //ŷ����ʽ
void normalize(vector<vector<double>>& img, double a, double b);
void fft(const vector<vector<double>>& img, vector<vector<double>>& img_mag, vector<vector<double>>& img_ang); //����Ҷ�任
void invfft(vector<vector<double>>& img_mag, vector<vector<double>>& img_ang, vector<vector<double>>& img_new); //����Ҷ���任
void move2center(vector<vector<double>>& img);
void log_exp(vector<vector<double>>& img);   //log����
double get_angle(complex<double> x);
void make_filter(vector<vector<double>>& H, int D, int n);
void img2big(vector<vector<double>>& img1, vector<vector<double>>& img2);
void act_filter(vector<vector<double>>& img_mag, vector<vector<double>>& H, vector<vector<double>>& G);
