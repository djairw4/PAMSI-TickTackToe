
#include <iostream>
#include<vector>
using namespace std;

struct Pole{
    char _znak;
    int _numer;
    int _wygrana_o=0;
    int _szybkosc_o=0;
    int _kolega_o=0;
    int _wygrana_x=0;
    int _szybkosc_x=0;
    int _kolega_x=0;
    bool puste() {
        return _znak == '_';
    }

};

vector<Pole> znajdz_max(vector<Pole> pola, int opcja, int rozmiar) {
    vector<Pole> tmp;
    tmp.reserve(rozmiar);
    int maks_wartosc = 0;
    switch (opcja) {
    case 1:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._wygrana_x > maks_wartosc) {
                maks_wartosc = (pola[i])._wygrana_x;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._wygrana_x == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    case 2:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._wygrana_o > maks_wartosc) {
                maks_wartosc = (pola[i])._wygrana_o;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._wygrana_o == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    case 3:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._szybkosc_x > maks_wartosc) {
                maks_wartosc = (pola[i])._szybkosc_x;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._szybkosc_x == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    case 4:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._szybkosc_o > maks_wartosc) {
                maks_wartosc = (pola[i])._szybkosc_o;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._szybkosc_o == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    case 5:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._kolega_x > maks_wartosc) {
                maks_wartosc = (pola[i])._kolega_x;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._kolega_x == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    case 6:
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._kolega_o > maks_wartosc) {
                maks_wartosc = (pola[i])._kolega_o;
            }
        }
        for (unsigned int i = 0; i < pola.size(); ++i) {
            if ((pola[i])._kolega_o == maks_wartosc) {
                tmp.push_back(pola[i]);
            }
        }
        break;
    }
    return tmp;
}



