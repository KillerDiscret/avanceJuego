#pragma once
#include "CirculoPadre.h"
class CirculoP :public padre
{
public:
	CirculoP(void);
	~CirculoP(void);
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr,int JX,int JY,int Width, int Heigth);
	Rectangle get_rectangle();
};
CirculoP::CirculoP() :padre()
{

}

void CirculoP::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	W = (bmp->Width /8.95);
	H = (bmp->Height);
	delete bmp;
}
void CirculoP::mostrar(Graphics^gr)
{
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*W, indiceH*H, W, H);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W/3, H/3);
	gr->DrawImage(bmp, zoom, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
Rectangle CirculoP::get_rectangle() 
{
	return Rectangle(x+12, y+10, (W / 3)-20, (H / 3)-15); 
}
void CirculoP::Mover(Graphics^gr, int JX, int JY,int Width, int Height)
{
	if (indiceH == 0 && indiceW == 8)
	{
		indiceH = 0;
		indiceW = 0;
	}
	if (((y<=JY&&y+H>=JY)||(y<=JY+Height&&y+H>=JY+Height))&&x>(JX))
	{
		//x--;
		x -= dx;
	}
	if (((y <= JY&&y + H >= JY) || (y <= JY + Height&&y + H >= JY + Height)) && x<(JX))
	{
		//x++;
		x += dx;
	}
	if (((x<=JX&&x+W>=JX)|| (x <= JX+Width&&x + W >= JX+Width))&&y>JY)
	{
		//y--;
		y -= dy;
	}
	if (((x <= JX&&x + W >= JX) || (x <= JX + Width&&x + W >= JX + Width)) && y<JY)
	{
		//y++;
		y += dy;
	}
	if (JY>=y&&JX>=x)
	{

		//x++;
		x += dx;
		//y++;
		y += dy;
	}
	if (JY <= y&&JX <= x)
	{

		//x--;
		x -= dx;
		//y--;
		y -= dy;
	}
	if (JX>x&&JY<y)
	{
		//x++;
		x += dx;
		//y--;
		y -= dy;
	}
	if (JX<x&&JY>y)
	{
		//x--;
		x -= dx;
		//y++;
		y += dy;
	}
	indiceW++;

	mostrar(gr);
}
CirculoP::~CirculoP()
{

}
