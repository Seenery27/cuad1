#include "tporo.h"
char* turnLowercase(const char* str);
// Constructors and overloaders

TPoro::TPoro() {
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = NULL;

}

TPoro::TPoro(int x, int y, double volumen) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
}

TPoro::TPoro(int x, int y, double volumen, char* color) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    this->color = turnLowercase(color);
}

TPoro::TPoro(TPoro &o) {
    this->x = o.x;
    this->y = o.y;
    this->volumen = o.volumen;
    this->color = turnLowercase(o.color);
}

TPoro::~TPoro() {}

TPoro&
TPoro::operator=(TPoro &o2) {
    (*this).~TPoro();
    x = o2.x;
    y = o2.y;
    volumen = o2.volumen;
    strcpy(color, o2.color);

    return *this;

}

// Operator functions

bool
TPoro::operator==(TPoro &ob) {
    bool temp;
    temp = (x == ob.x && y == ob.y && volumen == ob.volumen && color == ob.color) ? true : false;

    return temp;
}

bool
TPoro::operator!=(TPoro &ob) {
    return !(*this == ob);
}

// Setters

void TPoro::Posicion(int x, int y) {
    this->x = x;
    this->y = y;
}

void TPoro::Color(char * color) {
    strcpy(this->color, color);
}

// Getters

int TPoro::PosicionX() {return x;}

int TPoro::PosicionY() {return y;}

double TPoro::Volumen() {return volumen;}

char* TPoro::Color() {return color;}


// Method to check if all values are 0 or empty
bool TPoro::EsVacio() {
    if (x == 0 && y == 0 && volumen == 0 && color == NULL) return true;
    return false;
}

ostream & operator<<(ostream &os,const TPoro &poro){
    
    if(!poro.EsVacio()){
        os.setf(ios::fixed);
        os.precision(2);
        os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
        if(poro.color!=NULL)
        os<<poro.color;
        else
        os<<"-";
    }
    else os << "()";
    return os;
}

char* turnLowercase(const char* str) {
    if (!str) return nullptr;
    char* lowerStr = new char[strlen(str)+1];
    for(size_t i = 0; i < strlen(str); i++) {
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[strlen(str)] = '\0';
    return lowerStr;
}
