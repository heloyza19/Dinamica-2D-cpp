#pragma once
#include <iostream>
#include "dados.h"
#include "matriz.h"
#include <math.h>
#include"densidade.h"
#include "momento.h"

using namespace std;

double minimo(matriz M, int c);
double maximo(matriz M, int c);

void centrodemassa(dados* Dados)
{

	double dx = 0.001;
	double dy = dx;      
	double dA = dx * dy;
	double** massa = new double* [Dados->Nc];
	double** cm = new double*[Dados->Nc];
	double** I = new double*[Dados->Nc];

	for (int i = 0; i < Dados->Nc; i++)
	{
		massa[i] = new double(1);
		cm[i] = new double(2);
		I[i] = new double(1);
	}


	for (int i = 0; i < Dados->Nc; i++)    //para cada corpo rigido
	{
		int Mx = 0;       //contador momento em x
		int My = 0;       //contador momento em y
		int Ix = 0;       //contador  M inerciax
		int Iy = 0;       //contador M inercia y


		double Xmin = minimo(Dados->corpo[i],0);
		double Xmax = maximo(Dados->corpo[i], 0);

		double Ymin = minimo(Dados->corpo[i], 1);
		double Ymax = maximo(Dados->corpo[i], 1);
		int nx = ceil((Xmax - Xmin) / dx);            
		int ny = ceil((Ymax - Ymin) / dy);
		matriz *massa_esp =new matriz (nx, ny);      //matriz da massa especifica
		massa_esp->ones();
		
		massa[i][0] = densidade(massa_esp, Dados, nx, ny, dx, dy, i);
		
		double x=0;
		for (int i = 0; i < nx; i++)
		{
			x =Xmin + i * dx;

			for (int j = 0; j < ny; j++)
			{

				My +=  x * massa_esp->getM()[i][j];


			}

		}

		double y = 0;
		for (int k = 0; k < ny; k++) 
		{
			y =Ymin + k * dy;

			for (int l = 0; l < nx; l++)
			{

				Mx += y * massa_esp->getM()[l][k];

		}



		}

		
		cm[i][0] = dA * (My / massa[i][0]);
		cm[i][1] = dA * (Mx / massa[i][0]);
		I[i][0]= momento(cm, massa_esp, nx, ny, dx, dy, i);
	

			
	}


	Dados->massa.setM(massa);
	Dados->CM.setM(cm);
	Dados->I.setM(I);

	//Dados->massa.print();
	//Dados->CM.print();

}


double minimo(matriz Mat, int c)
{
	double minimo = Mat.getM()[0][c];
	
	
	for (int i = 1; i < Mat.size[0]; i++)
	{
		if (Mat.getM()[i][c] < minimo)
		{
			minimo = Mat.getM()[i][c];
		}

	}


	return minimo;
}

double maximo(matriz Mat, int c)
{

	double maximo = Mat.getM()[0][c];
	

	for (int i = 1; i < Mat.size[0]; i++)
	{
		if (Mat.getM()[i][c] >maximo)
		{
			maximo = Mat.getM()[i][c];
		}

	}


	return maximo;

	return 0;
}