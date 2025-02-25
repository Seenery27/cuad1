#include <iostream>
#include "tlistanodo.h"
using namespace std;

class TListaPosicion {
    private:
        TListaNodo *pos;
    public:
        TListaPosicion();
        TListaPosicion(TListaPosicion &);
        ~TListaPosicion();
        TListaPosicion& operator=(TListaPosicion &);
        bool operator==(TListaPosicion &);
        TListaPosicion Anterior();
        TListaPosicion Siguente();
        bool EsVacia();
};