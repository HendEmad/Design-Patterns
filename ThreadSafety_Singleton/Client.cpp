#include<iostream>
#include<string>
#include <thread>
#include "Counter.h"
using namespace std;

int main() {
thread task1([]() {
    Counter* counter1 = Counter::GetInstance();
    counter1 -> addOne();
    cout << "Counter1: " + to_string(counter1 -> count) << endl;
});

thread task2([]() {
    Counter* counter2 = Counter::GetInstance();
    counter2 -> addOne();
    cout << "Counter2: " + to_string(counter2 -> count) << endl;
});

task1.join();
task2.join();
}