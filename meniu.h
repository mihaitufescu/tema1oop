
#ifndef MAIN_CPP_MENIU_H
#define MAIN_CPP_MENIU_H
#include <iostream>
#include <cstring>
#include "Angajat.h"
#include "gestiuneAngajati.h"
using  namespace  std;

class Meniu
{
private:
    int module;
public:
    Meniu(int module)
    {
        this->module = module;
    }
    Meniu()
    {
        module = 0;
    }
    Meniu(const Meniu &rhs)
    {
        this->module = rhs.module;
    }
    int getModule ()
    {
        return module;
    }
    void setModule (int module)
    {
        cout<<"Pentru a afisa lista angajatilor apasati 1."<<endl<<"Pentru a adauga un angajat apasati 2."<<endl<<"Pentru a cauta un angajat apasati 3."<<endl;
        if(module>= 1 && module<=3)
            this->module = module;
        else
            module = 0;
    }

    friend istream &operator>>(istream& inputStream, Meniu meniuInteractiv)
    {
        std::cout<<"Pentru a afisa lista angajatilor apasati 1."<<endl<<"Pentru a adauga un angajat apasati 2."<<endl<<"Pentru a cauta un angajat apasati 3."<<endl;
        inputStream>>meniuInteractiv.module;
        return inputStream;
    }
    ~Meniu()
    {

    }

};


#endif //MAIN_CPP_MENIU_H
