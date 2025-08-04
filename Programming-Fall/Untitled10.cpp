#include <iostream>

// Fonksiyon tan�m�
void squareByReference(int &num) {
    num = num * num;
}

int main() {
    int number = 5;

    std::cout << "Before calling squareByReference: " << number << std::endl;

    // Fonksiyon �a�r�s� (call by reference)
    squareByReference(number);

    std::cout << "After calling squareByReference: " << number << std::endl;

    return 0;
}

