#pragma once
#include "CirculoGrande.h"
#include "CirculoMediano.h"
#include "ArregloCG.h"
#include "ArregloCM.h"
#include"ArregloCP.h"
#include "Jugador.h"
#include "CirculoPeque�o.h"
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
			imagenes[0] = gcnew Bitmap("mapa1.png");
			imagenes[1] = gcnew Bitmap("mapa2.png");
			imagenes[2] = gcnew Bitmap("mapa3.png");
			imagenes[3] = gcnew Bitmap("mapa4.png");
			imagenes[4] = gcnew Bitmap("mapa5.png");
			imagenes[5] = gcnew Bitmap("win.png");
			imagenes[6] = gcnew Bitmap("lose.png");
			objmapas = new mapa(0,0,this->ClientRectangle.Width,this->ClientRectangle.Height);
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
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
		bool pasarnivel1 = false;
		bool pasarnivel2 = false;
		bool pasarnivel3 = false;
		bool pasarnivel4 = false;
		bool pasarnivel0 = false;
		bool aux1=true;
		bool aux2=true;
		bool aux3=true;
		bool aux4=true;
		int time = 200;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labvidas;
	private: System::Windows::Forms::Label^  labtiempo;
			 bool aux5 = true;
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labvidas = (gcnew System::Windows::Forms::Label());
			this->labtiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::DarkRed;
			this->label1->Location = System::Drawing::Point(77, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"VIDAS:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::DarkRed;
			this->label2->Location = System::Drawing::Point(170, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"TIEMPO: ";
			// 
			// labvidas
			// 
			this->labvidas->AutoSize = true;
			this->labvidas->BackColor = System::Drawing::Color::Transparent;
			this->labvidas->ForeColor = System::Drawing::Color::DarkRed;
			this->labvidas->Location = System::Drawing::Point(125, 26);
			this->labvidas->Name = L"labvidas";
			this->labvidas->Size = System::Drawing::Size(0, 13);
			this->labvidas->TabIndex = 4;
			// 
			// labtiempo
			// 
			this->labtiempo->AutoSize = true;
			this->labtiempo->BackColor = System::Drawing::Color::Transparent;
			this->labtiempo->ForeColor = System::Drawing::Color::DarkRed;
			this->labtiempo->Location = System::Drawing::Point(219, 26);
			this->labtiempo->Name = L"labtiempo";
			this->labtiempo->Size = System::Drawing::Size(0, 13);
			this->labtiempo->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 593);
			this->Controls->Add(this->labtiempo);
			this->Controls->Add(this->labvidas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext ^bc = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics ^bg = bc->Allocate(gr, this->ClientRectangle);
		Color ^back = gcnew Color();
		bg->Graphics->Clear(Color::White);
		labvidas->Text = objjugador->get_vidas().ToString();
		labtiempo->Text = time.ToString();
		time--;
		if (time==0)
		{
			nivel++;
			if (nivel==1)
			{
				pasarnivel1 = true;
			}
			if (nivel == 2)
			{
				pasarnivel2 = true;
			}
			if (nivel == 3)
			{
				pasarnivel3 = true;
			}
			if (nivel == 4)
			{
				pasarnivel4 = true;
			}
			
			time = 200;

		}

//NIVEL 0************************************************************************************************
		if (nivel==0)
		{
			NumVecesCG = 4;
			NumVecesCM = 4;
			NumVecesCP = 0;
			objmapas->mostrar(bg->Graphics, imagenes[nivel]);
			objjugador->Mover(bg->Graphics);
			

			//colision circulo mediano
			for (int i = 0; i < arreglocm->get_N(); i++)
			{
				if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocm->obtener(i)->get_rectangle()))

				{
					objjugador->set_x(400);
					objjugador->set_y(400);
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo peque�o
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			if (contadorCG == 50 && CG == true)
			{
				if (arreglocg->get_N()<NumVecesCG)
				{
					CirculoG* obj2 = new CirculoG();
					obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					obj2->cambiar_dx_dy(4,4);
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
			if (contadorCM == 30&&CM==true)
			{
				if (arreglocm->get_N()<NumVecesCM)
				{
					CirculoM* objM = new CirculoM();
					objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objM->cambiar_dx_dy(4,4);
					objM->cambiar_imagen("spritemediano.png");
					arreglocm->agregar(objM);
				}
				contadorCM = 0;
			}
			contadorCM++;
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				arreglocm->obtener(i)->Mover(bg->Graphics);
			}
			//circulo peque�o
			if (contadorCP == 30&&CP==true)
			{
				if (arreglocp->get_N()<NumVecesCP)
				{
					CirculoP* objCP;
					objCP = new CirculoP();
					objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objCP->cambiar_dx_dy(1, 1);
					objCP->cambiar_imagen("spritepeque�o.png");
					arreglocp->agregar(objCP);
				}
				contadorCP = 0;
			}
			contadorCP++;
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				arreglocp->obtener(i)->Mover(bg->Graphics, objjugador->get_x(), objjugador->get_y(), objjugador->get_ancho(), objjugador->get_alto());

			}
		}
		if (pasarnivel1==true&&aux1==true)
		{
			for (int i=0; i<arreglocg->get_N();i++)
			{
				delete arreglocg->obtener(i);
			}
				arreglocg->set_N(0);

			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
				arreglocm->set_N(0);
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
				arreglocp->set_N(0);
				aux1 = false;
				CG = true;
				CM = true;
				CP = true;
		}
//NIVEL 1************************************************************************************************
		if (nivel==1)
		{
			NumVecesCG = 2;
			NumVecesCM = 4;
			NumVecesCP = 1;
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo peque�o
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			if (contadorCG == 50 && CG == true)
			{
				if (arreglocg->get_N()<NumVecesCG)
				{
					CirculoG* obj2 = new CirculoG();
					obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					obj2->cambiar_dx_dy(5,5);
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
			if (contadorCM == 30 && CM == true)
			{
				if (arreglocm->get_N()<NumVecesCM)
				{
					CirculoM* objM = new CirculoM();
					objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objM->cambiar_dx_dy(5, 5);
					objM->cambiar_imagen("spritemediano.png");
					arreglocm->agregar(objM);
				}
				contadorCM = 0;
			}
			contadorCM++;
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				arreglocm->obtener(i)->Mover(bg->Graphics);
			}
			//circulo peque�o
			if (contadorCP == 30 && CP == true)
			{
				if (arreglocp->get_N()<NumVecesCP)
				{
					CirculoP* objCP;
					objCP = new CirculoP();
					objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objCP->cambiar_dx_dy(1, 1);
					objCP->cambiar_imagen("spritepeque�o.png");
					arreglocp->agregar(objCP);
				}
				contadorCP = 0;
			}
			contadorCP++;
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				arreglocp->obtener(i)->Mover(bg->Graphics, objjugador->get_x(), objjugador->get_y(), objjugador->get_ancho(), objjugador->get_alto());

			}
		}

		if (pasarnivel2 == true && aux2 == true)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);

			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			aux2 = false;
			CG = true;
			CM = true;
			CP = true;
		}
