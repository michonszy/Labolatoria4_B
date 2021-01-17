// Labolatoria4_B.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <utility>
using namespace std;



class Osoba {
protected:
    static int licznik;
    string imie;
    string nazwisko;
    int rok_urodzenia;
public:

    Osoba(string imie, string nazwisko, int rok_urodzenia) : imie(imie), nazwisko(nazwisko), rok_urodzenia(rok_urodzenia) {
        cout << "-----------------OSOBA-----------------------" << endl;
        cout << "Imie tej osoby to: " << imie << endl;
        cout << "Nazwisko tej osoby to: " << nazwisko << endl;
        cout << "Rok urodzenia tej osoby to: " << rok_urodzenia << endl;
    }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getRokUrodzenia() { return rok_urodzenia; }

    //metoda wirtualna powodująca że klasa jest abstrakcyjna
    virtual int wiek() {
        return 2020 - rok_urodzenia;
    }

    Osoba() {}

    friend ostream& operator<<(ostream& out, const Osoba& o) {
        out << "Osoba " << o.imie << " " << o.nazwisko << ", urodzony " << o.rok_urodzenia << " roku.";
        return out;
    }
};

class Pracownik : public Osoba {
protected:
    string wojewodztwo;
    int placa_minimalna;

public:
    Pracownik(string imie, string nazwisko, int rok_urodzenia, string wojewodztwo) :Osoba(imie, nazwisko, rok_urodzenia), wojewodztwo(wojewodztwo) {
        cout << "-----------------PRACOWNIK-----------------------" << endl;
        cout << "Imie tej osoby to: " << imie << endl;
        cout << "Nazwisko tej osoby to: " << nazwisko << endl;
        cout << "Rok urodzenia tej osoby to: " << rok_urodzenia << endl;
        cout << "Wojewodztwo w którym mieszka to: " << wojewodztwo << endl;

    }
    Pracownik() {
    }

    string getWojewodztwo() { return wojewodztwo; }
    int getPlacaMinimalna() { return placa_minimalna; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getRokUrodzenia() { return rok_urodzenia; }

    friend ostream& operator<<(ostream& out, const Pracownik& i) {
        out << "Pracownik " << i.imie << " " << i.nazwisko << ", urodzony " << i.rok_urodzenia << " roku.";
        return out;
    }

};

class Informatyk : public Pracownik {


private:
    string specjalizacja;
    int mnoznik;
    int pensja;
public:
    Informatyk(string imie, string nazwisko, int rok_urodzenia, string wojewodztwo, string specjalizacja, int pensja, int mnoznik) : Pracownik(imie, nazwisko, rok_urodzenia, wojewodztwo), specjalizacja(specjalizacja), pensja(pensja), mnoznik(mnoznik) {
        cout << "-----------------INFORMATYK-----------------------" << endl;
        cout << "Imie tej osoby to: " << imie << endl;
        cout << "Nazwisko tej osoby to: " << nazwisko << endl;
        cout << "Rok urodzenia tej osoby to: " << rok_urodzenia << endl;
        cout << "Wojewodztwo w którym mieszka to: " << wojewodztwo << endl;
        cout << "Jego specjalizacja to: " << specjalizacja << endl;
        cout << "Jego pensja to: " << pensja << endl;
        cout << "Mnoznik to: " << mnoznik << endl;


    }
    string getSpecjalizacja() { return specjalizacja; }
    int getMnoznik() { return mnoznik; }
    int getPensja() { return pensja; }
    string getWojewodztwo() { return wojewodztwo; }
    int getPlacaMinimalna() { return placa_minimalna; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getRokUrodzenia() { return rok_urodzenia; }
    //C
    Informatyk(Informatyk& informatyk, string imie, string nazwisko, int rok_urodzenia) {

        this->imie = imie;
        this->nazwisko = nazwisko;
        this->rok_urodzenia = rok_urodzenia;



        cout << "-----------------INFORMATYK KOPIUJĄCY-----------------------" << endl;
        cout << "Imie tej osoby to: " << imie << endl;
        cout << "Nazwisko tej osoby to: " << nazwisko << endl;
        cout << "Rok urodzenia tej osoby to: " << rok_urodzenia << endl;

    }

    //C
    void zmien_dane(string imie, string nazwisko, int rok_urodzenia) {

    }

    friend ostream& operator<<(ostream& out, const Informatyk& i) {
        out << "Informatyk " << i.imie << " " << i.nazwisko << ", urodzony " << i.rok_urodzenia << " roku." << endl;
        return out;
    }
};

class Emeryt : public Osoba {
private:
    int emerytura;
public:
    Emeryt() {}
    Emeryt(string imie, string nazwisko, int rok_urodzenia, int emerytura) : Osoba(imie, nazwisko, rok_urodzenia), emerytura(emerytura) {}
    friend ostream& operator<<(ostream& out, const Emeryt& e) {
        out << "Emeryt " << e.imie << " " << e.nazwisko << ", urodzony " << e.rok_urodzenia << " roku. " << endl;
        return out;
    }

};

int rozmiar;
//E
Osoba* generatorEmerytow(Osoba* osoby[]) {
    Emeryt* emeryt = new Emeryt[3];
    for (int i = 0, j = 0; i < 3; i++) {
        int rok = osoby[i]->getRokUrodzenia();
        int rok2 = 2020 - rok;
        if (rok2 >= 65) {
            cout << "Mamy emeryta" << endl;
            cout << "Rok urodzenia: " << osoby[i]->getRokUrodzenia() << endl;
            cout << "Na imie mu: " << osoby[i]->getImie() << endl;
            cout << "Jego nazwisko to: " << osoby[i]->getNazwisko() << endl;
            cout << "A lat ma: " << rok2 << endl;
            emeryt[j] = Emeryt(osoby[i]->getImie(), osoby[i]->getNazwisko(), osoby[i]->getRokUrodzenia(), 1500);
            j++;


            osoby[i] = osoby[i + 3];
            rozmiar = rozmiar - 1;
        }
    }
    return emeryt;
}

int main()
{
    Pracownik *pracownik1 = new Pracownik("Pracownikimie", "Pracowniknazwisko", 1980, "Małopolskie");
    Informatyk *informatyk1 = new Informatyk("imie", "Informatyknazwisko", 1940,"Śląskie","bazy danych",6600,3);
    Emeryt *emeryt1 = new Emeryt("Emerytimie", "Emerytnazwisko", 1940, 1600);

    Osoba* osoby[3];
    osoby[0] = pracownik1;
    osoby[1] = informatyk1;
    osoby[2] = emeryt1;
    cout << "--------------TABLICA-------------------" << endl;
    for (Osoba* i : osoby) cout << *i << "\n";

    delete pracownik1;
    delete informatyk1;
    delete emeryt1;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
