
#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H

#include "../Repos/RepoFile.h"

class Service{
private:
    RepoFile &repoFile;
public:
//    Service(RepoFile &repoFile);
    Service(RepoFile &repoFile) : repoFile(repoFile){};


    void addEntitate(const string& cod, const string& name, int age);
    void deleteEntitate(const string& cod);
    void modifyEntitate(const string& cod, const string& name, int age);
    vector<Entitate*> getAll();
    int getSize();
    Entitate entitateCautata(const string& cod);

    vector<Entitate*> filtreazaDupaAni(int age);
    vector<Entitate*> sorteazaDescrescator();

};


#endif //UNTITLED1_SERVICE_H
