#include "pch.h"
#include "dados.h"


dados::dados(int nc)
{
	corpo = new corporigido(nc);

}


dados::~dados()
{
	delete[]corpo;
}
