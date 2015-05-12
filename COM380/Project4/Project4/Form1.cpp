#pragma once
#include "stdafx.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Data;

namespace Project4
{

	System::Void Form1::SetNum(int index, int number)
	{
		this->numbers[index] = number;
		switch (index)
		{
		case 0:
			if (this->textBox6->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number } );
			}
			else
			{
				textBox6->Text = number.ToString("D2");
			}
			break;
		case 1:
			if (this->textBox5->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number });
			}
			else
			{
				textBox5->Text = number.ToString("D2");
			}
			break;
		case 2:
			if (this->textBox4->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number });
			}
			else
			{
				textBox4->Text = number.ToString("D2");
			}
			break;
		case 3:
			if (this->textBox3->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number });
			}
			else
			{
				textBox3->Text = number.ToString("D2");
			}
			break;
		case 4:
			if (this->textBox2->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number });
			}
			else
			{
				textBox2->Text = number.ToString("D2");
			}
			break;
		case 5:
			if (this->textBox1->InvokeRequired)
			{
				this->Invoke(sndelegate, gcnew array <Object^> { index, number });
			}
			else
			{
				textBox1->Text = number.ToString("D2");
			}
			break;
		}
	}


	System::Void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
		sndelegate		= gcnew SetNumDelegate(this, &Form1::SetNum);
		numbers			= gcnew array < int > {0, 0, 0, 0, 0, 0};
		balls			= gcnew List < LottoBall^ > ;
		radioButtons	= gcnew List < RadioButton^ >;

		for (int i = 0; i < 5; i++)
		{
			balls->Add(gcnew LottoBall(1, 75, this, i));
			balls[i]->initThread();
		}

		balls->Add(gcnew LottoBall(1, 15, this, 5));
		balls[balls->Count-1]->initThread();

		radioButtons->Add(radioButton1);
		radioButtons->Add(radioButton2);
		radioButtons->Add(radioButton3);
		radioButtons->Add(radioButton4);
		radioButtons->Add(radioButton5);
		radioButtons->Add(radioButton6);

		for (int i = 0; i < radioButtons->Count; i++)
		{
			radioButtons[i]->Checked = true;
			balls[i]->start();
		}

	}

	System::Void Form1::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 0; i < balls->Count; i++)
		{
			balls[i]->stop();
		}

		Application::Exit();
	}

	System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		bool isRunning = false;
		bool poolRun = false;
		for (int i = 0; i < balls->Count; i++)
		{
			if (balls[i]->isDisplaying())
			{
				isRunning = true;
			}
		}

		if (isRunning)
		{
			for (int i = 0; i < balls->Count; i++)
			{
				balls[i]->stop();
				radioButtons[i]->Checked = false;
			}
			button1->Text = "Start";
		}
		else
		{
			for (int i = 0; i < balls->Count; i++)
			{
				balls[i]->start();
				radioButtons[i]->Checked = true;
			}
			button1->Text = "Stop";
		}
	}

	System::Void Form1::Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		for (int i = 0; i < balls->Count; i++)
		{
			if (balls[i]->isRunning())
			{
				balls[i]->abort();
				e->Cancel = true;
			}
		}
		if (e->Cancel)
		{
			MessageBox::Show("Cleaning up threads, please wait", "Hang on a momement", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}

	System::Void Form1::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		RadioButton^ rb = safe_cast<RadioButton^>(sender);

		String^ lastchar = rb->Name->Substring(rb->Name->Length - 1, 1);
		int out = -1;
		Int32::TryParse(lastchar, out);
		out = out - 1;
		if (out != -1)
		{
			if (!rb->Checked)
			{
				balls[out]->start();
			}
			else
			{
				balls[out]->stop();
			}
		}

		bool isRunning = false;
		for (int i = 0; i < balls->Count; i++)
		{
			if (balls[i]->isDisplaying())
			{
				isRunning = true;
			}
		}

		if (isRunning)
		{
			button1->Text = "Stop";
		}
		else
		{
			button1->Text = "Start";
		}

		rb->Checked = !rb->Checked;
	}

}