
#ifndef FUNKCJE_H
#define FUNKCJE_H

struct polaczenia
{
	int dokad;
	double droga;
	polaczenia * plewy;
	polaczenia * pprawy;
	polaczenia * rodzic;

};

struct miasto
{
	int nazwa;
	polaczenia *pDrogi;
	miasto *pnext;
	miasto *pprev;
};

void dodajdomiast(miasto *& pHeadmiast, miasto *& pTailmiast, const int skad, const int dokad, const double droga);
//Funkcja dodaje miasto do listy

void dodajdopol(polaczenia *& pkorzen, const int dokad, const double droga);
//Funckja do drzewa polaczen dodaje kolejne (uzyte w dodajdomiast);

void dodajdopol(polaczenia *& pkorzen, const int dokad, const double droga);
//Funckja wypisuje drzewo polaczen danego miasta (testy)

bool wczytaj(miasto *& pHeadmiast, miasto *& pTailmiast, const std::string & nazwa);
//Funkcja wczytuje dane z pliku wejscowego do drzewa; 

bool wypiszmiasta(miasto * pHeadmiast);
//Funkcja wypisauje miasta(testy);

bool znajdzpoAdresie(miasto * pHeadmiast, miasto * szukana);
//Funkcja znjaduje miasto o podanym adresie;

miasto * znajdzpoNazwie(miasto * pHeadmiast, const int nazwa);
//Funkcja znajdzuje miasto po nazwie;

void wypiszpol(polaczenia * proot, int wciecie);

void wypiszodkon(miasto * ptail);

void usunMiasto(miasto *& pHeadmiast, miasto *& pTailmiast, miasto *& dousuniecia);

void przenies(miasto *& pHeadmiast, miasto *& pTailmiast, miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, miasto *& doprzeniesienia);

void usundrzewopol(polaczenia *& pDrogi);

void dodajmiastojakoelement(miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, miasto *& doprzeniesienia, polaczenia *& drogiprzenies);

miasto *NajblizszeMiasto(polaczenia *pDrogi, miasto * pHeadmiast,  miasto * Start, double & droga);

miasto * nastepnyistniejacy(polaczenia *pDrogi, polaczenia *Aktualny, miasto * pHeadmiast, double & droga);

miasto * nastepnyistniejacynazwa(polaczenia *pDrogi, int nazwa, double & droga, miasto * pHeadmiast);

void PrzyblizonaTrasaKuriera(double & przebytadroga, miasto *& pHeadmiast, miasto *& pTailmiast, miasto * Poprzednie, miasto * Aktualne, miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone, miasto * Start);

bool PlikWyjsciowy(miasto * pHeadmiast, double droga, const std::string & output);

void usunwszystko(miasto *& pHeadmiast, miasto *& pTailmiast, miasto *& pHeadOdwiedzone, miasto *& pTailOdwiedzone);

#endif

