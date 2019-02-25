#include "pch.h"
#include <iostream>
#include "corporigido.h"


using namespace std;
int main()
{
 
int Np = 3;            //numero de particulas
int Ne = 10;	      //numero de elementos discretos
double Cn = 0;       //constante de amortecimento
double Kn = 10000;  //constante da mola
double L = 10;
double H = 10;

double** m = new double*[Np];
for (int i = 0; i < Np; i++)
{
	m[i] = new double[2];
}
m[0][0] = 1; m[0][1] = 1;
m[1][0] = 1; m[1][1] = 6;
m[2][0] = 5; m[2][1] = 1;



corporigido *corpo1 = new corporigido(Np);
corpo1->posicao.setM(m);
corpo1->posicao.print();
corpo1->centrodemassa();
corpo1->CM.print();
cout<<corpo1->I<<endl;



return 0;
}
