# Introduction 
A timer template class for timig and logging duration in C++ code. 

# Getting Started
Include ```Timer.h``` in a library or where you need it.\
Example timer
```C++
Timer<double, std::micro> tm;
tm.start();
std::cout << "Hello World!\n";
tm.stop();
std::cout << tm.getDuration() << '\n';
```
Example log
```C++
tm.logValues();
std::this_thread::sleep_for(0.5s);
tm.logValues();
std::this_thread::sleep_for(0.75s);
tm.logValues();
for (const auto& i : tm.getDurationLog()) {
	std::cout << i << '\n';
}
tm.clearLog();
```
See main.cpp for complete example.
# Build and Test
 No need to build copy the file ```Timer.h```. The unit test is in the TimerTest project.

# Contribute
Feel free to contribute.
- [Github C++ timer](https://github.com/CMHAS/Timer)
