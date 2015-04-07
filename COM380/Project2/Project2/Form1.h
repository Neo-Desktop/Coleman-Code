#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox16;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox15;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox14;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox13;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox12;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox11;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox10;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox9;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox8;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox7;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox6;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox5;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox16 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox15 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox14 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox13 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox12 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox11 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox10 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox9 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox8 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox7 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->maskedTextBox2);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(270, 176);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Employee Information";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Location = System::Drawing::Point(100, 45);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->numericUpDown1->Size = System::Drawing::Size(157, 20);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->ThousandsSeparator = true;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1350, 0, 0, 131072});
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(99, 19);
			this->maskedTextBox2->Mask = L"#############";
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(158, 20);
			this->maskedTextBox2->TabIndex = 0;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(75, 13);
			this->label9->TabIndex = 101;
			this->label9->Text = L"Hourly Wage: ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(23, 143);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(61, 13);
			this->label8->TabIndex = 104;
			this->label8->Text = L"Last Name:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(99, 111);
			this->textBox4->MaxLength = 1;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(32, 20);
			this->textBox4->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(14, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(71, 13);
			this->label7->TabIndex = 103;
			this->label7->Text = L"Middle Initial: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 88);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 13);
			this->label6->TabIndex = 102;
			this->label6->Text = L"First Name: ";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(99, 85);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(158, 20);
			this->textBox3->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(99, 140);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 100;
			this->label1->Text = L"Employee ID:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(703, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->dateTimePicker2);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Location = System::Drawing::Point(293, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(398, 176);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Pay Period";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(276, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 13);
			this->label5->TabIndex = 108;
			this->label5->Text = L"15 days";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(206, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 107;
			this->label4->Text = L"Total Days: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(64, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 106;
			this->label3->Text = L"Ending Date: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 105;
			this->label2->Text = L"Beginning Date: ";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(142, 76);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 1;
			this->dateTimePicker2->Value = System::DateTime(2012, 1, 10, 0, 0, 0, 0);
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker2_ValueChanged);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(142, 50);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->Value = System::DateTime(2012, 8, 21, 0, 0, 0, 0);
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker1_ValueChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->label37);
			this->groupBox3->Controls->Add(this->label36);
			this->groupBox3->Controls->Add(this->label35);
			this->groupBox3->Controls->Add(this->label34);
			this->groupBox3->Controls->Add(this->label33);
			this->groupBox3->Controls->Add(this->label32);
			this->groupBox3->Controls->Add(this->label31);
			this->groupBox3->Controls->Add(this->label30);
			this->groupBox3->Controls->Add(this->label29);
			this->groupBox3->Controls->Add(this->label28);
			this->groupBox3->Controls->Add(this->label27);
			this->groupBox3->Controls->Add(this->label26);
			this->groupBox3->Controls->Add(this->label25);
			this->groupBox3->Controls->Add(this->label24);
			this->groupBox3->Controls->Add(this->label18);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->maskedTextBox16);
			this->groupBox3->Controls->Add(this->maskedTextBox15);
			this->groupBox3->Controls->Add(this->maskedTextBox14);
			this->groupBox3->Controls->Add(this->maskedTextBox13);
			this->groupBox3->Controls->Add(this->maskedTextBox12);
			this->groupBox3->Controls->Add(this->maskedTextBox11);
			this->groupBox3->Controls->Add(this->maskedTextBox10);
			this->groupBox3->Controls->Add(this->maskedTextBox9);
			this->groupBox3->Controls->Add(this->maskedTextBox8);
			this->groupBox3->Controls->Add(this->maskedTextBox7);
			this->groupBox3->Controls->Add(this->maskedTextBox6);
			this->groupBox3->Controls->Add(this->maskedTextBox5);
			this->groupBox3->Controls->Add(this->maskedTextBox4);
			this->groupBox3->Controls->Add(this->maskedTextBox3);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Location = System::Drawing::Point(12, 209);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(679, 159);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Time Card";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 30);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 123;
			this->button3->Text = L"&Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label37
			// 
			this->label37->Location = System::Drawing::Point(553, 105);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(70, 13);
			this->label37->TabIndex = 122;
			this->label37->Text = L"09/05";
			this->label37->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label36
			// 
			this->label36->Location = System::Drawing::Point(477, 105);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(70, 13);
			this->label36->TabIndex = 121;
			this->label36->Text = L"09/04";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label35
			// 
			this->label35->Location = System::Drawing::Point(401, 105);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(70, 13);
			this->label35->TabIndex = 120;
			this->label35->Text = L"09/03";
			this->label35->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label34
			// 
			this->label34->Location = System::Drawing::Point(325, 105);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(70, 13);
			this->label34->TabIndex = 119;
			this->label34->Text = L"09/02";
			this->label34->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label33
			// 
			this->label33->Location = System::Drawing::Point(249, 105);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(70, 13);
			this->label33->TabIndex = 118;
			this->label33->Text = L"09/01";
			this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label32
			// 
			this->label32->Location = System::Drawing::Point(173, 105);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(70, 13);
			this->label32->TabIndex = 117;
			this->label32->Text = L"08/30";
			this->label32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label31
			// 
			this->label31->Location = System::Drawing::Point(97, 105);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(70, 13);
			this->label31->TabIndex = 116;
			this->label31->Text = L"08/29";
			this->label31->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label30
			// 
			this->label30->Location = System::Drawing::Point(553, 50);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(70, 13);
			this->label30->TabIndex = 115;
			this->label30->Text = L"08/28";
			this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label29
			// 
			this->label29->Location = System::Drawing::Point(477, 50);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(70, 13);
			this->label29->TabIndex = 114;
			this->label29->Text = L"08/27";
			this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label28
			// 
			this->label28->Location = System::Drawing::Point(401, 50);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(70, 13);
			this->label28->TabIndex = 113;
			this->label28->Text = L"08/25";
			this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label27
			// 
			this->label27->Location = System::Drawing::Point(325, 50);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(70, 13);
			this->label27->TabIndex = 112;
			this->label27->Text = L"08/24";
			this->label27->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label26
			// 
			this->label26->Location = System::Drawing::Point(249, 50);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(70, 13);
			this->label26->TabIndex = 111;
			this->label26->Text = L"08/23";
			this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label25
			// 
			this->label25->Location = System::Drawing::Point(173, 50);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(70, 13);
			this->label25->TabIndex = 110;
			this->label25->Text = L"08/22";
			this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label24
			// 
			this->label24->Location = System::Drawing::Point(97, 50);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(70, 13);
			this->label24->TabIndex = 109;
			this->label24->Text = L"08/21";
			this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label18
			// 
			this->label18->Location = System::Drawing::Point(553, 15);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(70, 13);
			this->label18->TabIndex = 106;
			this->label18->Text = L"Sunday";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->Location = System::Drawing::Point(477, 15);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(70, 13);
			this->label17->TabIndex = 105;
			this->label17->Text = L"Saturday";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->Location = System::Drawing::Point(401, 15);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(70, 13);
			this->label16->TabIndex = 104;
			this->label16->Text = L"Friday";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->Location = System::Drawing::Point(325, 15);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(70, 13);
			this->label15->TabIndex = 103;
			this->label15->Text = L"Thursday";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->Location = System::Drawing::Point(249, 15);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(70, 13);
			this->label14->TabIndex = 102;
			this->label14->Text = L"Wednesday";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(173, 15);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(70, 13);
			this->label13->TabIndex = 101;
			this->label13->Text = L"Tuesday";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(97, 15);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(70, 13);
			this->label12->TabIndex = 100;
			this->label12->Text = L"Monday";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// maskedTextBox16
			// 
			this->maskedTextBox16->Location = System::Drawing::Point(553, 121);
			this->maskedTextBox16->Mask = L"##.##";
			this->maskedTextBox16->Name = L"maskedTextBox16";
			this->maskedTextBox16->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox16->TabIndex = 13;
			this->maskedTextBox16->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox16->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox15
			// 
			this->maskedTextBox15->Location = System::Drawing::Point(477, 121);
			this->maskedTextBox15->Mask = L"##.##";
			this->maskedTextBox15->Name = L"maskedTextBox15";
			this->maskedTextBox15->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox15->TabIndex = 12;
			this->maskedTextBox15->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox15->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox14
			// 
			this->maskedTextBox14->Location = System::Drawing::Point(401, 121);
			this->maskedTextBox14->Mask = L"##.##";
			this->maskedTextBox14->Name = L"maskedTextBox14";
			this->maskedTextBox14->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox14->TabIndex = 11;
			this->maskedTextBox14->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox14->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox13
			// 
			this->maskedTextBox13->Location = System::Drawing::Point(325, 121);
			this->maskedTextBox13->Mask = L"##.##";
			this->maskedTextBox13->Name = L"maskedTextBox13";
			this->maskedTextBox13->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox13->TabIndex = 10;
			this->maskedTextBox13->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox13->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox12
			// 
			this->maskedTextBox12->Location = System::Drawing::Point(249, 121);
			this->maskedTextBox12->Mask = L"##.##";
			this->maskedTextBox12->Name = L"maskedTextBox12";
			this->maskedTextBox12->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox12->TabIndex = 9;
			this->maskedTextBox12->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox12->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox11
			// 
			this->maskedTextBox11->Location = System::Drawing::Point(173, 121);
			this->maskedTextBox11->Mask = L"##.##";
			this->maskedTextBox11->Name = L"maskedTextBox11";
			this->maskedTextBox11->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox11->TabIndex = 8;
			this->maskedTextBox11->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox11->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox10
			// 
			this->maskedTextBox10->Location = System::Drawing::Point(97, 121);
			this->maskedTextBox10->Mask = L"##.##";
			this->maskedTextBox10->Name = L"maskedTextBox10";
			this->maskedTextBox10->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox10->TabIndex = 7;
			this->maskedTextBox10->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox10->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox9
			// 
			this->maskedTextBox9->Location = System::Drawing::Point(553, 66);
			this->maskedTextBox9->Mask = L"##.##";
			this->maskedTextBox9->Name = L"maskedTextBox9";
			this->maskedTextBox9->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox9->TabIndex = 6;
			this->maskedTextBox9->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox9->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox8
			// 
			this->maskedTextBox8->Location = System::Drawing::Point(477, 66);
			this->maskedTextBox8->Mask = L"##.##";
			this->maskedTextBox8->Name = L"maskedTextBox8";
			this->maskedTextBox8->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox8->TabIndex = 5;
			this->maskedTextBox8->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox8->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox7
			// 
			this->maskedTextBox7->Location = System::Drawing::Point(401, 66);
			this->maskedTextBox7->Mask = L"##.##";
			this->maskedTextBox7->Name = L"maskedTextBox7";
			this->maskedTextBox7->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox7->TabIndex = 4;
			this->maskedTextBox7->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox7->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox6
			// 
			this->maskedTextBox6->Location = System::Drawing::Point(325, 66);
			this->maskedTextBox6->Mask = L"##.##";
			this->maskedTextBox6->Name = L"maskedTextBox6";
			this->maskedTextBox6->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox6->TabIndex = 3;
			this->maskedTextBox6->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox6->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox5
			// 
			this->maskedTextBox5->Location = System::Drawing::Point(249, 66);
			this->maskedTextBox5->Mask = L"##.##";
			this->maskedTextBox5->Name = L"maskedTextBox5";
			this->maskedTextBox5->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox5->TabIndex = 2;
			this->maskedTextBox5->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox5->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(173, 66);
			this->maskedTextBox4->Mask = L"##.##";
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox4->TabIndex = 1;
			this->maskedTextBox4->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox4->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(97, 66);
			this->maskedTextBox3->Mask = L"##.##";
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(70, 20);
			this->maskedTextBox3->TabIndex = 0;
			this->maskedTextBox3->TextChanged += gcnew System::EventHandler(this, &Form1::maskedText_TextChanged);
			this->maskedTextBox3->Enter += gcnew System::EventHandler(this, &Form1::maskedTextBox_Enter);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 124);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(82, 13);
			this->label11->TabIndex = 108;
			this->label11->Text = L"Second Week: ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(27, 69);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(64, 13);
			this->label10->TabIndex = 107;
			this->label10->Text = L"First Week: ";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button2);
			this->groupBox4->Controls->Add(this->textBox8);
			this->groupBox4->Controls->Add(this->label23);
			this->groupBox4->Controls->Add(this->label22);
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Controls->Add(this->textBox6);
			this->groupBox4->Controls->Add(this->textBox5);
			this->groupBox4->Controls->Add(this->textBox1);
			this->groupBox4->Controls->Add(this->label20);
			this->groupBox4->Controls->Add(this->label19);
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Location = System::Drawing::Point(12, 374);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(679, 120);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Payroll Processing";
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(548, 73);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"&Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(527, 42);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 6;
			this->textBox8->TabStop = false;
			this->textBox8->Text = L"$0.00";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(443, 45);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(78, 13);
			this->label23->TabIndex = 104;
			this->label23->Text = L"Total Earnings:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(341, 23);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(43, 13);
			this->label22->TabIndex = 103;
			this->label22->Text = L"Amount";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(204, 23);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(35, 13);
			this->label21->TabIndex = 102;
			this->label21->Text = L"Hours";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(317, 70);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 5;
			this->textBox7->TabStop = false;
			this->textBox7->Text = L"$0.00";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(317, 42);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 4;
			this->textBox6->TabStop = false;
			this->textBox6->Text = L"$0.00";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(178, 70);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 3;
			this->textBox5->TabStop = false;
			this->textBox5->Text = L"0.00";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(178, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"0.00";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(120, 73);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(52, 13);
			this->label20->TabIndex = 101;
			this->label20->Text = L"Overtime:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(125, 45);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(47, 13);
			this->label19->TabIndex = 100;
			this->label19->Text = L"Regular:";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(12, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"&Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->CreatePrompt = true;
			this->saveFileDialog1->DefaultExt = L"txt";
			this->saveFileDialog1->Title = L"Timecard save";
			// 
			// Form1
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(703, 506);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Employee Payroll";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Collections::ArrayList dayLabels;
	private: System::Collections::ArrayList dateLabels;
	private: System::Collections::ArrayList hourTextBoxes;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			//initalize day of week labels
			dayLabels.Add(label12);
			dayLabels.Add(label13);
			dayLabels.Add(label14);
			dayLabels.Add(label15);
			dayLabels.Add(label16);
			dayLabels.Add(label17);
			dayLabels.Add(label18);

			//initalize date labels
			dateLabels.Add(label24);
			dateLabels.Add(label25);
			dateLabels.Add(label26);
			dateLabels.Add(label27);
			dateLabels.Add(label28);
			dateLabels.Add(label29);
			dateLabels.Add(label30);
			dateLabels.Add(label31);
			dateLabels.Add(label32);
			dateLabels.Add(label33);
			dateLabels.Add(label34);
			dateLabels.Add(label35);
			dateLabels.Add(label36);
			dateLabels.Add(label37);

			//initalize hour boxes
			hourTextBoxes.Add(maskedTextBox3);
			hourTextBoxes.Add(maskedTextBox4);
			hourTextBoxes.Add(maskedTextBox5);
			hourTextBoxes.Add(maskedTextBox6);
			hourTextBoxes.Add(maskedTextBox7);
			hourTextBoxes.Add(maskedTextBox8);
			hourTextBoxes.Add(maskedTextBox9);
			hourTextBoxes.Add(maskedTextBox10);
			hourTextBoxes.Add(maskedTextBox11);
			hourTextBoxes.Add(maskedTextBox12);
			hourTextBoxes.Add(maskedTextBox13);
			hourTextBoxes.Add(maskedTextBox14);
			hourTextBoxes.Add(maskedTextBox15);
			hourTextBoxes.Add(maskedTextBox16);

			// initialize todays date
			DateTime today = DateTime::Now;
			DateTime set1 = DateTime::Now;
			DateTime set2 = DateTime::Now;
			if (today.Day <= 15) // if today is the 15th, we're still in the first pay period
			{
				set1 = DateTime(today.Year, today.Month, 1);
				set2 = DateTime(today.Year, today.Month, 15);
			}
			else
			{
				// 16th to the End of the month
				set1 = DateTime(today.Year, today.Month, 16);
				set2 = DateTime(today.Year, today.Month, DateTime::DaysInMonth(today.Year, today.Month));
			}
			// now set it
			dateTimePicker1->Value = set1;
			dateTimePicker2->Value = set2;

			// and label it
			label5->Text = (set2.Day - set1.Day) + 1 + " days";
		}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 Application::Exit();
		 }
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 DateTime set1 = dateTimePicker1->Value;
			 DateTime set2 = dateTimePicker2->Value;
			 label5->Text = (set2.Day - set1.Day) + 1 + " days";
			 DateTime helper = set1;
			 Label^ hold;
			 for (int i = 0; i < dayLabels.Count; i++)
			 {
				 hold = safe_cast<Label^>(dayLabels[i]);
				 String^ holds = helper.DayOfWeek.ToString();
				 if (holds->Length <= 1)
				 {
					 holds = "0" + holds;
				 }
				 hold->Text = holds;
				 helper = helper.AddDays(1);
			 }

			 helper = set1;
			 for (int i = 0; i < dateLabels.Count; i++)
			 {
				 hold = safe_cast<Label^>(dateLabels[i]);

				 String^ holds1 = helper.Month.ToString();
				 if (holds1->Length <=1)
					 holds1 = "0" + holds1;

				 String^ holds2 = helper.Day.ToString();
				 if (holds2->Length <=1)
					 holds2 = "0" + holds2;

				 hold->Text = holds1 + "/" + holds2;
				 helper = helper.AddDays(1);
			 }
		 }
