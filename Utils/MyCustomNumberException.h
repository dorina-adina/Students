
#ifndef UNTITLED1_MYCUSTOMNUMBEREXCEPTION_H
#define UNTITLED1_MYCUSTOMNUMBEREXCEPTION_H

#include <iostream>

class MyCustomNumberException: public std::exception {
private:
    std::string message;
public:
    MyCustomNumberException(std::string message): message(message){}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //UNTITLED1_MYCUSTOMNUMBEREXCEPTION_H
