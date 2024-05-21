#pragma once

#include <vector>

enum class TASK_TYPE
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

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TASK_TYPE taskType = TASK_TYPE::MVR;
		VAL valType = VAL::NUM;
		int m = 0;
		int n = 0;
		int maxStep = 0;
		double acc = 0;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
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
	private: System::Windows::Forms::TabControl^ tabControl1;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
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
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::ToolStripMenuItem^ ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vxyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uxy»ÎËV2xyToolStripMenuItem;
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
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
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(268, 43);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1181, 416);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView1);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1173, 387);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"“‡·ÎËˆ‡ ‰Îˇ ÓÒÌÓ‚ÌÓÈ";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 6);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1161, 375);
			this->dataGridView1->TabIndex = 1;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView2);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1173, 387);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"“‡·ÎËˆ‡ ‰Îˇ ÚÂÒÚÓ‚ÓÈ";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(6, 6);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(1161, 375);
			this->dataGridView2->TabIndex = 2;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->‚˚·ÓÃÂÚÓ‰‡ToolStripMenuItem,
					this->ÁÌ‡˜ÂÌËˇ“‡·ÎËˆ˚ToolStripMenuItem, this->ÒÔ‡‚Í‡ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1461, 28);
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
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"—Ô‡‚Í‡";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ÒÔ‡‚Í‡ToolStripMenuItem_Click);
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
			this->label4->Location = System::Drawing::Point(16, 178);
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
			this->button1->Location = System::Drawing::Point(19, 217);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"–Â¯ËÚ¸";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1461, 471);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"À‡·Ó‡ÚÓÌ‡ˇ ‡·ÓÚ‡ π2";
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Ï¬–ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		taskType = TASK_TYPE::MVR;
	}
private: System::Void ÏÃÕToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK_TYPE::MMN;
}
private: System::Void Ï—√ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK_TYPE::MSG;
}
private: System::Void Ï—√”ÌËÍ‡Î¸Ì‡ˇŒ·Î‡ÒÚ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	taskType = TASK_TYPE::MSG_UN;
}

private: System::Void vxyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::NUM;
}
private: System::Void uxy»ÎËV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::TRUE_OR_HALF;
}
private: System::Void uxyvxy»ÎËvxyV2xyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	valType = VAL::SUB;
}
private: System::Void drawMainTable()
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
	drawMainTable();
}
private: System::Void ÒÔ‡‚Í‡ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// ¬˚‚Ó‰ ÒÔ‡‚ÍË
}
};
}
