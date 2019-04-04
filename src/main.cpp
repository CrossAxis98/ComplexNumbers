#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
  
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona wyn, odp;
  int szansa=1;
  unsigned int poprawne=0, ilosc=0;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe.Arg1;
    cout << ZwrocOperator(WyrZ_PytanieTestowe.Op);
    cout << WyrZ_PytanieTestowe.Arg2;
    cout << endl;

    cout << "Twoja odpowiedz: ";
    cin >> odp;
    while((cin.fail())&&(szansa!=3))
      {
	cout<<"Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl;
	++szansa;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Twoja odpowiedz: ";
	cin >> odp;
	



      }
    szansa=1;




    wyn=Oblicz(WyrZ_PytanieTestowe);

    if(odp==wyn)
      {
	cout<<"Odpowiedz poprawna."<<endl;
	++poprawne;
	++ilosc;

      }
    else
      {
	cout<<"Blad. Prawidlowym wynikiem jest: "<< wyn <<endl;
	++ilosc;
	cin.clear();
	cin.ignore(10000, '\n');
      }
  
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  
  cout<<"Ilosc dobrych odpowiedzi: "<< poprawne <<endl;
  cout<<"Ilosc blednych odpowiedzi: "<< ilosc-poprawne<<endl;
  cout<<"Wynik procentowy poprawnych odpowiedzi: "<<ObliczProcentPop(poprawne, ilosc)<<"%"<<endl;
  
}
