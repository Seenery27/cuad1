#include <iostream>
#include <cstring> // For strcpy, strlen, and tolower
#include <cctype>  // For tolower
#ifndef __TPORO__
#define __TPORO__
using namespace std;

class TPoro {
    friend ostream & operator<<(ostream &, TPoro &);
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
		TPoro(TPoro &);
		~TPoro();
		TPoro & operator=(TPoro &);

		//------Methods

		// Operators
		bool operator==(TPoro &);
		bool operator!=(TPoro &);

		//Setters
		void Posicion(int,int);
		void Volumen(double);
		void Color(char*);

		//Getters
		int PosicionX();
		int PosicionY();
		double Volumen();
		char* Color();
		bool EsVacio();
};

#endif
