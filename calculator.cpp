#include <iostream>

// Function 'add' remains, but inner cout is removed
int add(int a, int b) {
    // std::cout << "Adding " << a << " and " << b << std::endl; // NEFC: cout call deleted
    return a + b;
}

// Function 'subtract' is deleted (NEM: 1)
/*
int subtract(int a, int b) {
    return a - b;
}
*/

// New function 'multiply' is added (NMM: 1)
int multiply(int a, int b) {
    std::cout << "Multiplying " << a << " and " << b << std::endl; // NMFC: cout call added
    return a * b;
}

int main() {
    int x = 10;
    int y = 5;
    // int z = 2; // NEV: 1 (variable z deleted)
    int sum = add(x, y);
    // int difference = subtract(x, y); // NEFC: 1 (subtract call deleted), NEV: 1 (variable difference possibly deleted)

    // std::cout << "Sum: " << sum << std::endl; // NEFC: 1 (cout call deleted)
    // std::cout << "Difference: " << difference << std::endl; // NEFC: 1 (cout call deleted)

    // New variable 'product' added (NMV: 1)
    int product = multiply(x, y); // NMFC: 1 (multiply call added)
    std::cout << "Product: " << product << std::endl; // NMFC: 1 (cout call added)

    if (sum > 10) {
        std::cout << "Sum is greater than 10." << std::endl;
        // Inner if statement deleted (NEC: 1)
        /*
        if (difference > 0) { // Added condition
            std::cout << "Difference is positive." << std::endl;
        }
        */
    } else {
        std::cout << "Sum is not greater than 10." << std::endl;
        // New conditional added (NMC: 1)
        if (product > 50) {
            std::cout << "Product is large." << std::endl;
        }
    }
    return 0;
}