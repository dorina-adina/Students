
#include "Repository.h"

Repository::Repository() {}



void Repository::addEntitate(Entitate *enti) {
    ///adauga entitate
    this->entitati.push_back(enti);
}



void Repository::modifyEntitate(const string& cod, Entitate* enti) {
    ///modifica o entitate dupa cod

    for(int i=0; i<entitati.size(); i++)
        if(entitati[i]->getCod() == cod)
        {
            entitati[i]->setName(enti->getName());
            entitati[i]->setAge(enti->getAge());
        }
}

void Repository::deleteEntitate(const string& cod) {
    ///sterge o entitate dupa cod
    if(!entitati.empty())
    {

        int dimensiune = entitati.size();
        for(int i = 0; i < dimensiune; i++)
            if(!entitati.empty())
            {
                if(entitati[i]->getCod() == cod) {
                    delete entitati[i];
                    entitati.erase(entitati.begin() + i);
                    i = i - 1;
                    dimensiune = dimensiune - 1;
                    continue;
                }

            }
            else break;
    }

}

vector<Entitate*> Repository::getAll() {
    ///returneaza toate entitatile
    return this->entitati;
}

int Repository::getSize() {
    ///returneaza dimensiunea vectorului entitati
    return this->entitati.size();
}

Entitate Repository::entitateCautata(const string& cod) {
    ///returneaza o entitate dupa cod

    for(int i=0; i<entitati.size(); i++)
        if(entitati[i]->getCod() == cod)
        {
            return *entitati[i];
        }
    return Entitate("", "", 0);
}