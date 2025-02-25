#include <iostream>
#include "tporo.h"
using namespace std;

class TListaNodo {
    private:
        TPoro e;
        TListaNodo *anterior;
        TListaNodo *siguente;
    public:
        TListaNodo();
        TListaNodo(TListaNodo &);
        ~TListaNodo();
        TListaNodo& operator=(TListaNodo &);
};