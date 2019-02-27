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

corporigido *corpo1=new corporigido (Np);
corpo1->posicao.setM(m);
corpo1->centrodemassa();
corpo1->polares();
elementodiscreto* corpo1ed = new elementodiscreto(corpo1, Ned);

corporigido *corpo2 =new corporigido (Np);
corpo2->posicao.setM(m2);
corpo2->centrodemassa();
corpo2->polares();
elementodiscreto* corpo2ed = new elementodiscreto (corpo2, Ned);

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
vetor Ac(2);
double alfa;

for (int t = 0; t < sizet; t++)
{
	Eelas[t] = 0;
	Ek[t] = 0;
	Ekr[t] = 0;
	momentolin[t] = 0;
	momentoang[t] = 0;
	vetormomento[0] = 0;
	vetormomento[1] = 0;

	for (int i = 0; i < Dados.size(); i++)
	{

		Fres = Dados[i]->Fext + Dados[i]->Fcont;
		Ac = Fres * (1 / Dados[i]->massa);

		Dados[i]->Vel = Dados[i]->Vel + Ac;  //erro *dt

		Dados[i]->CM = Dados[i]->CM + Dados[i]->Vel;

	}

	//rotacao

	for (int i = 0; i < Dados.size(); i++)
	{
		vetor M(Dados[i]->posicao.size[0]);
		Ek[t] = Ek[t] + 0.5*Dados[i]->massa*sqrt(pow(Dados[i]->Vel.getV()[0],2)+pow(Dados[i]->Vel.getV()[1],2));
		Ekr[t] = Ekr[t] + 0.5*(Dados[i]->I*pow(Dados[i]->W, 2));

		alfa = Dados[i]->torque / Dados[i]->I;

		//Dados[i]->pos_teta = Dados[i]->pos_teta + M.ones()*(0.5*Dados[i]->W);

	}


		/*alfa(g, 1) = Dados.torquecont(g, 1) / I(g, 1);

		c1 = Dados.W(g, 1);
		c2 = Dados.W(g, 1) + alfa(g, 1)*dt;
		teta{ g,1 } = teta{ g,1 }+0.5*dt*ones(Np, 1)*(c1 + c2);
		Dados.W(g, 1) = Dados.W(g, 1) + alfa(g, 1)*dt;

		posicao{ g,1 }(:, 1) = ones(Np, 1)*Cm(g, 1) + raio{ g,1 }.*cos(teta{ g,1 });
		posicao{ g,1 }(:, 2) = ones(Np, 1)*Cm(g, 2) + raio{ g,1 }.*sin(teta{ g,1 });

		Momento = Momento + Dados.massa(g, 1)*Dados.velocidade(g, 1);

		Mang(t) = Mang(t) + I(g, 1)*Dados.W(g, 1);

		%Para as bolas
			for h = 1:1 : Np

				angle{ g,1 }(h, :) = angle{ g,1 }(h, :) + 0.5*dt*ones(1, Nb)*(c1 + c2);
		bolas{ g,1 }(h, :) = ones(1, Nb)*Cm(g, 1) + (radius{ g,1 }(h, :)).*cos(angle{ g,1 }(h, :));
		bolas{ g,2 }(h, :) = ones(1, Nb)*Cm(g, 2) + (radius{ g,1 }(h, :)).*sin(angle{ g,1 }(h, :));

		end

			end
*/


	





}



return 0;
}


