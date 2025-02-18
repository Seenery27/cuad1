#include <iostream>
#include <vector>
#include "tporo.h"

class TVectorPoro {
    friend ostream & operator<<(ostream &, TVectorPoro &);
    private:
        int dimension;
        TPoro *datos;
        TPoro error;
    public:
        TVectorPoro();
        TVectorPoro(int);
        TVectorPoro(TVectorPoro &);
        ~TVectorPoro();
        TVectorPoro& operator=(TVectorPoro &);

        bool operator==(TVectorPoro &);
        bool operator!=(TVectorPoro &);
        TPoro& operator[](int);
        TPoro operator[](int) const;
        int Longitud();
        int Cantidad();
        bool Redimensionar(int);
};
