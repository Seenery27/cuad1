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

TPoro&
TVectorPoro::operator[](int index) {
    if (index < 1 || index > dimension) return error;
    return datos[index-1];
}

TPoro
TVectorPoro::operator[](int index) const {
    if (index < 1 || index > dimension) return error;
    return datos[index-1];
}

int
TVectorPoro::Longitud() const {return dimension;}

int 
TVectorPoro::Cantidad() const {
    int count = 0;
    for (int i = 0; i < dimension; i++) {
        if (!datos[i].EsVacio()) count++;
    }
    return count;
}

bool
TVectorPoro::Redimensionar(int newDim) {
    if (newDim <= 0 || newDim == dimension) return false;

    TPoro *newDatos = new TPoro[newDim];
    int minDim;
    if (newDim < dimension) minDim = newDim; else minDim = dimension;
    for (int i = 0; i < minDim; i++) {
        newDatos[i] = datos[i];
    }
    delete[] datos;
    datos = newDatos;
    dimension = newDim;
    return true;
}

ostream & operator<<(ostream &os,const TVectorPoro &vectorporo) {
    os << "[";
    for (int i = 0; i < vectorporo.dimension; i++) {
        os << i << " " << vectorporo[i];
        if (i != vectorporo.dimension) os << " "; 
    }
    os << "]";
    return os;
}