#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "corporigido.h"
#include "elementodiscreto.h"



using namespace std;
int main()
{
	vector <corporigido*> Dados;
	vector <elementodiscreto*> Element;

	int Ncr = 2;			//numero de corpos rigidos
	int Np = 4;            //numero de vertices
	int Ned = 10;	      //numero de elementos discretos
	double Cn = 0;       //constante de amortecimento
	double Kn = 10000;  //constante da mola
	double L = 10;
	double H = 10;

	double** m = new double*[Np];
	double** m2 = new double*[Np];
	for (int i = 0; i < Np; i++)
	{
		m[i] = new double[2];
		m2[i] = new double[2];
	}
	m[0][0] = 1; m[0][1] = 1;
	m[1][0] = 1; m[1][1] = 4;
	m[2][0] = 4; m[2][1] = 1;
	m[3][0] = 4; m[3][1] = 4;

	m2[0][0] = 5; m2[0][1] = 4;
	m2[1][0] = 5; m2[1][1] = 6;
	m2[2][0] = 8; m2[2][1] = 4;
	m2[3][0] = 8; m2[3][1] = 6;

	corporigido *corpo1 = new corporigido(Np);
	corpo1->posicao.setM(m);
	corpo1->centrodemassa();
	corpo1->polares();
	elementodiscreto* corpo1ed = new elementodiscreto(corpo1, Ned);

	corporigido *corpo2 = new corporigido(Np);
	corpo2->posicao.setM(m2);
	corpo2->centrodemassa();
	corpo2->polares();
	elementodiscreto* corpo2ed = new elementodiscreto(corpo2, Ned);

	Dados.push_back(corpo1);
	Dados.push_back(corpo2);

	Element.push_back(corpo1ed);
	Element.push_back(corpo2ed);

	//determincação do dt
	double massamax = 0;

	for (int i = 0; i < Dados.size(); i++)
	{
		if (Dados[i]->massa > massamax)
		{
			massamax = Dados[i]->massa;
		}

	}


	double tc = 2 * sqrt(massamax / Kn);    //tempo critico
	double e = 0.001;					    //percentual do tempo critico					
	double dt = e * tc;					   //passo no incremento do tempo
	double tempo = 0.006;			     //tempo de simulacao do problema
	int sizet = ceil(tempo / dt);       //numero de passos

	double* Eelas = new double(sizet);
	double* Ek = new double(sizet);
	double* Ekr = new double(sizet);
	double* momentolin = new double(sizet);
	double* momentoang = new double(sizet);
	double* vetormomento = new double(2);
	vetor modmomento(2);
	vetor Fres(2);
	vetor dV(2);
	double alfa;
	vetor vetmomento(2);

	for (int t = 0; t < sizet; t++)
	{
		Eelas[t] = 0;
		Ek[t] = 0;
		Ekr[t] = 0;
		vetmomento.zeros();


		//translacao
		for (int i = 0; i < Dados.size(); i++)
		{

			Fres = Dados[i]->Fext + Dados[i]->Fcont;
			dV = Fres * (dt / Dados[i]->massa);

			Dados[i]->Vel = Dados[i]->Vel + dV;  //erro *dt

			Dados[i]->CM = Dados[i]->CM + Dados[i]->Vel;

		}

		//rotacao

		for (int i = 0; i < Dados.size(); i++)
		{
			vetor V(Dados[i]->posicao.size[0]);
			matriz M(Dados[i]->posicao.size[0], Dados[i]->posicao.size[1]);

			Ek[t] = Ek[t] + 0.5*Dados[i]->massa*sqrt(pow(Dados[i]->Vel.getV()[0], 2) + pow(Dados[i]->Vel.getV()[1], 2));
			Ekr[t] = Ekr[t] + 0.5*(Dados[i]->I*pow(Dados[i]->W, 2));

			alfa = Dados[i]->torque / Dados[i]->I;


			//Dados[i]->pos_teta = Dados[i]->pos_teta + V.ones()*(0.5*Dados[i]->W)*dt;


			double** pos = new double*[Dados[i]->posicao.size[0]];


			for (int j = 0; j < Dados[i]->posicao.size[0]; j++)
			{
				pos[j] = new double[2];
				pos[j][0] = Dados[i]->CM.getV()[0] + Dados[i]->pos_raio.getV()[j] * cos(Dados[i]->pos_raio.getV()[j]);
				pos[j][1] = Dados[i]->CM.getV()[1] + Dados[i]->pos_raio.getV()[j] * sin(Dados[i]->pos_raio.getV()[j]);




				//para os elemetnos discretos
				for (int k = 0; k < Ned; k++)
				{
					Element[i]->pos_teta.getM()[j][k] = Element[i]->pos_teta.getM()[j][k] + dt * Dados[i]->W;
				}
			}
			Dados[i]->posicao.setM(pos);


			vetmomento = Dados[i]->Vel * Dados[i]->massa + vetmomento;
			momentoang[t] = momentoang[t] + Dados[i]->I* Dados[i]->W;
			momentolin[t] = sqrt(pow(vetmomento.getV()[0], 2) + pow(vetmomento.getV()[1], 2));


			//Fazer mapeamento

		}



		return 0;
	}
}