//NIVEL 2************************************************************************************************
		if (nivel == 2)
		{
			NumVecesCG = 1;
			NumVecesCM = 2;
			NumVecesCP = 1;
			objmapas->mostrar(bg->Graphics, imagenes[nivel]);
			objjugador->Mover(bg->Graphics);
			//objcirculo->Mover(bg->Graphics);
			//agregar un obj circulo Grande


			//colision circulo mediano
			for (int i = 0; i < arreglocm->get_N(); i++)
			{
				if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocm->obtener(i)->get_rectangle()))

				{
					
					objjugador->set_x(400);
					objjugador->set_y(400);

					//vidas --
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo grande
			for (int i = 0; i < arreglocg->get_N(); i++)
			{
				if (objjugador->get_rectangle_jugador().IntersectsWith(arreglocg->obtener(i)->get_rectangle()))

				{
					
					objjugador->set_x(400);
					objjugador->set_y(400);

					//vidas --
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo peque�o
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			if (contadorCG == 50 && CG == true)
			{
				if (arreglocg->get_N()<NumVecesCG)
				{
					CirculoG* obj2 = new CirculoG();
					obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					obj2->cambiar_dx_dy(6,6);
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
			if (contadorCM == 30 && CM == true)
			{
				if (arreglocm->get_N()<NumVecesCM)
				{
					CirculoM* objM = new CirculoM();
					objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objM->cambiar_dx_dy(6,6);
					objM->cambiar_imagen("spritemediano.png");
					arreglocm->agregar(objM);
				}
				contadorCM = 0;
			}
			contadorCM++;
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				arreglocm->obtener(i)->Mover(bg->Graphics);
			}
			//circulo peque�o
			if (contadorCP == 30 && CP == true)
			{
				if (arreglocp->get_N()<NumVecesCP)
				{
					CirculoP* objCP;
					objCP = new CirculoP();
					objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objCP->cambiar_dx_dy(3, 3);
					objCP->cambiar_imagen("spritepeque�o.png");
					arreglocp->agregar(objCP);
				}
				contadorCP = 0;
			}
			contadorCP++;
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				arreglocp->obtener(i)->Mover(bg->Graphics, objjugador->get_x(), objjugador->get_y(), objjugador->get_ancho(), objjugador->get_alto());

			}
		}
		if (pasarnivel3 == true && aux3 == true)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);

			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			aux3 = false;
			CG = true;
			CM = true;
			CP = true;
		}
