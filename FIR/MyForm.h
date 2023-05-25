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



	private: System::Windows::Forms::Label^  labelName1;
	private: System::Windows::Forms::Label^  labelName4;
	private: System::Windows::Forms::Label^  labelName3;
	private: System::Windows::Forms::Label^  labelName2;
	private: System::Windows::Forms::Label^  labelValue1;
	private: System::Windows::Forms::Label^  labelValue2;
	private: System::Windows::Forms::Label^  labelValue3;
	private: System::Windows::Forms::Label^  labelValue4;
	private: System::Windows::Forms::Label^  labelStat;
	private: System::Windows::Forms::Label^  labelValue5;
	private: System::Windows::Forms::Label^  labelName5;
	private: System::Windows::Forms::Button^  button_saveF;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button_data_processing;
	private: System::Windows::Forms::Button^  btn_mini;
	public: System::Windows::Forms::ProgressBar^  progressBar1;
	private:








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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->labelName1 = (gcnew System::Windows::Forms::Label());
			this->labelName4 = (gcnew System::Windows::Forms::Label());
			this->labelName3 = (gcnew System::Windows::Forms::Label());
			this->labelName2 = (gcnew System::Windows::Forms::Label());
			this->labelValue1 = (gcnew System::Windows::Forms::Label());
			this->labelValue2 = (gcnew System::Windows::Forms::Label());
			this->labelValue3 = (gcnew System::Windows::Forms::Label());
			this->labelValue4 = (gcnew System::Windows::Forms::Label());
			this->labelStat = (gcnew System::Windows::Forms::Label());
			this->labelValue5 = (gcnew System::Windows::Forms::Label());
			this->labelName5 = (gcnew System::Windows::Forms::Label());
			this->button_saveF = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button_data_processing = (gcnew System::Windows::Forms::Button());
			this->btn_mini = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_exit
			// 
			resources->ApplyResources(this->btn_exit, L"btn_exit");
			this->btn_exit->FlatAppearance->BorderSize = 0;
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MyForm::btn_exit_Click);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->Alignment = System::Drawing::StringAlignment::Center;
			legend3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			resources->ApplyResources(this->chart1, L"chart1");
			this->chart1->Name = L"chart1";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::White;
			series3->Legend = L"Legend1";
			series3->LegendText = L"ИХ";
			series3->Name = L"Series1";
			this->chart1->Series->Add(series3);
			// 
			// chart2
			// 
			this->chart2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			chartArea4->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea4);
			legend4->Alignment = System::Drawing::StringAlignment::Center;
			legend4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			legend4->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend4->Name = L"Legend1";
			this->chart2->Legends->Add(legend4);
			resources->ApplyResources(this->chart2, L"chart2");
			this->chart2->Name = L"chart2";
			series4->BorderWidth = 3;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::White;
			series4->Legend = L"Legend1";
			series4->LegendText = L"Спектр ИХ";
			series4->Name = L"Series1";
			this->chart2->Series->Add(series4);
			// 
			// tBox1
			// 
			this->tBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			resources->ApplyResources(this->tBox1, L"tBox1");
			this->tBox1->Name = L"tBox1";
			// 
			// tBox2
			// 
			this->tBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			resources->ApplyResources(this->tBox2, L"tBox2");
			this->tBox2->Name = L"tBox2";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// buttonFIR
			// 
			this->buttonFIR->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->buttonFIR, L"buttonFIR");
			this->buttonFIR->Name = L"buttonFIR";
			this->buttonFIR->UseVisualStyleBackColor = true;
			this->buttonFIR->Click += gcnew System::EventHandler(this, &MyForm::buttonFIR_Click);
			// 
			// button_openF
			// 
			this->button_openF->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->button_openF, L"button_openF");
			this->button_openF->Name = L"button_openF";
			this->button_openF->UseVisualStyleBackColor = true;
			this->button_openF->Click += gcnew System::EventHandler(this, &MyForm::button_openF_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L".wav";
			resources->ApplyResources(this->openFileDialog1, L"openFileDialog1");
			// 
			// labelName1
			// 
			resources->ApplyResources(this->labelName1, L"labelName1");
			this->labelName1->Name = L"labelName1";
			// 
			// labelName4
			// 
			resources->ApplyResources(this->labelName4, L"labelName4");
			this->labelName4->Name = L"labelName4";
			// 
			// labelName3
			// 
			resources->ApplyResources(this->labelName3, L"labelName3");
			this->labelName3->Name = L"labelName3";
			// 
			// labelName2
			// 
			resources->ApplyResources(this->labelName2, L"labelName2");
			this->labelName2->Name = L"labelName2";
			// 
			// labelValue1
			// 
			resources->ApplyResources(this->labelValue1, L"labelValue1");
			this->labelValue1->Name = L"labelValue1";
			// 
			// labelValue2
			// 
			resources->ApplyResources(this->labelValue2, L"labelValue2");
			this->labelValue2->Name = L"labelValue2";
			// 
			// labelValue3
			// 
			resources->ApplyResources(this->labelValue3, L"labelValue3");
			this->labelValue3->Name = L"labelValue3";
			// 
			// labelValue4
			// 
			resources->ApplyResources(this->labelValue4, L"labelValue4");
			this->labelValue4->Name = L"labelValue4";
			// 
			// labelStat
			// 
			resources->ApplyResources(this->labelStat, L"labelStat");
			this->labelStat->ForeColor = System::Drawing::Color::Snow;
			this->labelStat->Name = L"labelStat";
			// 
			// labelValue5
			// 
			resources->ApplyResources(this->labelValue5, L"labelValue5");
			this->labelValue5->Name = L"labelValue5";
			// 
			// labelName5
			// 
			resources->ApplyResources(this->labelName5, L"labelName5");
			this->labelName5->Name = L"labelName5";
			// 
			// button_saveF
			// 
			this->button_saveF->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->button_saveF, L"button_saveF");
			this->button_saveF->Name = L"button_saveF";
			this->button_saveF->UseVisualStyleBackColor = true;
			this->button_saveF->Click += gcnew System::EventHandler(this, &MyForm::button_saveF_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"wav";
			this->saveFileDialog1->FileName = L"Обработанный файл";
			resources->ApplyResources(this->saveFileDialog1, L"saveFileDialog1");
			// 
			// button_data_processing
			// 
			this->button_data_processing->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->button_data_processing, L"button_data_processing");
			this->button_data_processing->Name = L"button_data_processing";
			this->button_data_processing->UseMnemonic = false;
			this->button_data_processing->UseVisualStyleBackColor = false;
			this->button_data_processing->Click += gcnew System::EventHandler(this, &MyForm::button_data_processing_Click);
			// 
			// btn_mini
			// 
			resources->ApplyResources(this->btn_mini, L"btn_mini");
			this->btn_mini->FlatAppearance->BorderSize = 0;
			this->btn_mini->Name = L"btn_mini";
			this->btn_mini->UseVisualStyleBackColor = true;
			this->btn_mini->Click += gcnew System::EventHandler(this, &MyForm::btn_mini_Click);
			// 
			// progressBar1
			// 
			resources->ApplyResources(this->progressBar1, L"progressBar1");
			this->progressBar1->Name = L"progressBar1";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(140)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->btn_mini);
			this->Controls->Add(this->button_data_processing);
			this->Controls->Add(this->button_saveF);
			this->Controls->Add(this->labelName5);
			this->Controls->Add(this->labelValue5);
			this->Controls->Add(this->labelStat);
			this->Controls->Add(this->labelValue4);
			this->Controls->Add(this->labelValue3);
			this->Controls->Add(this->labelValue2);
			this->Controls->Add(this->labelValue1);
			this->Controls->Add(this->labelName2);
			this->Controls->Add(this->labelName3);
			this->Controls->Add(this->labelName4);
			this->Controls->Add(this->labelName1);
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
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: double a, b;													//значения частот для текстбоксов
	private: int x;															//количество семплов в файле
	private: int *dataF = new int[40074836];									//данные из обрабатываемого файла
	private: int *dataPROC = new int[40074836];								//обработанные данные для записи в файл
	private: double *data = new double[128];								//данные из файла с белым шумом для получения ИХ
	private: complex<double> *data_out_my = new complex<double>[128];		//комплексные числи на выходе прямого преобразования Фурье
	private: double *data_result = new double[128];							//данные ИХ после всех обработок ( обратное пр. Фурье и симметрия)
	private: double *data_result1 = new double[127];
	private: double *data_FIR = new double[127];							//временное хранение данных при обработке ИХ в треугольник.(обработчик события //кнопка расчета ИХ)
	private: complex<double> *datamatr = new complex<double>[128];			//матрица для вычисления ППФ и ОПФ
	private: const double TwoPi = 6.283185307179586;						//число Пи * 2



			 //выставляет параметры частот по умолчанию, если значения не были введены
	private: void DefaultParams() {
		a = 0;
		b = 5000;

	}

			 //считывание файла АБГШ в data
	private: void openF() {

		ifstream wav_file("005.wav", ios::binary);
		if (!wav_file.is_open()) {
			MessageBox::Show("Не удалось открыть файл!", "Ошибка.");
			return;
		}

		// Перемещаем курсор на нужное место в файле, чтобы начать чтение сэмплов
		wav_file.seekg(48);



		// Читаем каждый сэмпл из файла и сохраняем в векторе dataF
		int z = 0;
		while (z < 128) {
			short int sample;
			wav_file.read((char*)&sample, sizeof(sample));
			if (!wav_file.eof()) {
				
				data[z] = (int)sample;
				
			}
			z++;
		}



		wav_file.close();
		return;
	}
			 
			 //запись файла
	private: void writeWAV(int *data, const std::string &filename, int sampleRate, int numChannels, int bitsPerSample, int dataS)
	{
		ofstream outFile(filename, std::ios::binary);

		// Заголовок WAV-файла
		outFile.write("RIFF", 4);
		int32_t fileSize = 36 + dataS * bitsPerSample / 8;
		outFile.write(reinterpret_cast<const char *>(&fileSize), 4);
		outFile.write("WAVE", 4);

		// Формат
		outFile.write("fmt ", 4);
		int32_t subchunk1Size = 16;
		outFile.write(reinterpret_cast<const char *>(&subchunk1Size), 4);
		int16_t audioFormat = 1; // 1 для PCM
		outFile.write(reinterpret_cast<const char *>(&audioFormat), 2);
		outFile.write(reinterpret_cast<const char *>(&numChannels), 2);
		outFile.write(reinterpret_cast<const char *>(&sampleRate), 4);
		int32_t byteRate = sampleRate * numChannels * bitsPerSample / 8;
		outFile.write(reinterpret_cast<const char *>(&byteRate), 4);
		int16_t blockAlign = numChannels * bitsPerSample / 8;
		outFile.write(reinterpret_cast<const char *>(&blockAlign), 2);
		outFile.write(reinterpret_cast<const char *>(&bitsPerSample), 2);

		// Данные
		outFile.write("data", 4);
		int32_t dataSize = dataS * bitsPerSample / 8;
		outFile.write(reinterpret_cast<const char *>(&dataSize), 4);

		// Запись массива данных в файл
		for (int i = 0; i < dataS; i++)
		{
			outFile.write(reinterpret_cast<const char *>(&data[i]), bitsPerSample / 8);
		}

		outFile.close();
	}


			 //построение графиков
	private: void chart(double *masX, complex<double> *masY) {
		double y = 0;
		for (int i = 0; i < 127; i++)
		{
			y = masX[i];
			this->chart1->Series[0]->Points->AddXY(i, y);
		}
		for (int i = 1; i < 65; i++)
		{
			y = sqrt(pow(masY[i].real(), 2) + pow(masY[i].imag(), 2));
			this->chart2->Series[0]->Points->AddXY(i * 44100 / 128, y);
		}
	}

			 //обнуление ненужных частот
	private: void set_zero(complex<double> *data_out_my, double f1, double f2) {
		f1 = round(f1 * 128 / 44100);
		f2 = round(f2 * 128 / 44100);
		for (int i = 0; i < f1; i++)
		{
			data_out_my[i] *= 0;
		}
		for (int i = f1; i < f2; i++)
		{
			data_out_my[i] = complex<double>(50000, 25000);
		}

		for (int i = f2; i < 128; i++)
		{
			data_out_my[i] *= 0;
		}

	}

			 //прямое Фурье
	private: void dft(double *data, complex<double> *data_out_my) {
		const double TwoPi = 6.283185307179586;


		for (int k = 0; k < 128; ++k) {
			complex<double> sum(0, 0);
			for (int n = 0; n < 128; ++n) {
				sum += data[n] * std::exp(-1.0 * complex<double>(0, 1) * TwoPi * Convert::ToDouble(k) * Convert::ToDouble(n) / 128.0);
			}
			data_out_my[k] = abs(sum);
		}


	}

			 //обратное Фурье
	private: void idft(complex<double> *data_out_my, double *data_result) {
		const double TwoPi = 6.283185307179586;

		for (int n = 0; n < 128; ++n) {
			complex<double> sum(0, 0);
			for (int k = 0; k < 128; ++k) {
				sum += data_out_my[k] * std::exp(std::complex<double>(0, 1) * TwoPi * Convert::ToDouble(k) * Convert::ToDouble(n) / 128.0);
			}
			data_result[n] = round((1.0 / 128)*sum.real());
		}
		//отражает массив относительно центра
		for (int i = 65, j = 0; i < 128; i++, j++) {
			data_result1[j] = data_result[i];
		}
		for (int i = 0, j = 63; i < 64; i++, j++) {
			data_result1[j] = data_result[i];
		}
		
		
		
	}





			 //КНОПКА выхода
	private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
			 //КНОПКА свернуть
	private: System::Void btn_mini_Click(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = FormWindowState::Minimized;
	}



			 //КНОПКА расчета ИХ
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

		//считывание данных из файла с Аддитивным белым Гауссовским шумом !!!!!!!!!! data !!!!!!!!!!!!! 
		openF();

		//преобразование в треугольник
		double sko = 1;
		for (int i = 0; i < 128; i++) {
			data[i] = Convert::ToInt16(data[i] * sko);
			sko -= 0.0078125;
			
		}
		for (int i = 1, j = 0; i < 128; i += 2, j++) {
			data_FIR[j] = data[127 - i];
		}
		for (int i = 2, j = 64; i < 128; i += 2, j++) {
			data_FIR[j] = data[i];
		}
		
		
		//вызов функций
		dft(data_FIR, data_out_my);
		
		set_zero(data_out_my, a, b);
		
		idft(data_out_my, data_result);

		chart(data_result1, data_out_my);

		this->labelStat->Text = "Откройте файл";

	}


			 //КНОПКА открытия файла для преобразования
	private: System::Void button_openF_Click(System::Object^  sender, System::EventArgs^  e) {
		this->labelStat->Text = "Идет загрузка данных";

		
		String^ FileName = "";
		string Fname;


		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			FileName = openFileDialog1->FileName;
		}
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(FileName)).ToPointer();
		Fname = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		const char *c = Fname.c_str();
		

		

								//СЧИТЫВАНИЕ ФАЙЛА

		//считывание шапки
		
		FILE *file;
		errno_t error;
		error = fopen_s(&file, c, "rb");
		if (error)
		{
			MessageBox::Show("Файл не открыт.", "Ошибка.");
			//system("pause");
			return;
		}
		WAVHEADER header;
		fread_s(&header, sizeof(WAVHEADER), sizeof(WAVHEADER), 1, file);
		int sampleRate = header.SamplesRate;											//частота дискретизации
		int couSample = (header.Subchunk2Size * 8) / (header.BitsPerSample);   //количество сэмплов
		int bitPerSamp = header.BitsPerSample;										//бит в сэмпле
		int nChann = header.nChannels;												//количество каналов
		int dataBYTE = header.Subchunk2Size;
		//x = 50000;

		this->labelStat->Text = "Данные загружены";
		this->labelValue1->Text = Convert::ToString(sampleRate);
		this->labelValue2->Text = Convert::ToString(couSample);
		this->labelValue3->Text = Convert::ToString(bitPerSamp);
		this->labelValue4->Text = Convert::ToString(nChann);
		this->labelValue5->Text = Convert::ToString(dataBYTE);


		fclose(file);
		
		
		//считывание данных
		

			ifstream wav_file(c, ios::binary);
			if (!wav_file.is_open()) {
				MessageBox::Show("Не удалось открыть файл.", "Ошибка.");
				return;
			}

			// Перемещаем курсор на нужное место в файле, чтобы начать чтение сэмплов
			wav_file.seekg(44);

			// Читаем каждый сэмпл из файла и сохраняем в векторе dataF
			int z = 0;
			while (!wav_file.eof()) {
				short int sample;
				wav_file.read((char*)&sample, sizeof(sample));
				if (!wav_file.eof()) {
					
					dataF[z] = (int)sample;
					
				}
				z++;
			}
			x = z;

			wav_file.close();

	}

			//КНОПКА обработки файла
	private: System::Void button_data_processing_Click(System::Object^  sender, System::EventArgs^  e) {
		this->labelStat->Text = "Идет обработка данных";
		//MessageBox::Show("Для начала обработки нажмите <OK> ", "");
		this->progressBar1->Visible = true;
		double proBarVal = 0;
		int val = 0;
		for (int i = 0; i < x - 126; i++) {
			val = 0;
			for (int j = 0; j < 127; j++) {
				val += data_result1[j] * dataF[i + j];
			}

			dataPROC[i] = val / 32767;
			if ( i == proBarVal ){
				this->progressBar1->Increment(1);
				proBarVal += (x - 126) / 100;
			}

		}

		this->labelStat->Text = "Данные обработаны";
		this->progressBar1->Increment(-100);
		this->progressBar1->Visible = false;
		

		
		
	}


	
			 //КНОПКА сохранения файла
	private: System::Void button_saveF_Click(System::Object^  sender, System::EventArgs^  e) {
		this->labelStat->Text = "Идет сохранение данных";
		String^ FileName = "";
		string Fname;


		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
			FileName = saveFileDialog1->FileName;
		}
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(FileName)).ToPointer();
		Fname = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		const char *c = Fname.c_str();

		writeWAV(dataPROC, c, 44100, 1, 16, x);

		this->labelStat->Text = "Данные сохранены";
		MessageBox::Show("Данные сохранены.", "Успех.");



	}
	



			//ПЕРЕТАСКИВАНИЕ ОКНА
	private: bool dragging;
	private: Point offset;
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		offset = PointToScreen(e->Location) - (Drawing::Size)this->Location;

	}
	private: System::Void Shell_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dragging = false;
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	};
	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false;
	}
};
				
}