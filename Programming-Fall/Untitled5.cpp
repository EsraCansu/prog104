#include <iostream>
#include <cstring>
using namespace std;

class Card {
public:
    void store();
    void show();

private:
    char kitap_adi[80];
    char yazari[40];
    int adet;
};

void Card::store() {
    cout << "Enter the book name: ";
    cin.getline(kitap_adi, 80);

    cout << "Enter the author name: ";
    cin.getline(yazari, 40);

    cout << "Enter the quantity in stock: ";
    cin >> adet;

    // Bir önceki giriþte kalan '\n' karakterini temizle
    cin.ignore();
}

void Card::show() {
    cout << "Kitap adi: " << kitap_adi << endl;
    cout << "Yazari: " << yazari << endl;
    cout << "Eldeki sayi: " << adet << endl;
    cout << "------------------------" << endl;
}

int main() {
    const int numberOfBooks = 3;
    Card books[numberOfBooks];

    for (int i = 0; i < numberOfBooks; ++i) {
        cout << "Enter information for Book " << i + 1 << ":" << endl;
        books[i].store();
    }

    cout << "Book Information:" << endl;
    for (int i = 0; i < numberOfBooks; ++i) {
        books[i].show();
    }

    return 0;
}

