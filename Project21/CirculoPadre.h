#pragma once
#include "String.h"
using namespace System::Drawing;
using namespace System;
class padre
{
protected:
	int x, y;
	int dx, dy;
	char *imagen;
	int W, H;
	int indiceW;
	int indiceH;
public:
	padre(void);
	~padre(void);
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);
	int retornar_x();
	int retornar_y();
	int retornar_dx();
	int retornar_dy();
	int retornar_H();
	int retornar_W();

};
padre::padre()
{
	x = y = 100;
	dx = 4;
	dy = 4;
	indiceH = indiceW = 0;
	imagen = new char[100];
}
void padre::cambiar_x(int nuevo)
{
	x = nuevo;
}
void padre::cambiar_y(int nuevo)
{
	y = nuevo;
}
void padre::cambiar_dx(int nuevo)
{
	dx = nuevo;
}
void padre::cambiar_dy(int nuevo)
{
	dy = nuevo;
}
int  padre::retornar_x()
{
	return x;
}
int  padre::retornar_y()
{
	return y;
}
int  padre::retornar_dx()
{
	return dx;
}
int  padre::retornar_dy()
{
	return dy;
}
int  padre::retornar_H()
{
	return H;
}
int  padre::retornar_W()
{
	return W;
}


padre::~padre()
{

}