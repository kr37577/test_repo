// calculator.cpp
#include "calculator.hpp"
#include <iostream> // For std::cout in multiply (example change)

int Calculator::add(int a, int b) {
    return a + b; // Implementation for addition
}

// subtract function is now removed

int Calculator::multiply(int a, int b) {
    std::cout << "Multiplying " << a << " and " << b << std::endl; // Added a line
    return a * b;
}