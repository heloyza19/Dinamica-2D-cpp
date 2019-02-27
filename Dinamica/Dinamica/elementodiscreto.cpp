#include "pch.h"
#include "elementodiscreto.h"
#include <math.h>

#define pi acos(-1.0)

elementodiscreto::elementodiscreto(corporigido* corpo, int Ned) :xcentro(corpo->posicao.size[0],Ned), ycentro(corpo->posicao.size[0], Ned), raio(corpo->posicao.size[0]), pos_raio(corpo->posicao.size[0],2),pos_teta(corpo->posicao.size[0],2)
{

int Np = corpo->posicao.size[0];
int n;
double L,S;

double** Xcentro = new double*[corpo->posicao.size[0]];
double** Ycentro = new double*[corpo->posicao.size[0]];
double* Raio = new double[corpo->posicao.size[0]];
double** Pos_raio = new double*[corpo->posicao.size[0]];
double** Pos_teta = new double*[corpo->posicao.size[0]];

for (int i = 0; i < corpo->posicao.size[0]; i++)
{
	Xcentro[i] = new double[Ned];
	Ycentro[i] = new double[Ned];
	Pos_raio[i] = new double[Ned];
	Pos_teta[i] = new double[Ned];

	if (i == corpo->posicao.size[0] - 1)
	{
		n = 0;
	}
	else
	{
		n = i + 1;
	}

	L =sqrt( (corpo->posicao.getM()[n][0] - corpo->posicao.getM()[i][0])*(corpo->posicao.getM()[n][0] - corpo->posicao.getM()[i][0]) + (corpo->posicao.getM()[n][1] - corpo->posicao.getM()[i][1]) * (corpo->posicao.getM()[n][1] - corpo->posicao.getM()[i][1]));
	Raio[i] = 0.5*(L / Ned);

	for (int j = 0; j < Ned; j++)
	{
	S = Raio[i] + 2 * Raio[i] * j;
	Xcentro[i][j] = corpo->posicao.getM()[i][0] + (S*((corpo->posicao.getM()[n][0] - corpo->posicao.getM()[i][0]) / L));
	Ycentro[i][j]= corpo->posicao.getM()[i][1] + (S*((corpo->posicao.getM()[n][1] - corpo->posicao.getM()[i][1]) / L));
	}

	}
xcentro.setM(Xcentro);
ycentro.setM(Ycentro);
raio.setV(Raio);

for (int i = 0; i < corpo->posicao.size[0]; i++)
{
for (int j = 0; j < Ned; j++)
{
	Pos_raio[i][j] = sqrt((Xcentro[i][j]- corpo->CM.getV()[0])*(Xcentro[i][j] - corpo->CM.getV()[0]) +(Ycentro[i][j]-corpo->CM.getV()[1]*Ycentro[i][j] - corpo->CM.getV()[1]));
	Pos_teta[i][j] = atan((Ycentro[i][j] - corpo->CM.getV()[1]) / (Xcentro[i][j] - corpo->CM.getV()[0]));


	if (Xcentro[i][j] < corpo->CM.getV()[0])
	{
		Pos_teta[i][j] = Pos_teta[i][j] +pi;
	}

}
}
pos_raio.setM(Pos_raio);
pos_teta.setM(Pos_teta);
}


elementodiscreto::~elementodiscreto()
{
}
