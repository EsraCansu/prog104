#include <iostream>
#include <cstdlib> // for rand and srand functions
#include <ctime>   // for time function

using namespace std;

class Box {
public:
    double length;   // Length of the box
    double width;    // Width of the box
    double height;   // Height of the box
};

int main() {
    Box Box1; // Declaration of Box1 of type Box

    double volume = 0.0; // Variable to store the volume of the box

    // Customization of Box1
    cout << "Enter the length of Box1: ";
    cin >> Box1.length;

    cout << "Enter the width of Box1: ";
    cin >> Box1.width;

    cout << "Enter the height of Box1: ";
    cin >> Box1.height;

    // Volume of Box1
    volume = Box1.length * Box1.width * Box1.height;

    cout << "Volume of Box1: " << volume << endl;

    return 0;
}

