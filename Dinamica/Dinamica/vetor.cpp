#include "pch.h"
#include "vetor.h"
#include <iostream>

using namespace std;

vetor::vetor(int t)
{
	Size = t;
	double *V = new double(t);
}


vetor::~vetor()
{
	delete[]V;
}

void vetor::print()
{
	cout << "=[";
	for (int i = 0; i < Size; i++)
	{
		cout << *(V + i) << " ";
	}
	cout << "]\n";
}

void vetor::setV(double* A)
{
	V = A;
}


double* vetor::getV()
{
	return V;
}



int vetor::getsize()
{
	return Size;
}


//Sobrecarga do igual
void vetor::operator =(const vetor &A) //const
{

	this->Size = A.Size;

	double* vetor1 = new double[A.Size];
	for (int i = 0; i < A.Size; i++)
	{
		*(vetor1 + i) = *(A.V + i);
	}
	this->setV(vetor1);

}


//Sobrecarga do igual
//Construtor de c�pia-
//Por que usar o const na sobrecarga do operador



//Construtor de copia
vetor::vetor(const vetor &A)
{
	this->Size = A.Size;
	double* c = new double[A.Size];
	for (int i = 0; i < A.Size; i++)
	{
		*(c + i) = A.V[i];
	}
	this->setV(c);
}

vetor vetor::operator + (vetor &A) {
	if (A.Size == this->Size) {
		vetor C(A.Size);
		double* c = new double[A.Size];

		for (int i = 0; i < A.Size; i++)
		{
			*(c + i) = this->V[i] + A.V[i];
		}

		C.setV(c);

		return C;
	}
	else {
		cerr << "vetores com tamanhos diferentes\n";
	}
}

vetor vetor::operator - (vetor &A) {
	if (A.Size == this->Size) {
		vetor C(A.Size);
		double* c = new double[A.Size];

		for (int i = 0; i < A.Size; i++)
		{
			*(c + i) = this->V[i] - A.V[i];
		}

		C.setV(c);

		return C;
	}
	else {
		cerr << "vetores com tamanhos diferentes\n";
	}
}

double vetor::operator *(vetor &B) {
	if (this->Size == B.Size)
	{
		double p = 0;
		for (int i = 0; i < B.Size; i++)
		{
			p += this->V[i] * B.V[i];
		}
		return p;
	}
	else {
		cerr << "Vetores com tamanhos diferentes\n";
	}

}

vetor vetor::cross(vetor &B)
{
	if (this->Size == B.Size & B.Size == 3)
	{
		vetor C(3);
		double*c = new double[3];

		c[0] = (this->V[1] * B.V[2]) - (this->V[2] * B.V[1]);
		c[1] = (this->V[2] * B.V[0]) - (this->V[0] * B.V[2]);
		c[2] = (this->V[0] * B.V[1]) - (this->V[1] * B.V[0]);

		C.setV(c);
		return C;
	}
	else
	{
		cerr << "Erro\n";
	}

}

vetor vetor::operator *(double n)
{
	vetor C(this->Size);
	double* c = new double[this->Size];
	for (int i = 0; i < this->Size; i++)
	{
		c[i] = n * this->V[i];
	}
	C.setV(c);
	return C;
}


/*
vetor vetor::operator *(matriz &A)
{
	if (Size == A.getsize()[0])
	{
		double* v = new double[A.getsize()[1]];

			for (int j = 0; j < A.getsize()[1]; j++)
			{
				*(v + j) = 0;
				for (int k = 0; k < Size; k++)
				{

					*(v + j) += this->V[k] * A.getM()[k][j];
				}

			}
			vetor V;
			V.setV(v);
			return V;
	}
	else
	{
		std::cerr << "Os requisitos para a multiplicacao nao foram cumpridos\n";
	}


}
*/