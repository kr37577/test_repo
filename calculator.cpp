#include <iostream>

// Modified function
int add(int a, int b) {
    std::cout << "Adding " << a << " and " << b << std::endl; // Added a call
    return a + b;
}

// New function
int subtract(int a, int b) {
    return a - b;
}

int main() {
    int x = 10;
    int y = 5;
    int z = 2; // Added assignment
    int sum = add(x, y);
    int difference = subtract(x, y); // Added call

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl; // Added call

    if (sum > 10) {
        std::cout << "Sum is greater than 10." << std::endl;
        if (difference > 0) { // Added condition
            std::cout << "Difference is positive." << std::endl;
        }
    } else {
        std::cout << "Sum is not greater than 10." << std::endl;
    }
    return 0;
}