private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 DateTime set1 = dateTimePicker1->Value;
			 DateTime set2 = dateTimePicker2->Value;
			 label5->Text = (set2.Day - set1.Day) + 1 + " days";
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			  System::Windows::Forms::DialogResult d = MessageBox::Show("Are you sure you wish to exit?",
																		"Application Close",
																		MessageBoxButtons::YesNo,
																		MessageBoxIcon::Question,
																		MessageBoxDefaultButton::Button2);
			 if ( d == System::Windows::Forms::DialogResult::Yes )
			 {
				 Application::Exit();
			 }
		 }
private: System::Void update_hours()
		 {
			 Decimal hours1 = 0;
			 Decimal hours2 = 0;
			 Decimal tryHours = 0;

			 MaskedTextBox^ hold;
			 for (int i = 0; i < hourTextBoxes.Count; i++)
			 {
				 hold = safe_cast<MaskedTextBox^>(hourTextBoxes[i]);
				 Decimal::TryParse(hold->Text, tryHours);
				 if (i < hourTextBoxes.Count/2)
				 {
					 hours1 += tryHours;
				 }
				 else
				 {
					 hours2 += tryHours;
				 }
			 }
			 Decimal overtime1 = hours1 - 40;
			 Decimal overtime2 = hours2 - 40;
			 if (overtime1 > 0)
			 {
				 hours1 = 40;
			 }
			 else
			 {
				 overtime1 = 0;
			 }
			 if (overtime2 > 0)
			 {
				 hours2 = 40;
			 }
			 else
			 {
				 overtime2 = 0;
			 }

			 textBox1->Text = String::Format("{0:00.00}", hours1 + hours2);
			 textBox5->Text = String::Format("{0:00.00}", overtime1 + overtime2);

			 Decimal wage = 0;
			 Decimal::TryParse(numericUpDown1->Text, wage);
			 Decimal calcWage = (wage * hours1) + (wage * hours2);
			 textBox6->Text = String::Format("{0:C2}", calcWage );
			 Decimal calcOverTime = (wage * (Decimal)1.5 * overtime1) + (wage * (Decimal)1.5 * overtime2);
			 textBox7->Text = String::Format("{0:C2}", calcOverTime);

			 Decimal total = calcWage + calcOverTime;
			 textBox8->Text = String::Format("{0:C2}", total);
			 
		 }

