#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

/* Struktura wyrazenia zespolonego*/


/*funkcja wyswietlajaca liczbe zespolona */
void Wyswietl(LZespolona arg);


/*
 * Przeciazenia operatorow operacji wykonywanych na liczbach zespolonych oraz funkcje potrzebne do wykonania operacji dzielenia.
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator  * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1, int a);
double Modul2(LZespolona Skl2);
LZespolona Sprzezenie(LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
ostream& operator << (ostream& StrWyj, LZespolona liczba);   
istream & operator >> (istream & StrWej, LZespolona & liczba);

bool operator == (LZespolona l1, LZespolona l2);

LZespolona operator % (LZespolona aa, int bb);
LZespolona operator ^ (LZespolona aa, int bb);
  


#endif
