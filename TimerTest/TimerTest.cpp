#include "pch.h"
#include "CppUnitTest.h"
#include "..\TimerMain\Timer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::chrono_literals;

TEST_CLASS(DurationTest)
{
public:
	TEST_METHOD(TestMethod1)
	{
		Timer<double, std::ratio<1>> tm;
		tm.start();
		std::this_thread::sleep_for(0.1s);
		tm.stop();
		Assert::AreEqual(0.1, tm.getDuration(), 0.01);
	}
	TEST_METHOD(TestMethod2)
	{
		Timer<unsigned, std::ratio<1>> tm;
		tm.start();
		std::this_thread::sleep_for(1s);
		tm.stop();
		Assert::AreEqual(1U, tm.getDuration());
	}
};
TEST_CLASS(LogTest)
{
	std::array<const double, 2> testValues{50.0, 125.0}; // milliseconds
	std::array<const double, 2>::iterator iter = testValues.begin();
public:
	TEST_METHOD(TestMethod1)
	{
		Timer<double, std::milli> tm;
		tm.logValues();
		std::this_thread::sleep_for(0.05s);
		tm.logValues();
		std::this_thread::sleep_for(0.075s);
		tm.logValues();
		
		for (const auto& actuall : tm.getDurationLog()) {
			Assert::AreEqual(*(iter++), actuall, 2.0);
		}
		tm.clearLog();
		Assert::IsTrue(tm.getDurationLog().empty());
	}
};
