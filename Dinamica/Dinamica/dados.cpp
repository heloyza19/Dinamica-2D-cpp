#include "pch.h"
#include "dados.h"
#include "setCM.h"
#include <iostream>


using namespace std;

dados::dados(int Ne)
{
	corpo=new node* [Ne];   //verificar
	Nc = Ne;

	Fext = new double*[Ne];
	Fcont = new double*[Ne];
	Vel = new double*[Ne];
	CM = new double*[Ne];

	torque = new double[Ne];
	massa = new double[Ne];
	I = new double[Ne];

	for (int i = 0; i < Ne; i++)
	{
		Fext[i] = new double[2]{ 0,0 };
		Fcont[i] = new double[2]{ 0,0 };
		Vel[i] = new double[2]{ 0,0 };
		CM[i] = new double[2]{ 0,0 };
		torque[i] = 0;
		massa[i] = 0;
		I[i] = 0;

	}
}

void dados::setcorpo(int n, node &P)
{
	if (n < Nc)
	{
	corpo[n] = &P;
}

}

int dados::getNc()
{
	return Nc;

}


void dados::print()
{

	cout << "Dados: "<<endl;
	cout << "Fext=" << endl;

for (int i = 0; i < Nc; i++)
{
	cout << Fext[i][0] << " " << Fext[i][1] << endl;
}
cout << endl;


cout << "Fcont ="<<endl;
for (int i = 0; i < Nc; i++)
{
	cout << Fcont[i][0] << " " << Fcont[i][1] << endl;
}
cout << endl;


cout << "Vel ="<<endl;
for (int i = 0; i < Nc; i++)
{
	cout <<Vel[i][0] << " " << Vel[i][1] << endl;
}
cout << endl;

cout << "CM= " << endl;
for (int i = 0; i < Nc; i++)
{
	cout << CM[i][0] << " " << CM[i][1] << endl;
}
cout << endl;

cout << "torque= " << endl;
for (int i = 0; i < Nc; i++)
{
	cout << torque[i]<< " ";
}
cout << endl;

cout << "massa= " << endl;
for (int i = 0; i < Nc; i++)
{
	cout << massa[i] <<" ";
}
cout << endl;



cout << "I= " << endl;
for (int i = 0; i < Nc; i++)
{
	cout << I[i] << " ";
}
cout << endl;

}



dados::~dados()
{
	delete[]corpo;
}


