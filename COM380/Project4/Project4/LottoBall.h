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
	ref class Form1;

	public ref class LottoBall
	{

	public:
		LottoBall(int minval, int maxval, Form1^ form1, int num1);
		~LottoBall();

		int getCurrentValue();
		int num;

		System::Void start();
		System::Void stop();
		System::Void abort();

		System::Void initThread();
		System::Boolean isRunning();
		System::Boolean isDisplaying();
		System::Boolean getPoolRun();

	private:
		int minVal;
		int maxVal;
		int seedValue;
		bool poolRun;
		bool threadAbort;
		bool threadStop;
		Form1^ formptr;

		Random^ r;

		Thread^ thread;
		System::Void run();
		System::Boolean isUnique(int num);

	};
}
