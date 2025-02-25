#include <iostream>
#include <cstring> // For strcpy, strlen, and tolower
#include <cctype>  // For tolower
#ifndef __TPORO__
#define __TPORO__
using namespace std;

class TPoro {
	friend ostream & operator<<(ostream &, const TPoro &);
	private:
        int x;
		int y;
		double volumen;
		char* color;
    public:
		//------Canonical forms
		TPoro();
		TPoro(int, int, double);
		TPoro(int, int, double, char*);
		TPoro(const TPoro &);
		~TPoro();
		TPoro & operator=(const TPoro &);

		//------Methods

		// Operators
		bool operator==(const TPoro &)const;
		bool operator!=(const TPoro &)const;

		//Setters
		void Posicion(int,int);
		void Volumen(double);
		void Color(char*);

		//Getters
		int PosicionX() const;
		int PosicionY() const;
		double Volumen() const;
		char* Color() const;
        bool EsVacio() const;
};

#endif
