#include "pch.h"
#include "cell.h"


cell::cell(N,M)
{
double**** C = new double***[N];
for (int i = 0; i < N; i++)
{
	C[i] = new double**[M];
}


cell::~cell()
{

	delete[]C;
}
