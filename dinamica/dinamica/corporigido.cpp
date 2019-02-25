#include "pch.h"
#include "corporigido.h"
#include "centrodemassa.h"


corporigido::corporigido(int np):Fext(2),Fcont(2),Vel(2),CM(2), posicao(np,2)
{
Fext.zeros();
Fcont.zeros();
Vel.zeros();
CM.zeros();
torque=0;
W=0;
I=0;
massa=0;

}




corporigido::~corporigido()
{
}
