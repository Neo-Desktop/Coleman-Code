
#include "LottoBall.h"

LottoBall::LottoBall(int minval, int maxval, Form1^ form1)
{
	minVal = minval;
	maxVal = maxval;

	threadStop = false;
	num = 0;

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
	for(int i = 0; i < 100; ++i)
	{
		seed += r->Next(i, 9999 + i);
	}
	r = gcnew Random(seed);
	thread = gcnew Thread(gcnew ThreadStart(&this->run));
}

System::Void LottoBall::run()
{
	String^ threadname = Thread::CurrentThread->Name;
	int id = 0;
	Int32::TryParse(threadname, id);

	while (!this->threadStop)
	{
		this->num = r->Next(minVal, maxVal);
		formptr->affixNumber(id, this->num);
	}
}

int LottoBall::getCurrentValue()
{
	return this->num;
}

System::Void LottoBall::start()
{
	this->threadStop = false;
	thread->Start();
}

System::Void LottoBall::stop()
{
	this->threadStop = true;
}