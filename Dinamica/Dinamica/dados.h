#pragma once
#include "node.h"

class dados
{

private:
	int size;
	node** elem;
	double** Fext;
	double** Fcont;
	double** Vel;
	double** CM;


	double* torque;
	double* massa;
	double* I;

public:

	dados(int Ne);   //Ne= numero de elementos
	void print();
	void setelem(int n, node &P);
	int getsize();

	void setCM();

	~dados();

};

