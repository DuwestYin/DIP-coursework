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

void normalize(vector<vector<double>>& img)
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
			img[i][j] = (img[i][j] - min) * 255 / (max - min);
}

void fft(const vector<vector<double>>& img, vector<vector<double>>& fftimg)
{
	int P = img.size();
	int Q = img[0].size();
	int m = P / 2;
	int n = Q / 2;
	
	fftimg = img;

	for (int i = 0; i < P; ++i)
		for (int j = 0; j < Q; ++j)
			fftimg[i][j] *= pow(-1, i + j);

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
				temp_even += fftimg[u][2 * y] * W;
				temp_odd += fftimg[u][2 * y + 1] * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int v = 0; v < n; ++v)
		{
			complex<double> fw = fft_odd[v] * euler_fun(-2 * pi * v / Q);
			fftimg[u][v] = abs(fft_even[v] + fw);
			fftimg[u][v + n] = abs(fft_even[v] - fw);
		}
	}

	for (int i = 0; i < P; ++i)
		for (int j = 0; j < Q; ++j)
			fftimg[i][j] *= pow(-1, i + j);

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
				temp_even += fftimg[2 * x][v] * W;
				temp_odd += fftimg[2 * x + 1][v] * W;
			}
			fft_even.push_back(temp_even);
			fft_odd.push_back(temp_odd);
		}
		for (int u = 0; u < m; ++u)
		{
			complex<double> fw = fft_odd[u] * euler_fun(-2 * pi * u / P);
			fftimg[u][v] = abs(fft_even[u] + fw);
			fftimg[u + m][v] = abs(fft_even[u] - fw);
		}
	}

	for (int i = 0; i < P; ++i)
		for (int j = 0; j < Q; ++j)
			fftimg[i][j] = log(fftimg[i][j] + 1);

	normalize(fftimg);
}