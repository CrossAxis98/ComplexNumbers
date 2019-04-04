#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Deklaracja funkcji do operowania na wyrazeniach zespolonych
 *
 */


void Wyswietl(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
void WyswietlSymbol(Operator Op);


/*MOJE*/
Operator WczytajSymbol();
LZespolona WczytajLZesp();
WyrazenieZesp WczytajWyrazenie();
ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr);
char ZwrocOperator(Operator symbol);
istream & operator >> (istream & StrWej, WyrazenieZesp &wyr);




#endif
