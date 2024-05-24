#pragma once


#include "../ChMLaba2/MMN.h"
#include "../ChMLaba2/MVR.h"
#include "../ChMLaba2/MSG.h"
#include "../ChMLaba2/MSG_UN.h"
#include "../ChMLaba2/Functions.h"
#include "InfoText.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <list>

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÚËÔ«‡‰‡˜ËToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÚÂÒÚÓ‚‡ˇToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÓÒÌÓ‚Ì‡ˇToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uxy»ÎËV2xyToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÔÓÏÓ˘¸ToolStripMenuItem;

	public:
		MyForm(void)
		{
			InitializeComponent();
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


	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ï¬–ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ÏÃÕToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ï—√ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::ToolStripMenuItem^ Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::ToolStripMenuItem^ ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vxyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ uxyvxy»ÎËvxyV2xyToolStripMenuItem;

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
			this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ï¬–ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÏÃÕToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ï—√ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vxyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxy»ÎËV2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxyvxy»ÎËvxyV2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÚËÔ«‡‰‡˜ËToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÔÓÏÓ˘¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label1->Text = L"◊ËÒÎÓ ‡Á·ËÂÌËÈ ÔÓ X:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"◊ËÒÎÓ ‡Á·ËÂÌËÈ ÔÓ Y:";
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
			this->dataGridView1->Size = System::Drawing::Size(1590, 663);
			this->dataGridView1->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem,
					this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem, this->ÚËÔ«‡‰‡˜ËToolStripMenuItem, this->ÔÓÏÓ˘¸ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1902, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem
			// 
			this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Ï¬–ToolStripMenuItem,
					this->ÏÃÕToolStripMenuItem, this->Ï—√ToolStripMenuItem, this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem
			});
			this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Name = L"‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem";
			this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Text = L"¬˚·Ó ÏÂÚÓ‰‡";
			// 
			// Ï¬–ToolStripMenuItem
			// 
			this->Ï¬–ToolStripMenuItem->Name = L"Ï¬–ToolStripMenuItem";
			this->Ï¬–ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->Ï¬–ToolStripMenuItem->Text = L"Ã¬–";
			this->Ï¬–ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Ï¬–ToolStripMenuItem_Click);
			// 
			// ÏÃÕToolStripMenuItem
			// 
			this->ÏÃÕToolStripMenuItem->Name = L"ÏÃÕToolStripMenuItem";
			this->ÏÃÕToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->ÏÃÕToolStripMenuItem->Text = L"ÃÃÕ";
			this->ÏÃÕToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÏÃÕToolStripMenuItem_Click);
			// 
			// Ï—√ToolStripMenuItem
			// 
			this->Ï—√ToolStripMenuItem->Name = L"Ï—√ToolStripMenuItem";
			this->Ï—√ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->Ï—√ToolStripMenuItem->Text = L"Ã—√";
			this->Ï—√ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Ï—√ToolStripMenuItem_Click);
			// 
			// Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem
			// 
			this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem->Name = L"Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem";
			this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem->Text = L"Ã—√ ÛÌËÍ‡Î¸Ì‡ˇ Ó·Î‡ÒÚ¸";
			this->Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem_Click);
			// 
			// ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem
			// 
			this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->vxyToolStripMenuItem,
					this->uxy»ÎËV2xyToolStripMenuItem, this->uxyvxy»ÎËvxyV2xyToolStripMenuItem
			});
			this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Name = L"ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem";
			this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Text = L"«Ì‡˜ÂÌËˇ Ú‡·ÎËˆ˚";
			// 
			// vxyToolStripMenuItem
			// 
			this->vxyToolStripMenuItem->Name = L"vxyToolStripMenuItem";
			this->vxyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->vxyToolStripMenuItem->Text = L"v(x,y)";
			this->vxyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::vxyToolStripMenuItem_Click);
			// 
			// uxy»ÎËV2xyToolStripMenuItem
			// 
			this->uxy»ÎËV2xyToolStripMenuItem->Name = L"uxy»ÎËV2xyToolStripMenuItem";
			this->uxy»ÎËV2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxy»ÎËV2xyToolStripMenuItem->Text = L"u(x,y) ËÎË v2(x,y)";
			this->uxy»ÎËV2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxy»ÎËV2xyToolStripMenuItem_Click);
			// 
			// uxyvxy»ÎËvxyV2xyToolStripMenuItem
			// 
			this->uxyvxy»ÎËvxyV2xyToolStripMenuItem->Name = L"uxyvxy»ÎËvxyV2xyToolStripMenuItem";
			this->uxyvxy»ÎËvxyV2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxyvxy»ÎËvxyV2xyToolStripMenuItem->Text = L"|u(x,y)-v(x,y)| ËÎË |v(x,y) - v2(x,y)|";
			this->uxyvxy»ÎËvxyV2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxyvxy»ÎËvxyV2xyToolStripMenuItem_Click);
			// 
			// ÚËÔ«‡‰‡˜ËToolStripMenuItem
			// 
			this->ÚËÔ«‡‰‡˜ËToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem,
					this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem
			});
			this->ÚËÔ«‡‰‡˜ËToolStripMenuItem->Name = L"ÚËÔ«‡‰‡˜ËToolStripMenuItem";
			this->ÚËÔ«‡‰‡˜ËToolStripMenuItem->Size = System::Drawing::Size(101, 24);
			this->ÚËÔ«‡‰‡˜ËToolStripMenuItem->Text = L"“ËÔ Á‡‰‡˜Ë";
			// 
			// ÚÂÒÚÓ‚‡ˇToolStripMenuItem
			// 
			this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem->Name = L"ÚÂÒÚÓ‚‡ˇToolStripMenuItem";
			this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem->Text = L"“ÂÒÚÓ‚‡ˇ";
			this->ÚÂÒÚÓ‚‡ˇToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÚÂÒÚÓ‚‡ˇToolStripMenuItem_Click);
			// 
			// ÓÒÌÓ‚Ì‡ˇToolStripMenuItem
			// 
			this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem->Name = L"ÓÒÌÓ‚Ì‡ˇToolStripMenuItem";
			this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem->Text = L"ŒÒÌÓ‚Ì‡ˇ";
			this->ÓÒÌÓ‚Ì‡ˇToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÓÒÌÓ‚Ì‡ˇToolStripMenuItem_Click);
			// 
			// ÔÓÏÓ˘¸ToolStripMenuItem
			// 
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Name = L"ÔÓÏÓ˘¸ToolStripMenuItem";
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Text = L"œÓÏÓ˘¸";
			this->ÔÓÏÓ˘¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÔÓÏÓ˘¸ToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"10";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(175, 105);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 22);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"10";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ã‡ÍÒ. ˜ËÒÎÓ ¯‡„Ó‚:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(175, 142);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(87, 22);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"1000";
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
			this->label4->Text = L"“Ó˜ÌÓÒÚ¸ ÏÂÚÓ‰‡:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(175, 178);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(87, 22);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"0,00001";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 248);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"–Â¯ËÚ¸";
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
			this->label5->Text = L"w (‰Îˇ Ã¬–):";
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
			this->richTextBox1->Location = System::Drawing::Point(17, 278);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(245, 441);
			this->richTextBox1->TabIndex = 14;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1902, 741);
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
			this->Text = L"À‡·Ó‡ÚÓÌ‡ˇ ‡·ÓÚ‡ π2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Ï¬–ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		metType = MET::MVR;
		‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Text = "Ã¬–";
		textBox5->Enabled = true;
	}
