#pragma once
#include "matriz.h"
#include "dados.h"
#include <math.h>


double momento(double** cm, matriz* massa_esp, int nx, int ny, double dx, double dy, int n)
{
	double Iy = 0, Ix = 0;
	double dA = dx * dy;
	double X, Y;

	for (int i = 0; i < nx; i++)
	{
		X = i * dx;
	for (int j = 0; j < ny; j++)
	{
		Iy +=(X-cm[n][0]) * massa_esp->getM()[i][j];

	}
	}

	for (int i = 0; i < nx; i++)
	{
		Y = i * dx;
		for (int j = 0; j < ny; j++)
		{

			Ix += (Y - cm[n][1]) * massa_esp->getM()[i][j];
		}
	}

	double I = Ix * dA + Iy * dA;
	return I;
}
