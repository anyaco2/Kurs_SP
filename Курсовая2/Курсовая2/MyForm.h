#pragma once

namespace Kurs {

#include <math.h>

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Drawing::Imaging;


	int height, width, center[2], angle;
	float p1[2], p2[2], p3[2], p4[2];
	bool Triangle = true;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
		Pen^ pen;
		Bitmap^ image;
		Graphics^ gr;
		SolidBrush^ brush;

		

	private: System::Windows::Forms::Button^ stop;
	private: System::Windows::Forms::Label^ Label;
	private: System::Windows::Forms::NumericUpDown^ numeric;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ numeric1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ RAngle;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::Button^ start;

	public:

		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;
	private:

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

#pragma region Windows Form Designer generated code

/// <summary>
/// Требуемый метод для поддержки конструктора — не изменяйте
/// содержимое этого метода с помощью редактора кода.
/// </summary>

		void InitializeComponent(void)

		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->start = (gcnew System::Windows::Forms::Button());
			this->stop = (gcnew System::Windows::Forms::Button());
			this->Label = (gcnew System::Windows::Forms::Label());
			this->numeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->RAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeric1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RAngle))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::Color::AliceBlue;
			this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox->Location = System::Drawing::Point(270, 22);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(471, 360);
			this->pictureBox->TabIndex = 2;
			this->pictureBox->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// start
			// 
			this->start->BackColor = System::Drawing::Color::DeepPink;
			this->start->FlatAppearance->BorderSize = 0;
			this->start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->start->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start->ForeColor = System::Drawing::Color::AliceBlue;
			this->start->Location = System::Drawing::Point(270, 405);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(201, 40);
			this->start->TabIndex = 3;
			this->start->Text = L"Вращать";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &MyForm::startR);
			// 
			// stop
			// 
			this->stop->BackColor = System::Drawing::Color::DeepPink;
			this->stop->FlatAppearance->BorderSize = 0;
			this->stop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->stop->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->stop->ForeColor = System::Drawing::Color::AliceBlue;
			this->stop->Location = System::Drawing::Point(541, 405);
			this->stop->Name = L"stop";
			this->stop->Size = System::Drawing::Size(200, 40);
			this->stop->TabIndex = 4;
			this->stop->Text = L"Остановить";
			this->stop->UseVisualStyleBackColor = false;
			this->stop->Click += gcnew System::EventHandler(this, &MyForm::stopR);
			// 
			// Label
			// 
			this->Label->AutoSize = true;
			this->Label->BackColor = System::Drawing::Color::White;
			this->Label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Label->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Label->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Label->Location = System::Drawing::Point(15, 63);
			this->Label->Margin = System::Windows::Forms::Padding(0);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(60, 19);
			this->Label->TabIndex = 9;
			this->Label->Text = L"Высота:";
			// 
			// numeric
			// 
			this->numeric->BackColor = System::Drawing::Color::WhiteSmoke;
			this->numeric->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.18868F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->numeric->Location = System::Drawing::Point(19, 84);
			this->numeric->Margin = System::Windows::Forms::Padding(2);
			this->numeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {150, 0, 0, 0});
			this->numeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->numeric->Name = L"numeric";
			this->numeric->Size = System::Drawing::Size(200, 19);
			this->numeric->TabIndex = 11;
			this->numeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {90, 0, 0, 0});
			this->numeric->ValueChanged += gcnew System::EventHandler(this, &MyForm::changeH);
			// 
			// numeric1
			// 
			this->numeric1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->numeric1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numeric1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.18868F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->numeric1->Location = System::Drawing::Point(19, 136);
			this->numeric1->Margin = System::Windows::Forms::Padding(2);
			this->numeric1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->numeric1->Name = L"numeric1";
			this->numeric1->Size = System::Drawing::Size(200, 19);
			this->numeric1->TabIndex = 11;
			this->numeric1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {40, 0, 0, 0});
			this->numeric1->ValueChanged += gcnew System::EventHandler(this, &MyForm::changeW);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 115);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 19);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Ширина:";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Window;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Red", L"Brown", L"Green", L"Purple", L"Dark Blue", 
				L"Black"});
			this->comboBox1->Location = System::Drawing::Point(20, 240);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(199, 21);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::colorApp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F));
			this->label2->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label2->Location = System::Drawing::Point(15, 219);
			this->label2->Margin = System::Windows::Forms::Padding(0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 19);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Цвет линий:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Orange", L"Violet", L"Coral", L"White", L"Light Green", 
				L"Moccasin"});
			this->comboBox2->Location = System::Drawing::Point(20, 295);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(199, 21);
			this->comboBox2->TabIndex = 17;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::changeColor);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F));
			this->label3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label3->Location = System::Drawing::Point(16, 274);
			this->label3->Margin = System::Windows::Forms::Padding(0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 19);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Цвет фона:";
			// 
			// RAngle
			// 
			this->RAngle->BackColor = System::Drawing::Color::WhiteSmoke;
			this->RAngle->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->RAngle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->RAngle->Location = System::Drawing::Point(20, 188);
			this->RAngle->Margin = System::Windows::Forms::Padding(2);
			this->RAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {6, 0, 0, 0});
			this->RAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RAngle->Name = L"RAngle";
			this->RAngle->Size = System::Drawing::Size(199, 19);
			this->RAngle->TabIndex = 19;
			this->RAngle->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RAngle->ValueChanged += gcnew System::EventHandler(this, &MyForm::SpeedR);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(16, 167);
			this->label4->Margin = System::Windows::Forms::Padding(0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 19);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Скорость:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label5->Location = System::Drawing::Point(15, 33);
			this->label5->Margin = System::Windows::Forms::Padding(0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 19);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Выберите:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(773, 488);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->RAngle);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numeric1);
			this->Controls->Add(this->numeric);
			this->Controls->Add(this->Label);
			this->Controls->Add(this->stop);
			this->Controls->Add(this->start);
			this->Controls->Add(this->pictureBox);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TRIANLE 3D";
			this->Load += gcnew System::EventHandler(this, &MyForm::onLoad);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numeric1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RAngle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
