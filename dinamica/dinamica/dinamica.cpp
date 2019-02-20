
#include "pch.h"
#include <iostream>

#include "dados.h"
#include "elementosdiscretos.h"

using namespace std;
int main()
{
	int Np = 3;            //numero de particulas
	int Ne = 10;	      //numero de elementos discretos
	double Cn = 0;       //constante de amortecimento
	double Kn = 10000;  //constante da mola


	double L = 10;
	double H = 10;




	double** M = new double*[Np];
	for (int i = 0; i < Np; i++)
	{
		M[i] = new double[2];
	}

	node vertices(1);
	vertices.setponto(M);
	
	dados* Dados=new dados(1);
	Dados->setcorpo(0, vertices);
	

	
	//Dados.setCM();
	//Dados.print();

	//system("PAUSE");
	return 0;
}

