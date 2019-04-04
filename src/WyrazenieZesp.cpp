#include "WyrazenieZesp.hh"
#include <cstdlib>

/*
 * Wyswietla symbol w wyrazeniu zespolonym.
 *Argumenty:
 *Op - zmienna enum Operator
 *Zwraca:
 *Wyswietla adekwatny operator.
 */


void WyswietlSymbol(Operator Op)
{
  switch(Op)
    {
    case Op_Dodaj:
      cout<<"+";
      break;
    case Op_Odejmij:
      cout<<"-";
      break;
    case Op_Mnoz:
      cout<<"*";
      break;
    case Op_Dziel:
      cout<<"/";
      break;
    default:
	cout<<"Cos nie tak z symbolem!";
      break;
    }

}

/* 
 * Wyswietla wyrazenie Zespolone
 *Argumenty:
 *WyrZ - wyrazenie zespolone
 *Zwraca:
 *Wyswietla wyrazenie zespolone na ekran.
 */


void Wyswietl(WyrazenieZesp  WyrZ)
{
  Wyswietl(WyrZ.Arg1);
  WyswietlSymbol(WyrZ.Op);
  Wyswietl(WyrZ.Arg2);
}

/* Oblicza podane wyrazenie zespolone.
 *Argumenty:
 *WyrZ - wyrazenie zespolone
 *Zwraca:
 *Wynik danej operacji.
 */

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{

  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      return WyrZ.Arg1 + WyrZ.Arg2;
      break;
    case Op_Odejmij:
      return WyrZ.Arg1 - WyrZ.Arg2;
      break;
    case Op_Mnoz:
      return WyrZ.Arg1 * WyrZ.Arg2;
      break;
    case Op_Dziel:
      return WyrZ.Arg1 / WyrZ.Arg2;
      break;
    default:
      cerr<<"Cos nie tak z symbolem!";
      exit(1);
      
      break;




    }
}

/*
 *Wczytuje symbol
 *Zwraca:
 *Operacje ktora nalezy wykonac.
 */

Operator WczytajSymbol()
{
  Operator wynik;
  char znak;
  cin>>znak;
  switch(znak)
    {
    case '+': wynik=Op_Dodaj; break;
    case '-': wynik=Op_Odejmij; break;
    case '*': wynik=Op_Mnoz; break;
    case '/': wynik=Op_Dziel; break;
    default: 
    cerr<<"Cos nie tak z symbolem!";
        exit(1);

      break;

    }
  return wynik;
}

/*Funkcja zwracajaca odpowiedni znak w dzialaniu.
 *Argumenty:
 *symbol-operacja ktora ma sie wykonac
 *Zwraca:
 *odpowiedni znak
 */

char ZwrocOperator(Operator symbol)
{
  char znak;
  switch(symbol)
    { case Op_Dodaj:
	znak='+';
	return znak;
    case Op_Odejmij:
      znak='-';
      return znak;
    case Op_Mnoz:
      znak='*';
      return znak;
    case Op_Dziel:
      znak='/';
      return znak;
    default:
      znak='1';
      cout<<"Cos nie tak z ZwrocOperator"<<endl;
      return znak;
      }
}

/*
 *Wczytuje liczbe zespolona.
 *Zwraca:
 *Liczbe zespolona.
 */


LZespolona WczytajLZesp()
{
  LZespolona liczba;
  char tmp;
  cin>>tmp;
  cin>>liczba.re;
  cin>>liczba.im;
  cin>>tmp;
  cin>>tmp;
  return liczba;
}

/*Wczytuje wyrazenie Zespolone.
 *Zwraca:
 *Wczytane liczby zespolone oraz operator.
 */

WyrazenieZesp WczytajWyrazenie()
{
  WyrazenieZesp wyr;
  wyr.Arg1=WczytajLZesp();
  wyr.Op=WczytajSymbol();
  wyr.Arg2=WczytajLZesp();

  return wyr;
  
}

/*                                                                                                                                                                      
 * Przeciazenie operatora wyjscia dla wyrazenia zespolonego. Wyswietla wyrazenie Zespolone                                                                                                                                        
 *Argumenty:                                                                                                                                                             *wyr - wyrazenie zespolone                                                                                                                                            
 *Zwraca:                                                                                                                                                               
 *Wyswietla wyrazenie zespolone na ekran.                                                                                                                               
 */

ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr)
{
  StrWyj<<wyr.Arg1;
  StrWyj<<ZwrocOperator(wyr.Op);
  StrWyj<<wyr.Arg2;

  return StrWyj;


}

/*Przeciazenie operatora wejscia dla wyrazenia zespolonego. Wczytuje wyrazenie Zespolone.                                                                                                                                         
 *Zwraca:                                                                                                                                                               
 *Wczytane liczby zespolone oraz operator.                                                                                                                              
 */


istream & operator >> (istream & StrWej, WyrazenieZesp & wyr)
{
  StrWej>>wyr.Arg1;
  wyr.Op=WczytajSymbol();
  StrWej>>wyr.Arg2;
  return StrWej;

}
