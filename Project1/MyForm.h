#pragma once


#include "../ChMLaba2/MMN.h"
#include "../ChMLaba2/MVR.h"
#include "../ChMLaba2/MSG.h"
#include <vector>
#include <algorithm>
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>

# define M_PI           3.14159265358979323846
#define typeV std::vector<double> 
#define type2V std::vector<std::vector<double>> 

double rightFuncTest(double x, double y)
{
	double a = exp(sin(M_PI * x * y) * sin(M_PI * x * y)) * 0.5;
	double b = (x * x + y * y);
	double d = M_PI * M_PI;
	double c = (-1 - 4 * cos(2 * M_PI * x * y) + cos(4 * M_PI * x * y));
	return a * b * c * d;
}

double rightFuncTest2(double x, double y)
{
	double a = 2 * M_PI * M_PI * y * y * exp(sin(M_PI * x * y) * sin(M_PI * x * y));
	double b = 2 * sin(M_PI * x * y) * sin(M_PI * x * y) * cos(M_PI * x * y) * cos(M_PI * x * y) - sin(M_PI * x * y) * sin(M_PI * x * y) + cos(M_PI * x * y) * cos(M_PI * x * y);
	return a * b;
}

double boundFunc1Test(double x, double y)
{
	return 1;
}

double boundFunc2Test(double x, double y)
{
	return exp(sin(2 * M_PI * x) * sin(2 * M_PI * x));
}

double boundFunc3Test(double x, double y)
{
	return 1;
}

double boundFunc4Test(double x, double y)
{
	return exp(sin(M_PI * y) * sin(M_PI * y));
}

double testFunc(double x, double y)
{
	return exp(sin(y * M_PI * x) * sin(y * M_PI * x));
}

double boundFunc1Main(double x, double y)
{
	return x * (1 - x);
}

double boundFunc2Main(double x, double y)
{
	return x * (1-x) * exp(x);
}

double boundFunc3Main(double x, double y)
{
	return (sin(M_PI*y)) * (sin(M_PI*y));
}

double boundFunc4Main(double x, double y)
{
	return abs(exp(sin(M_PI * y)) - 1);
}

double rightMain(double x, double y)
{
	return -abs(x - y);
}

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uxy���V2xyToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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


	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vxyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ uxyvxy���vxyV2xyToolStripMenuItem;

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
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vxyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxy���V2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uxyvxy���vxyV2xyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->label1->Text = L"����� ��������� �� X:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"����� ��������� �� Y:";
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
			this->dataGridView1->Size = System::Drawing::Size(1484, 652);
			this->dataGridView1->TabIndex = 1;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�����������ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->���������ToolStripMenuItem, this->������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1796, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->���ToolStripMenuItem,
					this->���ToolStripMenuItem, this->���ToolStripMenuItem, this->��������������������ToolStripMenuItem
			});
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->�����������ToolStripMenuItem->Text = L"����� ������";
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->���ToolStripMenuItem->Text = L"���";
			this->���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���ToolStripMenuItem_Click);
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->���ToolStripMenuItem->Text = L"���";
			this->���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���ToolStripMenuItem_Click);
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->���ToolStripMenuItem->Text = L"���";
			this->���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->��������������������ToolStripMenuItem->Text = L"��� ���������� �������";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->vxyToolStripMenuItem,
					this->uxy���V2xyToolStripMenuItem, this->uxyvxy���vxyV2xyToolStripMenuItem
			});
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->���������������ToolStripMenuItem->Text = L"�������� �������";
			// 
			// vxyToolStripMenuItem
			// 
			this->vxyToolStripMenuItem->Name = L"vxyToolStripMenuItem";
			this->vxyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->vxyToolStripMenuItem->Text = L"v(x,y)";
			this->vxyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::vxyToolStripMenuItem_Click);
			// 
			// uxy���V2xyToolStripMenuItem
			// 
			this->uxy���V2xyToolStripMenuItem->Name = L"uxy���V2xyToolStripMenuItem";
			this->uxy���V2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxy���V2xyToolStripMenuItem->Text = L"u(x,y) ��� v2(x,y)";
			this->uxy���V2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxy���V2xyToolStripMenuItem_Click);
			// 
			// uxyvxy���vxyV2xyToolStripMenuItem
			// 
			this->uxyvxy���vxyV2xyToolStripMenuItem->Name = L"uxyvxy���vxyV2xyToolStripMenuItem";
			this->uxyvxy���vxyV2xyToolStripMenuItem->Size = System::Drawing::Size(307, 26);
			this->uxyvxy���vxyV2xyToolStripMenuItem->Text = L"|u(x,y)-v(x,y)| ��� |v(x,y) - v2(x,y)|";
			this->uxyvxy���vxyV2xyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uxyvxy���vxyV2xyToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������ToolStripMenuItem,
					this->��������ToolStripMenuItem
			});
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(101, 24);
			this->���������ToolStripMenuItem->Text = L"��� ������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������ToolStripMenuItem_Click);
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
			this->label3->Text = L"����. ����� �����:";
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
			this->label4->Text = L"�������� ������:";
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
			this->button1->Text = L"������";
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
			this->label5->Text = L"w (��� ���):";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(175, 207);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(87, 22);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"1,2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1796, 730);
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
			this->Text = L"������������ ������ �2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		metType = MET::MVR;
		�����������ToolStripMenuItem->Text = "���";
		textBox5->Enabled = true;
	}
