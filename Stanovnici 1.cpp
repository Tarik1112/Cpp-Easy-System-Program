#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

char * crt = "\n============================\n";

struct Drzava{
	char naziv[50];
	char kontinent[30];
	int brStanovnika;
};

struct Grad{
	Drzava drzava;
	char naziv[20];
	int brStanovnika;
};

struct Stanovnik{
	char imePrezime[50];
	Grad grad;
	int godiste;
	bool zaposlen;
};

Stanovnik unosStanovnika(){
	Stanovnik s;
	cout << "Unos podataka o stanovnicima:\n";
	cout << "Unijeti ime i prezime stanovnika: ";
	cin.getline( s.imePrezime, 50);
	cout << "Unesite naziv drzave iz koje je stanovnik: ";
	cin.getline(s.grad.drzava.naziv, 50);
	cout << "Unesite kontinent drzave: ";
	cin.getline(s.grad.drzava.kontinent,30);
	cout << "Unesite broj stanovnika drzave: ";
	cin >> s.grad.drzava.brStanovnika;
	cin.ignore();
	cout << "Unesite naziv grada iz kojeg je stanovnik: ";
	cin.getline(s.grad.naziv, 20);
	cout << "Unesite broj stanovnika grada: ";
	cin >> s.grad.brStanovnika;
	cout << "Unesite godiste stanovnika: ";
	cin >> s.godiste;
	cout << "Da li je stanovnik zaposlen: \n0 = NE \n1 = DA\nOdabir: ";
	cin >> s.zaposlen;
		return s;
}

void ispisStanovnika(Stanovnik s){
	cout << crt;
	cout << "Podaci o stanovniku: " <<endl;
	cout << "Ime i prezime: " << s.imePrezime <<endl;
	cout << "Grad: " << s.grad.naziv << endl;
	cout << "Drzava: " << s.grad.drzava.naziv << " - " << s.grad.drzava.kontinent <<  "(" << s.grad.drzava.brStanovnika << " stanovnika)" << endl;
	cout << "Godina: " << 2020 - s.godiste << endl;
	cout << "Zaposlenje: ";
	if (s.zaposlen == true){
		cout << "DA\n" ;
	}else{
		cout << "NE\n" ;
	}
}

int prirastajStanovnika(Drzava d, int n){
	if (n == 1){
		return d.brStanovnika ;
	}else return prirastajStanovnika(d, n-1) + d.brStanovnika*0.01;
}

int main(){
	
	Stanovnik st;
	int  a;
	st = unosStanovnika();
	ispisStanovnika(st);
	cout << "Unesite broj godina: ";
	cin >> a;
	cout << "Za " << a << " godine broj stanovnika ce biti jednak " << prirastajStanovnika(st.grad.drzava,a) <<endl;
	
	return 0;
}

