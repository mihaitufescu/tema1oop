#include <iostream>
#include <cstring>
#include "Angajat.h"
#include "gestiuneAngajati.h"
#include "meniu.h"
using namespace std;



int main() {
    Angajat a1(232,"dfs fss", 32, 32);
    a1.afisareAngajat();
    Angajat *a2 = new Angajat(2342,"FFDDD gdss", 432, 32);
    a2->afisareAngajat();
    int nr = 2;
    Angajat **lista = new Angajat*[3];
    for(int i=0; i<nr;i++)
    {
        int _idAngajat, _idDepartament, _varsta;
        char numeTemp[30];
        fflush(stdin);
        cout<<"Introduceti numele angajatului #"<<i<<endl;
        cin.getline(numeTemp,30);
        cout<<"Introduceti id-ul angajatului: \n";
        cin>>_idAngajat;
        cout<<"Introduceti id-ul de departament al angajatului: \n";
        cin>>_idDepartament;
        cout<<"Introduceti varsta angajatului: \n";
        cin>>_varsta;
        lista[i] = new Angajat(_idAngajat,numeTemp,_varsta,_idDepartament);
    }
    gestiuneAngajati *g1 = new gestiuneAngajati(nr,380901, lista);
    int module;
    std::cout<<"Pentru a afisa lista angajatilor apasati 1."<<endl<<"Pentru a adauga un angajat apasati 2."<<endl<<"Pentru a cauta un angajat apasati 3."<<endl;
    ///De adaugat salariu la angajat
  //  gestiuneAngajati *g3 = new gestiuneAngajati(nr+1,3804431, lista);
    //*g1 += *g3;
    cin>>module;
    switch (module) {
        case 1:
            g1->afisareGestiune();
            break;
        case 2:
          //  *g1 += *g3;
            g1->afisareGestiune();
            break;
        case 3:
            cout << "Introduceti numele angajatului pe care vreti sa il cautati!" << endl;
            char numeTemp[30];
            fflush(stdin);
            cin.getline(numeTemp,30);
            g1->cautareAngajat(numeTemp);
            break;
        default:
            return 0;
    }
    for(int i=0;i<nr;i++)
        delete lista[i];
    delete [] lista;
    return 0;
}
