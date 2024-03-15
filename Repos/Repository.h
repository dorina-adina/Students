

#ifndef UNTITLED1_REPOSITORY_H
#define UNTITLED1_REPOSITORY_H
#include "../Models/Entitate.h"
#include "vector"

class Repository {
protected:
    vector<Entitate*> entitati;

public:
    Repository();

    virtual void addEntitate(Entitate* enti);
    virtual void modifyEntitate(const string& cod, Entitate* enti);
    virtual void deleteEntitate(const string& cod);

     virtual vector<Entitate*> getAll();
     virtual int getSize();
     virtual Entitate entitateCautata(const string& cod);

};


#endif //UNTITLED1_REPOSITORY_H
