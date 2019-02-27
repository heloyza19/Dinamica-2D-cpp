#include "pch.h"
#include "corporigido.h"
#include "centrodemassa.h"
#include <math.h>

#define pi acos(-1)

corporigido::corporigido(int np):Fext(2),Fcont(2),Vel(2),CM(2), posicao(np,2),pos_raio(np),pos_teta(np)
{
Fext.zeros();
Fcont.zeros();
Vel.zeros();
CM.zeros();
torque=0;
W=0;
I=0;
massa=0;

}




corporigido::~corporigido()
{
}


void corporigido::polares()
{
	double* Pos_raio = new double[posicao.size[0]];
	double* Pos_teta = new double[posicao.size[0]];
	for (int i = 0; i < posicao.size[0]; i++)
	{
		Pos_raio[i] = sqrt(pow(posicao.getM()[i][0] - CM.getV()[0],2)+pow(posicao.getM()[i][1]-CM.getV()[1],2));
		Pos_teta[i] = atan((posicao.getM()[i][1] - CM.getV()[1]) / (posicao.getM()[i][0] - CM.getV()[0]));


		if (posicao.getM()[i][0] < CM.getV()[0])
		{
			Pos_teta[i] = Pos_teta[i] + pi;
		}
	}

	pos_raio.setV(Pos_raio);
	pos_teta.setV(Pos_teta);

}

