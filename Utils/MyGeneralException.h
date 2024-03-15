
#ifndef UNTITLED1_MYGENERALEXCEPTION_H
#define UNTITLED1_MYGENERALEXCEPTION_H


#include <iostream>


class MyGeneralException: public std::exception {
private:
    std::string message;
public:
    MyGeneralException(std::string message): message(message){}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //UNTITLED1_MYGENERALEXCEPTION_H
