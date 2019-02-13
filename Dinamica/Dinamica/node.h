#pragma once

class node
{
public:
	double** ponto;
	int size[2];

	node(int Np);
	void setponto(double**M);
	void print();

	~node();
};

