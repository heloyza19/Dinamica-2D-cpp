#include "pch.h"
#include "dados.h"
#include <iostream>


using namespace std;

dados::dados(int Ne)
{
	elem=new node* [Ne];   //verificar
	size = Ne;

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

void dados::setelem(int n, node &P)
{
	if (n < size)
	{
	elem[n] = &P;
}

}

int dados::getsize()
{
	return size;

}


void dados::print()
{

	cout << "Dados: "<<endl;
	cout << "Fext=" << endl;

for (int i = 0; i < size; i++)
{
	cout << Fext[i][0] << " " << Fext[i][1] << endl;
}
cout << endl;


cout << "Fcont ="<<endl;
for (int i = 0; i < size; i++)
{
	cout << Fcont[i][0] << " " << Fcont[i][1] << endl;
}
cout << endl;


cout << "Vel ="<<endl;
for (int i = 0; i < size; i++)
{
	cout <<Vel[i][0] << " " << Vel[i][1] << endl;
}
cout << endl;

cout << "CM= " << endl;
for (int i = 0; i < size; i++)
{
	cout << CM[i][0] << " " << CM[i][1] << endl;
}
cout << endl;

cout << "torque= " << endl;
for (int i = 0; i < size; i++)
{
	cout << torque[i]<< " ";
}
cout << endl;

cout << "massa= " << endl;
for (int i = 0; i < size; i++)
{
	cout << massa[i] <<" ";
}
cout << endl;



cout << "I= " << endl;
for (int i = 0; i < size; i++)
{
	cout << I[i] << " ";
}
cout << endl;

}



dados::~dados()
{
	delete[]elem;
}



void dados::setCM()
{






}