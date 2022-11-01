//
// Created by Simona on 10/25/2022.
//

#ifndef MAIN_CPP_GESTIUNEANGAJATI_H
#define MAIN_CPP_GESTIUNEANGAJATI_H
#include <iostream>
#include <cstring>
#include "Angajat.h"

class gestiuneAngajati {
private:
    int numarAngajati;
    int idDirector;
    Angajat **listaAngajati = new Angajat*[200];

public:
        gestiuneAngajati(int numarAngajati, int idDirector, Angajat *listaAngajati[])
        {
            this->numarAngajati = numarAngajati;
            this->idDirector = idDirector;
            for(int i=0;i<numarAngajati;i++)
            {
                this->listaAngajati[i] = listaAngajati[i];
            }
        }
        gestiuneAngajati()
        {
            numarAngajati = -1;
            idDirector = -1;
            for(int i=0;i<numarAngajati;i++)
            {
            this->listaAngajati[i] = nullptr;
            }
        }
        gestiuneAngajati(const gestiuneAngajati &rhs)
        {
            this->numarAngajati = rhs.numarAngajati;
            this->idDirector = rhs.idDirector;
            *listaAngajati = *rhs.listaAngajati;
        }
        void afisareGestiune() const
        {
            if(printf("Numar angajati= %d \nId director= %d\n" ,numarAngajati, idDirector ) <0)
                puts("Afisare nereusita!");
            for(int i=0; i<numarAngajati ; i++)
                listaAngajati[i]->afisareAngajat();
        }
         int get_idDirector() const
        {
            return  idDirector;
        }
        void set_idDirector(int _idDirector)
        {
            if(_idDirector>=100001 && _idDirector<=300999)
                idDirector = _idDirector;
            else
            {
                std::cout<<"Formatul id-ului de director este ######\n";
                return;
            }
        }
        int get_numarAngajati() const
        {
            return  numarAngajati;
        }
        void set_numarAngajati(int _numarAngajati)
        {
            if(_numarAngajati>=0)
                numarAngajati = _numarAngajati;
            else
            {
                std::cout<<"Firma nu poate sa nu aiba angajati!\n";
                return;
            }
        }
    gestiuneAngajati& operator+=(const gestiuneAngajati &rhs){

        int oldNum = numarAngajati;
        cout<<oldNum<<endl;
        this->numarAngajati= this->numarAngajati + rhs.numarAngajati;
        cout<<numarAngajati<<endl;

        this->listaAngajati = (Angajat**) realloc(listaAngajati, (this->numarAngajati +2)*sizeof(Angajat*));
        for(int i= oldNum; i< numarAngajati; i++)
            *listaAngajati[i] = *rhs.listaAngajati[i];
        return *this;

    }
    friend ostream &operator<<(ostream& outputStream, const gestiuneAngajati& gestiune)
    {
        outputStream<<"Numar angajti="<<" "<<gestiune.numarAngajati<<"\nId director= "<<gestiune.idDirector<<endl;
        for(int i=0;i<gestiune.numarAngajati;i++)
        {
            outputStream<<gestiune.listaAngajati[i];
        }
        return  outputStream;
    }
    friend istream &operator>>(istream& inputStream, gestiuneAngajati& gestiune)
    {
        cout<<"Introduceti numarul de angajati:\n";
        inputStream>>gestiune.numarAngajati;

        cout<<"Introduceti id-ul directorului:\n";
        inputStream>>gestiune.idDirector;

        return inputStream;
    }
    void cautareAngajat(const char *stringToFind)
    {
            for(int i=0; i< numarAngajati; i++)
            {
                if(strcmp(listaAngajati[i]->getNume(), stringToFind)== 0)
                    listaAngajati[i]->afisareAngajat();
            }
    }
    ~gestiuneAngajati()
    {
            for(int i = 0; i < numarAngajati; i++)
                delete listaAngajati[i];

            delete [] listaAngajati;
    }

};


#endif //MAIN_CPP_GESTIUNEANGAJATI_H
