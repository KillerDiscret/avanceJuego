#pragma once
#include "CirculoPadre.h"
#include <math.h>
class CirculoM :public padre
{
private:
	int orientacion;
	bool habilita = true;
	int pos = 1;
public:
	CirculoM(void);
	~CirculoM(void);
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr);
	Rectangle get_rectangle();
};
CirculoM::CirculoM() :padre()
{
	Random r;
	int aux;
	aux = r.Next(1, 5);
	if (aux == 1)
	{
		orientacion = 1;
	}
	if (aux == 2)
	{
		orientacion = 2;
	}
	if (aux == 3)
	{
		orientacion = 3;
	}
	if (aux == 4)
	{
		orientacion = 4;
	}
}

void CirculoM::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	W = (bmp->Width / 4);
	H = (bmp->Height);
	delete bmp;
}
void CirculoM::mostrar(Graphics^gr)
{
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*W, indiceH*H, W, H);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W / 6, H / 6);
	gr->DrawImage(bmp, zoom, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
Rectangle CirculoM::get_rectangle() 
{ 
	return Rectangle(x+5, y+4, (W / 6)-5, (H / 6)-1); 
}
void CirculoM::Mover(Graphics^gr)
{
	if (habilita == true)
	{

		if (orientacion == 1)
		{
			//derecha
			//x++;
			x = x + dx;
			if (x + W/6 >= gr->VisibleClipBounds.Width + (W / 12))
			{
				x = (gr->VisibleClipBounds.Width) - (W / 12);
				habilita = false;
				pos = 2;
			}
		}
		if (orientacion == 2)
		{
			//izquierda
			//x--;
			x = x - dx;
			if (x <= -1 * (W / 12))
			{
				x = -1 * (W / 12);
				habilita = false;
				pos = 4;
			}
		}
		if (orientacion == 3)
		{
			//abajo
			//y++;
			y = y + dy;
			if (y + W / 6 >= gr->VisibleClipBounds.Height+ (W / 12))
			{
				y = (gr->VisibleClipBounds.Height) - (W/ 12);
				habilita = false;
				pos = 3;
			}
		}
		if (orientacion == 4)
		{
			//arriba
			//y--;
			y = y - dy;
			if (y <= -1 * (W / 12))
			{
				y = -1 * (W / 12);
				habilita = false;
				pos = 1;
			}
		}
	}
	else
	{
		//arriba a la derecha
		if (y == -1 * (W / 12) && (x<gr->VisibleClipBounds.Width) && pos == 1)
		{
			//x++;
			x = x + dx;
			if (x + dx + (W / 12) >= gr->VisibleClipBounds.Width)
			{
				pos = 2;
				x = (gr->VisibleClipBounds.Width) - (W / 12);
			}
		}
		//derecha hacia abajo
		if (pos == 2 && y < gr->VisibleClipBounds.Height && (x == (gr->VisibleClipBounds.Width) - (W / 12)))
		{
			//y++;
			y = y + dy;
			if (y + dy + (W / 12) >= gr->VisibleClipBounds.Height)
			{
				pos = 3;
				y = (gr->VisibleClipBounds.Height) - (W / 12);
			}
		}
		//abajo hacia la izquieda
		if (pos == 3 && (y == (gr->VisibleClipBounds.Height) - (W / 12)) && x>-1 * (W / 12))
		{
			//x--;
			x = x - dx;
			if (x <= -1 * (W / 12))
			{
				//falta pulir para que cambie de posicion bien
				pos = 4;
				x = -1 * (W / 12);
			}
		}
		//izquierda hacia arriba
		if (pos == 4 && y >= -1 * (W / 12) && x == -1 * (W / 12))
		{
			//y--;
			y = y - dy;
			if (y<= -1 * (W / 12))
			{
				pos = 1;
				y = -1 * (W / 12);
			}
		}

	}
	
	if (indiceH == 0 && indiceW == 3)
	{
		indiceH = 0;
		indiceW = 0;
	}
	indiceW++;
	mostrar(gr);
}
CirculoM::~CirculoM()
{

}