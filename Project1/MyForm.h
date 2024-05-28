#pragma once

#include "../ChMLaba2/MMN.h"
#include "../ChMLaba2/MVR.h"
#include "../ChMLaba2/MSG.h"
#include "../ChMLaba2/MSG_UN.h"
#include "../ChMLaba2/Functions.h"
#include "../ChMLaba2/OldMethod.h"
#include "InfoText.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <list>
#include <mutex>
#include <thread>
#include <future>

#define typeV std::vector<double> 
#define type2V std::vector<std::vector<double>> 

struct MetData
{
	type2V V;
	type2V U_V2;
	type2V Sub;
	typeV X;
	typeV Y;
	double accuracy;
	int count;
	double accuracy2;
	int count2;
	double Rn2;
	double Rn;
	double R0;
	double R02;
	double testPrecision;
	double mainPrecision;
	double Nmax2;
	double x;
	double y;
	double x2;
	double y2;
};

MetData metData = {};

enum class MET
{
	MVR,
	MMN,
	MSG,
	MSG_UN
};

enum class VAL
{
	NUM,
	TRUE_OR_HALF,
	SUB
};

enum class TASK
{
	MAIN,
	TEST
};

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		MET metType = MET::MVR;
		VAL valType = VAL::NUM;
		TASK taskType = TASK::MAIN;
		int m = 0;
		int n = 0;
		int maxStep = 0;
		double acc = 0;
		double a = 0;
		double b = 1;
		double c = 0;
		double d = 2;
		double w = 0;
		bool started = false;
		InfoText^ infoData;
		double accMult = 1e-2;
		int numPage = 0;
		int countPages = 100;
		bool isActive = true;
		int processCount = 0;
		System::Collections::Generic::List<String^>^ forReplace;
		String^ startConditionMVR = " íóëåâîå íà÷àëüíîå ïğèáëèæåíèå ";
		String^ startConditionAll = " íóëåâîå íà÷àëüíîå ïğèáëèæåíèå ";
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ òèïÇàäà÷èToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ òåñòîâàÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îñíîâíàÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uxyÈëèV2xyToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label6;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîìîùüToolStripMenuItem;

	public:
		MyForm(void)
		{
			InitializeComponent();
			forReplace =
				gcnew System::Collections::Generic::List<String^>;
			//
			//TODO: Add the constructor code here
			//
			infoData = gcnew InfoText;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ âûáîğÌåòîäàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìÂĞToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìÌÍToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìÑÃToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::ToolStripMenuItem^ ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::ToolStripMenuItem^ çíà÷åíèÿÒàáëèöûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vxyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ uxyvxyÈëèvxyV2xyToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûáîğÌåòîäàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìÂĞToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìÌÍToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìÑÃToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çíà÷åíèÿÒàáëèöûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vxyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxyÈëèV2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxyvxyÈëèvxyV2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->òèïÇàäà÷èToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->òåñòîâàÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îñíîâíàÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîìîùüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"×èñëî ğàçáèåíèé ïî X:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"×èñëî ğàçáèåíèé ïî Y:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(300, 66);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1590, 631);
			this->dataGridView1->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->âûáîğÌåòîäàToolStripMenuItem,
					this->çíà÷åíèÿÒàáëèöûToolStripMenuItem, this->òèïÇàäà÷èToolStripMenuItem, this->ïîìîùüToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1902, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûáîğÌåòîäàToolStripMenuItem
			// 
			this->âûáîğÌåòîäàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ìÂĞToolStripMenuItem,
					this->ìÌÍToolStripMenuItem, this->ìÑÃToolStripMenuItem, this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem
			});
			this->âûáîğÌåòîäàToolStripMenuItem->Name = L"âûáîğÌåòîäàToolStripMenuItem";
			this->âûáîğÌåòîäàToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->âûáîğÌåòîäàToolStripMenuItem->Text = L"Âûáîğ ìåòîäà";
			// 
			// ìÂĞToolStripMenuItem
			// 
			this->ìÂĞToolStripMenuItem->Name = L"ìÂĞToolStripMenuItem";
			this->ìÂĞToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->ìÂĞToolStripMenuItem->Text = L"ÌÂĞ";
			this->ìÂĞToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìÂĞToolStripMenuItem_Click);
			// 
			// ìÌÍToolStripMenuItem
			// 
			this->ìÌÍToolStripMenuItem->Name = L"ìÌÍToolStripMenuItem";
			this->ìÌÍToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->ìÌÍToolStripMenuItem->Text = L"ÌÌÍ";
			this->ìÌÍToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìÌÍToolStripMenuItem_Click);
			// 
			// ìÑÃToolStripMenuItem
			// 
			this->ìÑÃToolStripMenuItem->Name = L"ìÑÃToolStripMenuItem";
			this->ìÑÃToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->ìÑÃToolStripMenuItem->Text = L"ÌÑÃ";
			this->ìÑÃToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìÑÃToolStripMenuItem_Click);
			// 
			// ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem
			// 
			this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem->Name = L"ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem";
			this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem->Text = L"ÌÑÃ óíèêàëüíàÿ îáëàñòü";
			this->ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem_Click);
			// 
			// çíà÷åíèÿÒàáëèöûToolStripMenuItem
			// 
			this->çíà÷åíèÿÒàáëèöûToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->vxyToolStripMenuItem,
					this->uxyÈëèV2xyToolStripMenuItem, this->uxyvxyÈëèvxyV2xyToolStripMenuItem
			});
			this->çíà÷åíèÿÒàáëèöûToolStripMenuItem->Name = L"çíà÷åíèÿÒàáëèöûToolStripMenuItem";
			this->çíà÷åíèÿÒàáëèöûToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = L"Çíà÷åíèÿ òàáëèöû";
			// 
			// vxyToolStripMenuItem
			// 
			this->vxyToolStripMenuItem->Name = L"vxyToolStripMenuItem";
			this->vxyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->vxyToolStripMenuItem->Text = L"v(x,y)";
			this->vxyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::vxyToolStripMenuItem_Click);
			// 
			// uxyÈëèV2xyToolStripMenuItem
			// 
			this->uxyÈëèV2xyToolStripMenuItem->Name = L"uxyÈëèV2xyToolStripMenuItem";
			this->uxyÈëèV2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxyÈëèV2xyToolStripMenuItem->Text = L"u(x,y) èëè v2(x,y)";
			this->uxyÈëèV2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxyÈëèV2xyToolStripMenuItem_Click);
			// 
			// uxyvxyÈëèvxyV2xyToolStripMenuItem
			// 
			this->uxyvxyÈëèvxyV2xyToolStripMenuItem->Name = L"uxyvxyÈëèvxyV2xyToolStripMenuItem";
			this->uxyvxyÈëèvxyV2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxyvxyÈëèvxyV2xyToolStripMenuItem->Text = L"|u(x,y)-v(x,y)| èëè |v(x,y) - v2(x,y)|";
			this->uxyvxyÈëèvxyV2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxyvxyÈëèvxyV2xyToolStripMenuItem_Click);
			// 
			// òèïÇàäà÷èToolStripMenuItem
			// 
			this->òèïÇàäà÷èToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->òåñòîâàÿToolStripMenuItem,
					this->îñíîâíàÿToolStripMenuItem
			});
			this->òèïÇàäà÷èToolStripMenuItem->Name = L"òèïÇàäà÷èToolStripMenuItem";
			this->òèïÇàäà÷èToolStripMenuItem->Size = System::Drawing::Size(101, 24);
			this->òèïÇàäà÷èToolStripMenuItem->Text = L"Òèï çàäà÷è";
			// 
			// òåñòîâàÿToolStripMenuItem
			// 
			this->òåñòîâàÿToolStripMenuItem->Name = L"òåñòîâàÿToolStripMenuItem";
			this->òåñòîâàÿToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->òåñòîâàÿToolStripMenuItem->Text = L"Òåñòîâàÿ";
			this->òåñòîâàÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::òåñòîâàÿToolStripMenuItem_Click);
			// 
			// îñíîâíàÿToolStripMenuItem
			// 
			this->îñíîâíàÿToolStripMenuItem->Name = L"îñíîâíàÿToolStripMenuItem";
			this->îñíîâíàÿToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->îñíîâíàÿToolStripMenuItem->Text = L"Îñíîâíàÿ";
			this->îñíîâíàÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îñíîâíàÿToolStripMenuItem_Click);
			// 
			// ïîìîùüToolStripMenuItem
			// 
			this->ïîìîùüToolStripMenuItem->Name = L"ïîìîùüToolStripMenuItem";
			this->ïîìîùüToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->ïîìîùüToolStripMenuItem->Text = L"Ïîìîùü";
			this->ïîìîùüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîìîùüToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"100";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(175, 105);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 22);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"100";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ìàêñ. ÷èñëî øàãîâ:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(175, 142);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(87, 22);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"10000";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Òî÷íîñòü ìåòîäà:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(175, 178);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(87, 22);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"0,0000000001";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 248);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Ğåøèòü";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 16);
			this->label5->TabIndex = 12;
			this->label5->Text = L"w (äëÿ ÌÂĞ):";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(175, 207);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(87, 22);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"1,2";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(17, 288);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(245, 431);
			this->richTextBox1->TabIndex = 14;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(300, 706);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Ïğåä. ñòğ.";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(585, 706);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Ñëåä. ñòğ.";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(443, 709);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 16);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Ñòîëáöû 0-100";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(725, 709);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 16);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Ïğîãğåññ: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1902, 741);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Ëàáîğàòîğíàÿ ğàáîòà ¹2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ìÂĞToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isActive)
		{
			return;
		}
		metType = MET::MVR;
		âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÂĞ";
		textBox5->Enabled = true;
	}
