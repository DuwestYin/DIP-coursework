#pragma once

#include <vector>
using std::vector;

void base_segmentation(vector<vector<double>>& img, const int& delta);  //����ȫ����ֵ�ָ�
void otsu_segmentation(vector<vector<int>>& img);       //��󷽲�ָ�
