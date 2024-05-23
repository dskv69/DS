#ifndef DS_TIMER_HPP
#define DS_TIMER_HPP

#include <chrono>
#include "common.hpp"

namespace DS
{
    typedef std::chrono::time_point<std::chrono::high_resolution_clock> DSTimePoint;
    typedef std::chrono::nanoseconds DSNanoSecond;

    class PerformanceTimer
    {
    public:
        DSTimePoint start;
        DSTimePoint end;
        std::string name;

        DSNanoSecond end_timer();

    public:
        PerformanceTimer(const std::string &name);
        ~PerformanceTimer();
    };

    double nano_to_millisec(std::chrono::nanoseconds s);
};

#endif