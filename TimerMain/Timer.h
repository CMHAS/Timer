#pragma once
#include <chrono>
#include <vector>

template <typename T = double, typename ratio = std::ratio<1>>
class Timer
{
	using durType	= std::chrono::duration<T, ratio>;
	using highClock = std::chrono::high_resolution_clock;
	using timePoint = std::chrono::time_point<highClock>;
public:
	Timer() {}
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;
	~Timer() {}
	void start();
	void stop(); 
	T getDuration() const;

	void logValues();
	std::vector<T> getDurationLog() const;
	void clearLog();
private:
	timePoint startTime;
	std::vector<timePoint> log{};
	durType durTime = static_cast<durType>(0);
};

template<typename T, typename ratio>
inline void Timer<T, ratio>::start()
{
	startTime = highClock::now();
}

template<typename T, typename ratio>
inline void Timer<T, ratio>::stop()
{
	durTime = std::chrono::duration_cast<durType>(highClock::now() - startTime);
}

template<typename T, typename ratio>
inline T Timer<T, ratio>::getDuration() const
{
	return durTime.count();
}

template<typename T, typename ratio>
inline void Timer<T, ratio>::logValues()
{
	log.emplace_back(highClock::now());
}

template<typename T, typename ratio>
inline std::vector<T> Timer<T, ratio>::getDurationLog() const
{
	if (log.size() < 2) {
		return std::vector<T>();
	}
	
	std::vector<T> durVector( log.size() - 1 );
	for (auto& i : durVector) {
		const auto logAt = (&i - &durVector[0]) + 1U;
 		i = std::chrono::duration_cast<durType>(log.at(logAt) - log.front()).count();
	}
	return durVector;
}

template<typename T, typename ratio>
inline void Timer<T, ratio>::clearLog()
{
	log.clear();
}


