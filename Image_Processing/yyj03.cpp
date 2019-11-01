#include "yyj01.h"
#include "stdafx.h"
#include <string>
#include <vector>
#include <complex>
using std::vector;
using std::string;
using std::complex;

const double pi = 3.141592653;
complex<double> euler_fun(double x)
{
	complex<double> y(cos(x), sin(x));
	return y;
}

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

void move2center(vector<vector<double>>& img)
{
	int m = img.size();
	int n = img[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img[i][j] *= pow(-1, i + j);
}

void log_exp(vector<vector<double>>& img)
{
	int m = img.size();
	int n = img[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img[i][j] = log(img[i][j] + 1);

}
double get_angle(complex<double> x)
{
	return atan2(x.imag(), x.real());
}

void img2big(vector<vector<double>>& img1, vector<vector<double>>& img2)
{
	int m = img1.size();
	int n = img1[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			img2[i][j] = img1[i][j];
}

void make_filter(vector<vector<double>>& H, int D, int num)
{
	int P = H.size();
	int Q = H[0].size();
	int m = P / 2;
	int n = Q / 2;
	switch (num)
	{
	case 0:           //理想低通滤波
	{
		for (int i = -D; i < D; ++i)
			for (int j = -D; j < D; ++j)
			{
				if ((i * i + j * j) < D * D)
					H[i + m][j + n] = 1;
			}
		break;
	}
	}
		
}

void act_filter(vector<vector<double>>& img_mag, vector<vector<double>>& H, vector<vector<double>>& G)
{
	int m = img_mag.size();
	int n = img_mag[0].size();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			G[i][j] = H[i][j] * img_mag[i][j];
}

void fft(const vector<vector<double>>& img, vector<vector<double>>& img_mag, vector<vector<double>>& img_ang)
{
	int P= img.size();
	int Q = img[0].size();
	int m = P / 2;
	int n = Q / 2;
	
	vector<vector<complex<double>>> img1;
	img1.resize(P);
	for (int i = 0; i < P; ++i)
		img1[i].resize(Q);

	for (int u = 0; u < P; ++u)
	{
		vector<complex<double>> fft_even;
		vector<complex<double>> fft_odd;
		for (int v = 0; v < n; ++v)
		{
			complex<double> temp_even(0, 0);
			complex<double> temp_odd(0, 0);
			for (int y = 0; y < n; ++y)
			{
				complex<double> W = euler_fun(-2 * pi * y * v / n);
				temp_even += img[u][2 * y] * W;
				temp_odd += img[u][2 * y + 1] * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int v = 0; v < n; ++v)
		{
			complex<double> fw = fft_odd[v] * euler_fun(-2 * pi * v / Q);
			img1[u][v] = fft_even[v] + fw;
			img1[u][v + n] = fft_even[v] - fw;
		}
	}

	for (int v = 0; v < Q; ++v)
	{
		vector<complex<double>> fft_even;
		vector<complex<double>> fft_odd;
		for (int u = 0; u < m; ++u)
		{
			complex<double> temp_even(0, 0);
			complex<double> temp_odd(0, 0);
			for (int x = 0; x < m; ++x)
			{
				complex<double> W = euler_fun(-2 * pi * x * u / m);
				temp_even += img1[2 * x][v] * W;
				temp_odd += img1[2 * x + 1][v] * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int u = 0; u < m; ++u)
		{
			complex<double> fw = fft_odd[u] * euler_fun(-2 * pi * u / P);
		    img_mag[u][v] = abs(fft_even[u] + fw);
			img_mag[u + m][v] = abs(fft_even[u] - fw);
			img_ang[u][v] = get_angle(fft_even[u] + fw);
			img_ang[u + m][v] = get_angle(fft_even[u] - fw);
		}
	}

}

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
			img_new[u][v] = a.real();
			a = fft_even[u] - fw;
			img_new[u + m][v] = a.real();
		}
	}
}