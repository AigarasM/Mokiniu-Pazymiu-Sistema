#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;

string vardai[MAX_MOKINIAI];
int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
int mokiniuKiekis = 0;
int pazymiuKiekis[MAX_MOKINIAI];

void ivestiDuomenis() {
    if (mokiniuKiekis >= MAX_MOKINIAI) {
        cout << "Pasiektas maksimalus mokiniu skaicius!\n";
        return;
    }

    cout << "Iveskite mokinio varda: ";
    cin >> vardai[mokiniuKiekis];

    cout << "Kiek pazymiu norite ivesti (iki 10): ";
    int kiekis;
    cin >> kiekis;

    if (kiekis > MAX_PAZYMIAI) kiekis = MAX_PAZYMIAI;

    pazymiuKiekis[mokiniuKiekis] = kiekis;

    for (int i = 0; i < kiekis; i++) {
        cout << "Iveskite " << i + 1 << "-aji pazymi: ";
        cin >> pazymiai[mokiniuKiekis][i];
    }

    mokiniuKiekis++;
    cout << "Mokinys pridetas sekmingai!\n";
}

void rodytiVisus() {
    if (mokiniuKiekis == 0) {
        cout << "Nera ivestu mokiniu.\n";
        return;
    }

    cout << "\n--- Mokiniu sarasas ---\n";
    for (int i = 0; i < mokiniuKiekis; i++) {
        cout << i + 1 << ". " << vardai[i] << ": ";
        for (int j = 0; j < pazymiuKiekis[i]; j++) {
            cout << pazymiai[i][j] << " ";
        }
        cout << endl;
    }
}

void rodytiKonkretu() {
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

    bool rastas = false;
    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            cout << vardai[i] << " pazymiai: ";
            for (int j = 0; j < pazymiuKiekis[i]; j++) {
                cout << pazymiai[i][j] << " ";
            }
            cout << endl;
            rastas = true;
            break;
        }
    }

    if (!rastas) cout << "Toks mokinys nerastas.\n";
}

void atnaujintiPazymi() {
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

    bool rastas = false;
    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            rastas = true;
            cout << "Pazymiai: ";
            for (int j = 0; j < pazymiuKiekis[i]; j++) {
                cout << "[" << j + 1 << "]=" << pazymiai[i][j] << " ";
            }
            cout << "\nKurio pazymio numeri keisti? ";
            int nr;
            cin >> nr;
            if (nr < 1 || nr > pazymiuKiekis[i]) {
                cout << "Neteisingas numeris.\n";
                return;
            }
            cout << "Naujas pazymys: ";
            cin >> pazymiai[i][nr - 1];
            cout << "Pazymys atnaujintas!\n";
            break;
        }
    }

    if (!rastas) cout << "Toks mokinys nerastas.\n";
}

void pasalintiMokini() {
    string vardas;
    cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
    cin >> vardas;

    int indeksas = -1;
    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            indeksas = i;
            break;
        }
    }

    if (indeksas == -1) {
        cout << "Toks mokinys nerastas.\n";
        return;
    }

    for (int i = indeksas; i < mokiniuKiekis - 1; i++) {
        vardai[i] = vardai[i + 1];
        pazymiuKiekis[i] = pazymiuKiekis[i + 1];
        for (int j = 0; j < pazymiuKiekis[i]; j++) {
            pazymiai[i][j] = pazymiai[i + 1][j];
        }
    }

    mokiniuKiekis--;
    cout << "Mokinys pasalintas sekmingai.\n";
}

int main() {
    int pasirinkimas;

    do {
        cout << "\n=== MOKINIU PAZYMIIU SISTEMA ===\n";
        cout << "1. Ivesti nauja mokini\n";
        cout << "2. Rodyti visu mokiniu pazymius\n";
        cout << "3. Rodyti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti darba\n";
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: ivestiDuomenis(); break;
            case 2: rodytiVisus(); break;
            case 3: rodytiKonkretu(); break;
            case 4: atnaujintiPazymi(); break;
            case 5: pasalintiMokini(); break;
            case 0: cout << "Programa baige darba.\n"; break;
            default: cout << "Neteisingas pasirinkimas!\n";
        }
    } while (pasirinkimas != 0);

    return 0;
}
