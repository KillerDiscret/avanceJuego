#pragma once
#include "CirculoGrande.h"
#include "CirculoMediano.h"
#include "ArregloCG.h"
#include "ArregloCM.h"
#include"ArregloCP.h"
#include "Jugador.h"
#include "CirculoPequeño.h"
#include "Mapa.h"
namespace Project21 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();
			d = this->CreateGraphics();
			/*
			objcirculo = new CirculoG();
			objcirculo->cambiar_x(d->VisibleClipBounds.Width/(2.5));
			objcirculo->cambiar_y(d->VisibleClipBounds.Height/(2.5));
			objcirculo->cambiar_imagen("prueba2.png");
			*/
			arreglocg = new Arrcg();
			arreglocm = new Arrcm();
			arreglocp = new Arrcp();
			objjugador = new Jugador();
			objjugador->cambiar_imagen("spritejugador.png");
			imagenes = gcnew cli::array<Bitmap^>(8);
			imagenes[0] = gcnew Bitmap("mapa1.jpg");
			imagenes[1] = gcnew Bitmap("mapa2.jpg");
			imagenes[2] = gcnew Bitmap("mapa3.jpg");
			imagenes[3] = gcnew Bitmap("mapa4.png");
			imagenes[4] = gcnew Bitmap("mapa5.png");
			objmapas = new mapa(0,0,this->ClientRectangle.Width,this->ClientRectangle.Height);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete d;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		//CirculoG*objcirculo;
		Arrcg* arreglocg;
		Arrcm* arreglocm;
		Arrcp*arreglocp;
		Graphics^d;
		Jugador*objjugador;
		cli::array<Bitmap^>^imagenes;
		mapa* objmapas;
		int NumVecesCG =2;
		int contadorCG = 0;
		bool CG = true;
		int NumVecesCM = 2;
		int contadorCM = 0;
		bool CM = true;
		int NumVecesCP = 1;
		int contadorCP = 0;
		bool CP = true;
		int nivel = 0;
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 593);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext ^bc = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics ^bg = bc->Allocate(gr, this->ClientRectangle);
		Color ^back = gcnew Color();
		bg->Graphics->Clear(Color::White);
		
			objmapas->mostrar(bg->Graphics, imagenes[nivel]);
		
		objjugador->Mover(bg->Graphics);
		//objcirculo->Mover(bg->Graphics);
		//agregar un obj circulo Grande
		

		//colision circulo mediano
		for (int i = 0; i < arreglocm->get_N(); i++)
		{
			if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocm->obtener(i)->get_rectangle()))

			{
				//objAdmControl->dibujarSangre(buffer->Graphics, bmpSangre, objAdmControl->get_oJugador()->get_x(), objAdmControl->get_oJugador()->get_y());
				objjugador->set_x(400);
				objjugador->set_y(400);

				//vidas --
			}
		}
		//colision circulo grande
		for (int i = 0; i < arreglocg->get_N(); i++)
		{
			if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocg->obtener(i)->get_rectangle()))

			{
				//objAdmControl->dibujarSangre(buffer->Graphics, bmpSangre, objAdmControl->get_oJugador()->get_x(), objAdmControl->get_oJugador()->get_y());
				objjugador->set_x(400);
				objjugador->set_y(400);

				//vidas --
			}
		}
		//colision circulo pequeño
		for (int i = 0; i < arreglocp->get_N(); i++)
		{
			if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocp->obtener(i)->get_rectangle()))

			{
				//objAdmControl->dibujarSangre(buffer->Graphics, bmpSangre, objAdmControl->get_oJugador()->get_x(), objAdmControl->get_oJugador()->get_y());
				objjugador->set_x(400);
				objjugador->set_y(400);
				arreglocp->obtener(i)->cambiar_x(d->VisibleClipBounds.Width / (2.5));
				arreglocp->obtener(i)->cambiar_y(d->VisibleClipBounds.Height / (2.5));
				//vidas --
			}
		}
		if (contadorCG==50&&CG==true)
		{
			if (arreglocg->get_N()<NumVecesCG)
			{
				CirculoG* obj2 = new CirculoG();
				obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
				obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
				obj2->cambiar_imagen("spritegrande1.png");
				arreglocg->agregar(obj2);
			}
			contadorCG = 0;
		}
		contadorCG++;
		for (int i = 0; i<arreglocg->get_N(); i++)
		{
			arreglocg->obtener(i)->Mover(bg->Graphics);
		}
		//para cambiar la velocidad "pausa del tiempo"
		/*if (arreglocg->get_N()==5)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				arreglocg->obtener(i)->cambiar_dx_dy(1,1);
			}
		}
		*/
		if (contadorCM == 30)
		{
			if (arreglocm->get_N()<NumVecesCM)
			{
				CirculoM* objM = new CirculoM();
				objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
				objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
				objM->cambiar_imagen("spritemediano.png");
				arreglocm->agregar(objM);
				if (arreglocm->get_N()==2)
				{
					arreglocg->set_N(0);
					CG = false;
					delete arreglocg->obtener(0);
				}
				
			}
			contadorCM = 0;
		}
		contadorCM++;
		for (int i = 0; i<arreglocm->get_N(); i++)
		{
			arreglocm->obtener(i)->Mover(bg->Graphics);
		}
		//*************************
		if (contadorCP == 30)
		{
			if (arreglocp->get_N()<NumVecesCP)
			{
				CirculoP* objCP;
				objCP = new CirculoP();
				objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
				objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
				objCP->cambiar_dx_dy(1, 1);
				objCP->cambiar_imagen("spritepequeño.png");
				arreglocp->agregar(objCP);
			}
			contadorCP = 0;
		}
		contadorCP++;
		for (int i = 0; i<arreglocp->get_N(); i++)
		{
			arreglocp->obtener(i)->Mover(bg->Graphics,objjugador->get_x(),objjugador->get_y(),objjugador->get_ancho(),objjugador->get_alto());

		}

		bg->Render(gr);
		delete gr;
		delete bc;
		delete bg;
	
	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{

		switch (e->KeyCode)
		{

		default:
			objjugador->setdireccion(ninguna);
			break;
		}
	
	}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
{
	switch (e->KeyCode)
	{
	case Keys::Up://arriba
		objjugador->setdireccion(arriba);
		break;

	case Keys::Left://Izquierda
		objjugador->setdireccion(izquierda);
		break;
	case Keys::Right://derecha
		objjugador->setdireccion(derecha);
		break;

	case Keys::Down://abajo
		objjugador->setdireccion(abajo);
		break;
	case Keys::C:
		nivel++;
		if (nivel == 5)
		{
			nivel = 0;
		}
		if (nivel==1)
		{
			objmapas = new mapa(0,0,( this->ClientRectangle.Width), (this->ClientRectangle.Height));
		}
		break;
	default:
		break;
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
}
};
}
