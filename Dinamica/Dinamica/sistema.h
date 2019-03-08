#pragma once
#include <vector>
#include "corporigido.h"
#include "elementodiscreto.h"
#include "campo.h"
using namespace std;
class sistema
{
public:
	vector <corporigido> corpo;
	vector <elementodiscreto> element;
	campo*** mapa;

	double L, H,dx;

	void setdx();
	void integracao(int Ned, double dt);
	void mapeamento(double x, double y, int* i, int* j);
	double contato(double Kn, double Cn, int Ned);
	
	sistema (double L, double H);
	~sistema();

	void setmapa();

};

