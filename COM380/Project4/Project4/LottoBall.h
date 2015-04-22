#pragma once

namespace Project4
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::Data;

	public ref class LottoBall
	{

	public:
		LottoBall(int minval, int maxval);
		~LottoBall();

		int getCurrentValue();
		int num;

		System::Void start();
		System::Void stop();

	private:
		int minVal;
		int maxVal;

		bool threadStop;
		Thread^ thread;
		System::Void run();

	};

}