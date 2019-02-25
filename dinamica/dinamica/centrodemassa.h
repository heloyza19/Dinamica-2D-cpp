#pragma once
#include "corporigido.h"
#include <math.h>
#include "densidade.h"
#include "momentodeinercia.h"

void corporigido::centrodemassa( )
{
double dx = 0.01;
double dy = dx;
double dA = dx * dy;
double* cm = new double [2];
double Mx = 0;       //contador momento em x
double My = 0;       //contador momento em y
double Ix = 0;       //contador  M inerciax
double Iy = 0;       //contador M inercia y


double Xmin = minimo(posicao, 0);
double Xmax = maximo(posicao, 0);

double Ymin = minimo(posicao, 1);
double Ymax = maximo(posicao, 1);

int nx = ceil((Xmax - Xmin) / dx);
int ny = ceil((Ymax - Ymin) / dy);
matriz *massa_esp = new matriz(nx, ny);      //matriz da massa especifica
massa_esp->ones();

massa = densidade(massa_esp, posicao, nx, ny, dx, dy);




double x;
double y;

for (int i = 0; i < nx; i++)
{
	x = i * dx;
	for (int j = 0; j < ny; j++)
	{
		My += x * massa_esp->getM()[i][j];
	}

}

for (int i = 0; i < ny; i++)
{
	y = i * dy;
	for (int j = 0; j < nx; j++)
	{
		Mx += y * massa_esp->getM()[j][i];
	}

}

cm[0] = dA * (My / massa);
cm[1] = dA * (Mx / massa);
CM.setV(cm);

I = momentodeinercia(massa_esp, nx, ny, dx, dy, CM);
}



