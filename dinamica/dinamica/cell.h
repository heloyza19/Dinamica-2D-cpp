#pragma once
class cell
{
private:
	double**** C;
	double* size[2]; 
public:
	
	cell(N,M);
	cell(i, j, double**M);
	~cell();
	double max();


};

