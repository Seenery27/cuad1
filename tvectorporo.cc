#include <tvectorporo.h>

TVectorPoro::TVectorPoro() {
    this->dimension = 0;
    this->datos = nullptr;
}

TVectorPoro::TVectorPoro(int dimension) {
    if (dimension <= 0) {
        this->dimension = 0;
        this->datos = nullptr;
    }
    else {
        this->dimension = dimension;
        this->datos = new TPoro[dimension];
    }
}

TVectorPoro::TVectorPoro(TVectorPoro &o) {
    this->dimension = o.dimension;
    if (dimension <= 0) {
        this->datos = nullptr;
    } 
    else {
        this->datos = new TPoro[dimension];
        for (int i = 0; i < dimension;i++) {
            datos[i] = o.datos[i];
        }
    }
}

TVectorPoro::~TVectorPoro() {
    delete[] datos;
    this->datos = nullptr;
    this->dimension = 0;
}

TVectorPoro&
TVectorPoro::operator=(TVectorPoro &o2) {
    (*this).~TVectorPoro();
    dimension = o2.dimension;
    if (dimension <= 0) {
        datos = nullptr;
    }
    else {
        datos = new TPoro[dimension];
        for (int i = 0; i < dimension; i++) {
            datos[i] = o2.datos[i];
        }
    }
    return *this;
}

bool
TVectorPoro::operator==(const TVectorPoro &ob) {
    if (dimension != ob.dimension) return false;
    for (int i = 0; i < dimension; i++) {
        if (datos[i] != ob.datos[i]) return false;
    }
    return true;
}

bool
TVectorPoro::operator!=(const TVectorPoro &ob) {
    return !(*this == ob);
}


