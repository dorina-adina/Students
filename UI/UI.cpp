
#include "UI.h"

//UI::UI(Service &service) {
//    this->service = &service;
//}


int UI::printMenu() {
    string option;

    cout << "Alegeti o optiune:" << endl;
    cout << "1. Adauga o entitate." << endl;
    cout << "2. Modifica o entitate." << endl;
    cout << "3. Sterge o entitate." << endl;
    cout << "4. Ordonare descrescatoare a entitatilor dupa ani." << endl;
    cout << "5. Filtrare a entitatilor dupa ani." << endl;
    cout << "6. Afiseaza dimensiunea vectorului." << endl;
    cout << "7. Afisati o entitate dupa un cod dat." << endl;
    cout << "8. Afiseaza toate entitatile." << endl;
    cout << "9. Exit." << endl;
    cin >> option;
    int opt = Validator::isNumber(option);
    return opt;
}

void UI::addEntitate() {
    ///adauga o entitate
    string cod, name;
    string raw_age;
    cout << "Introduceti codul: ";
    cin >> cod;
    cout << endl;
    cout << "Introduceti numele: ";
    cin >> name;
    cout << endl;
    cout << "Introduceti varsta: ";
    cin >> raw_age;
    cout << endl;
    int age = Validator::isNumber(raw_age);
    this->service.addEntitate(cod, name, age);
}

void UI::modifyEntitate() {
    ///modifica o entitate dupa cod
    string cod, name;
    string raw_age;
    cout << "Introduceti codul entitatii de modificat: ";
    cin >> cod;
    cout << endl;
    cout << "Introduceti numele nou: ";
    cin >> name;
    cout << endl;
    cout << "Introduceti varsta noua: ";
    cin >> raw_age;
    cout << endl;
    int age = Validator::isNumber(raw_age);
    this->service.modifyEntitate(cod, name, age);
}

void UI::deleteEntitate() {
    ///sterge o entitate dupa cod
    string cod;
    cout << "Introduceti codul entitatii de sters: ";
    cin >> cod;
    cout << endl;
    this->service.deleteEntitate(cod);
}

void UI::getAll() {
    ///returneaza toate entitatile
    for(const auto enti : this->service.getAll())
        cout << "Cod: " << enti->getCod() << " " << "Nume: " << enti->getName() << " " << "Ani: " << enti->getAge() << endl;
}

void UI::getSize() {
    ///returneaza dimensiunea vectorului entitati
    cout << this->service.getSize() << endl;
}

void UI::entitateCautata() {
    ///returneaza o entitate dupa cod
    string cod;
    cout << "Introduceti codul entitatii de cautat: ";
    cin >> cod;
    cout << endl;
     Entitate* enti = new Entitate(this->service.entitateCautata(cod));
    cout << "Cod: " << enti->getCod() << " " << "Nume: " << enti->getName() << " " << "Ani: " << enti->getAge() << endl;
}


void UI::sorteazaDescrescator() {
    ///sorteaza descrescator entitatile dupa ani
    for(const auto *enti : this->service.sorteazaDescrescator())
        cout << "Cod: " << enti->getCod() << " " << "Nume: " << enti->getName() << " " << "Ani: " << enti->getAge() << endl;

}

void UI::filtreazaDupaAni() {
    ///filtreaza entitatile dupa ani
    string raw_age;
    cin >> raw_age;
    int age = Validator::isNumber(raw_age);
    cout << endl;
    for(const auto *enti : this->service.filtreazaDupaAni(age))
        cout << "Cod: " << enti->getCod() << " " << "Nume: " << enti->getName() << " " << "Ani: " << enti->getAge() << endl;

}

void UI::start() {
//    this->repoFile.loadFromFile();
    while(true)
    {
        try {
            switch (this->printMenu()) {
                case 1:
                    this->addEntitate();
                    break;
                case 2:
                    this->modifyEntitate();
                    break;
                case 3:
                    this->deleteEntitate();
                    break;
                case 4:
                    this->sorteazaDescrescator();
                    break;
                case 5:
                    this->filtreazaDupaAni();
                    break;
                case 6:
                    this->getSize();
                    break;
                case 7:
                    this->entitateCautata();
                case 8:
                    this->getAll();
                    break;
                case 9:
                    return;

            }
        }catch (std::exception &e) {
            cout << e.what() << endl;
        }
    }
}