private: System::Void ���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MMN;
	�����������ToolStripMenuItem->Text = "���";
	textBox5->Enabled = false;
}
private: System::Void ���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG;
	�����������ToolStripMenuItem->Text = "���";
	textBox5->Enabled = false;
}
private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG_UN;
	�����������ToolStripMenuItem->Text = "��� ���������� �������";
	textBox5->Enabled = false;
}

private: System::Void vxyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::NUM;
	���������������ToolStripMenuItem->Text = "v(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxy���V2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::TRUE_OR_HALF;
	���������������ToolStripMenuItem->Text = "u(x,y) ��� v2(x,y)";
	if (started)
	{
		drawTable();
	}
}
private: System::Void uxyvxy���vxyV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::SUB;
	���������������ToolStripMenuItem->Text = "|u(x,y)-v(x,y)| ��� |v(x,y) - v2(x,y)|";
	if (started)
	{
		drawTable();
	}
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
	for (int i = 2; i <= n + 2; i++)
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
	type2V result(x.size(), typeV(y.size()));

	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < y.size(); j++)	
		{
			result[i][j] = testFunc(x[i], y[j]);
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
private: void calculateMVR_test()
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
	MVR_Met test(a, b, c, d, n, m, w);
	test.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	test.initRight(ptRight);
	int iterCount = test.solve(maxStep, acc);
	double acc = test.getAccuracy();
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
}
private: void calculateMVR_main()
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
	MVR_Met main(a, b, c, d, n, m, w);
	main.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	main.initRight(ptRight);
	int iterCount = main.solve(maxStep, acc);
	double acc = main.getAccuracy();
	type2V res = main.getV();
	typeV x = main.getX();
	typeV y = main.getY();

	MVR_Met main2(a, b, c, d, n * 2, m * 2, w);
	main2.initBounds(pt1, pt2, pt3, pt4, a, b, c, d);
	main2.initRight(ptRight);
	int iterCount2 = main2.solve(maxStep * 2, acc * 1e-2);
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
}
private: void calculateMVR()
{
	if (taskType == TASK::TEST)
	{
		calculateMVR_test();
	}
	else
	{
		calculateMVR_main();
	}
}
private: void calculateMMN()
{
}
private: void calculateMSG()
{
}
private: void calculateMSG_UN()
{
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
		return metData.V[i][j];
	case VAL::TRUE_OR_HALF:
		return metData.U_V2[i][j];
	case VAL::SUB:
		return metData.Sub[i][j];
	}
	return 0;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	handleValues();
	calculate();
	drawTable();
	started = true;
}
private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ s = Directory::GetCurrentDirectory();
	String^ processDir = s + "\\..\\x64\\Debug\\HelpPr.exe";
	auto process = Process::Start(processDir);
}
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::TEST;
	���������ToolStripMenuItem->Text = "��������";
}
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::MAIN;
	���������ToolStripMenuItem->Text = "��������";
}
String^ removeDots(String^ s)
{
	return s->Replace(".", ",");
}
};
}
