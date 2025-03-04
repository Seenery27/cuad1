#include "tporo.h"

#ifndef __TLISTANODO__
#define __TLISTANODO__



class TListaNodo {
    friend class TListaPoro;
    friend class TListaPosicion;
    friend ostream & operator<<(ostream &, const TListaPoro &);
    private:
        TPoro e;
        TListaNodo *anterior;
        TListaNodo *siguente;
    public:
        TListaNodo();
        TListaNodo(const TListaNodo &);
        ~TListaNodo();
        TListaNodo& operator=(const TListaNodo &);
};

#endif
