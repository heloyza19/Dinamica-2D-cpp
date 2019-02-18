
#include "pch.h"
#include <iostream>

#include "dados.h"

using namespace std;
int main()
{


	int Np = 3;
	double** M = new double*[Np];
	for (int i = 0; i < Np; i++)
	{
		M[i] = new double[2];
	}


	node vertices(1);
	vertices.setponto(M);
	
	dados Dados(5);
	Dados.setcorpo(1, vertices);
	Dados.setCM();
	//Dados.print();

	system("PAUSE");
	return 0;
}