private: System::Void ÏÃÕToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MMN;
	‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Text = "ÃÃÕ";
	textBox5->Enabled = false;
}
private: System::Void Ï—√ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG;
	‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Text = "Ã—√";
	textBox5->Enabled = false;
}
private: System::Void Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG_UN;
	taskType = TASK::TEST;
	ÚËÔ«‡‰‡˜ËToolStripMenuItem->Text = "“ÂÒÚÓ‚‡ˇ";
	‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem->Text = "Ã—√ ÛÌËÍ‡Î¸Ì‡ˇ Ó·Î‡ÒÚ¸";
	textBox5->Enabled = false;
}

private: System::Void vxyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::NUM;
	ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Text = "v(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxy»ÎËV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::TRUE_OR_HALF;
	ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Text = "u(x,y) ËÎË v2(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxyvxy»ÎËvxyV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::SUB;
	ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem->Text = "|u(x,y)-v(x,y)| ËÎË |v(x,y) - v2(x,y)|";
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
String^ buildInfo(String^ info, System::Collections::Generic::List<String^>^ forReplace)
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
	int realN = min(n,MaxNumColumns);
	for (int i = 0; i <= realN; i++)
	{
		DataGridViewColumn^ temp = gcnew DataGridViewColumn();
		temp->CellTemplate = gcnew DataGridViewTextBoxCell();
		//temp->HeaderText = "x" + Convert::ToString(i);
		temp->HeaderText = Convert::ToString(metData.X[i]);
		dataGridView1->Columns->Add(temp);
	}
	dataGridView1->Rows->Add(m + 2);
	dataGridView1->Rows[0]->Cells[0]->Value = "yj";
	dataGridView1->Rows[0]->Cells[1]->Value = "j/i";
	for (int i = 1; i <= m + 1; i++)
	{
		//dataGridView1->Rows[i]->Cells[0]->Value = "y" + Convert::ToString(i - 1);
		dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(metData.Y[i - 1]);
	}
	for (int i = 1; i <= m + 1; i++)
	{
		dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(i - 1);
	}
	for (int i = 2; i <= realN + 2; i++)
	{
		dataGridView1->Rows[0]->Cells[i]->Value = Convert::ToString(i - 2);
	}
	for (int i = 2; i <= realN + 2; i++)
	{
		for (int j = 1; j <= m + 1; j++)
		{
			dataGridView1->Rows[j]->Cells[i]->Value = Convert::ToString(getValue(i - 2, j - 1));
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
type2V getTrueVals(const typeV& x, const std::vector<double>& y)
{
	type2V result(y.size(), typeV(x.size()));

	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < y.size(); j++)	
		{
			result[j][i] = testFunc(x[i], y[j]);
		}
	}

	return result;
}

