#include "tlistaposicion.h"

TListaPosicion::TListaPosicion() {
    pos = nullptr;
}

TListaPosicion::TListaPosicion(const TListaPosicion& o) {
    pos = o.pos;
}

TListaPosicion::~TListaPosicion() {pos = nullptr;}

TListaPosicion&
TListaPosicion::operator=(const TListaPosicion& o2) {
    (*this).~TListaPosicion();
    pos = o2.pos;

    return *this;
}

bool
TListaPosicion::operator==(const TListaPosicion &o) {
    return pos == o.pos;
}

TListaPosicion
TListaPosicion::Siguente() {
    TListaPosicion nextPos;
    if (pos && pos->siguente) {
        nextPos.pos = pos->siguente;
    }
    return nextPos;
}


TListaPosicion
TListaPosicion::Anterior() {
    TListaPosicion lastPos;
    if (pos && pos->anterior) {
        lastPos.pos = pos->anterior;
    }
    return lastPos;
}

bool TListaPosicion::EsVacia()const {
    return pos == nullptr;
}
