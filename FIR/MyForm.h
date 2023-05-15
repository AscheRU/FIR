#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <complex>
#include <math.h>
#include <typeinfo>
#include <fstream>
#include <String>





namespace FIR {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	
	
	struct WAVHEADER
	{
		char                chunkId[4];                 // Информация о формате файла (RIFF), Содержит символы “RIFF” в ASCII кодировке;
		unsigned long       ChunkSize;                  // Размер без  chunkId[4];
		char                format[4];                  // Формат потоковых данных (WAVE);
		char                subchunk1Id[4];             // Описание параметров WAV-файла (fmt-chunk);
		unsigned long       subchunk1Size;              // Размер подструктуры  subchunk1  (16 байт);
		unsigned short      audioFormat;                // Аудио формат (PCM = 1);
		unsigned short      nChannels;                  // Количество каналов (Моно = 1, Стерео = 2);
		unsigned long       SamplesRate;                // Частота дискретизации в Гц;
		unsigned long       ByteRate;                   // Кол-во передаваемых байт в секунду воспроизведения;
		unsigned short      blockAlign;                 // Размер сэмпла в байтах 16 бит = 2 байта моно, 32 бита = 4 байта стерео (включая все каналы);
		unsigned short      BitsPerSample;              // Количество бит в сэмпле. Так называемая “глубина” или точность звучания. 8 бит, 16 бит и т.д. /// битов на отсчет
		char                Subchunk2ID[4];             // Символы "Data", начало чанка данных;
		unsigned long       Subchunk2Size;              // Размер области данных в байтах;

