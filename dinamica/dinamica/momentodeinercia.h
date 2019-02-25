#pragma once
#include "matriz.h"
#include "centrodemassa.h"

double momentodeinercia(matriz* massa_esp,int  nx, int ny, double dx, double dy, vetor CM)
{
	double I, Ix=0,Iy=0;
	double dA = dx * dy;

	double x, y;
	for(int i=0;i<nx;i++)
	{
		x = i * dx;
		for (int j = 0; j < ny; j++)
		{
			Iy += (x - CM.getV()[0])* (x - CM.getV()[0])*massa_esp->getM()[i][j];

	}
	
	
	}

	for (int i = 0; i < ny; i++)
	{
		y = i * dy;
		for (int j = 0; j < nx; j++)
		{
			Ix += (y - CM.getV()[1])* (y - CM.getV()[1])*massa_esp->getM()[j][i];

		}


	}

	I = Ix * dA + Iy * dA;


	return I;
}

