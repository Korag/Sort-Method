// sortbubble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <iostream>
using namespace std;
unsigned long int const n = 100000000;
float z[n + 1];

void bubble_sort(unsigned long int n, float *a)
{
	unsigned long int k, l;
	float p;
	l = n;
	do
	{
		k = 0;
		l = l - 1;
		for (unsigned long int i = 1; i <= l; i++)
		{ 
			if (a[i] > a[i + 1])
			{
				p = a[i];
				a[i] = a[i + 1];
				a[i + 1] = p;
				k = k + 1;
			}
		}
	} while (k != 0);
}


void insert_sort(unsigned long int n, float *a)
{
	unsigned long int l, p, s, k;
	float y;
	a[0] = -1,7E38;
	for (unsigned long int i = 2; i <= n; i++)
		{
		y = a[i];
		l = 0;
		p = i - 1;
		do
			{
			s = (l + p + 1) / 2;
			if (a[s] <= y)
				{
				l = s;
				}
			else
				{
				p = s - 1;
				}
		} while (l != p);
		k = l;
		for (unsigned long int j = i - 1; j >= k + 1; j--)
			{
			a[j + 1] = a[j];
			}
		a[k + 1] = y;
		}
}

void scalaj(unsigned long int l, unsigned long int s, unsigned long int p, float *a)
{
	unsigned long int i, j, m, k;
	//float z[n + 1];
	i = l;
	j = s;
	m = l;
	do
		{
		if (a[i] <= a[j])
		{
			z[m] = a[i];
			i = i + 1;
		}
		else
		{
			z[m] = a[j];
			j = j + 1;
		}
		m = m + 1;
	} while (i < s && j <= p);
	if (i < s)
	{
		k = p;
		for (unsigned long int j = s - 1; j >= i; j--)
		{
			a[k] = a[j];
			k = k - 1;
		}
	}
	for (unsigned long int i = l; i <= m - 1; i++)
	{
		a[i] = z[i];
	}
}

void sort_scal(unsigned long int d, unsigned long int g, float *a)
{
	unsigned long int s;
	if (d < g)
	{
		s = (d + g) / 2;
		sort_scal(d, s, a);
		sort_scal(s + 1, g, a);
		scalaj(d, s + 1, g, a);
	}
}

void quick_sort(unsigned long int d, unsigned long int g, float *a)
{
	unsigned long int l, p, s;
	float v, u;
	s = (d + g) / 2;
	v = a[s];
	l = d;
	p = g;
	do {
		while (a[l] < v) l = l + 1;
		while (a[p] > v) p = p - 1;
		if (l <= p)
		{
			u = a[l];
			a[l] = a[p];
			a[p] = u;
			l = l + 1;
			p = p - 1;
		}
	} while (l <= p);
	if (d < p) quick_sort(d, p, a);
	if (l < g) quick_sort(l, g, a);
}

int main()
{
	unsigned long int m;
	int k;
	float *a = new float[n];
	time_t t;
	clock_t tp, tk;
	double tc;
	srand(unsigned(&t));

	//cout << "Podaj liczbe wyrazow ciagu: ";
	//cin >> m;
	//cout << "\n";
	//cout << "Ciag wylosowany: " << m << endl;
	//for (unsigned long int i = 1; i <= m; i++)
	//{
	//	a[i] = rand() % 10000;
	//	//cout << a[i] << "\t";
	//}
	//cout << "\n";
	do
	{
		cout << "Podaj liczbe wyrazow ciagu: ";
		cin >> m;
		cout << "\n";
		cout << "Ciag wylosowany: " << m << endl;
		for (unsigned long int i = 1; i <= m; i++)
		{
			a[i] = rand() % 10000;
			//cout << a[i] << "\t";
		}
		cout << "\n";

		cout << "\n";
		cout << "Podaj numer procedury sortowania: ";
		cout << "\n";
		cout << "1 - sortowanie babelkowe " << endl;
		cout << "2 - sortowanie przez wstawianie " << endl;
		cout << "3 - sortowanie przez podzial i scalanie " << endl;
		cout << "4 - sortowanie szybkie ";
		cin >> k;
		cout << "\n";
		switch (k)
		{
		case 1:
		{
			tp = clock();
			bubble_sort(m, a);
			tk = clock();
			tc = (tk - tp) / double(CLOCKS_PER_SEC);
			cout << "Czas sortowania wynosi:" << tc;
			cout << "\n";
			break;
		}
		case 2:
		{
			tp = clock();
			insert_sort(m, a);
			tk = clock();
			tc = (tk - tp) / double(CLOCKS_PER_SEC);
			cout << "Czas sortowania wynosi:" << tc;
			cout << "\n";
			break;
		}
		case 3:
		{
			tp = clock();
			sort_scal(1, m, a);
			tk = clock();
			tc = (tk - tp) / double(CLOCKS_PER_SEC);
			cout << "Czas sortowania wynosi:" << tc;
			cout << "\n";
			break;
		}
		case 4:
		{
			tp = clock();
			quick_sort(1, m, a);
			tk = clock();
			tc = (tk - tp) / double(CLOCKS_PER_SEC);
			cout << "Czas sortowania wynosi:" << tc;
			cout << "\n";
			break;
		}
		case 0: 
		{
		break;
		}
		}
		cout << "Ciag posortowany:";
		cout << "\n";
		for (unsigned long int i = 1; i <= m; i++)
		{
			//cout << a[i] << "\t";
		}
	} while (k != 0);


    return 0;
}

