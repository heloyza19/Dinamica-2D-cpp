#pragma once
#include "matriz.h"

class dados
{
public:
	dados(int N);
	int Nc;
	
	matriz* corpo;   //coordenadas dos corpos rigidos
	
	matriz Fext;	//for�as externas
	matriz Fcont;	//for�as internas
	matriz torque;  //torque
	matriz Vel;		//velocidades dos corpos
	matriz W;		//velocidade angular dos corpos
	matriz massa;	//massa	
	matriz I;		//momento de inercia
	matriz CM;		//centro de massa
	
	


	void setcorpo (int i,matriz &M);
	void print();
	



	~dados();
};

