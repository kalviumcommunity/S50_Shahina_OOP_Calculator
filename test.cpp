#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Calculator {
private:
    double num1, num2;

public:
    Calculator(double a = 0, double b = 0){
        this->num1=a;
        this->num2=b;
    }

    double add() {
        return num1 + num2;
    }

    double sub() {
        return num1 - num2;
    }

    double mul() {
        return num1 * num2;
    }

    double div() {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "Error: DIVISION BY ZERO!" << endl;
            return 0;
        }
    }

 
    void Nums(double &a, double &b) const {
        a = num1;
        b = num2;
    }
};

int main() {
    const int MAX_CALCULATIONS = 10; 
    Calculator calculations[MAX_CALCULATIONS];
    int count = 0; 
    while (count < MAX_CALCULATIONS) {
        string expression;
        cout << "Enter an expression (or type '/' to stop): ";
        getline(cin, expression);

        if (expression == "/") {
            break;
        }

        char operation;
        double num1, num2;
        stringstream ss(expression);
        ss >> num1 >> operation >> num2;

      
        Calculator calc(num1, num2);
        calculations[count] = calc; 
        count++;

        double result;
        switch (operation) {
            case '+':
                result = calc.add();
                break;
            case '-':
                result = calc.sub();
                break;
            case '*':
                result = calc.mul();
                break;
            case '/':
                result = calc.div();
                break;
            default:
                cout << "Invalid operation!" << endl;
                continue;
        }

        cout << "THE RESULT IS " << fixed << setprecision(2) << result << endl;
    }

    cout << "NUMBERS CALCULATED BEFORE:" << endl;
    for (int i = 0; i < count; i++) {
        double num1, num2;
        calculations[i].Nums(num1, num2);
        cout << num1 << " and " << num2 << endl;
    }

    return 0;
}