private: System::Void ìÌÍToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	metType = MET::MMN;
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÌÍ";
	textBox5->Enabled = false;
}
private: System::Void ìÑÃToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	metType = MET::MSG;
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÑÃ";
	textBox5->Enabled = false;
}
private: System::Void ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	metType = MET::MSG_UN;
	taskType = TASK::TEST;
	òèïÇàäà÷èToolStripMenuItem->Text = "Òåñòîâàÿ";
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÑÃ óíèêàëüíàÿ îáëàñòü";
	textBox5->Enabled = false;
}

private: System::Void vxyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	valType = VAL::NUM;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "v(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxyÈëèV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	valType = VAL::TRUE_OR_HALF;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "u(x,y) èëè v2(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxyvxyÈëèvxyV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	valType = VAL::SUB;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "|u(x,y)-v(x,y)| èëè |v(x,y) - v2(x,y)|";
	if (started)
	{
		drawTable();
	}
}
//private: String^ getInfoFromFile(TASK task, MET met)
//{
//	//auto fileNamePath = std::filesystem::current_path();
//
//	//std::string fileName = fileNamePath.u8string() + "/../info/";
//	std::string fileName =  "/../info/";
//
//	if (task == TASK::TEST)
//	{
//		if (met == MET::MVR)
//		{
//			fileName += "test1.txt";
//		}
//	}
//	else
//	{
//	}
//
//	std::ifstream ifs;
//	ifs.open("C:/Users/lesni/lab2iter/info/test1.txt");
//	std::string source;
//	ifs >> source;
//
//	String^ converted = gcnew String(source.c_str());
//
//	return converted;
//}
String^ ReplaceOne(String^ s, String^ searchFor, String^ replaceWith)
{
    int index = s->IndexOf(searchFor);
    if (index == -1) return s; // search string was not found.
    return s->Substring(0, index) + replaceWith + s->Substring(index + searchFor->Length);
}
String^ buildInfo(String^ info)
{
	String^ res = info;
	for (int i = 0; i < forReplace->Count; i++)
	{
		res = ReplaceOne(res, "%", forReplace[i]);
	}
	return res;
}
private: System::Void drawTable()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	DataGridViewColumn^ col = gcnew DataGridViewColumn();
	col->CellTemplate = gcnew DataGridViewTextBoxCell();
	col->HeaderText = "";
	dataGridView1->Columns->Add(col);
	DataGridViewColumn^ col2 = gcnew DataGridViewColumn();
	col2->CellTemplate = gcnew DataGridViewTextBoxCell();
	col2->HeaderText = "xi";
	dataGridView1->Columns->Add(col2);
	int MaxNumColumns = 600;
	int shift = numPage * countPages;
	//int realN = min(n,MaxNumColumns);
	int realN = min(n,(numPage + 1) * countPages);
	for (int i = shift; i <= realN; i++)
	{
		DataGridViewColumn^ temp = gcnew DataGridViewColumn();
		temp->CellTemplate = gcnew DataGridViewTextBoxCell();
		//temp->HeaderText = "x" + Convert::ToString(i);
		temp->HeaderText = cropNumberString(Convert::ToString(metData.X[i]));
		dataGridView1->Columns->Add(temp);
	}
	dataGridView1->Rows->Add(m + 2);
	dataGridView1->Rows[0]->Cells[0]->Value = "yj";
	dataGridView1->Rows[0]->Cells[1]->Value = "j/i";
	for (int i = 1; i <= m + 1; i++)
	{
		//dataGridView1->Rows[i]->Cells[0]->Value = "y" + Convert::ToString(i - 1);
		dataGridView1->Rows[i]->Cells[0]->Value = cropNumberString(Convert::ToString(metData.Y[i - 1]));
	}
	for (int i = 1; i <= m + 1; i++)
	{
		dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(i - 1);
	}
	for (int i = 2 + shift; i <= realN + 2; i++)
	{
		dataGridView1->Rows[0]->Cells[i - shift]->Value = Convert::ToString(i - 2);
	}
	for (int i = 2 + shift; i <= realN + 2; i++)
	{
		for (int j = 1; j <= m + 1; j++)
		{
			dataGridView1->Rows[j]->Cells[i - shift]->Value = cropNumberString(Convert::ToString(getValue(i - 2, j - 1)));
		}
	}
}
private: System::Void handleValues()
{
	n = Convert::ToInt32(removeDots(textBox1->Text));
	m = Convert::ToInt32(removeDots(textBox2->Text));
	maxStep = Convert::ToInt32(removeDots(textBox3->Text));
	acc = Convert::ToDouble(removeDots(textBox4->Text));
	w = Convert::ToDouble(removeDots(textBox5->Text));
}
type2V getTrueVals(const typeV& x, const typeV& y)
{
	type2V result(y.size(), typeV(x.size()));

	for (int j = 0; j < y.size(); j++)
	{
		for (int i = 0; i < x.size(); i++)
		{
			result[j][i] = testFunc(x[i], y[j]);
		}
	}

	return result;
}

