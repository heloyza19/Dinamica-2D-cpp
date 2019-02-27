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

	
	vetor pos_raio;          // raio da posicao em coordenadas polares
	vetor pos_teta;		//angulo da posicao em coordenadas polares

	corporigido(int np);
	void polares();
	~corporigido();

	void centrodemassa();
};

