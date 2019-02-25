#pragma once
#include <math.h>
#include "matriz.h"
#include "dados.h"
#include "pontointerno.h"

double densidade(matriz* massa_esp, dados* Dados,int nx,int ny, int dx,int dy, int n)
{   
	double m=0;
	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{

			int ni = pontointerno(i*dx,j*dy,Dados);

			if (ni % 2 == 0) 
			{
				massa_esp->getM()[i][j] = 0;
			}

			m += massa_esp->getM()[i][j];
		}
	}
	m = m * dx*dy;
	return m;
}

