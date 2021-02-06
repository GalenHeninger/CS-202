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
    std::vector<int> v(10000000);
    
    // Generate
    auto gen = [&distribution, &generator](){
        return distribution(generator);
    };
    
    std::generate(v.begin(), v.end(), gen);
    
    Stopwatch timer;
    
    std::vector<int> it_offset = {9, 99, 999, 9999, 99999, 999999, 9999999}; //, 99999999, 999999999
    
    std::cout << "Vector lengths\n";
    std::cout << "10 100 1000 10000 100000 1000000 10000000\n";
    
    std::cout << "Timing for std::find (seconds)\n";
    
    // Test std::find
    for (const int& i : it_offset) {
        timer.start();
        auto it = std::find(v.begin(), v.begin() + i, -1);
        timer.stop();
        std::cout << timer.getSeconds();
        std::cout << " ";
    }
    
    std::cout << std::endl;
    
    std::cout << "Timing for std::search (seconds)\n";
        
    // Test std::search
    std::vector<int> v2 ={-1};
    for (const int& i : it_offset) {
        timer.start();
        auto it2 = std::search(v.begin(), v.begin() + i, v2.begin(), v2.end());
        timer.stop();
        std::cout << timer.getSeconds();
        std::cout << " ";
    }
    
    std::cout << std::endl;
    
    std::cout << "Timing for std::sort (seconds)\n";
    
    //Test std::sort
    for (const int& i : it_offset) {
        timer.start();
        std::sort(v.begin(), v.begin() + i);
        timer.stop();
        std::cout << timer.getSeconds();
        std::cout << " ";
    }
    
    std::cout << std::endl;
    
    std::cout << "Timing for std::binary_search (seconds)\n";
    
    // Test binary search
    for (const int& i : it_offset) {
        timer.start();
        auto it3 = std::binary_search(v.begin(), v.begin() + i, -1);
        timer.stop();
        std::cout << timer.getSeconds();
        std::cout << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
