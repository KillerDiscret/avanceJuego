#pragma once
#include"CirculoPeque�o.h"
class Arrcp
{
private:
	int *N;
	CirculoP**arreglo;
public:
	Arrcp();
	void agregar(CirculoP*obj);
	CirculoP* obtener(int indice);
	int get_N();
	~Arrcp();
};
Arrcp::Arrcp()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void Arrcp::agregar(CirculoP*obj)
{
	CirculoP**temporal;
	temporal = new CirculoP*[*N + 1];
	if (temporal != NULL)
	{
		for (int i = 0; i<*N; i++)
		{
			temporal[i] = arreglo[i];
		}
		temporal[*N] = obj;
		*N = *N + 1;
		arreglo = temporal;
	}
}
CirculoP* Arrcp::obtener(int indice)
{
	return arreglo[indice];
}
int Arrcp::get_N()
{
	return *N;
}
Arrcp::~Arrcp()
{

}