type2V getSub(const type2V& first, const type2V second)
{
	type2V result(first.size(), typeV(first[0].size()));

	for (int i = 1; i < first.size() - 1; i++)
	{
		for (int j = 1; j < first[0].size() - 1; j++)
		{
			result[i][j] = abs(first[i][j] - second[i][j]);
		}
	}

	return result;
}

type2V getSubTest(const type2V& v, const typeV& x, const typeV& y)
{
	type2V sub(v.size(), typeV(v[0].size()));

	for (int i = 1; i < y.size() - 1; i++)
	{
		for (int j = 1; j < x.size() - 1; j++)
		{
			sub[i][j] = abs(v[i][j] - testFunc(x[j], y[i]));
		}
	}

	return sub;
}

type2V getHalf(const type2V& v)
{
	type2V half(v.size() / 2 + 1, typeV(v[0].size() / 2 + 1));
	for (int i = 0; i < v.size(); i += 2)
	{
		for (int j = 0; j < v[0].size(); j += 2)
		{
			half[i / 2][j / 2] = v[i][j];
		}
	}
	return half;
}
std::pair<int, int> getMaxIndexes(const type2V& sub, double& maxSub)
{
	int imax = 0;
	int jmax = 0;
	double max_ = 0;
	for (int j = 0; j < sub.size(); j++)
	{
		for (int i = 0; i < sub[0].size(); i++)
		{
			if (sub[j][i] > max_)
			{
				imax = i;
				jmax = j;
				max_ = sub[j][i];
			}
		}
	}
	maxSub = max_;
	return {jmax, imax};
}
private: void calculate_test(IterSlauSolverOld* test)
{
	double (*pt1)(double, double) = NULL;
	double (*pt2)(double, double) = NULL;
	double (*pt3)(double, double) = NULL;
	double (*pt4)(double, double) = NULL;
	double (*ptRight)(double, double) = NULL;
	pt1 = &boundFunc1Test;
	pt2 = &boundFunc2Test;
	pt3 = &boundFunc3Test;
	pt4 = &boundFunc4Test;
	ptRight = &rightFuncTest;
	//MVR_Met test(a, b, c, d, n, m, w);
	test->initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	test->initRight(ptRight);
	test->calculateR();
	metData.R0 = test->calcNormR();
	int iterCount = test->solve(maxStep, acc, backgroundWorker1);
	double acc = test->getAccuracy();
	type2V res = test->getV();
	typeV x = test->getX();
	typeV y = test->getY();
	test->calculateR();
	metData.Rn = test->calcNormR();
	metData.accuracy = acc;
	metData.count = iterCount;
	metData.V = res;
	metData.U_V2 = getTrueVals(x, y);
	metData.Sub = getSubTest(res, x, y);
	//metData.Sub = getSub(metData.V, metData.U_V2);
	metData.X = x;
	metData.Y = y;
	double maxSub;
	auto yx = getMaxIndexes(metData.Sub, maxSub);
	metData.testPrecision = maxSub;
	metData.y = y[yx.first];
	metData.x = x[yx.second];

}
private: void calculate_main(IterSlauSolverOld* main, IterSlauSolverOld* main2)
{
	double (*pt1)(double, double) = NULL;
	double (*pt2)(double, double) = NULL;
	double (*pt3)(double, double) = NULL;
	double (*pt4)(double, double) = NULL;
	double (*ptRight)(double, double) = NULL;
	pt1 = &boundFunc1Main;
	pt2 = &boundFunc2Main;
	pt3 = &boundFunc3Main;
	pt4 = &boundFunc4Main;
	ptRight = &rightMain;
	//MVR_Met main(a, b, c, d, n, m, w);
	main->initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	main->initRight(ptRight);
	main->calculateR();
	metData.R0 = main->calcNormR();
	int iterCount = main->solve(maxStep, acc, backgroundWorker1);
	main->calculateR();
	metData.Rn = main->calcNormR();
	double acc = main->getAccuracy();
	type2V res = main->getV();
	typeV x = main->getX();
	typeV y = main->getY();

	//MVR_Met main2(a, b, c, d, n * 2, m * 2, w);
	main2->initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	main2->initRight(ptRight);
	main2->calculateR();
	metData.R02 = main2->calcNormR();
	int iterCount2 = main2->solve(maxStep * 2, acc * accMult, backgroundWorker1);
	main2->calculateR();
	metData.Rn2 = main2->calcNormR();
	double acc2 = main2->getAccuracy();
	type2V res2 = main2->getV();
	type2V res2half = getHalf(res2);
	metData.accuracy = acc;
	metData.count = iterCount;
	metData.V = res;
	metData.U_V2 = res2half;
	metData.Sub = getSub(res, res2half);
	metData.X = x;
	metData.Y = y;
	metData.count2 = iterCount2;
	metData.accuracy2 = acc2;
	double maxSub;
	auto yx = getMaxIndexes(metData.Sub, maxSub);
	metData.mainPrecision = maxSub;
	metData.y = y[yx.first];
	metData.x = x[yx.second];
}
private: void calculateMVR()
{
	if (taskType == TASK::TEST)
	{
		MVR_old* test = new MVR_old(a, b, c, d, n, m, w);
		calculate_test(test);
		delete test;
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add(Convert::ToString(w));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn));
		forReplace->Add(Convert::ToString(metData.testPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add(startConditionMVR);
		
	}
	else
	{
		MVR_old* main = new MVR_old(a, b, c, d, n, m, w);
		MVR_old* main2 = new MVR_old(a, b, c, d, n * 2, m * 2, w);
		calculate_main(main, main2);
		delete main;
		delete main2;
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add(Convert::ToString(w));
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn));
		forReplace->Add(Convert::ToString(w));
		forReplace->Add(Convert::ToString(acc * accMult));
		forReplace->Add(Convert::ToString(maxStep * 2));
		forReplace->Add(Convert::ToString(metData.count2));
		forReplace->Add(Convert::ToString(metData.accuracy2));
		forReplace->Add(Convert::ToString(metData.Rn2));
		forReplace->Add(Convert::ToString(metData.mainPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add(startConditionMVR);
		forReplace->Add(startConditionMVR);
	}
}
private: void showInfoMMNMSG(String^ metName)
{
	if (taskType == TASK::TEST)
	{
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add(metName);
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn));
		forReplace->Add(Convert::ToString(metData.testPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add(startConditionAll);
		forReplace->Add(Convert::ToString(metData.R0));
		richTextBox1->Text = buildInfo(infoData->testMMNMSG);
	}
	else
	{
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add("ÌÌÍ");
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn));
		forReplace->Add("ÒÈÏ ÏĞÈÁËÈÆÅÍÈß");
		forReplace->Add(Convert::ToString(metData.R0));
		forReplace->Add("ÌÌÍ");
		forReplace->Add(Convert::ToString(acc * accMult));
		forReplace->Add(Convert::ToString(maxStep * 2));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy2));
		forReplace->Add(Convert::ToString(metData.Rn2));
		forReplace->Add(Convert::ToString(metData.mainPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add(startConditionAll);
		forReplace->Add(Convert::ToString(metData.R02));
		richTextBox1->Text = buildInfo(infoData->mainMMNMSG);
	}
}
private: void showInfoWorker()
{
	if (metType == MET::MMN)
	{
		showInfoMMNMSG("ÌÌÍ");
	}
	else if (metType == MET::MSG)
	{
		showInfoMMNMSG("ÌÑÃ");
	}
	else if (metType == MET::MSG_UN)
	{
		showInfoMMNMSG("ÌÑÃ íà óíèêàëüíîé îáëàñòè");
	}
	else {
		if (taskType == TASK::MAIN)
		{
			richTextBox1->Text = buildInfo(infoData->mainMVR);
		}
		else
		{
			richTextBox1->Text = buildInfo(infoData->testMVR);
		}
	}
}
private: void calculateMMN()
{
	if (taskType == TASK::TEST)
	{
		MMN_old* test = new MMN_old(a, b, c, d, n, m);
		calculate_test(test);
		delete test;
	}
	else
	{
		MMN_old* main = new MMN_old(a, b, c, d, n, m);
		MMN_old* main2 = new MMN_old(a, b, c, d, n * 2, m * 2);
		calculate_main(main, main2);
		delete main;
		delete main2;
	}
}
private: void calculateMSG()
{
	if (taskType == TASK::TEST)
	{
		double (*pt1)(double, double) = NULL;
		double (*pt2)(double, double) = NULL;
		double (*pt3)(double, double) = NULL;
		double (*pt4)(double, double) = NULL;
		double (*ptRight)(double, double) = NULL;
		pt1 = &boundFunc1Test;
		pt2 = &boundFunc2Test;
		pt3 = &boundFunc3Test;
		pt4 = &boundFunc4Test;
		ptRight = &rightFuncTest;
		MSG_old test(a, b, c, d, n, m);
		test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		test.initRight(ptRight);
		test.firstStep();
		test.calculateR();
		metData.R0 = test.calcNormR();
		int iterCount = test.solve(maxStep, acc, backgroundWorker1);
		test.calculateR();
		metData.Rn = test.calcNormR();
		double acc = test.getAccuracy();
		type2V res = test.getV();
		typeV x = test.getX();
		typeV y = test.getY();
		metData.accuracy = acc;
		metData.count = iterCount;
		metData.V = res;
		metData.U_V2 = getTrueVals(x, y);
		metData.Sub = getSubTest(res, x, y);
		metData.X = x;
		metData.Y = y;
		double maxSub;
		auto yx = getMaxIndexes(metData.Sub, maxSub);
		metData.testPrecision = maxSub;
		metData.y = y[yx.first];
		metData.x = x[yx.second];
	}
	else
	{
		double (*pt1)(double, double) = NULL;
		double (*pt2)(double, double) = NULL;
		double (*pt3)(double, double) = NULL;
		double (*pt4)(double, double) = NULL;
		double (*ptRight)(double, double) = NULL;
		pt1 = &boundFunc1Main;
		pt2 = &boundFunc2Main;
		pt3 = &boundFunc3Main;
		pt4 = &boundFunc4Main;
		ptRight = &rightMain;
		MSG_old main(a, b, c, d, n, m);
		main.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		main.initRight(ptRight);
		main.firstStep();
		main.calculateR();
		metData.R0 = main.calcNormR();
		int iterCount = main.solve(maxStep, acc, backgroundWorker1);
		main.calculateR();
		metData.Rn = main.calcNormR();
		double acc = main.getAccuracy();
		type2V res = main.getV();
		typeV x = main.getX();
		typeV y = main.getY();

		MSG_old main2(a, b, c, d, n * 2, m * 2);
		main2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		main2.initRight(ptRight);
		main2.firstStep();
		main2.calculateR();
		metData.R02 = main2.calcNormR();
		int iterCount2 = main2.solve(maxStep * 2, acc * accMult, backgroundWorker1);
		main2.calculateR();
		metData.Rn2 = main2.calcNormR();
		double acc2 = main2.getAccuracy();
		type2V res2 = main2.getV();
		type2V res2half = getHalf(res2);
		metData.accuracy = acc;
		metData.count = iterCount;
		metData.V = res;
		metData.U_V2 = res2half;
		metData.Sub = getSub(res, res2half);
		metData.X = x;
		metData.Y = y;
		metData.count2 = iterCount2;
		metData.accuracy2 = acc2;
		double maxSub;
		auto yx = getMaxIndexes(metData.Sub, maxSub);
		metData.mainPrecision = maxSub;
		metData.y = y[yx.first];
		metData.x = x[yx.second];
	}
}
private: void calculateMSG_UN()
{
	taskType = TASK::TEST;
	òèïÇàäà÷èToolStripMenuItem->Text = "Òåñòîâàÿ";

	double (*pt1)(double, double) = NULL;
	double (*pt2)(double, double) = NULL;
	double (*pt3)(double, double) = NULL;
	double (*pt4)(double, double) = NULL;
	double (*ptRight)(double, double) = NULL;
	pt1 = &boundFunc1Test;
	pt2 = &boundFunc2Test;
	pt3 = &boundFunc3Test;
	pt4 = &boundFunc4Test;
	ptRight = &rightFuncTest;
	MSG_UN_Met test(a, b, c, d, n, m);
	test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	test.initBoundSpec(&testFunc);
	test.initRight(ptRight);
	test.firstStep(true);
	test.calculateR();
	metData.R0 = test.calcNormR();
	int iterCount = test.solve(maxStep, acc, backgroundWorker1, true);
	test.calculateR();
	metData.Rn = test.calcNormR();
	double acc = test.getAccuracy();
	type2V res = test.getV();
	typeV x = test.getX();
	typeV y = test.getY();
	metData.accuracy = acc;
	metData.count = iterCount;
	metData.V = res;
	metData.U_V2 = getTrueVals(x, y);
	metData.Sub = getSubTest(res, x, y);
	metData.X = x;
	metData.Y = y;
	double maxSub;
	auto yx = getMaxIndexes(metData.Sub, maxSub);
	metData.testPrecision = maxSub;
	metData.y = y[yx.first];
	metData.x = x[yx.second];
}
private: void calculate()
{
	switch (metType)
	{
	case MET::MVR:
		calculateMVR();
		break;
	case MET::MMN:
		calculateMMN();
		break;
	case MET::MSG:
		calculateMSG();
		break;
	case MET::MSG_UN:
		calculateMSG_UN();
		break;
	}
}
private: double getValue(int i, int j)
{
	switch(valType)
	{
	case VAL::NUM:
		return metData.V[j][i];
	case VAL::TRUE_OR_HALF:
		return metData.U_V2[j][i];
	case VAL::SUB:
		return metData.Sub[j][i];
	}
	return 0;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}

	numPage = 0;
	label6->Text = "Ñòîëáöû 0-100";
	handleValues();
	
	isActive = false;

	//afterCalculate();

	if (backgroundWorker1->IsBusy != true)
	{
		backgroundWorker1->RunWorkerAsync();
	}
}
private: System::Void ïîìîùüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	String^ s = Directory::GetCurrentDirectory();
	String^ processDir = s + "\\..\\x64\\Debug\\HelpPr.exe";
	auto process = Process::Start(processDir);
}
private: System::Void òåñòîâàÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	taskType = TASK::TEST;
	òèïÇàäà÷èToolStripMenuItem->Text = "Òåñòîâàÿ";
}
private: System::Void îñíîâíàÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	taskType = TASK::MAIN;
	òèïÇàäà÷èToolStripMenuItem->Text = "Îñíîâíàÿ";
}
String^ removeDots(String^ s)
{
	//cropNumberString("")
	return s->Replace(".", ",");
}
String^ cropNumberString(String^ s)
{
	int Eindex = s->IndexOf("E");
	int comma = s->IndexOf(",");
	if (Eindex == -1 || comma == -1)
	{
		return s;
	}

	int countDigits = 7;
	
	return s->Substring(0, comma + countDigits) + s->Substring(Eindex);
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	if (numPage <= 0 || !started)
	{
		return;
	}
	numPage--;
	label6->Text = "Ñòîëáöû " + Convert::ToString(numPage * countPages) + "-" + Convert::ToString(min((numPage + 1) * countPages, n + 2));
	drawTable();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isActive)
	{
		return;
	}
	if (!started || (numPage >= (n + 2) / countPages - 1 && (n + 2) / countPages == 0)
		|| (numPage >= (n + 2) / countPages && (n + 2) / countPages != 0))
	{
		return;
	}
	numPage++;
	label6->Text = "Ñòîëáöû " + Convert::ToString(numPage * countPages) + "-" + Convert::ToString(min((numPage + 1) * countPages, n + 2));
	drawTable();
}
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	progressMethod = 0;
	calculate();
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	showInfoWorker();
	forReplace->Clear();
	drawTable();
	started = true;
	isActive = true;
	label7->Text = "Ïğîãğåññ: çàâåğøåíî";
}
private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	int maxRealStep;

	if (taskType == TASK::MAIN)
	{
		maxRealStep = maxStep * 3;
	}
	else
	{
		maxRealStep = maxStep;
	}

	label7->Text = "Ïğîãğåññ: " + Convert::ToString((int)((double)progressMethod / maxRealStep * 100)) + "% (îòíîñèòåëüíî ìàêñèìàëüíîãî êîëè÷åñòâà èòåğàöèé)";
}
};
}
