#pragma once
#include "CirculoMediano.h"
class Arrcm
{
private:
	int *N;
	CirculoM**arreglo;
public:
	Arrcm();
	void agregar(CirculoM*obj);
	CirculoM* obtener(int indice);
	int get_N();
	void set_N(int valor);
	~Arrcm();
};
Arrcm::Arrcm()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void Arrcm::agregar(CirculoM*obj)
{
	CirculoM**temporal;
	temporal = new CirculoM*[*N + 1];
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
CirculoM* Arrcm::obtener(int indice)
{
	return arreglo[indice];
}
int Arrcm::get_N()
{
	return *N;
}
void Arrcm::set_N(int valor)
{
	*N = valor;
}
Arrcm::~Arrcm()
{

}