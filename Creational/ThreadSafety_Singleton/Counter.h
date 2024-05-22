#include <mutex>

class Counter {
    static Counter* instance;
    static std::mutex lockObj;
    Counter() {}

public:
    int count = 0;
    static Counter* GetInstance() {
        std::lock_guard<std::mutex> guard(lockObj);  // lock the mutex
        if(instance == nullptr)
            instance = new Counter();
        return instance;
    }

    void addOne() {
        count++;
    }
 
};