#include "timer.hpp"

namespace DS
{
    PerformanceTimer::PerformanceTimer(const std::string &n) : name(n)
    {
        start = std::chrono::high_resolution_clock::now();
        end = std::chrono::high_resolution_clock::now();
    }

    DSNanoSecond PerformanceTimer::end_timer()
    {
        end = std::chrono::high_resolution_clock::now();
        auto elapsed = end - start;
        DS_INFO("Time taken {} : {} seconds", name, nano_to_millisec(elapsed));
        return elapsed;
    }

    PerformanceTimer::~PerformanceTimer()
    {
        end_timer();
    }

    double nano_to_millisec(std::chrono::nanoseconds s)
    {
        return (double)s.count() * (pow(10., -9.));
    }
} // namespace DS
