
#include "LottoBall.h"
#include "Form1.h"

namespace Project4
{

	LottoBall::LottoBall(int minval, int maxval)
	{
		minVal = minval;
		maxVal = maxval;

		threadStop = false;
		num = 0;
		thread = gcnew Thread(gcnew ThreadStart(&run));

	}

	LottoBall::~LottoBall()
	{
		thread->Abort();
	}

	System::Void LottoBall::run()
	{
		Random^ r = gcnew Random();
		String^ threadname = Thread::CurrentThread->Name;
		int id = 0;
		Int32::TryParse(threadname, id);

		while (!this->threadStop)
		{
			this->num = r->Next(minVal, maxVal);
			Form1::numbers[id] = this->num;
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

}