		unsigned char data[128];						//128 кол-во сэмплов
	};

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
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
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::TextBox^  tBox1;
	private: System::Windows::Forms::TextBox^  tBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  buttonFIR;
	private: System::Windows::Forms::Button^  button_openF;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  labelName1;
	private: System::Windows::Forms::Label^  labelName4;
	private: System::Windows::Forms::Label^  labelName3;
	private: System::Windows::Forms::Label^  labelName2;
	private: System::Windows::Forms::Label^  labelValue1;
	private: System::Windows::Forms::Label^  labelValue2;
	private: System::Windows::Forms::Label^  labelValue3;
	private: System::Windows::Forms::Label^  labelValue4;
	private: System::Windows::Forms::Label^  labelStat;







	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonFIR = (gcnew System::Windows::Forms::Button());
			this->button_openF = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->labelName1 = (gcnew System::Windows::Forms::Label());
			this->labelName4 = (gcnew System::Windows::Forms::Label());
			this->labelName3 = (gcnew System::Windows::Forms::Label());
			this->labelName2 = (gcnew System::Windows::Forms::Label());
			this->labelValue1 = (gcnew System::Windows::Forms::Label());
			this->labelValue2 = (gcnew System::Windows::Forms::Label());
			this->labelValue3 = (gcnew System::Windows::Forms::Label());
			this->labelValue4 = (gcnew System::Windows::Forms::Label());
			this->labelStat = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_exit
			// 
			this->btn_exit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_exit->FlatAppearance->BorderSize = 0;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_exit->Location = System::Drawing::Point(924, 3);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(23, 23);
			this->btn_exit->TabIndex = 0;
			this->btn_exit->Text = L"X";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MyForm::btn_exit_Click);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(418, 12);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::White;
			series1->Legend = L"Legend1";
			series1->LegendText = L"ИХ";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(500, 300);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart";
			// 
			// chart2
			// 
			this->chart2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Alignment = System::Drawing::StringAlignment::Center;
			legend2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(418, 318);
			this->chart2->Name = L"chart2";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::White;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Спектр ИХ";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(500, 300);
			this->chart2->TabIndex = 2;
			this->chart2->Text = L"chart";
			// 
			// tBox1
			// 
			this->tBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->tBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBox1->Location = System::Drawing::Point(58, 49);
			this->tBox1->Name = L"tBox1";
			this->tBox1->Size = System::Drawing::Size(100, 26);
			this->tBox1->TabIndex = 3;
			// 
			// tBox2
			// 
			this->tBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->tBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tBox2->Location = System::Drawing::Point(58, 77);
			this->tBox2->Name = L"tBox2";
			this->tBox2->Size = System::Drawing::Size(100, 26);
			this->tBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(24, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(296, 23);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Введите необходимые частоты:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"от";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"до";
			// 
			// buttonFIR
			// 
			this->buttonFIR->Location = System::Drawing::Point(164, 49);
			this->buttonFIR->Name = L"buttonFIR";
			this->buttonFIR->Size = System::Drawing::Size(95, 54);
			this->buttonFIR->TabIndex = 8;
			this->buttonFIR->Text = L"Расчитать ИХ";
			this->buttonFIR->UseVisualStyleBackColor = true;
			this->buttonFIR->Click += gcnew System::EventHandler(this, &MyForm::buttonFIR_Click);
			// 
			// button_openF
			// 
			this->button_openF->Location = System::Drawing::Point(58, 139);
			this->button_openF->Name = L"button_openF";
			this->button_openF->Size = System::Drawing::Size(100, 52);
			this->button_openF->TabIndex = 9;
			this->button_openF->Text = L"Открыть файл";
			this->button_openF->UseVisualStyleBackColor = true;
			this->button_openF->Click += gcnew System::EventHandler(this, &MyForm::button_openF_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"(*.wav)|*.wav";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(58, 197);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 52);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Обработать файл";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(58, 260);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 52);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Сохранить файл";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// labelName1
			// 
			this->labelName1->AutoSize = true;
			this->labelName1->Location = System::Drawing::Point(55, 372);
			this->labelName1->Name = L"labelName1";
			this->labelName1->Size = System::Drawing::Size(171, 17);
			this->labelName1->TabIndex = 12;
			this->labelName1->Text = L"Частота дискретизации:";
			// 
			// labelName4
			// 
			this->labelName4->AutoSize = true;
			this->labelName4->Location = System::Drawing::Point(55, 474);
			this->labelName4->Name = L"labelName4";
			this->labelName4->Size = System::Drawing::Size(148, 17);
			this->labelName4->TabIndex = 13;
			this->labelName4->Text = L"Количество каналов:";
			// 
			// labelName3
			// 
			this->labelName3->AutoSize = true;
			this->labelName3->Location = System::Drawing::Point(55, 440);
			this->labelName3->Name = L"labelName3";
			this->labelName3->Size = System::Drawing::Size(98, 17);
			this->labelName3->TabIndex = 14;
			this->labelName3->Text = L"Бит в сэмпле:";
			// 
			// labelName2
			// 
			this->labelName2->AutoSize = true;
			this->labelName2->Location = System::Drawing::Point(55, 406);
			this->labelName2->Name = L"labelName2";
			this->labelName2->Size = System::Drawing::Size(149, 17);
			this->labelName2->TabIndex = 15;
			this->labelName2->Text = L"Количество семплов:";
			// 
			// labelValue1
			// 
			this->labelValue1->AutoSize = true;
			this->labelValue1->Location = System::Drawing::Point(232, 372);
			this->labelValue1->Name = L"labelValue1";
			this->labelValue1->Size = System::Drawing::Size(13, 17);
			this->labelValue1->TabIndex = 16;
			this->labelValue1->Text = L"-";
			// 
			// labelValue2
			// 
			this->labelValue2->AutoSize = true;
			this->labelValue2->Location = System::Drawing::Point(232, 406);
			this->labelValue2->Name = L"labelValue2";
			this->labelValue2->Size = System::Drawing::Size(13, 17);
			this->labelValue2->TabIndex = 17;
			this->labelValue2->Text = L"-";
			// 
			// labelValue3
			// 
			this->labelValue3->AutoSize = true;
			this->labelValue3->Location = System::Drawing::Point(232, 440);
			this->labelValue3->Name = L"labelValue3";
			this->labelValue3->Size = System::Drawing::Size(13, 17);
			this->labelValue3->TabIndex = 18;
			this->labelValue3->Text = L"-";
			// 
			// labelValue4
			// 
			this->labelValue4->AutoSize = true;
			this->labelValue4->Location = System::Drawing::Point(232, 474);
			this->labelValue4->Name = L"labelValue4";
			this->labelValue4->Size = System::Drawing::Size(13, 17);
			this->labelValue4->TabIndex = 19;
			this->labelValue4->Text = L"-";
			// 
			// labelStat
			// 
			this->labelStat->AutoSize = true;
			this->labelStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelStat->ForeColor = System::Drawing::Color::Snow;
			this->labelStat->Location = System::Drawing::Point(55, 508);
			this->labelStat->Name = L"labelStat";
			this->labelStat->Size = System::Drawing::Size(0, 20);
			this->labelStat->TabIndex = 20;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->ClientSize = System::Drawing::Size(950, 650);
			this->Controls->Add(this->labelStat);
			this->Controls->Add(this->labelValue4);
			this->Controls->Add(this->labelValue3);
			this->Controls->Add(this->labelValue2);
			this->Controls->Add(this->labelValue1);
			this->Controls->Add(this->labelName2);
			this->Controls->Add(this->labelName3);
			this->Controls->Add(this->labelName4);
			this->Controls->Add(this->labelName1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_openF);
			this->Controls->Add(this->buttonFIR);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tBox2);
			this->Controls->Add(this->tBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->btn_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"КИХ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: double a, b;
	private: double x = 0;
	private: double *data = new double[128];
	private: double *filedata = new double[x];
	private: double *data_out = new double[128];
	private: complex<double> *data_out_my = new complex<double>[128];
			 //private: double *data_out_my = new double[128];
	private: double *data_result = new double[128];
	private: complex<double> *datamatr = new complex<double>[128];
	private: typedef complex<double> base;
	private: int sampleR = 44100;
	private: const double TwoPi = 6.283185307179586;



			 //выставляет параметры частот по умолчанию, если значения не были введены
	private: void DefaultParams() {
		a = 0;
		b = 5000;

	}

			 //считывание файла в data
	private: void openF() {

		setlocale(0, "");
		FILE *file;
		errno_t error;
		error = fopen_s(&file, "005.wav", "rb");
		if (error)
		{
			cout << "Не удалось открыть файл\n";
			system("pause");
			return;
		}

		WAVHEADER header;
		fread_s(&header, sizeof(WAVHEADER), sizeof(WAVHEADER), 1, file);


		for (int i = 0; i < 128; i++)
		{
			data[i] = static_cast<int>(header.data[i + 10]);
			//cout << data[i] << endl;

		}





		fclose(file);

		//system("pause");
		return;
	}

	private: void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft) {
		int i, j, n, m, Mmax, Istp;
		double Tmpr, Tmpi, Wtmp, Theta;
		double Wpr, Wpi, Wr, Wi;
		double *Tmvl;

		n = Nvl * 2; Tmvl = new double[n];

		for (i = 0; i < n; i += 2) {
			Tmvl[i] = 0;
			Tmvl[i + 1] = AVal[i / 2];
		}

		i = 1; j = 1;
		while (i < n) {
			if (j > i) {
				Tmpr = Tmvl[i]; Tmvl[i] = Tmvl[j]; Tmvl[j] = Tmpr;
				Tmpr = Tmvl[i + 1]; Tmvl[i + 1] = Tmvl[j + 1]; Tmvl[j + 1] = Tmpr;
			}
			i = i + 2; m = Nvl;
			while ((m >= 2) && (j > m)) {
				j = j - m; m = m >> 1;
			}
			j = j + m;
		}

		Mmax = 2;
		while (n > Mmax) {
			Theta = -TwoPi / Mmax; Wpi = sin(Theta);
			Wtmp = sin(Theta / 2); Wpr = Wtmp * Wtmp * 2;
			Istp = Mmax * 2; Wr = 1; Wi = 0; m = 1;

			while (m < Mmax) {
				i = m; m = m + 2; Tmpr = Wr; Tmpi = Wi;
				Wr = Wr - Tmpr * Wpr - Tmpi * Wpi;
				Wi = Wi + Tmpr * Wpi - Tmpi * Wpr;

				while (i < n) {
					j = i + Mmax;
					Tmpr = Wr * Tmvl[j] - Wi * Tmvl[j - 1];
					Tmpi = Wi * Tmvl[j] + Wr * Tmvl[j - 1];

					Tmvl[j] = Tmvl[i] - Tmpr; Tmvl[j - 1] = Tmvl[i - 1] - Tmpi;
					Tmvl[i] = Tmvl[i] + Tmpr; Tmvl[i - 1] = Tmvl[i - 1] + Tmpi;
					i = i + Istp;
				}
			}

			Mmax = Istp;
		}

		for (i = 0; i < Nft; i++) {
			j = i * 2; FTvl[i] = 2 * sqrt(pow(Tmvl[j], 2) + pow(Tmvl[j + 1], 2)) / Nvl;
		}

		delete[]Tmvl;




	}

	private: void FFidft(double *data_out_my, double *data_result) {
		const double TwoPi = 6.283185307179586;

		for (int n = 0; n < 128; ++n) {
			complex<double> sum(0, 0);
			for (int k = 0; k < 128; ++k) {
				sum += data_out_my[k] * std::exp(std::complex<double>(0, 1) * TwoPi * Convert::ToDouble(k) * Convert::ToDouble(n) / 128.0);
			}
			data_result[n] = std::round((1.0 / 128)*sum.real());
		}

	}

			 //построение графиков
	private: void chart(double *masX, complex<double> *masY) {
		double y = 0;
		for (int i = 0; i < 128; i++)
		{
			y = masX[i];
			this->chart1->Series[0]->Points->AddXY(i, y);
		}
		for (int i = 1; i < 65; i++)
		{
			y = fabs(masY[i].real());
			this->chart2->Series[0]->Points->AddXY(i * sampleR / 128, y);
		}
	}

			 //обнуление ненужных частот
	private: void set_zero(complex<double> *data_out_my, double f1, double f2) {
		f1 = round(f1 * 128 / 44100);
		f2 = round(f2 * 128 / 44100);
		cout << endl << f1 << " " << f2 << endl;
		for (int i = 0; i < f1; i++)
		{
			data_out_my[i] *= 0;
		}

		for (int i = f2; i < 128; i++)
		{
			data_out_my[i] *= 0;
		}

	}

	private: void fft(double *data, complex<double> *data_out_my) {
		complex<double> datamatr[128][128];
		complex<double> jCO(0, 1);
		const double TwoPi = 6.283185307179586;
		//datamatr[0][0] = jCO;
		for (int i = 0; i < 128; i++) {
			for (int j = 0; j < 128; j++) {
				datamatr[i][j] = pow(2.7182, -1.0 * jCO * TwoPi / 128.0 * Convert::ToDouble(i) * Convert::ToDouble(j));
			}
		}

		for (int i = 0; i < 128; i++) {
			complex<double> value = (0, 0);
			for (int j = 0; j < 128; j++) {
				value += Convert::ToDouble(data[j]) * datamatr[i][j];
			}
			data_out_my[i] = value;
		}
		cout << data_out_my[0] << "data out my 0" << endl;
		cout << data_out_my[1] << "data out my 0" << endl;


	}

	private: void fftr(complex<double> *data_out_my, complex<double> *data_result) {
		complex<double> datamatr[128][128];
		complex<double> jCO(0, 1);
		const double TwoPi = 6.283185307179586;
		for (int i = 0; i < 128; i++) {
			for (int j = 0; j < 128; j++) {
				datamatr[i][j] = pow(2.7182, jCO * TwoPi / 128.0 * Convert::ToDouble(i) * Convert::ToDouble(j));
			}
		}

		for (int i = 0; i < 128; i++) {
			complex<double> value = 0.0;
			for (int j = 0; j < 128; j++) {
				value += data_out[j] * datamatr[i][j];
			}
			data_result[i] = value * 1.0 / 128.0;
		}
	}


			 //из gpt
	private: void dft(double *data, complex<double> *data_out_my) {
		const double TwoPi = 6.283185307179586;


		for (int k = 0; k < 128; ++k) {
			complex<double> sum(0, 0);
			for (int n = 0; n < 128; ++n) {
				sum += data[n] * std::exp(-1.0 * complex<double>(0, 1) * TwoPi * Convert::ToDouble(k) * Convert::ToDouble(n) / 128.0);
			}
			data_out_my[k] = sum;
		}


		cout << data[0] << endl;
	}

			 //обратное из gpt
	private: void idft(complex<double> *data_out_my, double *data_result) {
		const double TwoPi = 6.283185307179586;

		for (int n = 0; n < 128; ++n) {
			complex<double> sum(0, 0);
			for (int k = 0; k < 128; ++k) {
				sum += data_out_my[k] * std::exp(std::complex<double>(0, 1) * TwoPi * Convert::ToDouble(k) * Convert::ToDouble(n) / 128.0);
			}
			data_result[n] = fabs(std::round((1.0 / 128)*sum.real()));
		}
		cout << endl;
		for (int i = 0; i < 128; i++) {
			cout << data_result[i] << data_out_my[i] << " data result " << data[i] << endl;
		}
	}

			 //кнопка выхода
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}



			 //кнопка расчета ИХ
	private: System::Void buttonFIR_Click(System::Object^  sender, System::EventArgs^  e) {

		//проверка на ввод параметров частот
		if (tBox1->Text == "" || tBox2->Text == "") {
			MessageBox::Show("Введены параметры по умолчанию.", "Параметры отсутствуют.");
			DefaultParams();
		}
		else {
			a = Convert::ToDouble(tBox1->Text);
			b = Convert::ToDouble(tBox2->Text);
		}
		//очистка графиков
		this->chart1->Series[0]->Points->Clear();
		this->chart2->Series[0]->Points->Clear();

		//считывание данных из файла с Аддитивным белым Гауссовским шумомв !!!!!!!!!! data !!!!!!!!!!!!! 
		openF();


		dft(data, data_out_my);
		//FFTAnalysis(data, data_out, 128, 128);
		set_zero(data_out_my, a, b);
		//FFidft(data_out, data_result);

		idft(data_out_my, data_result);

		//fftr(data_out_my, data_result);

		//cout << endl << data_result[0] << " Result " << data[0];
		//cout << endl << data_result[1] << " Result " << data[1];
		chart(data_result, data_out_my);






	}


			 //кнопка открытия файла для преобразования
	private: System::Void button_openF_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ FileName = "";
		string Fname;


		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			FileName = openFileDialog1->FileName;
		}
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(FileName)).ToPointer();
		Fname = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		const char *c = Fname.c_str();
		vector<int> dataF;
		//считывание файла
		
			ifstream wav_file(c, ios::binary);
			if (!wav_file.is_open()) {
				cout << "Could not open file: " << endl;
				return;
			}

			// Перемещаем курсор на нужное место в файле, чтобы начать чтение сэмплов
			wav_file.seekg(44);

			// Читаем каждый сэмпл из файла и сохраняем в векторе dataF
			while (!wav_file.eof()) {
				short int sample;
				wav_file.read((char*)&sample, sizeof(sample));
				if (!wav_file.eof()) {
					dataF.push_back((int)sample);
				}
			}

			wav_file.close();
			for (int i = 0; i < dataF.size(); i++) {
				cout << i << " " << dataF[i] << endl;
			}
		





	//setlocale(0, "");
	//FILE *file;
	//errno_t error;
	//error = fopen_s(&file, c, "rb");
	//if (error)
	//{
	//	cout << "Не удалось открыть файл\n";
	//	system("pause");
	//	return;
	//}

	//WAVHEADER header;
	//fread_s(&header, sizeof(WAVHEADER), sizeof(WAVHEADER), 1, file);

	////const int couSample, sampleRate, bitPerSamp, nChann;
	//
	//int sampleRate = header.SamplesRate;									//частота дискретизации
	//const int couSample = (header.Subchunk2Size * 8) / (header.BitsPerSample) ;   //количество сэмплов
	//int bitPerSamp = header.BitsPerSample;									//бит в сэмпле
	//int nChann = header.nChannels;											//количество каналов
	//int dataBYTE = header.Subchunk2Size;
	//cout << dataBYTE << endl;
	//
	//vector <long int> mass(couSample);
	////int filedataF[couSample]; //массив для заполнения из header.data
	//cout << couSample << "количество сэмплов";
	//

	//this->labelStat->Text = "Данные загружены";
	//this->labelValue1->Text = Convert::ToString(sampleRate);
	//this->labelValue2->Text = Convert::ToString(couSample);
	//this->labelValue3->Text = Convert::ToString(bitPerSamp);
	//this->labelValue4->Text = Convert::ToString(nChann);
	//cout << endl << static_cast<int>(header.data[2000]) << " 88000" << endl;
	////for (int i = 0; i < couSample; i++)
	////{
	////	mass.push_back(static_cast<int>(header.data[i]));
	////	//cout << i << ' ' << static_cast<int>(header.data[i]) << endl;
	////}
	//
	//fclose(file);

	////system("pause");
	//return;


	}
	


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void lableValue2_Click(System::Object^  sender, System::EventArgs^  e) {}

};
				
}