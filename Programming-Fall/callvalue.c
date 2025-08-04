#include <iostream>

// Fonksiyon tan�m�
void squareByValue(int num) {
    num = num * num;
}

int main() {
    int number = 5;

    std::cout << "Before calling squareByValue: " << number << std::endl;

    // Fonksiyon �a�r�s� (call by value)
    squareByValue(number);

    std::cout << "After calling squareByValue: " << number << std::endl;

    return 0;
}