type2V getSub(const type2V& first, const type2V second)
{
	type2V result(first.size(), typeV(first[0].size()));

	for (int i = 0; i < first.size(); i++)
	{
		for (int j = 0; j < first[0].size(); j++)
		{
			double first_ = first[i][j];
			double second_ = second[i][j];
			double sub_ = first_ - second_;
			result[i][j] = abs(first[i][j] - second[i][j]);
		}
	}

	return result;
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
private: void calculate_test(IterSlauSolver* test)
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
	metData.R0 = test->calcNorm2R();
	int iterCount = test->solve(maxStep, acc);
	double acc = test->getAccuracy();
	type2V res = test->getV();
	typeV x = test->getX();
	typeV y = test->getY();
	test->calculateR();
	metData.Rn = test->calcNorm2R();
	metData.accuracy = acc;
	metData.count = iterCount;
	metData.V = res;
	metData.U_V2 = getTrueVals(x, y);
	metData.Sub = getSub(metData.V, metData.U_V2);
	metData.X = x;
	metData.Y = y;
	double maxSub;
	auto yx = getMaxIndexes(metData.Sub, maxSub);
	metData.testPrecision = maxSub;
	metData.y = y[yx.first];
	metData.x = x[yx.second];

}
private: void calculate_main(IterSlauSolver* main, IterSlauSolver* main2)
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
	metData.R0 = main->calcNorm2R();
	int iterCount = main->solve(maxStep, acc);
	main->calculateR();
	metData.Rn = main->calcNorm2R();
	double acc = main->getAccuracy();
	type2V res = main->getV();
	typeV x = main->getX();
	typeV y = main->getY();

	//MVR_Met main2(a, b, c, d, n * 2, m * 2, w);
	main2->initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	main2->initRight(ptRight);
	main2->calculateR();
	metData.R02 = main2->calcNorm2R();
	int iterCount2 = main2->solve(maxStep * 2, acc * accMult);
	main2->calculateR();
	metData.Rn2 = main2->calcNorm2R();
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
		MVR_Met* test = new MVR_Met(a, b, c, d, n, m, w);
		calculate_test(test);
		delete test;
		System::Collections::Generic::List<String^>^ forReplace = 
			gcnew System::Collections::Generic::List<String^>;
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
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		richTextBox1->Text = buildInfo(infoData->testMVR, forReplace);
	}
	else
	{
		MVR_Met* main = new MVR_Met(a, b, c, d, n, m, w);
		MVR_Met* main2 = new MVR_Met(a, b, c, d, n * 2, m * 2, w);
		calculate_main(main, main2);
		delete main;
		delete main2;
		System::Collections::Generic::List<String^>^ forReplace = 
			gcnew System::Collections::Generic::List<String^>;
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add(Convert::ToString(w));
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn2));
		forReplace->Add(Convert::ToString(w));
		forReplace->Add(Convert::ToString(acc * accMult));
		forReplace->Add(Convert::ToString(maxStep * 2));
		forReplace->Add(Convert::ToString(metData.count2));
		forReplace->Add(Convert::ToString(metData.accuracy2));
		forReplace->Add(Convert::ToString(metData.Rn2));
		forReplace->Add(Convert::ToString(metData.mainPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		richTextBox1->Text = buildInfo(infoData->mainMVR, forReplace);
	}
}
private: void showInfoMMNMSG(String^ metName)
{
	if (taskType == TASK::TEST)
	{
		System::Collections::Generic::List<String^>^ forReplace = 
			gcnew System::Collections::Generic::List<String^>;
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
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		forReplace->Add(Convert::ToString(metData.R0));
		richTextBox1->Text = buildInfo(infoData->testMMNMSG, forReplace);
	}
	else
	{
		System::Collections::Generic::List<String^>^ forReplace = 
			gcnew System::Collections::Generic::List<String^>;
		forReplace->Add(Convert::ToString(n));
		forReplace->Add(Convert::ToString(m));
		forReplace->Add("ÃÃÕ");
		forReplace->Add(Convert::ToString(acc));
		forReplace->Add(Convert::ToString(maxStep));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy));
		forReplace->Add(Convert::ToString(metData.Rn));
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		forReplace->Add(Convert::ToString(metData.R0));
		forReplace->Add("ÃÃÕ");
		forReplace->Add(Convert::ToString(acc * accMult));
		forReplace->Add(Convert::ToString(maxStep * 2));
		forReplace->Add(Convert::ToString(metData.count));
		forReplace->Add(Convert::ToString(metData.accuracy2));
		forReplace->Add(Convert::ToString(metData.Rn2));
		forReplace->Add(Convert::ToString(metData.mainPrecision));
		forReplace->Add(Convert::ToString(metData.x));
		forReplace->Add(Convert::ToString(metData.y));
		forReplace->Add("“»œ œ–»¡À»∆≈Õ»ﬂ");
		forReplace->Add(Convert::ToString(metData.R02));
		richTextBox1->Text = buildInfo(infoData->mainMMNMSG, forReplace);
	}
}
private: void calculateMMN()
{
	if (taskType == TASK::TEST)
	{
		MMN_Met* test = new MMN_Met(a, b, c, d, n, m);
		calculate_test(test);
		delete test;
	}
	else
	{
		MMN_Met* main = new MMN_Met(a, b, c, d, n, m);
		MMN_Met* main2 = new MMN_Met(a, b, c, d, n * 2, m * 2);
		calculate_main(main, main2);
		delete main;
		delete main2;
	}
	showInfoMMNMSG("ÃÃÕ");
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
		MSG_Met test(a, b, c, d, n, m);
		test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		test.initRight(ptRight);
		double acc = test.firstStep();
		test.calculateR();
		metData.R0 = test.calcNorm2R();
		int iterCount = test.solve(maxStep, acc);
		test.calculateR();
		metData.Rn = test.calcNorm2R();
		acc = test.getAccuracy();
		type2V res = test.getV();
		typeV x = test.getX();
		typeV y = test.getY();
		metData.accuracy = acc;
		metData.count = iterCount;
		metData.V = res;
		metData.U_V2 = getTrueVals(x, y);
		metData.Sub = getSub(metData.V, metData.U_V2);
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
		MSG_Met main(a, b, c, d, n, m);
		main.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		main.initRight(ptRight);
		double acc = main.firstStep();
		main.calculateR();
		metData.R0 = main.calcNorm2R();
		int iterCount = main.solve(maxStep, acc);
		main.calculateR();
		metData.Rn = main.calcNorm2R();
		acc = main.getAccuracy();
		type2V res = main.getV();
		typeV x = main.getX();
		typeV y = main.getY();

		MSG_Met main2(a, b, c, d, n * 2, m * 2);
		main2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
		main2.initRight(ptRight);
		double acc2 = main2.firstStep();
		main2.calculateR();
		metData.R02 = main2.calcNorm2R();
		int iterCount2 = main2.solve(maxStep * 2, acc * accMult);
		main2.calculateR();
		metData.Rn2 = main2.calcNorm2R();
		acc2 = main2.getAccuracy();
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
	showInfoMMNMSG("Ã—√");
}
private: void calculateMSG_UN()
{
	taskType = TASK::TEST;
	ÚËÔ«‡‰‡˜ËToolStripMenuItem->Text = "“ÂÒÚÓ‚‡ˇ";

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
	test.initRight(ptRight);
	double acc = test.firstStep();
	test.calculateR();
	metData.R0 = test.calcNorm2R();
	int iterCount = test.solve(maxStep, acc);
	test.calculateR();
	metData.Rn = test.calcNorm2R();
	acc = test.getAccuracy();
	type2V res = test.getV();
	typeV x = test.getX();
	typeV y = test.getY();
	metData.accuracy = acc;
	metData.count = iterCount;
	metData.V = res;
	metData.U_V2 = getTrueVals(x, y);
	metData.Sub = getSub(metData.V, metData.U_V2);
	metData.X = x;
	metData.Y = y;
	double maxSub;
	auto yx = getMaxIndexes(metData.Sub, maxSub);
	metData.testPrecision = maxSub;
	metData.y = y[yx.first];
	metData.x = x[yx.second];

	showInfoMMNMSG("Ã—√ Ì‡ ÛÌËÍ‡Î¸ÌÓÈ Ó·Î‡ÒÚË");
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
	handleValues();
	calculate();
	drawTable();
	started = true;
}
private: System::Void ÔÓÏÓ˘¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ s = Directory::GetCurrentDirectory();
	String^ processDir = s + "\\..\\x64\\Debug\\HelpPr.exe";
	auto process = Process::Start(processDir);
}
private: System::Void ÚÂÒÚÓ‚‡ˇToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::TEST;
	ÚËÔ«‡‰‡˜ËToolStripMenuItem->Text = "“ÂÒÚÓ‚‡ˇ";
}
private: System::Void ÓÒÌÓ‚Ì‡ˇToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::MAIN;
	ÚËÔ«‡‰‡˜ËToolStripMenuItem->Text = "ŒÒÌÓ‚Ì‡ˇ";
}
String^ removeDots(String^ s)
{
	return s->Replace(".", ",");
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
