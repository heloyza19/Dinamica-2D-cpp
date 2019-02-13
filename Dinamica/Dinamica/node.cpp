#include "pch.h"
#include "node.h"
#include<iostream>

using namespace std;
node::node(int Np)
{
	ponto = new double*[Np];
	for (int i = 0; i < Np; i++)
	{
		ponto[i] = new double[2];
	}

	size[0] = Np;
	size[1] = 2;
}

void node::setponto(double** M)
{

	ponto = M;

}


void node::print()
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++) {
			cout << *(*(ponto + i) + j)<<"\t" ;
		}
		cout << endl;

}
	cout << endl;
}

node::~node()
{

	delete[]ponto;
}