public: System::Void onLoad(System::Object^ sender, System::EventArgs^ e)
{

	height = (int)numeric->Value;
	width = (int)numeric1->Value;
	center[0] = pictureBox->Width / 2;
	center[1] = pictureBox->Height / 2;
	image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	pictureBox->Image = image;
	gr = Graphics::FromImage(image);
	colorApp(sender, e);
	
}

private: System::Void coordinate()
{
	p1[0] = center[0] - width / 2;
	p1[1] = center[1]+ height / 2;
	p2[0] = center[0] + width;
	p2[1] = center[1] + height / 2;
	p3[0] = center[0] + (1.6 * width);
	p3[1] = center[1] + (0.6 * height);
	p4[0] = center[0] + width;
	p4[1] = center[1] - height / 2;
}

private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
{ 
	angle = (int)RAngle->Value;
	float alpha((-15 * angle) * 3.14 / 360);
	gr->Clear(pictureBox->BackColor);
	float oldp = p1[0];
	p1[0] = (oldp - center[0]) * cos(alpha) - (p1[1] - center[1]) * sin(alpha) + center[0];
	p1[1] = (oldp - center[0]) * sin(alpha) + (p1[1] - center[1]) * cos(alpha) + center[1];
	oldp = p2[0];
	p2[0] = (oldp - center[0]) * cos(alpha) - (p2[1] - center[1]) * sin(alpha) + center[0];
	p2[1] = (oldp - center[0]) * sin(alpha) + (p2[1] - center[1]) * cos(alpha) + center[1];
	oldp = p3[0];
	p3[0] = (oldp - center[0]) * cos(alpha) - (p3[1] - center[1]) * sin(alpha) + center[0];
	p3[1] = (oldp - center[0]) * sin(alpha) + (p3[1] - center[1]) * cos(alpha) + center[1];
	oldp = p4[0];
	p4[0] = (oldp - center[0]) * cos(alpha) - (p4[1] - center[1]) * sin(alpha) + center[0];
	p4[1] = (oldp - center[0]) * sin(alpha) + (p4[1] - center[1]) * cos(alpha) + center[1];

	Triangle = false;
	colorApp(sender, e);
	Triangle = true;
	pictureBox->Refresh();
}



