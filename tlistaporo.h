#include "tlistaposicion.h"


#ifndef __TLISTAPORO__
#define __TLISTAPORO__


using namespace std;

class TListaPoro {
    friend ostream & operator<<(ostream &, const TListaPoro &);
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;
    public:
        //------Canonical forms
        TListaPoro();
        TListaPoro(const TListaPoro &);
        ~TListaPoro();
        TListaPoro& operator=(const TListaPoro &);
        
        //------Methods

        //Operators
        bool operator==(const TListaPoro &);
        bool operator+(const TListaPoro &);
        bool operator-(const TListaPoro &);

        //Setters and 
        bool esVacia();
        bool Insertar(const TPoro &);
        bool Borrar(const TPoro &);
        bool Borrar(const TListaPosicion &);
        TPoro Obtener(const TListaPosicion &);
        bool Buscar(const TPoro &)const;
        int Longitud();
        TListaPosicion Primera()const;
        TListaPosicion Ultima()const;
        TListaPoro ExtraerRango(int n1, int n2);

};

#endif
