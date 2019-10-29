#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

//第一次作业
void reduce_spatial_resolution(vector<vector<double>>& image, int step);      //降低空间分辨率
void reduce_grayscale_resolution(vector<vector<double>>& image, int step);    //降低灰度分辨率
void superimposed_denoising(vector<vector<vector<double>>>& images);          //叠加去噪
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2); //差分增强