private: System::Void startR(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled = true;
}

private: System::Void stopR(System::Object^ sender, System::EventArgs^ e)
{
	timer->Enabled = false;
}

private: System::Void changeH(System::Object^ sender, System::EventArgs^ e)

{
	height = (int)numeric->Value;
	if (timer->Enabled) coordinate();
	else colorApp(sender, e);

}
private: System::Void changeW(System::Object^ sender, System::EventArgs^ e)

{
	width = (int)numeric1->Value;
	if (timer->Enabled) coordinate();
	else colorApp(sender, e);
}

private: System::Void colorApp(System::Object^ sender, System::EventArgs^ e) {
	gr->Clear(pictureBox->BackColor);
	array <Brush^>^ Bruh = gcnew array <Brush^> {Brushes::DeepPink};
	array<Pen^>^ ge2 = gcnew array <Pen^>{ Pens::Red, Pens::Brown, Pens::Green, Pens::Purple, Pens::DarkBlue, Pens::Black};
	int x;
	if (comboBox1->SelectedIndex == 0) {
		x = 0;
	}
	else if (comboBox1->SelectedIndex == 1) {
		x = 1;
	}
	else if (comboBox1->SelectedIndex == 2) {
		x = 2;
	}
	else if (comboBox1->SelectedIndex == 3) {
		x = 3;
	}
	else if (comboBox1->SelectedIndex == 4) {
		x = 4;
	}
	else x = 5;
	if (Triangle) {
		coordinate();
	}
	array<Point>^ points1 = gcnew array<Point>{ Point(p1[0], p1[1]), Point(p2[0], p2[1]), Point(p3[0], p3[1])};
	gr->FillPolygon(Bruh[0], points1);
	array<Point>^ points2 = gcnew array<Point>{ Point(p1[0], p1[1]), Point(p2[0], p2[1]), Point(p4[0], p4[1])};
	gr->FillPolygon(Bruh[0], points2);
	array<Point>^ points3 = gcnew array<Point>{ Point(p2[0], p2[1]), Point(p3[0], p3[1]), Point(p4[0], p4[1])};
	gr->FillPolygon(Bruh[0], points3);
	gr->DrawLine(ge2[x], p1[0], p1[1], p2[0], p2[1]);
	gr->DrawLine(ge2[x], p1[0], p1[1], p3[0], p3[1]);
	gr->DrawLine(ge2[x], p1[0], p1[1], p4[0], p4[1]);
	gr->DrawLine(ge2[x], p2[0], p2[1], p3[0], p3[1]);
	gr->DrawLine(ge2[x], p2[0], p2[1], p4[0], p4[1]);
	gr->DrawLine(ge2[x], p3[0], p3[1], p4[0], p4[1]);
	

	
	pictureBox->Refresh();
}
private: System::Void changeColor(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox2->SelectedIndex == 0) {
		pictureBox->BackColor = Color::Orange;
	}
	else if (comboBox2->SelectedIndex == 1) {
		pictureBox->BackColor = Color::Violet;
	}
	else if (comboBox2->SelectedIndex == 2) {
		pictureBox->BackColor = Color::Coral;
	}
	else if (comboBox2->SelectedIndex == 3) {
		pictureBox->BackColor = Color::White;
	}
	else if (comboBox2->SelectedIndex == 4) {
		pictureBox->BackColor = Color::LightGreen;
	}
	else if (comboBox2->SelectedIndex == 5) {
		pictureBox->BackColor = Color::AliceBlue;
	}
	gr->Clear(pictureBox->BackColor);

	if (!timer->Enabled) {
		Triangle = false;
		colorApp(sender, e);
		Triangle = true;
	}
	pictureBox->Refresh();
}

private: System::Void SpeedR(System::Object^ sender, System::EventArgs^ e) {

}

};

}
