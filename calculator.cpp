#include "calculator.hpp"
#include <iostream> // For AuditLogger and basic output
#include <vector>
#include <numeric>    // For std::accumulate
#include <cmath>      // For std::abs, std::pow

// Dummy AuditLogger class for demonstration
// This class itself will also be parsed if in the same translation unit or repo.
class AuditLogger {
public:
    AuditLogger(const std::string& context) : context_(context) {
        // Example of call and assignment in constructor
        std::cout << "AuditLogger initialized for: " << context_ << std::endl; // Call (operator<<)
        logCount_ = 0; // Assignment
    }
    ~AuditLogger() {
        std::cout << "AuditLogger for " << context_ << " shutting down. Logs: " << logCount_ << std::endl; // Call
    }
    void logMessage(const std::string& message) {
        std::cout << "[" << context_ << "] LOG: " << message << std::endl; // Call
        logCount_++; // Assignment
    }
private:
    std::string context_; // Assignment in constructor
    int logCount_;    // Assignment
};


namespace MyProject {

// Static member initialization
// Note: The Python script might not specifically track static member initializations
// as "function metrics" unless they are within a function scope.

Calculator::Calculator() : currentValue_(0.0), operationCounter_(0), logger_(nullptr) { // Assignments
    logger_ = new AuditLogger("CalculatorInstance_Default"); // Assignment, Call (new, AuditLogger constructor)
    if (logger_) { // Condition
        logger_->logMessage("Default constructor called."); // Call
    }
}

Calculator::Calculator(double initialValue) : currentValue_(initialValue), operationCounter_(0), logger_(nullptr) { // Assignments
    logger_ = new AuditLogger("CalculatorInstance_InitialValue"); // Assignment, Call
    if (logger_) { // Condition
        logger_->logMessage("Constructor with initial value called."); // Call
    }
}

Calculator::~Calculator() {
    if (logger_) { // Condition
        logger_->logMessage("Destructor called."); // Call
        delete logger_; // Call (delete)
    }
    logger_ = nullptr; // Assignment
}

void Calculator::recordOperation(const std::string& operationName) {
    operationCounter_++; // Assignment
    if (logger_) { // Condition
        std::string logMsg = operationName + " performed. Count: " + std::to_string(operationCounter_); // Calls (operator+, std::to_string), Assignment
        logger_->logMessage(logMsg); // Call
    }
}

void Calculator::add(double value) {
    if (value == 0.0) { // <<< Cond +1
        recordOperation("add_zero_value"); // <<< Call +1
        return; // No change to currentValue_
    }
    currentValue_ += value; // Assign (変更なし)
    recordOperation("add"); // Call (変更なし)
    if (currentValue_ > 10000.0 && value > 0) { // <<< Cond +1 (&&は1つのif_statement)
        if (logger_) logger_->logMessage("Current value exceeded 10000 after addition!"); // <<< Cond +1, Call +1
    }
}

void Calculator::subtract(double value) {
    currentValue_ -= value; // Assignment
    recordOperation("subtract"); // Call
}

double Calculator::multiply(double factor1, double factor2) {
    double result = factor1 * factor2; // Assignment, Call (operator*)
    recordOperation("multiply"); // Call
    if (result == 0.0 && factor1 != 0.0) { // Condition (with &&)
        if (factor2 != 0.0) { // Nested Condition
             recordOperation("Multiplication resulted in zero from non-zeros"); // Call
        }
    }
    return result;
}

double Calculator::divide(double dividend, double divisor) {
    recordOperation("divide_attempt"); // Call
    if (divisor == 0.0) { // Condition
        if (logger_) logger_->logMessage("Error: Division by zero."); // Condition, Call
        throw std::invalid_argument("Division by zero is not allowed."); // Call (throw)
    }
    double result = dividend / divisor; // Assignment, Call (operator/)
    currentValue_ = result; // Assignment
    recordOperation("divide_success"); // Call
    return result;
}

double Calculator::getCurrentValue() const {
    // This function is simple, mainly for testing function detection.
    // Could add a log if needed for testing calls: recordOperation("getCurrentValue");
    return currentValue_;
}

void Calculator::reset() {
    currentValue_ = 0.0; // Assignment
    operationCounter_ = 0; // Assignment
    recordOperation("reset"); // Call
}

bool Calculator::isValuePositive() const {
    // Using an if statement to ensure it's captured by `if_statement` query
    if (currentValue_ > 0.0) { // Condition
        return true;
    } else {
        return false;
    }
    // A ternary version like `return currentValue > 0.0;` might be caught by `conditional_expression`
    // depending on its context, but an `if` is more explicit for the query.
}

long long Calculator::sumUpToN(int n) {
    recordOperation("sumUpToN_v2_simplified"); // Call (文字列変更)
    long long sum = 0LL; // Assign (変更なし)

    if (n < 1) { // Cond (変更なし)
        if (logger_) logger_->logMessage("N is less than 1 for sumUpToN (v2), returning 0."); // Cond, Call (変更なし)
        return 0LL;
    }
    // Simple loop only
    for (int i = 1; i <= n; ++i) { // Cond (for_statement)
        sum += i; // Assign (+=)
    }
    // Removed while, do-while, and switch statements from previous version
    return sum;
}

void Calculator::complexCalculation(int type, const std::vector<double>& data) {
    recordOperation("complexCalculation"); // Call
    if (data.empty()) { // Condition
        if (logger_) logger_->logMessage("No data provided for complex calculation."); // Condition, Call
        currentValue_ = 0.0; // Assignment
        return;
    }

    double tempResult = 0.0; // Assignment
    switch (type) { // Condition
        case 1: // Sum of squares
            for (double val : data) { // Range-based for (internally a loop construct)
                tempResult += val * val; // Assignment, Call (operator*)
            }
            break;
        case 2: // Product
            tempResult = 1.0; // Assignment
            if (!data.empty()) { // Condition
                 for (size_t i = 0; i < data.size(); ++i) { // Condition (for_statement)
                    tempResult *= data[i]; // Assignment
                }
            }
            break;
        case 3: // Average
            if (!data.empty()) { // Condition
                tempResult = std::accumulate(data.begin(), data.end(), 0.0); // Call, Assignment
                tempResult /= data.size(); // Assignment, Call (data.size, operator/)
            } else {
                tempResult = 0.0; // Assignment
            }
            break;
        default:
            if (logger_) logger_->logMessage("Unknown complex calculation type."); // Condition, Call
            throw std::runtime_error("Unknown complex calculation type specified."); // Call (throw)
    }
    currentValue_ = tempResult; // Assignment
    recordOperation("Complex calculation finished"); // Call
}

int Calculator::getVersion() { // Static method
    return 101; // Version 1.0.1
    // No assignments, calls, or conditions counted by typical queries here.
}

// Standalone function implementation
int countSetBits(int n) {
    // Not using logger here to test functions without member access.
    if (n < 0) { // Condition
        // Or handle error, for now, count bits of absolute for simplicity in example
        n = -n; // Assignment
    }
    int bitCount = 0; // Assignment
    while (n > 0) { // Condition (while_statement)
        n &= (n - 1); // Assignment (clears the least significant set bit)
        bitCount++;   // Assignment
    }
    return bitCount;
}

void Calculator::multiplyByTwo() {
    recordOperation("multiplyByTwo"); // Call +1
    this->currentValue_ *= 2;      // Assign +1
    if (this->currentValue_ == 0) { // Cond +1
        recordOperation("multiplyByTwo_resulted_in_zero"); // Call +1
    }
}

} // namespace MyProject

