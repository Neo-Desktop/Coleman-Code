#include "stdafx.h"
#include "Form1.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Data;
using namespace Project4;


public ref class LottoBall
{

public:
	LottoBall(int minval, int maxval, Form1^ form1);
	~LottoBall();

	int getCurrentValue();
	int num;

	System::Void start();
	System::Void stop();
	System::Void initThread();

private:
	int minVal;
	int maxVal;
	int seedValue;

	Form1^ formptr;

	Random^ r;

	bool threadStop;
	Thread^ thread;
	System::Void run();

};