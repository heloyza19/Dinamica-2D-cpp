#pragma once
#include "iostream"
#include "dados.h"
#include "matriz.h"

using namespace std;

double minimo(node M, int c);
double maximo(node M, int c);

void setCM(dados* D)
{
	int Mx = 0;       //contador momento em x
	int My = 0;       //contador momento em y
	int Ix = 0;       //contador  M inerciax
	int Iy = 0;       //contador M inercia y


	double dx = 0.001;
	double dy = dx;      
	double dA = dx * dy;

	for (int i = 0; i < D->Nc; i++)

	{
		double Xmin = minimo(D->corpo[i],0);
		double Xmax = maximo(D->corpo[i], 0);
		double Ymin = minimo(D->corpo[i], 1);
		double Ymax = maximo(D->corpo[i], 1);

		int nx = (Xmax - Xmin) / dx;
		int ny = (Ymax - Ymin) / dy;
		matriz *m_esp =new matriz (nx, ny);      //matriz da massa especifica
		m_esp->ones();

		//Fazer funcao da densidade
		double x=0;
		for (int i = 0; i < nx; i++)
		{
			x =Xmin + i * dx;

			for (int j = 0; j < ny; j++)
			{

				My += My + x * m_esp->getM[i][j];


			}

		}

		double y = 0;
		for (int k = 0; k < ny; k++) 
		{
			y =Ymin + k * dy;

			for (int l = 0; l < nx; l++)
			{

				Mx += Mx + y * m_esp->getM[l][k];

		}


		}

	}

}


double minimo(node M, int c)
{
	double minimo = M.ponto[0][c];
	cout << minimo << endl;
	
	for (int i = 1; i < M.size[0]; i++)
	{
		if (M.ponto[i][c] < minimo)
		{
			minimo = M.ponto[i][c];
		}

	}


	return minimo;
}

double maximo(node M, int c)
{

	double maximo = M.ponto[0][c];
	cout << maximo << endl;

	for (int i = 1; i < M.size[0]; i++)
	{
		if (M.ponto[i][c] >maximo)
		{
			maximo = M.ponto[i][c];
		}

	}


	return maximo;

	return 0;
}