#pragma once
#include "sistema.h"

vetor Fnormal(vetor Vnormal, double Cn, double Kn, vetor Vel1, vetor Vel2, double ra, double rb, double d);
void sistema::contato()
{
double Eelas = 0;
int* C = new int(2);
int l, h;
int* P = new int(2);
int P1, P2;
int Nba, E, Na;
double D;
double torque1x = 0, torque1y = 0;
double torque2x = 0, torque2y = 0;
double ang1x, ang1y, ang2x, and2y;
vetor Fn(2);
vetor Fr(2);
vetor Fnx(2);
vetor Fny(2);
vetor R1(2);
//vetor R2(2);


double* Vn = new double[2];
vetor Vnormal(2);

 
for (int i=0; i < corpo.size(); i++) 
{
for (int j=0; j < corpo[i].posicao.size[0]; j++)
{
	for (int k = 0; k < Ned; k++)
	{

		/*C=mapeamento(element[i].xcentro.getM()[j][k], element[i].ycentro.getM()[j][k]);
		l = C[0];
		h = C[1];*/
		//colisao lateral  (paredes)

		if (element[i].xcentro.getM()[j][k] <= element[i].raio.getV()[j])
		{
			vetor Vel2(2);
			Vel2.zeros();
			Vn[0] = 1;
			Vn[1] = 0;
			Vnormal.setV(Vn);
			Fn = Fnormal(Vnormal, Cn, Kn, corpo[i].Vel, Vel2, element[i].raio.getV()[j], 0, element[i].xcentro.getM()[j][k]);
			Fr = corpo[i].Fcont + Fn;
			corpo[i].Fcont.setV(Fr.getV());
			Eelas += 0.5*Kn*pow(element[i].raio.getV()[j] - element[i].xcentro.getM()[j][k], 2);

		}
		else if (element[i].xcentro.getM()[j][k] >= (L - element[i].raio.getV()[j]))
		{
			vetor Vel2(2);
			Vel2.zeros();
			Vn[0] = -1;
			Vn[1] = 0;
			Vnormal.setV(Vn);
			Fn = Fnormal(Vnormal, Cn, Kn, corpo[i].Vel, Vel2, element[i].raio.getV()[j], 0, L - element[i].xcentro.getM()[j][k]);
			Fr = corpo[i].Fcont + Fn;
			corpo[i].Fcont.setV(Fr.getV());
			Eelas += 0.5*Kn*pow(element[i].raio.getV()[j] - L - element[i].xcentro.getM()[j][k], 2);

		}


		//colisao vertical (paredes)
		if (element[i].ycentro.getM()[j][k] <= element[i].raio.getV()[j])
		{
			vetor Vel2(2);
			Vel2.zeros();
			Vn[0] = 0;
			Vn[1] = 1;
			Vnormal.setV(Vn);
			Fn = Fnormal(Vnormal, Cn, Kn, corpo[i].Vel, Vel2, element[i].raio.getV()[j], 0, element[i].ycentro.getM()[j][k]);
			Fr = corpo[i].Fcont + Fn;
			corpo[i].Fcont.setV(Fr.getV());
			Eelas += 0.5*Kn*pow(element[i].raio.getV()[j] - element[i].ycentro.getM()[j][k], 2);

		}
		else if (element[i].ycentro.getM()[j][k] >= H - element[i].raio.getV()[j])
		{
			vetor Vel2(2);
			Vel2.zeros();
			Vn[0] = 0;
			Vn[1] = -1;
			Vnormal.setV(Vn);
			Fn = Fnormal(Vnormal, Cn, Kn, corpo[i].Vel, Vel2, element[i].raio.getV()[j], 0, H - element[i].ycentro.getM()[j][k]);
			Fr = corpo[i].Fcont + Fn;
			corpo[i].Fcont.setV(Fr.getV());
			Eelas += 0.5*Kn*pow(element[i].raio.getV()[j] - H - element[i].ycentro.getM()[j][k], 2);

		}

		//colisao entre corpos
		
		
		
		P=mapeamento(element[i].xcentro.getM()[j][k], element[i].ycentro.getM()[j][k]);
		P1 = P[0];
		P2 = P[1];

		int a = -1;
		int b = 1;
		int c = -1;
		int d = 1;

		if (P1 == 0)
		{ a = 0;
		}
		else if (P1 == ceil(L / dx))
		{	b = 0;
		}
		if(P2 == 0)
		{
			c = 0;
		}
		else if(P2 == ceil(H / dx))
		{
			d = 0;
		}
	
		//Percorre as células vizinhas
		for (int A = a; A < b; A++)
		{
			for (int B = c; B < d; B++)
			{
				if (mapa[P1 + A][P2 + B]->corpo.size() > 0) 
				{
					for(int C=0;C< mapa[P1 + A][P2 + B]->corpo.size();C++)
					{
						Nba = mapa[P1 + A][P2 + B]->elem[C];
						E = mapa[P1 + A][P2 + B]->corpo[C];
						Na = mapa[P1 + A][P2 + B]->aresta[C];
						
						D = sqrt(pow(element[i].xcentro.getM()[j][k] - element[E].xcentro.getM()[Na][Nba], 2) + pow(element[i].ycentro.getM()[j][k] - element[E].ycentro.getM()[Na][Nba], 2));

						if (D < (element[E].raio.getV()[Na] + element[i].raio.getV()[j]))
						{
							Vn[0] = (element[i].xcentro.getM()[j][k] - element[E].xcentro.getM()[Na][Nba]) / (D);
							Vn[1]= (element[i].ycentro.getM()[j][k] - element[E].ycentro.getM()[Na][Nba]) / (D);
							Vnormal.setV(Vn);
							Fn = Fnormal(Vnormal, Cn, Kn, corpo[i].Vel, corpo[E].Vel, element[i].raio.getV()[j], element[E].raio.getV()[Na], D);
							


							//corpo 1 

							R1.V[0] = element[i].xcentro.getM()[j][k] - corpo[i].CM.V[0];
							R1.V[1] = element[i].ycentro.getM()[j][k] - corpo[i].CM.V[1];

							if (Fn.V[0] == 0) 
							{
								torque1x = 0;
							}
							else
							{

								Fnx.V[0] = Fn.V[0];
								Fnx.V[1] = Fn.V[1];
								ang1x = acos((Fnx*R1) / (R1.norm()*Fnx.norm()));
								torque1x = Fnx.norm()*R1.norm()*sin(ang1x);

								if (Fnx.V[0] > 0 & element[i].ycentro.getM()[j][k]> corpo[i].CM.V[1])
								{
									torque1x = -torque1x;
								}
								else if (Fnx.V[0] < 0 & element[i].ycentro.getM()[j][k] < corpo[i].CM.V[1])
								{
									torque1x = -torque1x;
								}
							}


							if (Fn.V[1] == 0)
							{
								torque1y = 0;
							}
							else
							{
								Fny.V[0] = 0;
								Fny.V[1] = Fn.V[1];

								ang1y = acos((Fny*R1)/(R1.norm()*Fny.norm()));
								torque1y = Fny.norm()*R1.norm()*sin(ang1y);

								if (Fny.V[1] > 0 & element[i].xcentro.getM()[j][k] < corpo[i].CM.V[0])
								{
									torque1y = -torque1y;
								}
								else if (Fny.V[1] < 0 & element[i].xcentro.getM()[j][k] > corpo[i].CM.V[0])
								{
									torque1y = -torque1y;
								}
							
							
							}
							
							corpo[i].torque+=torque1x+torque1y;
						
						

						//corpo2

							R1.V[0] = element[E].xcentro.getM()[Na][Nba] - corpo[E].CM.V[0];
							R1.V[1] = element[E].ycentro.getM()[Na][Nba] - corpo[E].CM.V[1];

							if (Fn.V[0] == 0)
							{
								torque2x = 0;
							}
							else
							{
								Fnx.V[0] = -Fn.V[0];
								Fnx.V[1] = 0;		

								ang1x = acos((Fnx*R1) / (R1.norm()*Fnx.norm()));
								torque2x = Fnx.norm()*R1.norm()*sin(ang1x);

								if (Fnx.V[0] > 0 & element[i].ycentro.getM()[j][k] > corpo[i].CM.V[1])
								{
									torque2x = -torque2x;
								}
								else if (Fnx.V[0] < 0 & element[i].ycentro.getM()[j][k] < corpo[i].CM.V[1])
								{
									torque2x = -torque2x;
								}
							}


							if (Fn.V[1] == 0)
							{
								torque2y = 0;
							}
							else
							{
								Fny.V[0] = 0;
								Fny.V[1] = -Fn.V[1];

								ang1y = acos((Fny*R1) / (R1.norm()*Fny.norm()));
								torque2y = Fny.norm()*R1.norm()*sin(ang1y);

								if (Fny.V[1] > 0 & element[E].xcentro.getM()[Na][Nba] < corpo[E].CM.V[0])
								{
									torque2y = -torque2y;
								}
								else if (Fny.V[1] < 0 & element[E].xcentro.getM()[Na][Nba] > corpo[E].CM.V[0])
								{
									torque2y = -torque2y;
								}


							}
							corpo[E].torque += torque2x + torque2y;


							corpo[i].Fcont = corpo[i].Fcont + Fn;
							corpo[E].Fcont = corpo[E].Fcont - Fn;

							Eelas += 0.5*Kn*pow(element[i].raio.V[j]+element[E].raio.V[Na]-D,2);
							


						}

					}

				}


			}


		}
		
	}
}
}



	//return Eelas;
}



vetor Fnormal(vetor Vnormal, double Cn, double Kn, vetor Vel1, vetor Vel2, double ra, double rb, double d)
{
	vetor Fn(2);
	double Fne= Kn*(ra+rb-d);
	double Fnd = Cn * ((Vel1 - Vel2)*Vnormal);
	Fn = Vnormal * (Fne + Fnd);

	return Fn;

}

