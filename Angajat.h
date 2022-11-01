#ifndef MAIN_CPP_ANGAJAT_H
#define MAIN_CPP_ANGAJAT_H
#include <iostream>
#include <cstring>

using namespace std;

class Angajat
{
private:
    int idAngajat;
    char *numeAngajat = new char[30];
    int varstaAngajat;
    int idDepartament;

public:

    Angajat(int _idAngajat,const char *_numeAngajat, int _varstaAngajat, int _idDepartament)
    {
        idAngajat = _idAngajat;
        idDepartament = _idDepartament;
        varstaAngajat = _varstaAngajat;
        delete[] numeAngajat;
        size_t len = strlen(_numeAngajat) + 1;
        char *numeAngajat = new char[len];
        strcpy(numeAngajat, _numeAngajat);

    }
    Angajat(const Angajat &rhs)
    {
        idAngajat = rhs.idAngajat;
        idDepartament = rhs.idDepartament;
        varstaAngajat = rhs.varstaAngajat;
        size_t lungimeNume = strlen(rhs.numeAngajat);
        numeAngajat = new char[lungimeNume+1];
        strcpy(numeAngajat , rhs.numeAngajat);
    }

    void afisareAngajat () const
    {
        if(printf("Id angajat= %d \nNume angajat= %s\nVarsta angajat= %d\nId departament= %d\n",idAngajat,numeAngajat,varstaAngajat,idDepartament)<0)
            puts("Afisare nereusita!");

    }
    char* getNume()
    {
        return  numeAngajat;
    }
    void setNume(const char* _numeAngajat)
    {
        bool ok= true;
        if(strchr(_numeAngajat, ' ') == nullptr )
            ok = false;
        for(size_t i=0;i< strlen(_numeAngajat);i++)
            if(_numeAngajat[i]>= '0' && _numeAngajat[i] <= '9')
                ok = false;
        if(ok)
            strcpy(numeAngajat, _numeAngajat);
        else
        {
            std::cout<<"Numele introdus este invalid. Incearca cu alt nume\n";
            return;
        }
    }

    int get_idDepartament() const
    {
        return  idDepartament;
    }

    void set_idDepartament(int idDepartament)
    {
        if(idDepartament<100 || idDepartament>300)
        {
            std::cout<<"Id-ul de departament introdus este invalid \n";
            return;
        }
        else
            this->idDepartament = idDepartament;
    }

    int get_varsta() const
    {
        return  varstaAngajat;
    }
    void set_varsta(int varstaAngajat)
    {
        if(varstaAngajat>=18)
            this->varstaAngajat = varstaAngajat;
        else
        {
            std::cout<<"Firma nu angajeaza minori. Introduce alta varsta!\n";
            return;
        }
    }
    int get_idAngajat() const
    {
        return  idAngajat;
    }
    void set_idAngajat(int idAngajat)
    {
        if(idAngajat>=100001 && idAngajat<=300999)
            this->idAngajat = idAngajat;
        else
        {
            std::cout<<"Formatul id-ului de angajat este ######, unde primele 3 cifre reprezinta departamentele\n";
            return;
        }
    }
    Angajat& operator=(const Angajat &rhs)
    {
        delete [] numeAngajat;
        size_t len = strlen(rhs.numeAngajat)+1;
        numeAngajat = new char[len];
        strcpy(numeAngajat,rhs.numeAngajat);
        idAngajat = rhs.idAngajat;
        idDepartament = rhs.idDepartament;
        varstaAngajat = rhs.idAngajat;

        return *this;
    }
    friend ostream &operator<<(ostream& outputStream, const Angajat& angajat)
    {
        outputStream<<"Nume angajat="<<" "<<angajat.numeAngajat<<"\nVarsta angajat= "<<angajat.varstaAngajat<<"\nId departament= "<<angajat.idDepartament<<"\nId angajat= "<<angajat.idAngajat<<"\n";
        return  outputStream;
    }

    friend istream &operator>>(istream& inputStream, Angajat& angajat)
    {
        char numeTemp[30];
        cout<<"Introduceti numele angajatului:\n";
        inputStream.getline(numeTemp,30, '\n');

        delete [] angajat.numeAngajat;

        fflush(stdin);
        size_t len = strlen(numeTemp) +1;
        angajat.numeAngajat = new char[len];
        strcpy(angajat.numeAngajat, numeTemp);

        cout<<"Introduceti varsta angajatului:\n";
        inputStream>>angajat.varstaAngajat;

        cout<<"Introduceti id-ul de departament al angajatului:\n";
        inputStream>>angajat.idDepartament;

        cout<<"Introduceti id-ul de angajat:\n";
        inputStream>>angajat.idAngajat;

        return inputStream;


    }

    ~Angajat() {
        delete [] numeAngajat;
        std::cout<<"D:"<<'\n';
    }
};
#endif //MAIN_CPP_ANGAJAT_H