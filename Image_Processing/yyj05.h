#pragma once

#include <vector>
using std::vector;

void base_segmentation(vector<vector<double>>& img, const int& delta);  //基本全局阈值分割
void otsu_segmentation(vector<vector<int>>& img);       //最大方差分割
