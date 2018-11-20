#pragma once
#include "CirculoGrande.h"
class Arrcg
{
private:
	int *N;
	CirculoG**arreglo;
public:
	Arrcg();
	void agregar(CirculoG*obj);
	CirculoG* obtener(int indice);
	int get_N();
	void set_N(int valor);
	~Arrcg();
};
Arrcg::Arrcg()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void Arrcg::agregar(CirculoG*obj)
{
	CirculoG**temporal;
	temporal = new CirculoG*[*N + 1];
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
CirculoG* Arrcg::obtener(int indice)
{
	return arreglo[indice];
}
int Arrcg::get_N()
{
	return *N;
}
void Arrcg::set_N(int valor)
{
	*N = valor;
}
Arrcg::~Arrcg()
{

}