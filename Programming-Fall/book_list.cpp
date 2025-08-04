#include <iostream>
#include <cstdio>

using namespace std;

struct Book {
    int bookID;
    char title[100];
    char author[100];
    char genre[50];
};

Book bookObj;
FILE *file;

int choice;

void book_write() {
    cout << "Book ID: ";
    cin >> bookObj.bookID;

    cout << "Title: ";
    cin >> bookObj.title;

    cout << "Author: ";
    cin >> bookObj.author;

    cout << "Genre: ";
    cin >> bookObj.genre;

    fseek(file, sizeof(Book) * (bookObj.bookID - 1), SEEK_SET);
    fwrite(&bookObj, sizeof(Book), 1, file);
}

void book_search() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    fseek(file, sizeof(Book) * (id - 1), SEEK_SET);
    fread(&bookObj, sizeof(Book), 1, file);

    if (bookObj.bookID) {
        cout << "Book ID: " << bookObj.bookID << endl;
        cout << "Title: " << bookObj.title << endl;
        cout << "Author: " << bookObj.author << endl;
        cout << "Genre: " << bookObj.genre << endl << endl;
    } else {
        cout << "Book not found." << endl << endl;
    }
}

void book_list() {
    int i, number_of_books;
    fseek(file, 0, SEEK_END);
    number_of_books = ftell(file) / sizeof(Book);

    for (i = 1; i <= number_of_books; i++) {
        fseek(file, sizeof(Book) * (i - 1), SEEK_SET);
        fread(&bookObj, sizeof(Book), 1, file);

        if (bookObj.bookID) {
            cout << "Book ID: " << bookObj.bookID << endl;
            cout << "Title: " << bookObj.title << endl;
            cout << "Author: " << bookObj.author << endl;
            cout << "Genre: " << bookObj.genre << endl << endl;
        }
    }
}

int main() {
    file = fopen("books.dat", "r+b");

    if (!file) {
        file = fopen("books.dat", "w+b");
        fclose(file);
        file = fopen("books.dat", "r+b");
    }

    do {
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. List Books\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book_write();
                break;
            case 2:
                book_search();
                break;
            case 3:
                book_list();
                break;
        }
    } while (choice != 4);

    fclose(file);

    return 0;
}

