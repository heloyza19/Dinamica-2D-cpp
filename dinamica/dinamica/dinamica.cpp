#include "pch.h"
#include <iostream>
//#include <vector>

#include "sistema.h"

using namespace std;
int main()
{
	
	int Ncr = 2;			//numero de corpos rigidos
	int Np = 4;            //numero de vertices
	int Ned = 10;	      //numero de elementos discretos
	double Cn = 0;       //constante de amortecimento
	double Kn = 10000;  //constante da mola
	double L = 10;
	double H = 10;

	double** m = new double*[Np];
	double** m2 = new double*[Np];
	for (int i = 0; i < Np; i++)
	{
		m[i] = new double[2];
		m2[i] = new double[2];
	}
	m[0][0] = 1; m[0][1] = 1;
	m[1][0] = 1; m[1][1] = 4;
	m[2][0] = 4; m[2][1] = 1;
	m[3][0] = 4; m[3][1] = 4;

	m2[0][0] = 5; m2[0][1] = 4;
	m2[1][0] = 5; m2[1][1] = 6;
	m2[2][0] = 8; m2[2][1] = 4;
	m2[3][0] = 8; m2[3][1] = 6;

	corporigido corpo1(Np);
	corpo1.posicao.setM(m);
	corpo1.centrodemassa();
	corpo1.polares();
	corpo1.Vel.ones();

	elementodiscreto corpo1ed (&corpo1, Ned);

	corporigido corpo2 (Np);
	corpo2.posicao.setM(m2);
	corpo2.centrodemassa();
	corpo2.polares();
	corpo2.Vel.ones();
	elementodiscreto corpo2ed (&corpo2, Ned);

	sistema* Dados = new sistema(L,H);

	Dados->corpo.push_back(corpo1);
	Dados->corpo.push_back(corpo2);
	Dados->element.push_back(corpo1ed);
	Dados->element.push_back(corpo2ed);
	Dados->setdx();

	cout<<Dados->element.size()<<endl;
	//Dados->setmapa();

	Dados->element[0].raio.print();
	Dados->element[1].raio.print();
	cout << Dados->dx<<endl;

;

	////determincação do dt
	double massamax = 0;

	for (int i = 0; i < Dados->corpo.size(); i++)
	{
		if (Dados->corpo[i].massa > massamax)
		{
			massamax = Dados->corpo[i].massa;
		}

	}


	double tc = 2 * sqrt(massamax / Kn);    //tempo critico
	double e = 0.1;					    //percentual do tempo critico					
	double dt = e * tc;					   //passo no incremento do tempo
	double tempo = 0.01;			     //tempo de simulacao do problema
	int sizet = ceil(tempo / dt);       //numero de passos
	cout << "sizet= " << sizet << endl;
	std::cout << "Tempo critico= " << tc << std::endl;
	cout << "dt= " << dt << endl;

	double* Eelas = new double[sizet];
	double* Ek = new double[sizet];
	double* Ekr = new double[sizet];
	double* momentolin = new double[sizet];
	double* momentoang = new double[sizet];
	double* vetormomento = new double[2];

	vetor modmomento(2);
	vetor Fres(2);
	vetor dV(2);
	vetor ds(2);
	
	vetor vetmomento(2);
	vetor K(2);


	for (int t = 0; t < sizet; t++)
	{
	
		Ek[t] = 0;
		Ekr[t] = 0;
		vetmomento.zeros();
		momentoang[t] = 0;

		Eelas[t]=Dados->contato(Kn, Cn, Ned);





	}



	

	return 0;
}













