//
//  main.cpp
//  CS-202-HW1
//
//  Created by Galen on 1/21/21.
//  Copyright © 2021 Galen. All rights reserved.
//

#include <iostream>

#include "stopwatch.hpp"

#include <chrono>
#include <ctime>

using std::cout;
using std::chrono::system_clock;
using std::ctime;

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

    double getDuration () {
        return std::chrono::duration<double>(_endTime - _startTime).count();
    }

private:
    
    std::chrono::time_point<std::chrono::system_clock> _startTime;
    std::chrono::time_point<std::chrono::system_clock> _endTime;
    
};

int main() {
    
    Stopwatch A;
    
    return 0;
}
