// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "Timer.h"
using namespace std::chrono_literals;

int main()
{
	Timer<double, std::milli> tm;
	tm.start();
    std::cout << "Hello World!\n";
	tm.stop();
	std::cout << tm.getDuration() << '\n';

	tm.logValues();
	std::this_thread::sleep_for(0.5s);
	tm.logValues();
	std::this_thread::sleep_for(0.75s);
	tm.logValues();
	for (const auto& i : tm.getDurationLog()) {
		std::cout << i << '\n';
	}
	tm.clearLog();
}

