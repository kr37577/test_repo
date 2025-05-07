// calculator.cpp
#include "calculator.hpp"
#include <iostream> // For std::cout in multiply (example change)

// calculator.cpp (変更箇所のみ抜粋)
int Calculator::add(int a, int b) {
    int sum = a + b;
    // ★追加: 同じクラスの別メソッドを呼び出す
    if (sum > 10) { // ★追加: 条件式 (呼び出しの条件)
         multiply(sum, 2); // メソッド呼び出し
    }
    return sum;
}

// subtract function is now removed

int Calculator::multiply(int a, int b) {
    std::cout << "Multiplying " << a << " and " << b << std::endl; // Added a line
    return a * b;
}

