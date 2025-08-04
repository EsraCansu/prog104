#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateRandomPassword(int length) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string password;

    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.length()];
    }

    return password;
}

string generateRandomFileName() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string fileName = "passwords_";

    for (int i = 0; i < 5; ++i) {
        fileName += alphabet[rand() % alphabet.length()];
    }

    fileName += ".txt";
    return fileName;
}

int main() {
    srand(time(0));

    int numberOfPasswords = 2;
    int passwordLength = 20;

    for (int i = 0; i < numberOfPasswords; ++i) {
        string password = generateRandomPassword(passwordLength);
        string fileName = generateRandomFileName();

        ofstream outFile(fileName);

        if (outFile.is_open()) {
            outFile << password << endl;
            outFile.close();

            cout << "Password written to file: " << fileName << endl;
        } else {
            cerr << "Unable to open file: " << fileName << endl;
        }
    }

    return 0;
}