struct Plansza {
    int _wymiar; //plansza: wymiar x wymiar
    int _ile; //ile znakow w lini daje wygrana
    vector<Pole> _pola;
    Plansza(unsigned int n,unsigned int ile) {
        _wymiar = n;
        if (ile > n) { _ile = n; }
        else { _ile = ile; }
        _pola = vector<Pole>(_wymiar * _wymiar);
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            (_pola[i])._znak = '_';
            (_pola[i])._numer = i;
        }
    }
    void wyswietl() {
        int wiersz;
        cout << endl;
        for (unsigned int i = 0; i < _wymiar; ++i) {
            cout << i << " ";
        }
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._znak << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { wiersz = i / _wymiar; cout<<wiersz<< endl; }
        } 
        cout << endl;
    }
    void wyswietl_parametry() {
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._wygrana_x << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._szybkosc_x << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._kolega_x << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._wygrana_o << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._szybkosc_o << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
        cout << endl;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            cout << (_pola[i])._kolega_o << " ";
            if ((i % _wymiar) == (_wymiar - 1)) { cout << endl; }
        }
        cout << endl;
    }
    bool puste(int nr) {
        if (nr >= (_wymiar * _wymiar)) { return false; }
        else { return (_pola[nr]).puste(); }
    }
    bool pusta() {
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if ((_pola[i])._znak != '_') { return false; }
        }
        return true;
    }
    bool remis() {
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if ((_pola[i])._znak == '_') return false;
        }
        return true;
    }
    bool nalezy(int nr) {
        return (nr >= 0 && nr < (_wymiar* _wymiar));
    }
    void zaznacz(char znak, unsigned int nr) {
       if((_pola[nr])._znak =='_'){
           (_pola[nr])._znak = znak;
       }
    }
    void zeruj(unsigned int nr) {
        if (nr<_wymiar*_wymiar) {
            (_pola[nr])._znak = '_';
        }
    }
    bool wygrana() {
        if (_ile == 0) { return true; }
        //w poziomie
        for (int i = 0; i < (_wymiar * _wymiar); i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak != '_') {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n+j])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //w pionie
        for (int i = 0; i < _wymiar * (_wymiar + 1 - _ile); i += _wymiar) {
            for (int n = i; n < i + _wymiar; ++n) {
                if ((_pola[n])._znak != '_') {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n+j*_wymiar])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //na skos malejacy
        for (int i = 0; i < _wymiar * (_wymiar + 1 - _ile); i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak != '_') {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n+j +j*_wymiar])._znak ) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //na skos rosnacy
        for (int i = (_ile - 1) * _wymiar; i < _wymiar * _wymiar; i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak != '_') {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n+j - j*_wymiar])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        return false;
    }
    bool wygrana(char znak) {
        if (_ile == 0) { return true; }
        //w poziomie
        for (int i = 0; i < (_wymiar * _wymiar); i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak == znak) {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n + j])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //w pionie
        for (int i = 0; i < _wymiar * (_wymiar + 1 - _ile); i += _wymiar) {
            for (int n = i; n < i + _wymiar; ++n) {
                if ((_pola[n])._znak ==znak) {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n + j * _wymiar])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //na skos malejacy
        for (int i = 0; i < _wymiar * (_wymiar + 1 - _ile); i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak == znak) {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n + j + j * _wymiar])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        //na skos rosnacy
        for (int i = (_ile - 1) * _wymiar; i < _wymiar * _wymiar; i += _wymiar) {
            for (int n = i; n < (i + _wymiar + 1 - _ile); ++n) {
                if ((_pola[n])._znak == znak) {
                    int licznik = 1;
                    for (int j = 1; j < _ile; ++j) {
                        if ((_pola[n])._znak == (_pola[n + j - j * _wymiar])._znak) { ++licznik; }
                        else { break; }
                    }
                    if (licznik == _ile) { return true; }
                }
            }
        }
        return false;
    }
    void oblicz_param_W(char znak) {
        for (int i = 0; i < (_wymiar * _wymiar); i += _wymiar) {
            for (int n = i; n < (i + _wymiar); ++n) {
                if (znak == 'x') { (_pola[n])._wygrana_x = 0; }
                if (znak == 'o') { (_pola[n])._wygrana_o = 0; }
                if ((_pola[n])._znak == '_') {
                    //w poziomie
                    unsigned int licznik_poziom = 1;
                    for (int j = n + 1; j < i + _wymiar && j < (n + _ile); ++j) {
                        if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                            ++licznik_poziom;
                        }
                        else { break; }
                    }
                    if (licznik_poziom == _ile) {
                        if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                        if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                    }
                    else {
                        for (int j = n - 1; j >= i && licznik_poziom != _ile; --j) {
                            if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                                ++licznik_poziom;
                                if (licznik_poziom == _ile) {
                                    if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                                    if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                                }
                            }
                            else { break; }
                        }
                    }
                    //w pionie
                    unsigned int licznik_pion = 1;
                    for (int j = n + _wymiar; j < _wymiar * _wymiar && j < (n + _ile * _wymiar); j += _wymiar) {
                        if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                            ++licznik_pion;
                        }
                        else { break; }
                    }
                    if (licznik_pion == _ile) {
                        if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                        if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                    }
                    else {
                        for (int j = n - _wymiar; j >= 0 && licznik_pion != _ile; j -= _wymiar) {
                            if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                                ++licznik_pion;
                                if (licznik_pion == _ile) {
                                    if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                                    if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                                }
                            }
                            else { break; }
                        }
                    }
                    //na skos malejacy
                    unsigned int licznik_skos1 = 1;
                    for (int j = n + 1 +_wymiar,k=2; (j < i + k*_wymiar) && j< _wymiar*_wymiar && licznik_skos1 != _ile; j+=(_wymiar+1),++k) {
                        if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                            ++licznik_skos1;
                        }
                        else { break; }
                    }
                    if (licznik_skos1 == _ile) {
                        if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                        if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                    }
                    else {
                        for (int j = n - 1-_wymiar,k=1;  (j >= i - k * _wymiar) && j>=0 && licznik_skos1 != _ile; j -= (_wymiar + 1),++k) {
                            if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                                ++licznik_skos1;
                                if (licznik_skos1 == _ile) {
                                    if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                                    if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                                }
                            }
                            else { break; }
                        }
                    }
                    //na skos rosnacy
                    unsigned int licznik_skos2 = 1;
                    for (int j = n - 1 + _wymiar, k = 1; (j >= i + k * _wymiar) && j < _wymiar * _wymiar && licznik_skos2 != _ile; j += (_wymiar - 1), ++k) {
                        if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                            ++licznik_skos2;
                        }
                        else { break; }
                    }
                    if (licznik_skos2 == _ile) {
                        if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                        if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                    }
                    else {
                        for (int j = n + 1 - _wymiar, k = 0; (j < i - k * _wymiar) && j >= 0 && licznik_skos2 != _ile; j -= (_wymiar - 1), ++k) {
                            if ((_pola[j])._znak == '_' || (_pola[j])._znak == znak) {
                                ++licznik_skos2;
                                if (licznik_skos2 == _ile) {
                                    if (znak == 'x') { ++((_pola[n])._wygrana_x); }
                                    if (znak == 'o') { ++((_pola[n])._wygrana_o); }
                                }
                            }
                            else { break; }
                        }
                    }
                }
            }
        }
    }
    bool koncz_blokuj(char znak) {
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if (znak == 'x' && (_ile - (_pola[i])._szybkosc_x == 1)) { zaznacz(znak, i); return true; }
            if (znak == 'o' && (_ile - (_pola[i])._szybkosc_o == 1)) { zaznacz(znak, i); return true; }
        }
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if (znak == 'x' && (_ile - (_pola[i])._szybkosc_o == 1)) { zaznacz(znak, i); return true; }
            if (znak == 'o' && (_ile - (_pola[i])._szybkosc_x == 1)) { zaznacz(znak, i); return true; }
        }
        return false;
    }
    void szukaj_kolegow() {
        for (int i = 0; i < _pola.size(); ++i) {
            (_pola[i])._kolega_x = 0;
            (_pola[i])._kolega_o = 0;
            if ((i % _wymiar )== 0) {
                for (int j = (i - _wymiar); j <= (i + _wymiar); j += _wymiar) {
                    for (int k = j; k < (j + 2); ++k) {
                        if (k >= 0 && k < (_wymiar * _wymiar)) {
                            if ((_pola[k])._znak == 'x') { ++((_pola[i])._kolega_x); }
                            if ((_pola[k])._znak == 'o') { ++((_pola[i])._kolega_o); }
                        }
                    }
                }
            }
            else if ((i % _wymiar) == (_wymiar - 1)) {
                for (int j =( i -(_wymiar+1)); j <=( i + _wymiar); j += _wymiar) {
                    for (int k = j; k < (j + 2); ++k) {
                        if (k >= 0 && k < (_wymiar * _wymiar)) {
                            if ((_pola[k])._znak == 'x') { ++((_pola[i])._kolega_x); }
                            if ((_pola[k])._znak == 'o') { ++((_pola[i])._kolega_o); }
                        }
                    }
                }
            }
            else {
                for (int j = (i - (_wymiar + 1)); j <= (i + _wymiar - 1); j += _wymiar) {
                    for (int k = j; k < (j + 3); ++k) {
                        if (k >= 0 && k < (_wymiar * _wymiar)) {
                            if ((_pola[k])._znak == 'x') { ++((_pola[i])._kolega_x); }
                            if ((_pola[k])._znak == 'o') { ++((_pola[i])._kolega_o); }
                        }
                    }
                }
            }
        }
    }
    void oblicz_param_S(char znak) {
        for (int i = 0; i < (_wymiar * _wymiar); i += _wymiar) {
            for (int n = i; n < (i + _wymiar); ++n) {
                if (znak == 'x') { (_pola[n])._szybkosc_x = 0; }
                if (znak == 'o') { (_pola[n])._szybkosc_o = 0; }
                if ((_pola[n])._znak == '_') {
                    //w poziomie
                    int j = n + 1 - _ile;
                    if (j < i) { j = i; }
                    for (; j <= n ; ++j) {
                        int licznik_znakow = 0;
                        int zakres=0;
                        for (int k = j; k < j + _ile && k<i+_wymiar; ++k) {
                            if ((_pola[k])._znak == znak) { ++licznik_znakow; }
                            else if ((_pola[k])._znak == '_') {}
                            else { j = k; licznik_znakow = 0; break; }
                            ++zakres;
                        }
                        if (zakres ==_ile && znak=='x' && (_pola[n])._szybkosc_x < licznik_znakow) { (_pola[n])._szybkosc_x = licznik_znakow; }
                        if (zakres == _ile && znak == 'o' && (_pola[n])._szybkosc_o < licznik_znakow) { (_pola[n])._szybkosc_o = licznik_znakow; }
                    }
                    //w pionie
                    j = n - (_ile-1)*_wymiar;
                    if (j < 0) { j = n%_wymiar; }
                    for (; j <= n; j+=_wymiar) {
                        int licznik_znakow = 0;
                        int zakres = 0;
                        for (int k = j; k < j + _ile*_wymiar && k < _wymiar*_wymiar; k+=_wymiar) {
                            if ((_pola[k])._znak == znak) { ++licznik_znakow; }
                            else if ((_pola[k])._znak == '_') {}
                            else { j = k; licznik_znakow = 0; break; }
                            ++zakres;
                        }
                        if (zakres == _ile && znak == 'x' && (_pola[n])._szybkosc_x < licznik_znakow) { (_pola[n])._szybkosc_x = licznik_znakow; }
                        if (zakres == _ile && znak == 'o' && (_pola[n])._szybkosc_o < licznik_znakow) { (_pola[n])._szybkosc_o = licznik_znakow; }
                    }
                    //skos malejacy
                    j = n - (_ile-1)*(_wymiar+1);
                    int l = 0;
                    if (j < 0) {
                        while (j < 0) { j += (_wymiar + 1); ++l; }
                    }
                    
                    if (j < (i - (_ile -1 - l) * _wymiar)) { while (j < (i - (_ile - 1 - l) * _wymiar)) { j += (_wymiar + 1); ++l; } }
                    for (; j <= n; j+=(_wymiar+1)) {
                        int licznik_znakow = 0;
                        int zakres = 0;
                        for (int k = j; k < j + _ile*(_wymiar+1) && (k < (i - (_ile-2- l) * _wymiar) + (zakres) * _wymiar) && k < _wymiar * _wymiar; k+=(_wymiar+1)) {
                            if ((_pola[k])._znak == znak) { ++licznik_znakow; }
                            else if ((_pola[k])._znak == '_') {}
                            else { j = k; licznik_znakow = 0; break; }
                            ++zakres;
                        }
                        if (zakres == _ile && znak == 'x' && (_pola[n])._szybkosc_x < licznik_znakow) { (_pola[n])._szybkosc_x = licznik_znakow; }
                        if (zakres == _ile && znak == 'o' && (_pola[n])._szybkosc_o < licznik_znakow) { (_pola[n])._szybkosc_o = licznik_znakow; }
                        ++l;
                    }
                    //skos rosnacy
                    j = n - (_ile - 1) * (_wymiar - 1);
                    l = 0;
                    if (j < 0) {
                        while (j < 0) { j += (_wymiar - 1); ++l; }
                    }

                    if (j >= (i - (_ile - 2 - l) * _wymiar)) { while (j >= (i - (_ile - 2 - l) * _wymiar)) { j += (_wymiar - 1); ++l; } }
                    for (; j <= n; j += (_wymiar - 1)) {
                        int licznik_znakow = 0;
                        int zakres = 0;
                        for (int k = j; k < j + _ile * (_wymiar - 1) && (k >= (i - (_ile - 1 - l) * _wymiar) + zakres * _wymiar) && k < _wymiar * _wymiar; k += (_wymiar - 1)) {
                            if ((_pola[k])._znak == znak) { ++licznik_znakow; }
                            else if ((_pola[k])._znak == '_') {}
                            else { j = k; licznik_znakow = 0; break; }
                            ++zakres;
                        }
                        if (zakres == _ile && znak == 'x' && (_pola[n])._szybkosc_x < licznik_znakow) { (_pola[n])._szybkosc_x = licznik_znakow; }
                        if (zakres == _ile && znak == 'o' && (_pola[n])._szybkosc_o < licznik_znakow) { (_pola[n])._szybkosc_o = licznik_znakow; }
                        ++l;
                    }
                }

            }
        }
    }

   
    void oblicz_parametry() {
        oblicz_param_W('x');
        oblicz_param_W('o');
        oblicz_param_S('x');
        oblicz_param_S('o');
        szukaj_kolegow();
    }

    void pierwszy_ruch() {
        unsigned int wynik;
        if (_wymiar % 2 == 1) { wynik = (_wymiar * _wymiar) / 2; }
        else { wynik = (_wymiar * _wymiar) / 2 + _wymiar / 2; }
        zaznacz('o', wynik);
    }

    int ile_pustych(){
        int licznik = 0;
        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if (puste(i)) {
                ++licznik;
            }
        }
        return licznik;
    }

    int MinMax(char gracz1, int poziom) {

        if (wygrana('x')) { return -1; }
        if (wygrana('o')) { return 1; }
        if (remis()) { return 0; }

        unsigned int numer = 0;
        int wartosc;
        int wartosc_max = -2;
        char gracz2 = 'x';
        if (gracz1 == 'x') { gracz2 = 'o'; wartosc_max = 2; }

        for (unsigned int i = 0; i < _pola.size(); ++i) {
            if (puste(i)) {
                zaznacz(gracz1, i);
                wartosc = MinMax(gracz2, poziom + 1);
                if (((gracz1 == 'x') && (wartosc < wartosc_max)) || ((gracz1 == 'o') && (wartosc > wartosc_max))) {
                    wartosc_max = wartosc; numer = i;
                }
                zeruj(i);
            }
            if (((gracz1 == 'x') && (wartosc_max == -1)) || ((gracz1 == 'o') && (wartosc_max == 1))) {
                break;
            }
        }
        if (poziom == 0) { zaznacz(gracz1, numer); }
        return wartosc_max;
    }

    bool ruch_przegrany(unsigned int nr, char znak) {
        Plansza Kopia = (*this);
        char gracz='x';
        unsigned int licznik = 0;
        if (znak == 'x') { gracz = 'o'; }
        Kopia.zaznacz(znak, nr);
        Kopia.oblicz_parametry();
        if (!Kopia.koncz_blokuj(gracz)) {
            for (unsigned int i = 0; i < Kopia._pola.size(); ++i) {
                licznik = 0;
                if ((Kopia._pola[i])._znak == '_') {
                    Kopia.zaznacz(gracz, i);
                    Kopia.oblicz_parametry();
                    for (unsigned int j = 0; j < Kopia._pola.size(); ++j) {
                        if (znak == 'x' && (_ile - (Kopia._pola[j])._szybkosc_o == 1)) { ++licznik; }
                        if (znak == 'o' && (_ile - (Kopia._pola[j])._szybkosc_x == 1)) { ++licznik; }
                        if (licznik >= 2) { return true; }
                    }
                    Kopia.zeruj(i);
                } 
            }
        }
        else {
            Kopia.oblicz_parametry();
            for (unsigned int i = 0; i < Kopia._pola.size(); ++i) {
                if (znak == 'x' && (_ile - (Kopia._pola[i])._szybkosc_o == 1)) { ++licznik; }
                if (znak == 'o' && (_ile - (Kopia._pola[i])._szybkosc_x == 1)) { ++licznik; }
                if (licznik >= 2) { return true; }
            }
        }
        return false;
    }
    
  
    void ruch_komputera(char znak) {
        
        if (pusta()) { pierwszy_ruch(); }
        else {
            if (!koncz_blokuj(znak)) {
                if (znak == 'x') {
                    int poziom = ile_pustych();
                    if (poziom <= 9) { MinMax(znak, 0); }
                    else {
                        vector<Pole> tmp;
                        bool zaznaczono = false;
                        tmp = znajdz_max(_pola, 4, _wymiar * _wymiar);
                        tmp = znajdz_max(tmp, 2, tmp.size());
                        tmp = znajdz_max(tmp, 3, tmp.size());
                        tmp = znajdz_max(tmp, 1, tmp.size());
                        tmp = znajdz_max(tmp, 6, tmp.size());
                        tmp = znajdz_max(tmp, 5, tmp.size());
                        for (unsigned int i = 0; i < tmp.size(); ++i) {
                            if (!ruch_przegrany((tmp[i])._numer, znak)) {
                                zaznacz(znak, (tmp[i])._numer);
                                zaznaczono = true;
                                break;
                            }
                        }
                        if (!zaznaczono) {
                            for (unsigned int i = 0; i < _pola.size(); ++i) {
                                if (_pola[i]._znak == '_' && !ruch_przegrany(i, znak)) {
                                    zaznacz(znak, i);
                                    zaznaczono = true;
                                    break;
                                }
                            }
                        }
                        if (!zaznaczono) { zaznacz(znak, (tmp[0])._numer); }
                    }
                }
                if (znak == 'o') {
                    int poziom = ile_pustych();
                    if (poziom <= 9) { MinMax(znak, 0); }
                    else {
                        vector<Pole> tmp;
                        bool zaznaczono = false;
                        tmp = znajdz_max(_pola, 2, _wymiar * _wymiar);
                        tmp = znajdz_max(tmp, 4, tmp.size());
                        tmp = znajdz_max(tmp, 1, tmp.size());
                        tmp = znajdz_max(tmp, 3, tmp.size());
                        tmp = znajdz_max(tmp, 6, tmp.size());
                        tmp = znajdz_max(tmp, 5, tmp.size());
                        for (unsigned int i = 0; i < tmp.size(); ++i) {
                            if (!ruch_przegrany((tmp[i])._numer, znak)) {
                                zaznacz(znak, (tmp[i])._numer);
                                zaznaczono = true;
                                break;
                            }
                        }
                        if (!zaznaczono) {
                            for (unsigned int i = 0; i < _pola.size(); ++i) {
                                if (_pola[i]._znak == '_' && !ruch_przegrany(i, znak)) {
                                    zaznacz(znak, i);
                                    zaznaczono = true;
                                    break;
                                }
                            }
                        }
                        if (!zaznaczono) { zaznacz(znak, (tmp[0])._numer); }
                    }
                }
            }
        }
    }  

    void zaznacz(char znak, unsigned int wiersz, unsigned int kolumna) {
            zaznacz(znak, wiersz * _wymiar + kolumna);
    }
    
};


