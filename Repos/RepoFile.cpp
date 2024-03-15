
#include "RepoFile.h"
#include <fstream>

RepoFile::RepoFile(const string& filename) : fileName(filename){
    loadFromFile();
}

void RepoFile::addEntitate(Entitate* enti) {
    Repository::addEntitate(enti);
    saveToFile();
}

void RepoFile::modifyEntitate(const string& cod, Entitate* enti) {
    Repository::modifyEntitate(cod, enti);
    saveToFile();
}

void RepoFile::deleteEntitate(const string& cod) {
    Repository::deleteEntitate(cod);
    saveToFile();
}

vector<Entitate*> RepoFile::getAll() {
    loadFromFile();
    return entitati;
}

int RepoFile::getSize() {
    return Repository::getSize();
}

Entitate RepoFile::entitateCautata(const string& cod) {
    return Repository::entitateCautata(cod);
}


void RepoFile::loadFromFile() {
    ifstream fileStream(fileName);
    if (!fileStream.is_open()) {
        cout << "nu"<<endl;
    }
    entitati.clear();
    while (!fileStream.eof()) {
        string cod;
        string nume;
        int pret;
        fileStream >> cod >> nume >> pret;
        if (fileStream.fail()) {
            break;
        }
        Entitate* enti = new Entitate(cod, nume, pret);
        Repository::addEntitate(enti);
        while(fileStream >> cod >> nume >> pret)
        {
            Entitate *enti = new Entitate(cod, nume, pret);
            entitati.push_back(enti);
        }
    }
    fileStream.close();
}

void RepoFile::saveToFile() {
    ofstream fileStream(fileName);
    for (const auto *enti : Repository::getAll()) {
        //fileStream >> prod.getCod() >> prod.getNume() >> prod.getPret();
        fileStream  << enti->getCod() << " " << enti->getName() << " " << enti->getAge() << endl;
    }
    fileStream.close();
}

RepoFile::~RepoFile() {
    saveToFile();
}
