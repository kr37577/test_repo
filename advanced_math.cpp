// advanced_math.cpp
#include <cmath> // For std::pow

// advanced_math.cpp (変更箇所のみ抜粋)
double power(double base, double exp) {
    double result_val; // ★追加: 宣言 (代入を伴わない)
    result_val = std::pow(base, exp); // ★追加: 代入文
    if (result_val > 10000) { // ★追加: 条件式
        result_val = 10000; // ★追加: 条件内の代入文
    }
    return result_val;
}