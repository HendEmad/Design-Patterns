#include <iostream>
#include <vector>
#include <string>

class Logger{
public:
     //Retrive the single instance of the object created, and we'll enforce
     // only one object to be created
    static Logger& GetInstance(){
        static Logger* s_instance = new Logger;
        // static Logger* s_instance;
        // if (s_instance == nullptr)
        //     s_instance = new Logger;
        return *s_instance;
    }

    void printMessages()
    {
        std::cout << "Acessing the logger\n";
        for(auto& e : m_messages){
            std::cout << e << " ";
        }
    }

    void add_message(std::string s){
        m_messages.push_back(s);
    }

private:
    Logger(){
        std::cout << "Logger is created.\n"; 
    }

    ~Logger(){
        std::cout << "Logger is destructed.\n";
    }

    std::vector<std::string> m_messages;

};


int main(){
    // Logger logger1;
    // Logger logger2;
    // Logger logger3;
    // Logger logger4;
    // Logger logger5;
    // Logger logger6;
    Logger::GetInstance().printMessages();
    Logger::GetInstance().add_message("Hello, message 1\n");
    Logger::GetInstance().add_message("Hello, message 2\n");
    Logger::GetInstance().add_message("Hello, message 3\n");
    Logger::GetInstance().add_message("Hello, message 4\n");
    Logger::GetInstance().printMessages(); 
    return 0;
}