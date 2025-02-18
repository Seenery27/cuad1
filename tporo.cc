#include <tvectorporo.h>

TVectorPoro::TVectorPoro() {
    this->dimension = 0;
    this->datos = NULL;
}

TVectorPoro::TVectorPoro(int dimension) {
    if (dimension <= 0) this->dimension = 0;
    this->dimension = dimension;
}

TVectorPoro::TVectorPoro(TVectorPoro &o) {
    this->dimension = o.dimension;
    this->datos = o.datos;
}

TVectorPoro::~TVectorPoro() {
    this->dimension = 0;
    this->datos = NULL;
}

TVectorPoro&
TVectorPoro::operator=(TVectorPoro &o2) {
    (*this).~TVectorPoro();
    dimension = o2.dimension;
    datos = o2.datos;

    return *this;
}

bool
TVectorPoro::operator==(TVectorPoro &ob) {
    bool temp;
    temp = (dimension == ob.dimension && datos == ob.datos) ? true : false;
    return temp;
}

bool
TVectorPoro::operator!=(TVectorPoro &ob) {
    return !(*this == ob);
}

TVectorPoro::operator[](TVectorPoro &vectorporo) {

}
