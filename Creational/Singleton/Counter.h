class Counter {
private:
    static Counter* instance;  // memory allocation for the object as it is initialized inside the class itself
    Counter() {}

public:
    int count = 0;
    static Counter* GetInstance() {
        if(instance == nullptr)
            instance = new Counter();
        return instance;
    }
    void addOne() {
        count++;
    }
};

 
