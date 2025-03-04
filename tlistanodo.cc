#include "tlistanodo.h"

TListaNodo::TListaNodo() {
    anterior = nullptr;
    siguente = nullptr;
}

TListaNodo::TListaNodo(const TListaNodo &o) {
    anterior = o.anterior;
    siguente = o.siguente;
    e = o.e;
}

TListaNodo::~TListaNodo() {
    anterior = nullptr;
    siguente = nullptr;
}

TListaNodo&
TListaNodo::operator=(const TListaNodo &o2) {
    (*this).~TListaNodo();
    e = o2.e;
    anterior = o2.anterior;
    siguente = o2.siguente;
    
    return *this;
} 
