
#ifndef UNTITLED1_ENTITATE_H
#define UNTITLED1_ENTITATE_H

#include <iostream>
#include <fstream>
using namespace std;

class Entitate {
private:
    string cod;
    string name;
    int age;
public:
    Entitate();
    Entitate(string cod, string name, int age);
    Entitate(const Entitate& enti);
    ~Entitate();

    const string& getCod() const;
    const string& getName() const;
    int getAge() const;

    void setCod(const string& newCod);
    void setName(const string& newName);
    void setAge(int newAge);

    bool operator==(const Entitate& enti);
    Entitate& operator=(const Entitate& enti);

    friend istream& operator>>(istream& input, const Entitate& enti);
    friend ostream& operator<<(ostream& os, const Entitate& enti);
};


#endif //UNTITLED1_ENTITATE_H