private: System::Void maskedText_TextChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 update_hours();
		 }
private: System::Void maskedTextBox_Enter(System::Object^  sender, System::EventArgs^  e)
		 {
			 MaskedTextBox^ hold;
			 hold = safe_cast<MaskedTextBox^>(sender);
			 hold->SelectionStart = 0;
			 hold->SelectionLength = hold->Text->Length;
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 MaskedTextBox^ hold;
			 for(int i = 0; i < hourTextBoxes.Count; i++)
			 {
				 hold = safe_cast<MaskedTextBox^>(hourTextBoxes[i]);
				 hold->Text = "";
			 }
		 }
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 update_hours();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 saveFileDialog1->FileName = "Employee-" + maskedTextBox2->Text + ".txt";
			 System::Windows::Forms::DialogResult d = saveFileDialog1->ShowDialog();

			 if ( d == System::Windows::Forms::DialogResult::OK)
			 {
				 //MessageBox::Show(saveFileDialog1->FileName, "Save file");
				 FileInfo^ fi1 = gcnew FileInfo( saveFileDialog1->FileName );
				 StreamWriter^ sw = fi1->CreateText();

				 Decimal wage = 0;
				 Decimal::TryParse(numericUpDown1->Text, wage);

				 if (fi1->Length <= 0)
				 {
					 try
					 {
						 sw->WriteLine("EMPLOYEE TIMECARD");
						 sw->WriteLine(maskedTextBox2->Text +"\t"+ textBox3->Text +"\t"+ textBox4->Text +".\t"+ textBox2->Text);
						 sw->WriteLine("Pay rate: $" + wage.ToString() + "/hr");
						 sw->WriteLine("-----------------------------");
					 }
					 catch (Exception^ e)
					 {
						 MessageBox::Show("Error creating file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
				 }
				 try
				 {
					Label^ hold1;
					MaskedTextBox^ hold2;
					StringBuilder^ out1 = gcnew StringBuilder("",50);
					StringBuilder^ out2 = gcnew StringBuilder("",50);
					StringBuilder^ out3 = gcnew StringBuilder("",50);
					StringBuilder^ out4 = gcnew StringBuilder("",50);
					StringBuilder^ out5 = gcnew StringBuilder("",50);

					Decimal hours1 = 0;
					Decimal hours2 = 0;
					Decimal tryHours = 0;

					for (int i = 0; i < dateLabels.Count; i++)
					{
						hold1 = safe_cast<Label^>(dateLabels[i]);
						hold2 = safe_cast<MaskedTextBox^>(hourTextBoxes[i]);
						Decimal::TryParse(hold2->Text, tryHours);

						if (i < dateLabels.Count/2)
						{
							out1->Append(hold1->Text + "\t");
							out2->Append(hold2->Text + "\t");
							hours1 += tryHours;
						}
						else
						{
							out3->Append(hold1->Text + "\t");
							out4->Append(hold2->Text + "\t");
							hours2 += tryHours;
						}
					}

					Decimal overtime1 = hours1 - 40;
					Decimal overtime2 = hours2 - 40;
					if (overtime1 > 0)
					{
						hours1 = 40;
					}
					else
					{
						overtime1 = 0;
					}
					if (overtime2 > 0)
					{
						hours2 = 40;
					}
					else
					{
						overtime2 = 0;
					}

					out5->Append("Regular hours: ");
					out5->AppendFormat("{0:00.00}\t", hours1 + hours2);
					out5->Append("Overtime hours: ");
					out5->AppendFormat("{0:00.00}\n", overtime1 + overtime2);
					
					Decimal calcWage = (wage * hours1) + (wage * hours2);
					out5->Append("Regular pay: ");
					out5->AppendFormat("{0:C2}\t", calcWage);

					Decimal calcOverTime = (wage * (Decimal)1.5 * overtime1) + (wage * (Decimal)1.5 * overtime2);
					out5->Append("Overtime pay: ");
					out5->AppendFormat("{0:C2}\n\n", calcOverTime);

					Decimal total = calcWage + calcOverTime;
					out5->Append("Total pay: ");
					out5->AppendFormat("{0:C2}", total);

					sw->WriteLine(out1->ToString());
					sw->WriteLine(out2->ToString());
					sw->WriteLine("");
					sw->WriteLine(out3->ToString());
					sw->WriteLine(out4->ToString());
					sw->WriteLine("");
					sw->WriteLine(out5->ToString());
				 }
				 catch (Exception^ e)
				 {
					MessageBox::Show("Error creating file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
				 finally
				 {
					 if ( sw )
						delete (IDisposable^)sw;
				 }
			 }
			 else
			 {
				 MessageBox::Show("File save canceled", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			 }
		 }
};
}

