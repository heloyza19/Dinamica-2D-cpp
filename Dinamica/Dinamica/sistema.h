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

	double L, H,dx, Kn, Cn;
	int Ned;

	void setdx();
	void integracao( double dt);
	int* mapeamento(double x, double y);
	void contato();
	
	sistema (double L, double H, double Kn, double Cn, int Ned);
	~sistema();

	void setmapa();

};

