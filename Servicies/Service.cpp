
#include "Service.h"
#include "algorithm"

//Service::Service(RepoFile &repoFile){
//    this->repoFile = &repoFile;
//}


void Service::addEntitate(const string& cod, const string& name, int age) {
    ///adauga o entitate
    Entitate *enti = new Entitate(cod, name, age);
    this->repoFile.addEntitate(enti);
}

void Service::modifyEntitate(const string& cod, const string& name, int age) {
    ///modifica o entitate dupa cod
    Entitate *enti = new Entitate(cod, name, age);
    this->repoFile.modifyEntitate(cod, enti);
}

void Service::deleteEntitate(const string& cod) {
    ///sterge o entitate dupa cod
    this->repoFile.deleteEntitate(cod);
}

vector<Entitate*> Service::getAll() {
    ///returneaza toate entitatile
    vector<Entitate*> entitati = this->repoFile.getAll();
    return entitati;
}

int Service::getSize() {
    ///returneaza dimensiunea vectorului entitati
    return this->repoFile.getSize();
}

Entitate Service::entitateCautata(const string& cod) {
    ///returneaza o entitate dupa cod
    return this->repoFile.entitateCautata(cod);
}

bool compara(Entitate *a, Entitate *b) {
    ///compara doua entitati dupa ani
    return a->getAge() > b->getAge();
}

vector<Entitate*> Service::sorteazaDescrescator() {
    ///sorteaza descrescator entitatile dupa ani
    vector<Entitate*> entitati = this->repoFile.getAll();
    sort(entitati.begin(), entitati.end(), compara);
    return entitati;
}

vector<Entitate*> Service::filtreazaDupaAni(int age) {
    ///filtreaza entitatile dupa ani
    vector<Entitate*> entitati = this->repoFile.getAll();
    vector<Entitate*> listaCeruta;
    for (auto & i : entitati) {
        if (i->getAge() > age) {
            listaCeruta.push_back(i);
        }
    }

    return listaCeruta;
}
