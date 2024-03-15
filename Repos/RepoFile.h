
#ifndef UNTITLED1_REPOFILE_H
#define UNTITLED1_REPOFILE_H

#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include "Repository.h"

using namespace std;

class RepoFile : public Repository{
private:
    string fileName;

public:

    RepoFile(const string& filename);
    ~RepoFile();
    void addEntitate(Entitate* enti)override;
    void modifyEntitate(const string& cod, Entitate* enti)override;
    void deleteEntitate(const string& cod)override;


    vector<Entitate*> getAll()override;
    int getSize()override;
    Entitate entitateCautata(const string& cod)override;

    void loadFromFile();
    void saveToFile();
};


#endif //UNTITLED1_REPOFILE_H