//NIVEL 3************************************************************************************************
		if (nivel == 3)
		{
			NumVecesCG = 2;
			NumVecesCM = 3;
			NumVecesCP = 2;
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo peque�o
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			if (contadorCG == 50 && CG == true)
			{
				if (arreglocg->get_N()<NumVecesCG)
				{
					CirculoG* obj2 = new CirculoG();
					obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					obj2->cambiar_dx_dy(6,6);
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
			if (contadorCM == 100 && CM == true)
			{
				if (arreglocm->get_N()<NumVecesCM)
				{
					CirculoM* objM = new CirculoM();
					objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objM->cambiar_dx_dy(6,6);
					objM->cambiar_imagen("spritemediano.png");
					arreglocm->agregar(objM);
				}
				contadorCM = 0;
			}
			contadorCM++;
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				arreglocm->obtener(i)->Mover(bg->Graphics);
			}
			//circulo peque�o
			if (contadorCP == 80 && CP == true)
			{
				if (arreglocp->get_N()<NumVecesCP)
				{
					CirculoP* objCP;
					objCP = new CirculoP();
					objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objCP->cambiar_dx_dy(2, 2);
					objCP->cambiar_imagen("spritepeque�o.png");
					arreglocp->agregar(objCP);
				}
				contadorCP = 0;
			}
			contadorCP++;
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				arreglocp->obtener(i)->Mover(bg->Graphics, objjugador->get_x(), objjugador->get_y(), objjugador->get_ancho(), objjugador->get_alto());

			}
		}
		if (pasarnivel4 == true && aux4 == true)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);

			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			aux4 = false;
			CG = true;
			CM = true;
			CP = true;
		}

//NIVEL 4************************************************************************************************
		if (nivel == 4)
		{
			NumVecesCG = 4;
			NumVecesCM = 2;
			NumVecesCP = 1;
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			//colision circulo peque�o
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
					int vidas = objjugador->get_vidas();
					vidas--;
					objjugador->set_vidas(vidas);
					if (vidas == 0)
					{
						nivel = 6;
					}

				}
			}
			if (contadorCG == 50 && CG == true)
			{
				if (arreglocg->get_N()<NumVecesCG)
				{
					CirculoG* obj2 = new CirculoG();
					obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					obj2->cambiar_dx_dy(8,8);
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
			if (contadorCM == 30 && CM == true)
			{
				if (arreglocm->get_N()<NumVecesCM)
				{
					CirculoM* objM = new CirculoM();
					objM->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objM->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objM->cambiar_dx_dy(8,8);
					objM->cambiar_imagen("spritemediano.png");
					arreglocm->agregar(objM);
				}
				contadorCM = 0;
			}
			contadorCM++;
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				arreglocm->obtener(i)->Mover(bg->Graphics);
			}
			//circulo peque�o
			if (contadorCP == 80 && CP == true)
			{
				if (arreglocp->get_N()<NumVecesCP)
				{
					CirculoP* objCP;
					objCP = new CirculoP();
					objCP->cambiar_x(d->VisibleClipBounds.Width / (2.5));
					objCP->cambiar_y(d->VisibleClipBounds.Height / (2.5));
					objCP->cambiar_dx_dy(2, 2);
					objCP->cambiar_imagen("spritepeque�o.png");
					arreglocp->agregar(objCP);
				}
				contadorCP = 0;
			}
			contadorCP++;
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				arreglocp->obtener(i)->Mover(bg->Graphics, objjugador->get_x(), objjugador->get_y(), objjugador->get_ancho(), objjugador->get_alto());

			}
		}

//NIVEL 5************************************************************************************************
		if (nivel==5)
		{
			objmapas->mostrar(bg->Graphics, imagenes[nivel]);
		}

