//
//  stopwatch.cpp
//  CS-202-HW1
//
//  Created by Galen on 1/30/21.
//  Copyright © 2021 Galen. All rights reserved.
//

#include <chrono>
#include <ctime>

using std::chrono::system_clock;
using std::ctime;

#include "stopwatch.hpp"

class Stopwatch {
    
public:
    
    Stopwatch() : _startTime{system_clock::now()},
                  _endTime{system_clock::now()}
    {}

    void start () {
        _startTime = system_clock::now();
    }

    void stop () {
        _endTime = system_clock::now();
    }

    std::chrono::duration<double> getDuration () {
        return _endTime - _startTime;
    }

private:
    
    std::chrono::time_point<std::chrono::system_clock> _startTime;
    std::chrono::time_point<std::chrono::system_clock> _endTime;
    
};





