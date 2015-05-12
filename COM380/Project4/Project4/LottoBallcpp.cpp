#pragma once
#include "stdafx.h"

namespace Project4
{

	LottoBall::LottoBall(int minval, int maxval, Form1^ form1, int num1)
	{
		minVal = minval;
		maxVal = maxval;

		threadStop = false;
		poolRun = false;
		threadAbort = false;

		num = num1;

		formptr = form1;
	}

	LottoBall::~LottoBall()
	{
		thread->Abort();
	}

	System::Void LottoBall::initThread()
	{
		r = gcnew Random();
		long long seed = 0;
		int min = r->Next(0, 1000);
		int max = r->Next(0, 1000);

		if (min > max)
		{
			int hold = max;
			max = min;
			min = hold;
		}

		for (int i = min; i < max; i++)
		{
			seed += r->Next(min, max);
			if (seed % 500 > 250)
			{
				seed += r->Next(min, max) + num;
			}
		}

		r = gcnew Random(seed);
		thread = gcnew Thread(gcnew ThreadStart(this, &LottoBall::run));
		thread->Name = num.ToString();
	}

	System::Boolean LottoBall::isUnique(int num)
	{
		for (int i = 0; i < Form1::numbers->Length; i++)
		{
			if (num == Form1::numbers[i])
			{
				return false;
			}
		}
		return true;
	}

	System::Void LottoBall::run()
	{
		String^ threadname = Thread::CurrentThread->Name;
		int id = 0;
		Int32::TryParse(threadname, id);

		while (!threadAbort)
		{
			this->num = r->Next(1, 199999) % maxVal + 1;
			if (!threadStop)
			{
				if (this->isUnique(this->num))
				{
					Form1::numbers[id] = num;
					formptr->SetNum(id, this->num);
				}
			}
			Thread::Sleep(r->Next(0, 10));
		}
	}

	int LottoBall::getCurrentValue()
	{
		return this->num;
	}

	System::Void LottoBall::start()
	{
		this->threadStop = false;
		if (!poolRun)
		{
			thread->Start();
			poolRun = true;
		}
	}

	System::Void LottoBall::stop()
	{
		this->threadStop = true;
	}

	System::Boolean LottoBall::isDisplaying()
	{
		return !this->threadStop;
	}

	System::Boolean LottoBall::isRunning()
	{
		return !this->threadAbort;
	}

	System::Boolean LottoBall::getPoolRun()
	{
		return this->poolRun;
	}

	System::Void LottoBall::abort()
	{
		this->threadAbort = true;
	}

}