#pragma once
#include "String.h"
using namespace System::Drawing;
using namespace System;
class padre
{
protected:
	double x, y;
	double dx, dy;
	char *imagen;
	int W, H;
	int indiceW;
	int indiceH;
public:
	padre(void);
	~padre(void);
	void cambiar_x(double nuevo);
	void cambiar_y(double nuevo);
	void cambiar_dx(double nuevo);
	void cambiar_dy(double nuevo);
	void cambiar_dx_dy(double DX, double DY);
	double retornar_x();
	double retornar_y();
	double retornar_dx();
	double retornar_dy();
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
void padre::cambiar_x(double nuevo)
{
	x = nuevo;
}
void padre::cambiar_y(double nuevo)
{
	y = nuevo;
}
void padre::cambiar_dx(double nuevo)
{
	dx = nuevo;
}
void padre::cambiar_dy(double nuevo)
{
	dy = nuevo;
}
void padre::cambiar_dx_dy(double DX, double DY)
{
	//cuando mandamos parámetros tienen que ser positivos
	if (dx<0)
	{
		dx = DX*-1;
	}
	if (dx>0)
	{
		dx = DX;
	}
	if (dy<0)
	{
		dy = DY*-1;
	}
	if (dy>0)
	{
		dy = DY;
	}

}
double  padre::retornar_x()
{
	return x;
}
double  padre::retornar_y()
{
	return y;
}
double  padre::retornar_dx()
{
	return dx;
}
double  padre::retornar_dy()
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