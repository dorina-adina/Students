
#include "Tests.h"

#include "../Repos/RepoFile.h"
#include "../Repos/Repository.h"
#include "../Servicies/Service.h"
#include "../UI/UI.h"
#include <cassert>
#include <cstring>

void testEntitate() {
    ///testam constructorii

    Entitate entitate1;

    entitate1.setCod("cod1");
    entitate1.setName("andrei");
    entitate1.setAge(11);
    assert(entitate1.getCod() == "cod1");
    assert(entitate1.getName() == "andrei");
    assert(entitate1.getAge() == 11);


    Entitate entitate2("cod2", "alexa", 12);
    assert(entitate2.getName() == "alexa");
    assert(entitate2.getAge() == 12);
    assert(entitate2.getCod() == "cod2");


    Entitate entitate3 = Entitate(entitate2);
    assert((entitate3.getName() == "alexa"));
    assert(entitate3.getAge() == 12);
    assert(entitate3.getCod() == "cod2");


    Entitate *entitate4 = new Entitate("cod3", "ana", 18);
    assert((entitate4->getName() == "ana"));
    assert(entitate4->getCod() == "cod3");
    assert(entitate4->getAge() == 18);


    ///testam repository

    Repository r;
    Entitate* enti1 = new Entitate("cod1", "andrei", 11);

    Entitate* enti2 = new Entitate("cod2", "alexa", 12);

    Entitate *enti3 = new Entitate("cod3", "ana", 18);

    r.addEntitate(enti1);
    r.addEntitate(enti2);
    r.addEntitate(enti3);

    assert(r.getSize() == 3);

    vector<Entitate*> entitati = r.getAll();

    assert((entitati[0]->getCod() == "cod1"));
    assert(entitati[1]->getName() == "alexa");
    assert(entitati[2]->getAge() == 18);

    Entitate* enti4 = new Entitate("cod1", "amalia", 17);

    r.modifyEntitate("cod1", enti4);
    assert((entitati[0]->getCod() == "cod1"));
    assert(entitati[0]->getAge() == 17);
    assert(entitati[0]->getName() == "amalia");

    r.deleteEntitate("cod1");
    vector<Entitate*> entitatile = r.getAll();

    assert((entitatile[0]->getCod() == "cod2"));
    assert(entitatile[0]->getName() == "alexa");
    assert(entitatile[0]->getAge() == 12);

    Entitate* entiCautata = new Entitate(r.entitateCautata("cod3"));
    assert(entiCautata->getCod() == "cod3");
    assert(entiCautata->getName() == "ana");
    assert(entiCautata->getAge() == 18);


    ///testam repoFile

    RepoFile repoFile("entitatiTeste.txt");

    Entitate* e1 = new Entitate("cod1", "andrei", 11);
    Entitate* e2 = new Entitate("cod2", "alexa", 12);
    Entitate* e3 = new Entitate("cod3", "ana", 18);

    repoFile.addEntitate(e1);
    repoFile.addEntitate(e2);
    repoFile.addEntitate(e3);

    assert(repoFile.getSize() == 3);

    vector<Entitate*> entitatii = repoFile.getAll();

    assert((entitatii[0]->getCod() == "cod1"));
    assert(entitatii[1]->getName() == "alexa");
    assert(entitatii[2]->getAge() == 18);

    Entitate* e4 = new Entitate("cod1", "alex", 10);

    repoFile.modifyEntitate("cod1", e4);
    assert((entitatii[0]->getCod() == "cod1"));
    assert(entitatii[0]->getAge() == 10);
    assert(entitatii[0]->getName() == "alex");

    repoFile.deleteEntitate("cod1");
    vector<Entitate*> entitatiile = repoFile.getAll();
    assert((entitatiile[0]->getCod() == "cod2"));
    assert(entitatiile[0]->getName() == "alexa");
    assert(entitatiile[0]->getAge() == 12);

    Entitate* entiCautata1 = new Entitate(repoFile.entitateCautata("cod3"));
    assert(entiCautata1->getCod() == "cod3");
    assert(entiCautata1->getName() == "ana");
    assert(entiCautata1->getAge() == 18);


    ///testam service

    Service serv(repoFile);

    serv.addEntitate("cod11", "maria", 10);
    serv.addEntitate("cod12", "medeea", 14);
    serv.addEntitate("cod13", "alin", 16);

    assert(serv.getSize() == 5);

    serv.deleteEntitate("cod2");
    serv.deleteEntitate("cod3");

    vector<Entitate*> entitati1 = serv.getAll();

    assert((entitati1[0]->getCod() == "cod11"));
    assert(entitati1[1]->getName() == "medeea");
    assert(entitati1[2]->getAge() == 16);

    serv.modifyEntitate("cod11", "amalia", 17);
    assert((entitati1[0]->getCod() == "cod11"));
    assert(entitati1[0]->getAge() == 17);
    assert(entitati1[0]->getName() == "amalia");

    serv.deleteEntitate("cod11");
    vector<Entitate*> entitatii1 = serv.getAll();
    assert((entitatii1[0]->getCod() == "cod12"));
    assert(entitatii1[0]->getName() == "medeea");
    assert(entitatii1[0]->getAge() == 14);


    assert(serv.getSize() == 2);

    vector<Entitate*> entitati2;
    entitati2 = serv.filtreazaDupaAni(15);

    assert((entitati2[0]->getCod() == "cod13"));
    assert(entitati2[0]->getName() == "alin");
    assert(entitati2[0]->getAge() == 16);


    vector<Entitate*> entitati3;
    entitati3 = serv.sorteazaDescrescator();

    assert((entitati3[0]->getCod() == "cod13"));
    assert(entitati3[0]->getName() == "alin");
    assert(entitati3[0]->getAge() == 16);

    Entitate* entiCautata2 = new Entitate(serv.entitateCautata("cod13"));
    assert(entiCautata2->getCod() == "cod13");
    assert(entiCautata2->getName() == "alin");
    assert(entiCautata2->getAge() == 16);

    serv.deleteEntitate("cod12");
    serv.deleteEntitate("cod13");


    std::cout << "Tests passed successfully" << "\n";
}


