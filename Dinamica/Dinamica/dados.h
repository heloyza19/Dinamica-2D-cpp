#pragma once
#include "node.h"

class dados
{

private:
	int Nc;         //numero de elementos
	node** corpo;	//coodenadas dos vertices de cada corpo
	double** Fext;  //[Fx Fy] externa de cada corpo
	double** Fcont;  //[Fx Fy] de contato de cada corpo
	double** Vel;	//[Vx Vy] de cada corpo	
	double** CM;    //[Xcm Ycm] de cada corpo


	double* torque;
	double* massa;
	double* I;

public:

	dados(int Nc);   //Ne= numero de elementos
	void print();
	void setcorpo(int n, node &P);
	int getNc();

	void setCM();

	~dados();

};

