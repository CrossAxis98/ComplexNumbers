#include "LZespolona.hh"
#include <math.h>



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!                                                                                                                                                                     
 * Realizuje odejmowanie dwoch liczb zespolonych.                                                                                                                           
 * Argumenty:                                                                                                                                                           
 *    Skl1 - pierwszy skladnik                                                                                                                         
 *    Skl2 - drugi skladnik                                                                                                                                  
 * Zwraca:                                                                                                                                                              
 *    Roznice dwoch skladnikow przekazanych jako parametry.                                                                                                                
 */


LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!                                                                                                                                                                     
 * Realizuje mnozenie dwoch liczb zespolonych.                                                                                                                           
 * Argumenty:                                                                                                                                                           
 *    Skl1 - pierwszy skladnik                                                                                                                                
 *    Skl2 - drugi skladnik                                                                                                                                  
 * Zwraca:                                                                                                                                                              
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.                                                                                                                
 */


LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - ( Skl1.im * Skl2.im);
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;

}
/*!                                                                                                                                                                     
 * Realizuje mnozenie liczby zespolonej przez liczbe calkowita.                                                                                                                           
 * Argumenty:                                                                                                                                                           
 *    Skl1 - pierwszy skladnik                                                                                                                                
 *    Skl2 - drugi skladnik                                                                                                                                   
 * Zwraca:                                                                                                                                                              
 *   Iloczyn skladnikow przekazanych jako parametry.                                                                                                                
 */


LZespolona  operator * (LZespolona  Skl1, int a)
{

  LZespolona wynik;
  wynik.re = Skl1.re * a;
  wynik.im=Skl1.im * a;
  return wynik;


}

/* Porownuje dwie liczby zespolone 
 *Argumenty:
 * Dwie liczby zespolone.
 *Zwraca:
 * wartosc true gdy liczby sa sobie rowne i false gdy sa rozne
 */

bool operator == (LZespolona l1, LZespolona l2)
{
  if((l1.re==l2.re)&&(l1.im==l2.im))
    return true;
  else
    return false;
  }





/*
 * Liczy modul liczby zespolonej podniesiony do kwadratu.
 * Argumenty:
 * Skl2 - liczba zespolona
 * Zwraca: 
 * Modul liczby zespolonej Skl2 ^2.
 */


double Modul2(LZespolona Skl2)
{
  double modul2;
modul2 = Skl2.re * Skl2.re + Skl2.im * Skl2.im;

  
return modul2;
}

/* 
 * Tworzy sprzezenie liczby zespolonej.
 *Argumenty:
 * Skl2 - liczba zespolona
 * Zwraca:
 * Sprzezenie liczby Skl2
 */

LZespolona Sprzezenie(LZespolona Skl2)
{
  LZespolona wynik;
  wynik.re = Skl2.re;
  wynik.im = -Skl2.im;
  
  return wynik;

}

/*
 * Realizuje dzielenie liczb zespolonych przy pomocy funkcji sprzezenie oraz modul.
 *Argumenty:
 *Skl1, Skl2 - liczby zespolone
 *Zwraca:
 *Wynik dzielenia liczb zespolonych.
 */

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  double mod = Modul2(Skl2);
  LZespolona wynik;
  LZespolona gora= Skl1 * Sprzezenie(Skl2);
  if(mod==0)
    cout<<"NIE MOZNA DZIELIC PRZEZ ZERO!!!"<<endl;
  else
    {
  wynik.re=gora.re / mod;
  wynik.im=gora.im / mod;
    }
  return wynik;

}

/*
 *Wyswietla liczbe zespolona.
 *Argumenty:
 *arg- liczba zespolona
 *Zwraca:
 *Wyswietla liczbe zespolona na ekran.
 */



void Wyswietl(LZespolona arg)
{
  cout<<"("<<arg.re<<showpos<<arg.im<<"i"<<")"<<noshowpos;



}

/*                                                                                                                                                                      
 *Przeciazenie operatora wyjscia dla liczby zespolonej. Wyswietla liczbe zespolona.                                                                                                                                           
 *Argumenty:                                                                                                                                                            
 *liczba - liczba zespolona                                                                                                                                                 
 *Zwraca:                                                                                                                                                               
 *Wyswietla liczbe zespolona na ekran.                                                                                                                                  
 */


ostream& operator << (ostream& StrWyj, LZespolona liczba)
{
  StrWyj<<"("<<liczba.re<<showpos<<liczba.im<<"i)"<<noshowpos;
  return StrWyj;
  

}

/* Przeciazenie operatora wyjscia dla liczby zespolonej. Wczytuje liczbe zespolona.
 * Argumenty:
 * liczba - l.zespolona
 * Zwraca:
 * StrWej istream
 */

istream & operator >> (istream & StrWej, LZespolona & liczba)
{
  char tmp;
  StrWej >> tmp;
  if(StrWej.fail())
    {
      return StrWej;
    }
  if(tmp!='(')
    {
      StrWej.setstate(ios::failbit);
      return StrWej;
    }
  StrWej >> liczba.re;
  StrWej >> liczba.im;
  StrWej>>tmp;
  if(StrWej.fail())
    {
      return StrWej;
    }
  if(tmp!='i')
    {
      StrWej.setstate(ios::failbit);
      return StrWej;
    }
  StrWej>>tmp;
  if(StrWej.fail())
    {
      return StrWej;
    }
  if(tmp!=')')
    {
      StrWej.setstate(ios::failbit);
      return StrWej;
    }
  return StrWej;




}



  

LZespolona operator % (LZespolona aa, int bb)
{
  LZespolona wynik;
  wynik.re=fmod(aa.re,bb);
  wynik.im=fmod(aa.im,bb+1)*2;
  return wynik;
}

LZespolona operator ^ (LZespolona aa, int bb)
{
  LZespolona wynik;
  wynik.re=pow(aa.re,bb);
  wynik.im=pow(aa.im,2*bb);
  return wynik;
}