//NIVEL 6************************************************************************************************
		if (nivel == 6)
		{
			objmapas->mostrar(bg->Graphics, imagenes[nivel]);
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
		case Keys::Z:
		{
			if (nivel==0)
			{
				for (int i = 0; i < arreglocg->get_N(); i++)
				{
					arreglocg->obtener(i)->cambiar_dx_dy(4,4);
				}
				for (int i = 0; i < arreglocm->get_N(); i++)
				{
					arreglocm->obtener(i)->cambiar_dx_dy(4, 4);
				}
				
			}
			if (nivel==1)
			{
				for (int i = 0; i < arreglocg->get_N(); i++)
				{
					arreglocg->obtener(i)->cambiar_dx_dy(5, 5);
				}
				for (int i = 0; i < arreglocm->get_N(); i++)
				{
					arreglocm->obtener(i)->cambiar_dx_dy(5, 5);
				}
				for (int i = 0; i < arreglocp->get_N(); i++)
				{
					arreglocp->obtener(i)->cambiar_dx_dy(1, 1);
				}
			}
			if (nivel == 2)
			{
				for (int i = 0; i < arreglocg->get_N(); i++)
				{
					arreglocg->obtener(i)->cambiar_dx_dy(6, 6);
				}
				for (int i = 0; i < arreglocm->get_N(); i++)
				{
					arreglocm->obtener(i)->cambiar_dx_dy(6, 6);
				}
				for (int i = 0; i < arreglocp->get_N(); i++)
				{
					arreglocp->obtener(i)->cambiar_dx_dy(3, 3);
				}
			}
			if (nivel == 3)
			{
				for (int i = 0; i < arreglocg->get_N(); i++)
				{
					arreglocg->obtener(i)->cambiar_dx_dy(6, 6);
				}
				for (int i = 0; i < arreglocm->get_N(); i++)
				{
					arreglocm->obtener(i)->cambiar_dx_dy(6, 6);
				}
				for (int i = 0; i < arreglocp->get_N(); i++)
				{
					arreglocp->obtener(i)->cambiar_dx_dy(2, 2);
				}
			}
			if (nivel == 4)
			{
				for (int i = 0; i < arreglocg->get_N(); i++)
				{
					arreglocg->obtener(i)->cambiar_dx_dy(8, 8);
				}
				for (int i = 0; i < arreglocm->get_N(); i++)
				{
					arreglocm->obtener(i)->cambiar_dx_dy(8, 8);
				}
				for (int i = 0; i < arreglocp->get_N(); i++)
				{
					arreglocp->obtener(i)->cambiar_dx_dy(2, 2);
				}
			}
			break;
		}
		default:
			objjugador->setdireccion(ninguna);
			break;
		}
	
	}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
{
	switch (e->KeyCode)
	{
	case Keys::G:
	{
		if (nivel==0)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);
			CG = false;
		}
		if (nivel == 1)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);
			CG = false;
		}
		if (nivel == 2)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);
			CG = false;
		}
		if (nivel == 3)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);
			CG = false;
		}
		if (nivel == 4)
		{
			for (int i = 0; i<arreglocg->get_N(); i++)
			{
				delete arreglocg->obtener(i);
			}
			arreglocg->set_N(0);
			CG = false;
		}
		break;
	}
	case Keys::P:
	{
		if (nivel == 0)
		{
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			CP = false;
		}
		if (nivel == 1)
		{
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			CP = false;
		}
		if (nivel == 2)
		{
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			CP = false;
		}
		if (nivel == 3)
		{
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			CP = false;
		}
		if (nivel == 4)
		{
			for (int i = 0; i<arreglocp->get_N(); i++)
			{
				delete arreglocp->obtener(i);
			}
			arreglocp->set_N(0);
			CP = false;
		}
		break;
	}
	case Keys::M:
	{
		if (nivel == 0)
		{
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			CM = false;
		}
		if (nivel == 1)
		{
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			CM = false;
		}
		if (nivel == 2)
		{
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			CM = false;
		}
		if (nivel == 3)
		{
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			CM = false;
		}
		if (nivel == 4)
		{
			for (int i = 0; i<arreglocm->get_N(); i++)
			{
				delete arreglocm->obtener(i);
			}
			arreglocm->set_N(0);
			CM = false;
		}
		break;
	}
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
	case Keys::Z:
	{
		for (int i = 0; i < arreglocg->get_N(); i++)
		{
			arreglocg->obtener(i)->cambiar_dx_dy(0.5, 0.5);
		}
		for (int i = 0; i < arreglocm->get_N(); i++)
		{
			arreglocm->obtener(i)->cambiar_dx_dy(0.5, 0.5);
		}
		for (int i = 0; i < arreglocp->get_N(); i++)
		{
			arreglocp->obtener(i)->cambiar_dx_dy(0.2, 0.2);
		}
		break;
	}
	case Keys::C:
		nivel++;
		if (nivel == 7)
		{
			nivel = 0;
		}
		
		if (nivel==1)
		{
			pasarnivel1 = true;

		}
		if (nivel == 2)
		{
			pasarnivel2 = true;
		}
		if (nivel == 3)
		{
			pasarnivel3 = true;
		}
		if (nivel == 4)
		{
			pasarnivel4 = true;
		}
		if (nivel == 0)
		{
			pasarnivel0 = true;
		}
		break;
	default:
		break;
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
