//
//  main.cpp
//  CS-202-HW1
//
//  Created by Galen on 1/21/21.
//  Copyright © 2021 Galen. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <random>

using std::cout;
using std::chrono::system_clock;
using std::ctime;
using std::search;

class Stopwatch {
    
public:
    
    Stopwatch () : _startTime{system_clock::now()},
                  _endTime{system_clock::now()}
    {}

    void start ()  {
        _startTime = system_clock::now();
    }

    void stop () {
        _endTime = system_clock::now();
    }

    double getSeconds () const {
        return std::chrono::duration<double>(_endTime - _startTime).count();
    }
    
    double getMilliseconds () const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime - _startTime).count();
    }

private:
    
    std::chrono::time_point<std::chrono::system_clock> _startTime;
    std::chrono::time_point<std::chrono::system_clock> _endTime;
    
};


int main() {
    
    // Create distribution for RNG
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(0, 1);
    
    // Create vector
    std::vector<int> v(1000);
    
    // Generate
    auto gen = [&distribution, &generator](){
        return distribution(generator);
    };
    
    std::generate(v.begin(), v.end(), gen);
    
    int heads = std::accumulate(v.begin(), v.end(), 0);
    
    std::cout << "Heads: " << heads << "\nTails: " << 1000 - heads << std::endl;
    
    
    Stopwatch timer;
    
    // Test search
    timer.start();
    
    timer.stop();
    
    double seconds = timer.getSeconds();
    
    cout << seconds << "\n";
    
    return 0;
}
