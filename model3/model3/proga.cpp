#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <time.h>
using namespace std;

float ub()
{
	
	float om1 = (rand() % 100) / (100 * 1.0);
	float om2 = (rand() % 100) / (100 * 1.0);
	float ksi = 2 * om1 + 4;
	float ny = 2 * om2 + 4;
	float v = ksi*ny;
	return v;
}

float minimum(float *a,int n)
{
	float m = 0;
	m = a[1];
	for (int i = 1; i < n+1; i++)
	{
		if (a[i] < m)
		{
			m = a[i];
		}
	}
	return m;
}

float maximum(float *a, int n)
{
	float m = 0;
	m = a[1];
	for (int i = 1; i < n+1; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}
	return m;
}

int prom(float *a, float b, float c, int N)
{
	int ch = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if ((a[i] >= b) && (a[i] < c))
		{
			ch =ch + 1;
		}
	}
	return ch;
}

void outputf(ofstream &f,int *a,int k)
{
	f.open("result.txt");
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	for (int i = 1; i < k + 1; i++)
	{
		f << a[i] << endl;
	}
	f.close();
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int N;
	int ch = 0;
	float res = 0;
	float min, max;
	float w;
	int k;
	int del;
	float delt;
	int u;
	int z = 0;
	int y = 0;
	while (z!=1 )
	{
		system("cls");
		cout << "Введите число повторов эксперимента" << endl;
		cin >> N;
		float *a = new float[N];
		srand(time(NULL));
		cout << "Исходная таблица данных:" << endl;
		for (int i = 1; i < N + 1; i++)
		{
			a[i] = ub();
			printf("%.4f ", a[i]);
			if ((i % 10 == 0) && (i != 0))
			{
				cout << endl;
			}
		}
		cout << endl << endl;
		min = minimum(a, N);
		max = maximum(a, N);
		cout << "Минимальное и максимальное значиения:"<< endl;
		printf("a0=%.4f\n", min);
		printf("a%d=%.4f\n",N, max);
		cout << endl;
		w = max - min;
		k = pow(N, 1.0 / 3)+0.99999;
		del = w / k + 0.5;
		delt = w / k;
		cout << "Размах выборки:" << w << endl;
		cout << "Число интервалов группировки:" << k << endl;
		cout << "Интервал группировки:" << delt << endl;
		cout << endl;
		float *a1 = new float[k];
		float *a2 = new float[k];
		float *a3 = new float[k];
		float *a4 = new float[k];
		int *a5 = new int[k];
		int *a6 = new int[k];
		for (int l = 1; l < k + 1; l++)
		{
			a6[l] = 0;
		}
		float *a7 = new float[k];
		for (int j = 1; j < k + 1; j++)
		{
			a1[j] = j;
			a2[j] = min + delt*(j - 1);
			a3[j] = min + delt + delt*(j - 1);
			if (j == k)
			{
				a3[j] = max;
			}
			a4[j] = (a2[j] + a3[j]) / 2;
			a5[j] = prom(a, a2[j], a3[j], N);
			if (j == k)
			{
				a5[j] = a5[j]+1;
			}
			if (j == 1)
			{
				u = 0;
			}
			else
			{
				u = 1;
			}
			a6[j] = a6[j - 1] * u + a5[j];
		}
		cout << "Промежуточные вычисления:" << endl;
		for (int j = 1; j < k + 1; j++)
		{

			cout << a1[j];
			printf(" [%.4f ", a2[j]);
			cout << " , ";
			printf("%.4f ) ", a3[j]);
			printf("%.4f", a4[j]);
			cout << " " << a5[j] << " " << a5[j] << "/" << N << " " << a6[j] << " " << a6[j] << "/" << N << " " << endl;
		}
		cout << "Функция распределения= " << endl;
		for (int j = 1; j < k + 1; j++)
		{
			if (j == k)
			{
				goto G;
			}
			if (j == 1)
			{
				cout << "  __" << endl;
				cout << " | 0 ,если x<z1="<< a4[j] <<endl;
			}
			else
			{
				cout << " | " << a6[j] << "/" << N << " " << ",если z" << j - 1 << " < x <= z" << j << " = " << a4[j] << " ;" << endl;
			}
			G:
			if (j == k)
			{
				cout << " | 1 ,если z"<< k <<"<x" << endl;
				cout << " |__ ";
			}


			/*cout << a1[j] << " [" << a2[j] << " , ";
			printf("%.4f ) ", a3[j]);
			printf("%.4f", a4[j]);
			cout << " " << a5[j] << " " << a5[j] << "/" << N << " " << a6[j] << " " << a6[j] << "/" << N << " " << endl;*/

		}
		cout << endl;
		cout << endl;
		/*cout <<"Гисторграмма:"<< endl;
		cout << " | " << endl;
		for (int l = 1; l < 51; l++)
		{
			cout << " | " << endl;
		}
		cout << " |";
		for (int l = 1; l < 101; l++)
		{
			cout << "_" ;
		}
		//cout << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " | " << endl << " |" << "______________________________" << endl;
		cout << endl;*/
		cout << "Гистограмма:" << endl;
		for (int i = 1; i < k + 1; i++)
		{
			printf("[%.4f ", a2[i]);
			cout << " , ";
			printf("%.4f ) ", a3[i]);
			cout << " = " << a5[i] << " / " << del*N << endl;
		}
		ofstream f1;
		float *b = new float[k];
		for (int i = 1; i < k + 1; i++)
		{
			b[i] = a5[i]/(delt*N);
		}
		outputf(f1, a5,k);
		system("WindowsFormsApplication1.exe");
		cout << "Хотите повторить?(нажмите '1' для выхода):" << endl;
		cin >> z;
		cout << endl;
	}
	return 0;

}

