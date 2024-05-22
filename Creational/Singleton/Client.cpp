#include <iostream>
#include <string>
#include "C:\Users\Data-DCS\Design-Patterns\Singleton\Counter.h"
using namespace std;

int main() {
    Counter* counter1 =  Counter::GetInstance();
    Counter* counter2 = Counter::GetInstance();
    counter1 -> addOne();  // addOne ==> 1
    counter2 -> addOne();  // addOne ==> 2
    // The two objects points to the same location 
    cout << "Counter 1: " + to_string(counter1 -> count) << endl;  // count = 2
    cout << "Counter 2: " + to_string(counter2 -> count) << endl;  // count = 2

    counter1 -> addOne();  // addOne ==> 3
    cout << "Counter 1: " + to_string(counter1 -> count) << endl;  // count = 3 
    cout << "Counter 2: " + to_string(counter2 -> count) << endl;  // count = 3
}
