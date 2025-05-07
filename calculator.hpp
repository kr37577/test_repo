#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>
#include <stdexcept> // For std::invalid_argument
#include <numeric>   // For std::accumulate

// Forward declaration for a helper class
class AuditLogger;

namespace MyProject {

class Calculator {
public:
    // Constructors and Destructor
    Calculator();
    explicit Calculator(double initialValue);
    ~Calculator();

    // Basic operations
    void add(double value);
    void subtract(double value);
    double multiply(double factor1, double factor2);
    double divide(double dividend, double divisor);

    // Utility functions
    double getCurrentValue() const;
    void reset();
    bool isValuePositive() const; // Renamed for clarity
    long long sumUpToN(int n);    // Renamed for clarity
    void complexCalculation(int type, const std::vector<double>& data);

    // Static member function example
    static int getVersion();

private:
    double currentValue_;
    int operationCounter_;
    AuditLogger* logger_; // Example of using another class (pointer)

    // Private helper method
    void recordOperation(const std::string& operationName);
};

// A standalone function in the namespace
int countSetBits(int n);

// A template function
template<typename T>
T findSmaller(T a, T b) {
    // This is a conditional expression that should be caught by the query
    return (a < b) ? a : b;
}

// Another template function with different structure
template<typename T, typename U>
U processValues(T val1, U val2, int mode) {
    U result = val2; // Assignment
    if (mode == 1) { // Condition
        result += static_cast<U>(val1); // Assignment, Call (static_cast)
    } else {
        result *= static_cast<U>(val1); // Assignment, Call (static_cast)
    }
    return result;
}

} // namespace MyProject

#endif // CALCULATOR_HPP