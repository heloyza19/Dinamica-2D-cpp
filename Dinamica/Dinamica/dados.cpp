#include "pch.h"
#include "dados.h"
#include "iostream"

using namespace std;


dados::dados(int Ne)
{
	Nc = Ne;
	corpo = new matriz(Ne, 2);

	matriz Fext(Ne,2);	
	matriz Fcont(Ne,2);	
	matriz torque(Ne,1);  
	matriz Vel(Ne,2);		
	matriz W(Ne,1);		
	matriz massa(Ne,1);		
	matriz I(Ne,1);		
	matriz CM(Ne,2);		

	
	Fext.zeros();
	Fcont.zeros();
	torque.zeros();
	Vel.zeros();
	W.zeros();
	massa.zeros();
	I.zeros();
	CM.zeros();

	
}


dados::~dados()
{
	delete[]corpo;
	

}


void dados::setcorpo(int i, matriz &M)
{
	if (i < Nc)
	{
		corpo[i] = M;

	}

}






void dados::print() {

	Fext.print();
	
	Vel.print();

}