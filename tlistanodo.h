
#ifndef __TLISTANODO__
#define __TLISTANODO__

#include "tporo.h"


class TListaNodo {
    friend class TListaPoro;
    friend class TListaPosicion;
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
