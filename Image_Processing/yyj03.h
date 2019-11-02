#pragma once

#include <string>
#include <vector>
#include <complex>

using std::vector;
using std::string;
using std::complex;


//第三次作业
complex<double> euler_fun(double x);      //欧拉公式
void normalize(vector<vector<double>>& img, double a, double b);     //归一化函数
void fft(const vector<vector<double>>& img, vector<vector<double>>& img_mag, vector<vector<double>>& img_ang);  //傅立叶变换
void invfft(vector<vector<double>>& img_mag, vector<vector<double>>& img_ang, vector<vector<double>>& img_new);  //傅立叶反变换
void move2center(vector<vector<double>>& img);    //移动傅立叶谱到中心
void log_exp(vector<vector<double>>& img);        //log拉伸暗灰度
double get_angle(complex<double> x);              //获取复数的相角
void make_filter(vector<vector<double>>& H, int D, int n);   //构造滤波器
void img2big(vector<vector<double>>& img1, vector<vector<double>>& img2);   //扩充图像为两倍
void act_filter(vector<vector<double>>& img_mag, vector<vector<double>>& H, vector<vector<double>>& G);  //执行滤波
