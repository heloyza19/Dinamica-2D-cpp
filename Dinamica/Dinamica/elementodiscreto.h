#pragma once
#include "matriz.h"
#include "corporigido.h"

class elementodiscreto
{
public:
	matriz xcentro;     //centros dos elementos discretos
	matriz ycentro;		//centros dos elementos discretos
	vetor raio;	        //raios dos elementos discretos

	matriz pos_raio;	//raio da posicao em coordenadas polares
	matriz pos_teta;    //angulo da posicao em coordenadas polares

	elementodiscreto(corporigido* Dados,int Ned);
	~elementodiscreto();
};

