#include <iostream>

// Fonksiyon tan�m�
int squareByValue(int num) {
    num = num * num;
    return num;
}

int main() {
    int number = 5;

    std::cout << "Before calling squareByValue: " << number << std::endl;

    // Fonksiyon �a�r�s� (call by value)
    

	number= squareByValue(number);
    std::cout << "After calling squareByValue: " << number << std::endl;

    return 0;
}

