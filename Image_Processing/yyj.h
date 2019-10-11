#ifndef __YYJ_H__
#define __YYJ_H_

#include <string>
#include <vector>
using std::vector;
using std::string;

void histogram2(vector<double> p, vector<vector<int>>& hist);

//��һ����ҵ
void reduce_spatial_resolution(vector<vector<double>>& image, int step);      //���Ϳռ�ֱ���
void reduce_grayscale_resolution(vector<vector<double>>& image, int step);    //���ͻҶȷֱ���
void superimposed_denoising(vector<vector<vector<double>>>& images);          //����ȥ��
void differential_enhancement(vector<vector<double>>& image1, vector<vector<double>>& image2); //�����ǿ

//�ڶ�����ҵ
vector<double> histogram_display(const vector<vector<int>>& image, vector<vector<int>>& hist); //ֱ��ͼ��ʾ
auto histogram_equalization(const vector<vector<int>>& image)-> const vector<vector<int>>;     //ֱ��ͼ���⻯
void histogram_specification(const vector<vector<int>>& image, vector<vector<int>>& image2, const vector<double> Pz);   //ֱ��ͼ�涨��
void mean_filtering(vector<vector<double>>& image, const int& size);     //��ֵ�˲�
void median_filtering(vector<vector<double>>& image, const int& size);   //��ֵ�˲�

#endif // __YYJ_H_
