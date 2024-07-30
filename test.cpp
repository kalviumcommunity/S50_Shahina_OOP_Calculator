#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Calculator{
    private:
    double num1 ,num2;

    public:
    Calculator(double a, double b){
    this->num1=a;
    this->num2=b;
    }

    void Nums(double &a ,double &b){
        a=num1;
        b=num2;
    }

    double add(){
        return num1 + num2;

    }

      double sub(){
        return num1 - num2;

    }
    
   double mul(){
        return num1 * num2;

    }
    double div(){
        if(num2!=0){
            return num1/num2;
        }
        else{
            cout<<"Error:DIVISION BY ZERO!"<<endl;
            return 0;
        }

    }

};

int main(){
  string expression;
    cout << "ENTER AN EXPRESSION:";
    getline(cin, expression);

    char operation;
    double num1, num2;
    stringstream ss(expression);
    ss >> num1 >> operation >> num2;

    Calculator calc(num1, num2);
    double result;

    switch(operation) {
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
            return 1;
    }

    cout << "THE RESULT IS:" <<fixed<<setprecision(5)<< result << endl;

 
    return 0;
}


