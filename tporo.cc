#include "tporo.h"
char* turnLowercase(const char* str);
// Constructors and overloaders

TPoro::TPoro() {
    this->x = 0;
    this->y = 0;
    this->volumen = 0;
    this->color = nullptr;
}

TPoro::TPoro(int x, int y, double volumen) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    this->color = nullptr;
}

TPoro::TPoro(int x, int y, double volumen, char* color) {
    this->x = x;
    this->y = y;
    this->volumen = volumen;
    this->color = turnLowercase(color);
}

TPoro::TPoro(const TPoro &o) {
    this->x = o.x;
    this->y = o.y;
    this->volumen = o.volumen;
    this->color = turnLowercase(o.color);
}

TPoro::~TPoro() {
    delete[] color;
    color = nullptr;
}

TPoro&
TPoro::operator=(const TPoro &o2) {
    (*this).~TPoro();
    x = o2.x;
    y = o2.y;
    volumen = o2.volumen;
    color = o2.color;

    return *this;

}

// Operator functions

bool
TPoro::operator==(const TPoro &ob) const{

    return (x == ob.x && y == ob.y && volumen == ob.volumen && ((color == nullptr && ob.color == nullptr) ||(color && ob.color && strcmp(color,ob.color)==0)));


}

bool
TPoro::operator!=(const TPoro &ob)const {
    return !(*this == ob);
}

// Setters

void TPoro::Posicion(int x, int y) {
    this->x = x;
    this->y = y;
}

void TPoro::Color(char * color) {
    delete[] color;
    color = turnLowercase(color);
}

// Getters

int TPoro::PosicionX()const {return x;}

int TPoro::PosicionY()const {return y;}

double TPoro::Volumen()const {return volumen;}

char* TPoro::Color() const{
    if (!color) return nullptr;
    char* copy = new char[strlen(color)+1];
    strncpy(copy, color, strlen(color)+1);
    return copy;
}


// Method to check if all values are 0 or empty
bool TPoro::EsVacio()const{
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
    if (!str) return NULL;
    char* lowerStr = new char[strlen(str)+1];
    for(size_t i = 0; i < strlen(str); i++) {
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[strlen(str)] = '\0';
    return lowerStr;
}
