#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

//��һ����ҵ
void reduce_spatial_resolution(vector<vector<double>>& image, int step);      //���Ϳռ�ֱ���
void reduce_grayscale_resolution(vector<vector<double>>& image, int step);    //���ͻҶȷֱ���
void superimposed_denoising(vector<vector<vector<double>>>& images);          //����ȥ��
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2); //�����ǿ
