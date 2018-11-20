#pragma once
#include "String.h"
using namespace System;
using namespace System::Drawing;
class mapa
{
private:
	int x, y;
	int W, H;
public:
	mapa(int X, int Y, int w, int h);
	void mostrar(Graphics^gr, Bitmap ^bmp);
	~mapa();
};
mapa::mapa(int X,int Y, int w, int h)
{
	x = X;
	y = Y;
	W = w;
	H = h;
}

void mapa::mostrar(Graphics^gr, Bitmap ^bmp)
{
	gr->DrawImage(bmp, x, y, W, H);
}

mapa::~mapa()
{

}