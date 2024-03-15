
#ifndef UNTITLED1_UI_H
#define UNTITLED1_UI_H

#include "../Servicies/Service.h"
#include "../Utils/Validator.h"

class UI {
private:
    Service service;

    void addEntitate();
    void deleteEntitate();
    void modifyEntitate();
    void getAll();
    void getSize();
    void entitateCautata();
    void filtreazaDupaAni();
    void sorteazaDescrescator();

    int printMenu();

public:
//    UI(Service& service);
    UI(Service& service) : service(service){}

//    UI() = default;


    void start();
};


#endif //UNTITLED1_UI_H
