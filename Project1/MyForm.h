#pragma once


#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

# define M_PI           3.14159265358979323846


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

struct Data
{
	static std::vector<std::vector<double>> V_main;
	static std::vector<std::vector<double>> V_test;
	static std::vector<std::vector<double>> V2;
	static std::vector<std::vector<double>> U;
};

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ òèïÇàäà÷èToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ òåñòîâàÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îñíîâíàÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uxyÈëèV2xyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîìîùüToolStripMenuItem;

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
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(300, 66);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1149, 375);
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
			this->menuStrip1->Size = System::Drawing::Size(1461, 28);
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
			this->label3->Location = System::Drawing::Point(16, 145);
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
			this->label4->Location = System::Drawing::Point(16, 178);
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
			this->textBox4->Text = L"0,00001";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 217);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Ğåøèòü";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1461, 471);
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
		metType = MET::MVR;
		âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÂĞ";
	}
private: System::Void ìÌÍToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MMN;
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÌÍ";
}
private: System::Void ìÑÃToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG;
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÑÃ";
}
private: System::Void ìÑÃÓíèêàëüíàÿÎáëàñòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	metType = MET::MSG_UN;
	âûáîğÌåòîäàToolStripMenuItem->Text = "ÌÑÃ óíèêàëüíàÿ îáëàñòü";
}

private: System::Void vxyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::NUM;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "v(x,y)";
}
private: System::Void uxyÈëèV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::TRUE_OR_HALF;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "u(x,y) èëè v2(x,y)";
}
private: System::Void uxyvxyÈëèvxyV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::SUB;
	çíà÷åíèÿÒàáëèöûToolStripMenuItem->Text = "|u(x,y)-v(x,y)| èëè |v(x,y) - v2(x,y)|";
}
private: System::Void drawTable()
{
	DataGridViewColumn^ col = gcnew DataGridViewColumn();
	col->CellTemplate = gcnew DataGridViewTextBoxCell();
	col->HeaderText = "";
	dataGridView1->Columns->Add(col);
	DataGridViewColumn^ col2 = gcnew DataGridViewColumn();
	col2->CellTemplate = gcnew DataGridViewTextBoxCell();
	col2->HeaderText = "xi";
	dataGridView1->Columns->Add(col2);
	for (int i = 0; i <= n; i++)
	{
		DataGridViewColumn^ temp = gcnew DataGridViewColumn();
		temp->CellTemplate = gcnew DataGridViewTextBoxCell();
		temp->HeaderText = "x" + Convert::ToString(i);
		dataGridView1->Columns->Add(temp);
	}
	dataGridView1->Rows->Add(m + 2);
	dataGridView1->Rows[0]->Cells[0]->Value = "yj";
	dataGridView1->Rows[0]->Cells[1]->Value = "j/i";
	for (int i = 1; i <= m + 1; i++)
	{
		dataGridView1->Rows[i]->Cells[0]->Value = "y" + Convert::ToString(i - 1);
	}
	for (int i = 1; i <= m + 1; i++)
	{
		dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(i - 1);
	}
	for (int i = 2; i <= m + 2; i++)
	{
		dataGridView1->Rows[0]->Cells[i]->Value = Convert::ToString(i - 2);
	}
}
private: System::Void handleValues()
{
	n = Convert::ToInt32(textBox1->Text);
	m = Convert::ToInt32(textBox2->Text);
	maxStep = Convert::ToInt32(textBox3->Text);
	acc = Convert::ToDouble(textBox4->Text);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	handleValues();
	drawTable();
}
private: System::Void ïîìîùüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Process::Start("C:/Users/lesni/lab2iter/Project1/HelpPr.exe");
}
private: System::Void òåñòîâàÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::TEST;
	òèïÇàäà÷èToolStripMenuItem->Text = "Òåñòîâàÿ";
}
private: System::Void îñíîâíàÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK::MAIN;
	òèïÇàäà÷èToolStripMenuItem->Text = "Îñíîâíàÿ";
}
};
}
