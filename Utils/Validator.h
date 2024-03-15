
#ifndef UNTITLED1_VALIDATOR_H
#define UNTITLED1_VALIDATOR_H

#include <iostream>
#include <string>
#include "MyGeneralException.h"
#include "MyCustomNumberException.h"

class Validator {

public:
    static int isNumber(std::string possible_number) {
        try {
            return std::stoi(possible_number);
        } catch (std::exception e) { // <- bad practice
            throw MyCustomNumberException("Received parameter " + possible_number + " is not a number");
        }
    }

//    static int isName(std::string option) {
//        try {
//            if (isdigit(option[1]) == 0)
//                return 0;
//        } catch (std::exception e) { // <- bad practice
//            throw MyCustomNumberException("Received parameter " + option + " is not a string");
//        }
//    }
};

#endif //UNTITLED1_VALIDATOR_H
