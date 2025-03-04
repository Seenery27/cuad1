#ifndef __TLISTAPORO__
#define __TLISTAPORO__

#include "tlistaposicion.h"
using namespace std;

class TListaPoro {
    friend ostream & operator<<(ostream &, const TListaPoro &);
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;
    public:
        TListaPoro();
        TListaPoro(TListaPoro &);
        ~TListaPoro();
        TListaPoro& operator=(TListaPoro &);

        bool operator==(TListaPoro &);
        bool operator+(TListaPoro &);
        bool operator-(TListaPoro &);
        bool esVacia();
        bool Insertar(TPoro &);
        bool Borrar(TPoro &);
        bool Boorar(TListaPosicion &);
        TPoro Obtener(TListaPosicion &);
        bool Buscar(TPoro &);
        int Longitud();
        TListaPosicion Primera();
        TListaPosicion Ultima();
        TListaPoro ExtraerRango(int n1, int n2);

};

#endif
