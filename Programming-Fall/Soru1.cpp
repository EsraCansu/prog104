#include <iostream>
#include <string>

using namespace std;

int str_num_sum(string s) {
    int sum = 0;
    int currentNumber = 0;

    for (char c : s) {
        if (isdigit(c)) {
            // If the current character is a digit, update the currentNumber
            currentNumber = currentNumber * 10 + (c - '0');
        } else {
            // If the current character is not a digit, add the currentNumber to the sum
            sum += currentNumber;
            currentNumber = 0;  // Reset currentNumber for the next potential number
        }
    }

    // Add the last number in case the string ends with a number
    sum += currentNumber;

    return sum;
}

int main() {
    // Example usage:
    string input = "abc12de34hf1";
    int result = str_num_sum(input);

    cout << "Sum of numbers in the string: " << result << endl;

    return 0;
}

