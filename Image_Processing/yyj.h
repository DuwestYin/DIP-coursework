#ifndef __YYJ_H__
#define __YYJ_H_

#include <string>
#include <vector>
using std::vector;
using std::string;

void histogram2(vector<double> p, vector<vector<int>>& hist);

//第一次作业
void reduce_spatial_resolution(vector<vector<double>>& image, int step);      //降低空间分辨率
void reduce_grayscale_resolution(vector<vector<double>>& image, int step);    //降低灰度分辨率
void superimposed_denoising(vector<vector<vector<double>>>& images);          //叠加去噪
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2); //差分增强

//第二次作业
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist); //直方图显示
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>;     //直方图均衡化
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz);   //直方图规定化
void mean_filtering(vector<vector<double>>& image, const int& size);     //均值滤波
void median_filtering(vector<vector<double>>& image, const int& size);   //中值滤波

#endif // __YYJ_H_
