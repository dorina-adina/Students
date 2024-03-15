#include <iostream>
using namespace std;
#include "Models/Entitate.h"
#include "Repos/Repository.h"
#include "Repos/RepoFile.h"
#include "Servicies/Service.h"
#include "UI/UI.h"
#include "Tests/Tests.h"

int main()
{

    testEntitate();

    RepoFile repoFile("entitati.txt");
//    repoFile.loadFromFile();

    Service service(repoFile);

    UI ui(service);
    ui.start();

    cout << "Hello world" << endl;
    return 0;
}










































































//try  {
//int x;
//
//cin >> x;
//throw 'a';
//}
//catch (int x)  {
//cout << "Caught " << x;
//}
////    catch (...)  {
////        cout << "Default Exception\n";
////    }