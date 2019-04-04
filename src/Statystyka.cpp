#include <iostream>
#include "Statystyka.hh"

using namespace std;

/*Funkcja liczaca stosunek poprawnych odpowiedzi do liczby zadanych
 *Argumenty:
 *Pop-poprawne odpowiedzi
 *ile-ilosc pytan
 *Zwraca:
 *Stosunek poprawnych do ilosci pod postacia procentowa.
 */


double ObliczProcentPop(unsigned int Pop, unsigned int ile)
{
  double wynik;
  wynik=(Pop*100)/ile;
  return wynik;


}
