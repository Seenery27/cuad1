#include "tlistaporo.h"

TListaPoro::TListaPoro() {
    primero = nullptr;
    ultimo = nullptr;
}

TListaPoro::TListaPoro(const TListaPoro &o) {
    primero = nullptr;
    ultimo = nullptr;

    TListaPosicion pos = o.Primera();
}

TListaPoro::~TListaPoro() {
    primero = nullptr;
    ultimo = nullptr;
}

TListaPoro&
TListaPoro::operator=(const TListaPoro &o2) {
    (*this).~TListaPoro();
    primero = o2.primero;
    ultimo = o2.ultimo;

    return *this;
}

bool
TListaPoro::operator==(const TListaPoro &o) {
    TListaPosicion pos1 = Primera();
    TListaPosicion pos2 = o.Primera();

    while (!pos1.EsVacia() && !pos2.EsVacia()) {
        if (!(pos1.pos->e == pos2.pos->e)) {
            return false;
        }
        pos1 = pos1.Siguente();
        pos2 = pos2.Siguente();
    }    
    return pos1.EsVacia() && pos2.EsVacia();
}

bool
TListaPoro::operator+(const TListaPoro &o) {
    bool changed = false;
    TListaPosicion pos = o.Primera();
    while (!pos.EsVacia()) {
        if (Insertar(pos.pos->e)) {
            changed = true;
        }
        pos = pos.Siguente();
        
    }
    return changed;
}

bool
TListaPoro::operator-(const TListaPoro &o) {
    bool changed = false;
    TListaPosicion pos = Primera();
    while (!pos.EsVacia()) {
        if (o.Buscar(pos.pos->e)) {
            TListaPosicion tmp = pos.Siguente();
            Borrar(pos);
            pos = tmp;
            changed = true;
        } else {
            pos = pos.Siguente();
        }
    }
    return changed;
}


bool TListaPoro::esVacia() {
    return primero == nullptr;
}

int TListaPoro::Longitud() {
    int cnt = 0;
    TListaPosicion pos = Primera();
    while (!pos.EsVacia()) {
        cnt++;
        pos = pos.Siguente();
    }
    return cnt;
}


TListaPosicion TListaPoro::Primera()const {
    TListaPosicion pos;
    pos.pos = primero;
    return pos;
}

TListaPosicion TListaPoro::Ultima()const {
    TListaPosicion pos;
    pos.pos = ultimo;
    return pos;
}

bool TListaPoro::Insertar(const TPoro &poro) {
    if (Buscar(poro)) return false;
    TListaNodo *nuevo = new TListaNodo();
    nuevo->e = poro;
    nuevo->siguente = nullptr;
    nuevo->anterior = nullptr;
    if (esVacia()) {
        primero = nuevo;
        ultimo = nuevo;
        return true;
    }

    TListaNodo *actual = primero;
    while (actual && actual->e.Volumen() < poro.Volumen()) {
        actual = actual->siguente;
    }
    if (!actual) {
        ultimo->siguente = nuevo;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    } else if (actual == primero) {
        nuevo->siguente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
    } else {
        nuevo->siguente = actual;
        nuevo->anterior = actual->anterior;
        actual->anterior->siguente = nuevo;
        actual->anterior = nuevo;
    }
    return true;
}

bool
TListaPoro::Borrar(const TPoro &poro) {
    if (esVacia()) return false;
    TListaNodo *actual = primero;
    while (actual && !(actual->e == poro)) {
        actual = actual->siguente;
    }
    if (!actual) return false;
    if (actual == primero) primero = actual->siguente;
    if (actual == ultimo) ultimo = actual->anterior;
    if (actual->anterior) actual->anterior->siguente = actual->siguente;
    if (actual->siguente) actual->siguente->anterior = actual->anterior;
    delete actual;
    return true;
}

bool
TListaPoro::Borrar(const TListaPosicion &pos) {
    if (pos.EsVacia()) return false;
    return Borrar(pos.pos->e);
}

TPoro
TListaPoro::Obtener(const TListaPosicion &pos) {
    if (pos.EsVacia()) return TPoro();
    return pos.pos->e;
}

bool
TListaPoro::Buscar(const TPoro &poro)const{
    TListaPosicion pos = Primera();
    while (!pos.EsVacia()) {
        if (pos.pos->e == poro) return true;
        pos = pos.Siguente();
    }
    return false;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {
    TListaPoro extracted;
    if (n1 > n2 || n1 <= 0) return extracted;

    TListaPosicion pos = Primera();
    int index = 1;

    while (!pos.EsVacia() && index < n1) {
        pos = pos.Siguente();
        index++;
    }

    while (!pos.EsVacia() && index <= n2) {
        extracted.Insertar(pos.pos->e);
        TListaPosicion temp = pos.Siguente();
        Borrar(pos);
        pos = temp;
        index++;
    }
    return extracted;
}

ostream &operator<<(ostream &os, const TListaPoro &lista) {
    os << "(";
    TListaPosicion pos = lista.Primera();
    while (!pos.EsVacia()) {
        os << pos.pos->e;
        pos = pos.Siguente();
        if (!pos.EsVacia()) os << " ";
    }
    os << ")";
    return os;
}