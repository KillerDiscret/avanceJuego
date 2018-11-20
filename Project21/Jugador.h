#pragma once
#include "String.h"
enum Direcciones { arriba, abajo, izquierda, derecha, ninguna};
using namespace System::Drawing;
using namespace System;
class Jugador
{
private:
	int x, y;
	int dx, dy;
	char*imagen;//nombre del archivo
	int ancho, alto;
	int indicex, indicey;
	Direcciones direccion;
	Direcciones ultima;
public:
	Jugador(void);
	~Jugador(void);
	void set_x(int nuevo);
	void set_y(int nuevo);
	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_ancho();
	int get_alto();
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr);
	void setdireccion(Direcciones teclapulsada);
	Rectangle get_rectangle_jugador();
};
Jugador::Jugador(void)
{
	y=500;
	x = 300;
	dx = 12;
	dy = 12;
	indicex = indicey = 0;
	
	imagen = new char[50];
	direccion = ninguna;//esta variable obtiene la tecla que presiono
	ultima = arriba;//esta variable muestra la imagen de la ultima tecla que presioné
}
void Jugador::set_x(int nuevo)
{
	x = nuevo;
}
void Jugador::set_y(int nuevo)
{
	y = nuevo;
}
int  Jugador::get_x()
{
	return x;
}
int  Jugador::get_y()
{
	return y;
}
int  Jugador::get_dx()
{
	return dx;
}
int  Jugador::get_dy()
{
	return dy;
}
int  Jugador::get_ancho()
{
	return ancho;
}
int  Jugador::get_alto()
{
	return alto;
}

void Jugador::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);//copia de una cadena a otra
						  //imagen tiene el nombre del archivo sprite
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	//carga la imagen
	ancho = bmp->Width / 5;//5 imagenes x columna
	alto = bmp->Height / 4;//4 imagenes xcolumna
	delete bmp;
}
void Jugador::mostrar(Graphics^gr)
{
	x += dx;
	y += dy;
	//clase Bitmap para leer la imagen del archivo
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	//porcion que será un cuadro del sprite
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	//zoom para que la imagen sea más grande que la original
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho, alto);
	//Dibuja la imagen en el canvas
	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	//borrar el bmp
	delete bmp;
}
Rectangle Jugador::get_rectangle_jugador() 
{ 
	return Rectangle(x-8, y-5, ancho, alto); 
}
void Jugador::Mover(Graphics^gr)
{
	switch (direccion)
	{
	case arriba:
	{
		indicey = 3;
		if (indicex>=0&&indicex<2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		if (y-1<0)
		{

			dx = 0;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = -12;
		}
		ultima = arriba;
		break;
	}
	case abajo:
	{
		indicey = 0;
		if (indicex >= 0 && indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		
		if (y +alto-8>gr->VisibleClipBounds.Height)
		{
			dx = 0;
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = +12;
		}

		ultima = abajo;
		break;
	}
	case izquierda:
	{
		indicey = 1;
		if (indicex >= 0 && indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		if (x<0)
		{
			dx = 0;
			dy = 0;
		}
		else
		{
			dx = -12;
			dy = 0;
		}
		ultima = izquierda;
		break;
	}
	case derecha:
	{
		indicey = 2;
		if (indicex >= 0 && indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}

		if (x+ancho-8>gr->VisibleClipBounds.Width)
		{
			dx = 0;
			dy = 0;
		}
		else
		{
			dx = +12;
			dy = 0;
		}
		ultima = derecha;
		break;
	}
	case ninguna:
	{
		dx = 0;
		dy = 0;
		if (ultima == abajo)
		{
			indicex = 0;
			indicey = 0;
			
		}
		if (ultima == arriba)
		{
			
				indicex = 0;
				indicey = 3;
		}

		if (ultima == derecha)
		{
			
				indicex = 0;
				indicey = 2;
		}
		if (ultima == izquierda)
		{
			
				indicex = 0;
				indicey = 1;
		}
		break;
	}
	default:
		break;
	}
		mostrar(gr);
}
void Jugador::setdireccion(Direcciones direccion_actual)
{
	direccion = direccion_actual;

}
Jugador::~Jugador()
{
	//Delete imagen
}
