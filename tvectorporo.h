#include <iostream>
#include <vector>

class TVectorPoro {
    private:
        int dimension;
        TPoro *datos;
        TPoro error;
    public:
        TVectorPoro();
        TVectorPoro(int);
        TVectorPoro(TVectorPoro &);
        ~TVectorPoro();
        TVectorPoro & operator=(TVectorPoro &);
}