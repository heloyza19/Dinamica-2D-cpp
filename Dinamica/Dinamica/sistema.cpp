#include "pch.h"
#include "sistema.h"

#include <iostream>

sistema::sistema(double L, double H)
{
	this->L = L;
	this->H = H;
}

void sistema::setdx()
{
	dx = 0; //raio maximo

	for (int i = 0; i < element.size(); i++)
	{
		for (int j = 0; j < element[i].raio.size; j++)
		{
			if (dx < element[i].raio.getV()[j])
			{
				dx = element[i].raio.getV()[j];
			}
		}
	}


}

void sistema::integracao(int Ned, double dt)
{
	for (int i = 0; i < corpo.size(); i++)
	{
		//Translacao
		corpo[i].CM = corpo[i].Vel*dt + corpo[i].CM;
		corpo[i].Vel = (corpo[i].Fcont + corpo[i].Fext)*(dt / corpo[i].massa) + corpo[i].Vel;

		//Rotacao
		vetor M(corpo[i].posicao.size[0]);
		M.ones();
		corpo[i].pos_teta = M * dt*(corpo[i].W) + corpo[i].pos_teta;
		corpo[i].W = corpo[i].torque*(dt / corpo[i].I) + corpo[i].W;
		double** m = new double*[corpo[i].posicao.size[0]];

		for (int j = 0; j < corpo[i].posicao.size[0]; j++)
		{
			m[j] = new double[2];
			m[j][0] = corpo[i].CM.getV()[0] + corpo[i].pos_raio.getV()[j] * cos(corpo[i].pos_teta.getV()[j]);
			m[j][1] = corpo[i].CM.getV()[1] + corpo[i].pos_raio.getV()[j] * sin(corpo[i].pos_teta.getV()[j]);

			//Elementos discretos
			double** pos = new double*[corpo[i].posicao.size[0]];
			double** xc = new double*[corpo[i].posicao.size[0]];
			double** yc = new double*[corpo[i].posicao.size[0]];

			for (int k = 0; k < Ned; k++)
			{
				pos[k] = new double[Ned];
				xc[k] = new double[Ned];
				yc[k] = new double[Ned];

				pos[j][k] = element[i].pos_teta.getM()[j][k] + corpo[i].W*dt;
				xc[j][k] = corpo[i].CM.getV()[0] + element[i].pos_raio.getM()[j][k] * cos(element[i].pos_teta.getM()[j][k]);
				yc[j][k] = corpo[i].CM.getV()[1] + element[i].pos_raio.getM()[j][k] * sin(element[i].pos_teta.getM()[j][k]);
			}

			element[i].pos_teta.setM(pos);
			element[i].xcentro.setM(xc);
			element[i].ycentro.setM(yc);

		}

		corpo[i].posicao.setM(m);
	

	}
}

void sistema::mapeamento(double x, double y, int* i, int* j)
{

*i = floor(x / dx) ;
*j = floor(y/ dx) ;

}

void sistema::setmapa()
{
int N = ceil(L / dx);
int M = ceil(H / dx);
int* a=0;
int* b=0;
mapa = new campo**[N];
for (int i = 0; i < N; i++)
{
	mapa[N] = new campo*[M];
}

for (int i = 0; i < corpo.size(); i++)
{
	for (int j = 0; j < corpo[i].posicao.size[0]; j++)
	{

		for (int k = 0; k < element[i].pos_raio.size[1]; k++)
		{

			mapeamento(element[i].xcentro.getM()[j][k], element[i].ycentro.getM()[j][k], a, b);

			mapa[*a][*b]->corpo.push_back(i);
			mapa[*a][*b]->aresta.push_back(j);
			mapa[*a][*b]->elem.push_back(k);

		}

	}

}

//for a = 1:1 : Ne
//Np = size(posicao{ a,1 }, 1);
//for d = 1:1 : Np
//for e = 1 : 1 : Nb
//[i, j] = mapeamento(bolas{ a,1 }(d, e), bolas{ a,2 }(d, e), Xmin, Ymin, dx);
//T = size(campo{ i,j });
//l = T(1);
//campo{ i,j }(l + 1, 1) = e;  %Número da bola
//campo{ i,j }(l + 1, 2) = a;  %Número do elemento
//campo{ i,j }(l + 1, 3) = d;
//end
//end
//end



}

sistema::~sistema()
{
}