int main()
{
    unsigned int wymiar,wiersz,kolumna, ile_wygrywa;
    char tura='x',gracz='n';
    cout << "Podaj rozmiar planszy NxN \n"<<"N= ";
    cin >> wymiar;
    cout <<endl<< "Ustal ile znakow w jednej lini bedzie dawac wygrana \n" << "Ilosc= ";
    cin >> ile_wygrywa;
    while (gracz!='x' && gracz!='o') {
        cout << endl << "Wybierz swoj znak (kolko 'o' zaczyna gre)." << endl << "Wpisz 'o' lub 'x': ";
        cin >> gracz;
    }
    Plansza Rozgrywka(wymiar, ile_wygrywa);
    Rozgrywka.wyswietl();
    Rozgrywka.oblicz_parametry();

    while (!Rozgrywka.wygrana() && !Rozgrywka.remis()) {
        if (tura == 'o')tura = 'x';
        else if (tura == 'x')tura = 'o';
        cout << "Tura gracza: " << tura << endl;
        if (tura == gracz) {
            do{
            cout << "Podaj numer wiersza i kolumny pola, ktore chcesz zaznaczyc " << endl;
            cin >> wiersz;
            cin >> kolumna;
            }while (wiersz >= wymiar || kolumna >= wymiar);
            while (!Rozgrywka.puste(wiersz*wymiar + kolumna)) {
                cout << "Pole zajete, wybierz nowe pole" << endl;
                cin >> wiersz;
                cin >> kolumna;
            }
            Rozgrywka.zaznacz(tura, wiersz, kolumna);
        }
        else {
            if (gracz == 'x') { Rozgrywka.ruch_komputera('o'); }
            if (gracz == 'o') { Rozgrywka.ruch_komputera('x'); }
        }
        Rozgrywka.wyswietl();
        Rozgrywka.oblicz_parametry();
    } 
    if (Rozgrywka.wygrana()) { cout << "Wygrywa gracz: " << tura << endl; }
    else if (Rozgrywka.remis()) { cout << "Remis" << endl; }
}