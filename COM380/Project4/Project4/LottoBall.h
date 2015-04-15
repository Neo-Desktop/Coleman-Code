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
		LottoBall();
		~LottoBall();

		int getCurrentValue();

	private:
		Thread^ thread;
		System::Void run();

	};

}