#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

/* Struktura dla Statystyki odpowiedzi
 * liczbaPoprawnych - ilosc poprawnie udzielonych odpowiedzi
 * liczbaZadanych - ilosc pytan
 */


struct Statystyka {
  unsigned int liczbaPoprawnych;
  unsigned int liczbaZadanych;
};


/* Deklaracja funkcji do liczenia poprawnych odpowiedzi */

double ObliczProcentPop(unsigned int Pop, unsigned int ile);




#endif
