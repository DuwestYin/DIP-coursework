#include "yyj01.h"
#include "stdafx.h"
#include <string>
#include <vector>
#include <complex>
using std::vector;
using std::string;
using std::complex;

const double pi = 3.141592653;

//欧拉公式
complex<double> euler_fun(double x)
{
	complex<double> y(cos(x), sin(x));
	return y;
}

//将图像灰度值归一化到指定范围[a, b]
void normalize(vector<vector<double>>& img, double a, double b)
{
	double max = 0, min = 0;
	for (int i = 0; i < img.size(); ++i)
		for (int j = 0; j < img[0].size(); ++j)
		{
			if (img[i][j] < min)
				min = img[i][j];
			if (img[i][j] > max)
				max = img[i][j];
		}
	for (int i = 0; i < img.size(); ++i)
		for (int j = 0; j < img[0].size(); ++j)
			img[i][j] = (img[i][j] - min) * (b - a) / (max - min) + a;
}

//将图像乘上(-1)^(i+j)，傅立叶谱移动中心
void move2center(vector<vector<double>>& img)
{
	int m = img.size();
	int n = img[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img[i][j] *= pow(-1, i + j);
}

//对傅立叶变换后的结果取对数，以拉伸较暗的灰度
void log_exp(vector<vector<double>>& img)
{
	int m = img.size();
	int n = img[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img[i][j] = log(img[i][j] + 1);

}

//获取复数的相角
double get_angle(complex<double> x)
{
	return atan2(x.imag(), x.real());
}

//将图像填0扩充为原来的两倍
void img2big(vector<vector<double>>& img1, vector<vector<double>>& img2)
{
	int m = img1.size();
	int n = img1[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img2[i][j] = img1[i][j];
}

//构造滤波器
void make_filter(vector<vector<double>>& H, int D, int num)
{
	int P = H.size();
	int Q = H[0].size();
	int m = P / 2;
	int n = Q / 2;
	switch (num)
	{
	case 0:           //理想低通
	{
		for (int i = -D; i < D; ++i)
			for (int j = -D; j < D; ++j)
			{
				if ((i * i + j * j) < D * D)
					H[i + m][j + n] = 1;
			}
		break;
	}
	case 1:     //巴特沃斯低通
	{
		for (int i = 0; i < P; ++i)   
			for (int j = 0; j < Q; ++j)
			{
				double temp = pow(sqrt((i - m) * (i - m) + (j - n) * (j - n)) / D, 4);
				H[i][j] = 1 / (1 + temp);
			}
		break;
	}
	case 2:     //高斯低通
	{
		for (int i = 0; i < P; ++i)   
			for (int j = 0; j < Q; ++j)
			{
				double temp = (i - m) * (i - m) + (j - n) * (j - n);
				H[i][j] = exp(-temp / (D * D));
			}
		break;
	}
	case 3:  //理想高通
	{
		for (int i = -D; i < D; ++i)
			for (int j = -D; j < D; ++j)
			{
				if ((i * i + j * j) < D * D)
					H[i + m][j + n] = 1;
			}
		for (int i = 0; i < P; ++i)
			for (int j = 0; j < Q; ++j)
				H[i][j] = 1 - H[i][j];
		break;
	}
	case 4:   //巴特沃斯高通
	{
		for (int i = 0; i < P; ++i)   
			for (int j = 0; j < Q; ++j)
			{
				double temp = pow(D / sqrt((i - m) * (i - m) + (j - n) * (j - n)), 4);
				H[i][j] = 1 / (1 + temp);
			}
		break;
	}
	case 5:     //高斯高通
	{
		for (int i = 0; i < P; ++i)   
			for (int j = 0; j < Q; ++j)
			{
				double temp = (i - m) * (i - m) + (j - n) * (j - n);
				H[i][j] = 1 - exp(-temp / (D * D));
			}
		break;
	}
	}
		
}

//执行图像对应像素之间的乘法，滤波操作
void act_filter(vector<vector<double>>& img_mag, vector<vector<double>>& H, vector<vector<double>>& G)
{
	int m = img_mag.size();
	int n = img_mag[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			G[i][j] = H[i][j] * img_mag[i][j];
}

//快速傅立叶变换
void fft(const vector<vector<double>>& img, vector<vector<double>>& img_mag, vector<vector<double>>& img_ang)
{
	int P= img.size();
	int Q = img[0].size();
	int m = P / 2;
	int n = Q / 2;
	
	vector<vector<complex<double>>> img1;   //临时vector数组，存储第一次变换的复数值
	img1.resize(P);
	for (int i = 0; i < P; ++i)
		img1[i].resize(Q);

	for (int u = 0; u < P; ++u)            //先对每一行进行变换
	{
		vector<complex<double>> fft_even;  //偶数部分
		vector<complex<double>> fft_odd;   //奇数部分
		for (int v = 0; v < n; ++v)        //遍历一行的所有元素
		{
			complex<double> temp_even(0, 0);  //临时变量
			complex<double> temp_odd(0, 0);
			for (int y = 0; y < n; ++y)
			{
				complex<double> W = euler_fun(-2 * pi * y * v / n);   //欧拉公式
				temp_even += img[u][2 * y] * W;           //偶数的变换
				temp_odd += img[u][2 * y + 1] * W;        //奇数的变换
			}
			fft_even.push_back(temp_even);       //推进临时数组
			fft_odd.push_back(temp_odd);
		}
		for (int v = 0; v < n; ++v)
		{
			complex<double> fw = fft_odd[v] * euler_fun(-2 * pi * v / Q);   
			img1[u][v] = fft_even[v] + fw;               //将变换结果幅值给中间数组
			img1[u][v + n] = fft_even[v] - fw;
		}
	}

	for (int v = 0; v < Q; ++v)            //再对每一列进行变换
	{
		vector<complex<double>> fft_even;  //偶数部分
		vector<complex<double>> fft_odd;   //奇数部分
		for (int u = 0; u < m; ++u)        //遍历每一列的所有元素
		{
			complex<double> temp_even(0, 0);  //临时变量
			complex<double> temp_odd(0, 0);
			for (int x = 0; x < m; ++x)
			{
				complex<double> W = euler_fun(-2 * pi * x * u / m);    //欧拉公式
				temp_even += img1[2 * x][v] * W;       //偶数的变换
				temp_odd += img1[2 * x + 1][v] * W;    //奇数的变换
			}
			fft_even.push_back(temp_even);       //推入临时数组
			fft_odd.push_back(temp_odd);
		}
		for (int u = 0; u < m; ++u)
		{
			complex<double> fw = fft_odd[u] * euler_fun(-2 * pi * u / P);
		    img_mag[u][v] = abs(fft_even[u] + fw);                //傅立叶变换的幅值
			img_mag[u + m][v] = abs(fft_even[u] - fw);
			img_ang[u][v] = get_angle(fft_even[u] + fw);          //傅立叶变换的相角
			img_ang[u + m][v] = get_angle(fft_even[u] - fw);
		}
	}

}

//傅立叶反变化，同快速傅立叶变换几乎一样
void invfft(vector<vector<double>>& img_mag, vector<vector<double>>& img_ang, vector<vector<double>>& img_new)
{
	int P = img_mag.size();
	int Q = img_mag[0].size();
	int m = P / 2;
	int n = Q / 2;

	vector<vector<complex<double>>> img1;
	img1.resize(P);
	for (int i = 0; i < P; ++i)
		img1[i].resize(Q);

	for (int u = 0; u < P; ++u)                //进行每行的变换
	{
		vector<complex<double>> fft_even;
		vector<complex<double>> fft_odd;
		for (int v = 0; v < n; ++v)
		{
			complex<double> temp_even(0, 0);
			complex<double> temp_odd(0, 0);
			for (int y = 0; y < n; ++y)
			{
				complex<double> W = euler_fun(2 * pi * y * v / n);
				temp_even += img_mag[u][2 * y] * euler_fun(img_ang[u][2 * y]) * W;
				temp_odd += img_mag[u][2 * y + 1] * euler_fun(img_ang[u][2 * y + 1]) * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int v = 0; v < n; ++v)
		{
			complex<double> fw = fft_odd[v] * euler_fun(2 * pi * v / Q);
			img1[u][v] = fft_even[v] + fw;
			img1[u][v + n] = fft_even[v] - fw;
		}
	}

	for (int v = 0; v < Q; ++v)          //进行每列的变换
	{
		vector<complex<double>> fft_even;
		vector<complex<double>> fft_odd;
		for (int u = 0; u < m; ++u)
		{
			complex<double> temp_even(0, 0);
			complex<double> temp_odd(0, 0);
			for (int x = 0; x < m; ++x)
			{
				complex<double> W = euler_fun(2 * pi * x * u / m);
				temp_even += img1[2 * x][v] * W;
				temp_odd += img1[2 * x + 1][v] * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int u = 0; u < m; ++u)
		{
			complex<double> fw = fft_odd[u] * euler_fun(2 * pi * u / P);
			complex<double> a = fft_even[u] + fw;
			img_new[u][v] = a.real();        //取反变换的实部
			a = fft_even[u] - fw;
			img_new[u + m][v] = a.real();
		}
	}
}