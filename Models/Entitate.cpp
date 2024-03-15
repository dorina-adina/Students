
#include "Entitate.h"
#include <istream>
#include <iostream>

using namespace std;

Entitate::Entitate() {
    /// constructor implicit
    this->cod = "";
    this->name = "";
    this->age = 0;
}

Entitate::Entitate(string cod, string name, int age) {
    /// constructor cu parametri
    this->cod = cod;
    this->name = name;
    this->age = age;
}

Entitate::Entitate(const Entitate &enti) {
    /// constructor de copiere
    this->cod = enti.cod;
    this->name = enti.name;
    this->age = enti.age;
}

Entitate::~Entitate() = default;
    /// destructor


const string& Entitate::getCod() const {
    /// se returneaza codul
    return this->cod;
}

const string& Entitate::getName() const {
    /// se returneaza numele
    return this->name;
}

int Entitate::getAge() const {
    /// se returneaza varsta
    return this->age;
}

void Entitate::setCod(const string& newCod) {
    /// se seteaza un nou cod
    this->cod = newCod;
}

void Entitate::setName(const string& newName) {
    /// se seteaza un nou nume
    this->name = newName;
}

void Entitate::setAge(int newAge) {
    /// se seteaza o noua varsta
    this->age = newAge;
}

bool Entitate::operator==(const Entitate &enti) {
    return this->cod == enti.cod && this->name == enti.name && this->age == enti.age;
}

Entitate &Entitate::operator=(const Entitate &enti) {
   if(this == &enti)
       return *this;
   this->cod = enti.cod;
    this->name = enti.name;
    this->age = enti.age;
    return *this;
}

istream& operator>>(istream& input, const Entitate& enti){
    int age;
    string name, cod;
    input  >> cod >> name >> age;
    Entitate *entitate = new Entitate(cod, name, age);
    return input;
}

ostream& operator<<(ostream& os, const Entitate& enti){
    os << "Cod: " << enti.getCod() << " " << "Nume: " << enti.getName() << " " << "Ani: " << enti.getAge() << endl;
    return os;
}

