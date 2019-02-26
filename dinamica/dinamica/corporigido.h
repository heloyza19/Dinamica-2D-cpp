#pragma once
#include "matriz.h"

class corporigido
{

public:
	matriz posicao;

	vetor Fext;
	vetor Fcont;
	vetor Vel;
	vetor CM;
	double torque;
	double W;
	double I;
	double massa;

	corporigido(int np);
	~corporigido();

	void centrodemassa();
};

