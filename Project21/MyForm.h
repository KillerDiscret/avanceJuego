#pragma once
#include "CirculoGrande.h"
#include "ArregloCG.h"
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
			objcirculo = new CirculoG();
			objcirculo->cambiar_x(d->VisibleClipBounds.Width/(2.5));
			objcirculo->cambiar_y(d->VisibleClipBounds.Height/(2.5));
			objcirculo->cambiar_imagen("prueba2.png");
			arreglocg = new Arrcg();
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
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		CirculoG*objcirculo;
		Arrcg* arreglocg;
		Graphics^d;
		int veces =0;
		int contador = 0;

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
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext ^bc = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics ^bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);
		objcirculo->Mover(bg->Graphics);
		//agregar un obj circulo Grande
		if (contador==50)
		{
			if (veces<=3)
			{
				CirculoG* obj2 = new CirculoG();
				obj2->cambiar_x(d->VisibleClipBounds.Width / (2.5));
				obj2->cambiar_y(d->VisibleClipBounds.Height / (2.5));
				obj2->cambiar_imagen("prueba2.png");
				arreglocg->agregar(obj2);
				veces++;
			}
			contador = 0;
		}
		contador++;
		for (int i = 0; i<arreglocg->get_N(); i++)
		{
			arreglocg->obtener(i)->Mover(bg->Graphics);
		}


		bg->Render(gr);
		delete gr;
		delete bc;
		delete bg;
	}
	};
}
