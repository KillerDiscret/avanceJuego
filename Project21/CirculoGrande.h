#pragma once
#include "CirculoPadre.h"
#include <math.h>
class CirculoG:public padre
{

public:
	CirculoG(void);
	~CirculoG(void);
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr);
};
CirculoG::CirculoG():padre()
{
	Random r;
	if (r.Next(1,5)==1)
	{
		cambiar_dx(dx*-1);
	}
	if (r.Next(1, 5) == 2)
	{
		cambiar_dy(dy*-1);
	}
	if (r.Next(1, 5) == 3)
	{
		cambiar_dx(dx*-1);
		cambiar_dy(dy*-1);
	
	}
	if (r.Next(1, 5) == 4)
	{
		dx = dx;
		dy = dy;
	}
}

void CirculoG::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	W = (bmp->Width / 4);
	H = (bmp->Height);
	delete bmp;
}
void CirculoG::mostrar(Graphics^gr)
{
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*W, indiceH*H, W, H);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W/4, H/4);
	gr->DrawImage(bmp, zoom, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
void CirculoG::Mover(Graphics^gr)
{
	if (indiceH == 0&&indiceW==3)
	{
		indiceH = 0;
		indiceW = 0;
	}
	if (x+dx<1)
	{
		dx = dx*-1;
		x++;
	}
	if (y + dy<1)
	{
		dy = dy*-1;
		y++;
	}
	if (x + dx+(W/4)>gr->VisibleClipBounds.Width)
	{
		dx = dx*-1;
		x--;
	}
	if (y + dy+(H/4)>gr->VisibleClipBounds.Height)
	{
		dy = dy*-1;
		y--;
	}
	indiceW ++;
	x = x + dx;
	y = y + dy;
	mostrar(gr);
}
CirculoG::~CirculoG()
{

}