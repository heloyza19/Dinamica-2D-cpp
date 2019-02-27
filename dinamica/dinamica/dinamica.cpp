#include "pch.h"
#include <iostream>
#include <vector>
#include "corporigido.h"
#include "elementodiscreto.h"




using namespace std;
int main()
{
vector <corporigido*> Dados;
int Ncr = 2;			//numero de corpos rigidos
int Np = 4;            //numero de vertices
int Ne = 10;	      //numero de elementos discretos
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

corporigido *corpo2 =new corporigido (Np);
corpo2->posicao.setM(m2);
corpo2->centrodemassa();

Dados.push_back(corpo1);
Dados.push_back(corpo2);




//Fazer polares dos vertices
//Fazer integracao temporal
//Fazer determina��o de contatos

return 0;
}