// Example main for standalone testing (optional, can be in a separate file or commented out)
/*
int main() {
    MyProject::Calculator calc(10.0); // Assignment (constructor call)
    calc.add(20.0);                  // Call
    calc.subtract(5.0);                // Call

    if (calc.isValuePositive()) {      // Condition, Call
        std::cout << "Value is positive: " << calc.getCurrentValue() << std::endl; // Call
    }

    long long sumResult = calc.sumUpToN(10); // Assignment, Call
    std::cout << "Sum up to 10: " << sumResult << std::endl; // Call

    try {
        calc.divide(100.0, 0.0); // Call - this will throw
    } catch (const std::invalid_argument& e) { // Catch implies a condition for flow
        std::cerr << "Caught exception: " << e.what() << std::endl; // Call
    }

    std::vector<double> myData = {1.1, 2.2, 3.3}; // Assignment
    calc.complexCalculation(1, myData);       // Call
    std::cout << "Complex calc result: " << calc.getCurrentValue() << std::endl; // Call

    // Test template functions
    int smallerInt = MyProject::findSmaller(10, 20); // Call, Assignment
    std::cout << "Smaller of 10, 20 is " << smallerInt << std::endl; // Call
    double smallerDouble = MyProject::findSmaller(15.5, 10.5); // Call, Assignment
    std::cout << "Smaller of 15.5, 10.5 is " << smallerDouble << std::endl; // Call

    float processed = MyProject::processValues<int, float>(5, 2.0f, 1); // Call, Assignment
    std::cout << "Processed 5, 2.0f (mode 1): " << processed << std::endl; // Call

    std::cout << "Calculator version: " << MyProject::Calculator::getVersion() << std::endl; // Call
    std::cout << "Set bits in 13: " << MyProject::countSetBits(13) << std::endl; // Call

    return 0;
}
*/