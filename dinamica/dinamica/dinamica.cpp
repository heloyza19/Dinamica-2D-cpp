#include "pch.h"
#include <iostream>
#include "centrodemassa.h"
#include "dados.h"

using namespace std;


int main()
{
 
int Np = 3;            //numero de particulas
int Ne = 10;	      //numero de elementos discretos
double Cn = 0;       //constante de amortecimento
double Kn = 10000;  //constante da mola
double L = 10;
double H = 10;

double** m = new double* [Np];
for (int i = 0; i < Np; i++)
{
	m[i] = new double[2];
}
m[0][0] = 1; m[0][1] = 1;
m[1][0] = 1; m[1][1] = 6;
m[2][0] = 5; m[2][1] = 1;

matriz pos  (3, 2);
pos.setM(m);
cout << "corpo 1: " << endl;
pos.print();

dados* Dados = new dados(1);
Dados->setcorpo(0, pos);

matriz Fres;
Fres= Dados->Fext + Dados->Fcont;
Fres.print();

//centrodemassa(Dados);


return 0;
						
system("PAUSE");

}

