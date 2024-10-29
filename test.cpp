#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Operation
{
public:
    virtual double calculate(double a, double b) const = 0; 
    virtual ~Operation() {}
};

class Add : public Operation
{
public:
    double calculate(double a, double b) const override
    {
        return a + b;
    }
};

class Subtract : public Operation
{
public:
    double calculate(double a, double b) const override
    {
        return a - b;
    }
};

class Multiply : public Operation
{
public:
    double calculate(double a, double b) const override
    {
        return a * b;
    }
};

class Divide : public Operation
{
public:
    double calculate(double a, double b) const override {
        if (b == 0) {
            throw runtime_error("Error: Division by zero!");
        }
        return a / b;
    }
};

class Calculator
{
private:
    static int totalCalculations;

public:
    Calculator() { totalCalculations++; }

    ~Calculator() { cout << "Calculator object is being destroyed. Total Calculations: " << totalCalculations << endl; }

    static int getTotalCalculations() { return totalCalculations; }

    double calculate(Operation* operation, double num1, double num2) const
    {
        return operation->calculate(num1, num2);
    }
};

int Calculator::totalCalculations = 0;

int main()
{
    const int MAX_CALCULATIONS = 10;
    Calculator *calculations[MAX_CALCULATIONS];
    int count = 0;

    while (count < MAX_CALCULATIONS)
    {
        string expression;
        cout << "Enter an expression (or type '/' to stop): ";
        getline(cin, expression);

        if (expression == "/")
        {
            break;
        }

        char operation;
        double num1, num2;
        stringstream ss(expression);
        ss >> num1 >> operation >> num2;

        Operation* op = nullptr;
        switch (operation)
        {
            case '+': op = new Add(); break;
            case '-': op = new Subtract(); break;
            case '*': op = new Multiply(); break;
            case '/': op = new Divide(); break;
            default: cout << "Invalid operation!" << endl; continue;
        }

        Calculator *calc = new Calculator();
        calculations[count] = calc;
        count++;

        if (op != nullptr)
        {
            double result = calc->calculate(op, num1, num2);
            cout << "THE RESULT IS " << fixed << setprecision(2) << result << endl;
            delete op;
        }
    }

    cout << "TOTAL CALCULATIONS PERFORMED: " << Calculator::getTotalCalculations() << endl;



    return 0;
}
