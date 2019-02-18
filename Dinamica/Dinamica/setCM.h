#pragma once
#include "iostream"
#include "dados.h"

using namespace std;

double minimo(node* M, int c);
double maximo(node* M, int c);

void dados::setCM()
{
	int Mx = 0;       //contador momento em x
	int My = 0;       //contador momento em y
	int Ix = 0;       //contador  M inerciax
	int Iy = 0;       //contador M inercia y


	double dx = 0.001;
	double dy = dx;      
	double dA = dx * dy;

	for (int i = 0; i < Nc; i++)

	{
		double Xmin = minimo(corpo[i],0);
		cout << Xmin << endl;
		double Xmax = maximo(corpo[i], 0);
		cout << Xmax << endl;

		double Ymin = minimo(corpo[i], 1);
		double Ymax = maximo(corpo[i], 1);







	}

}


double minimo(node* M, int c)
{
	double minimo = M->ponto[0][c];
	
	for (int i = 1; i < M->size[0]; i++)
	{
		if (M->ponto[i][c] < minimo)
		{
			minimo = M->ponto[i][c];
		}

	}


	return minimo;
}

double maximo(node* M, int c)
{
	double** pos = M->ponto;
	double maximo = pos[0][c];

	for (int i = 1; i < M->size[0]; i++)
	{
		if (pos[i][c] <maximo)
		{
			maximo = pos[i][c];
		}

	}


	return maximo;

	return 0;
}