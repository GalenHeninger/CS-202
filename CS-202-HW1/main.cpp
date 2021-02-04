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
    std::uniform_int_distribution<int> distribution(0, 10);
    
    // Create vector
    std::vector<int> v(1000);
    
    // Generate
    auto gen = [&distribution, &generator](){
        return distribution(generator);
    };
    
    std::generate(v.begin(), v.end(), gen);
    
    Stopwatch timer;
    
    // Test std::find
    timer.start();
    auto it = std::find(v.begin(), v.end(), -1);
    timer.stop();
    
    double seconds_find = timer.getSeconds();
    
    // Test std::search
    std::vector<int> v2 ={-1};
    timer.start();
    auto it2 = std::search(v.begin(), v.end(), v2.begin(), v2.end());
    timer.stop();
    
    double seconds_search = timer.getSeconds();
    
    //Test std::sort
    timer.start();
    std::sort(v.begin(), v.end());
    timer.stop();
    
    double seconds_sort = timer.getSeconds();
    
    // Test binary search
    timer.start();
    auto it3 = std::binary_search(v.begin(), v.end(), -1);
    timer.stop();
    
    double seconds_binary = timer.getSeconds();
    
    cout << seconds_find << " seconds for std::find.\n";
    cout << seconds_search << " seconds for std::search.\n";
    cout << seconds_sort << " seconds for std::sort.\n";
    cout << seconds_binary << " seconds for std::binary_search.\n";
    
    return 0;
}
