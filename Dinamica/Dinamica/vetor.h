#pragma once

//#include "matriz.h"
class vetor
{

public:
	vetor(int t);
	~vetor();
	vetor(const vetor &A);

	void setV(double* A);
	double* getV();
	int getsize();
	void print();


	vetor cross(vetor &);
	//operadores
	void operator =(const vetor &);
	vetor operator + (vetor &);
	vetor operator - (vetor &);
	double operator *(vetor &);
	vetor operator *(double);
	//vetor operator *(matriz &A);

private:
	int Size;
	double *V;


};

