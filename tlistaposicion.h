#include <iostream>
#include "tlistanodo.h"
#ifndef __TLISTAPOSICION__
#define __TLISTAPOSICION__

using namespace std;

class TListaPosicion {
    friend class TListaPoro;
    friend class TListaNodo;

    private:
        TListaNodo *pos;
    public:
        TListaPosicion();
        TListaPosicion(const TListaPosicion &);
        ~TListaPosicion();
        TListaPosicion& operator=(const TListaPosicion &);
        bool operator==(const TListaPosicion &);
        TListaPosicion Anterior();
        TListaPosicion Siguente();
        bool EsVacia();
};

#endif
