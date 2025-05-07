#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10;
    int y = 5;
    int sum = add(x, y);
    std::cout << "Sum: " << sum << std::endl;
    if (sum > 10) {
        std::cout << "Sum is greater than 10." << std::endl;
    }
    return 0;
}