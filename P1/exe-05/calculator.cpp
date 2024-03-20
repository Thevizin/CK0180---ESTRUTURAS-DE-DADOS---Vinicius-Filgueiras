#include <iostream>
#include <cstring>
using namespace std;

struct Calculator {
    double numbers[100];
    char operators[100];
    int quantityChar, quantityDouble;
};

void start(Calculator &c) {
    c.quantityChar = c.quantityDouble = 0;
}

bool empty(Calculator &c) {
    return (c.quantityDouble == 0);
}

double getLastDouble(Calculator &c) {
    c.quantityDouble--;
    return c.numbers[c.quantityDouble];
}

char getLastExp(Calculator &c) {
    c.quantityChar--;
    return c.operators[c.quantityChar];
}

void toStackDouble(Calculator &c, double n) {
    c.numbers[c.quantityDouble] = n;
    c.quantityDouble++;
}

void toStackChar(Calculator &c, char g) {
    c.operators[c.quantityChar] = g;
    c.quantityChar++;
}

double calculate(double n1, char ex, double n2) {
    switch (ex) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 != 0) {
                return n1 / n2;
            } else {
                return -99999; 
            }
        default:
            return -99999;
    }
}

double realize(Calculator &c, char *cIn) {
    int size = strlen(cIn);
    double num = 0;
    for (int i = 0; i < size; i++){
        if(isdigit(cIn[i])){
            num = num * 10 + (cIn[i] - '0');
        }
        else if(cIn[i] == '+' || cIn[i] == '-' || cIn[i] == '*' || cIn[i] == '/'){
            toStackDouble(c,num);
            num = 0;
            toStackChar(c,cIn[i]);
        }
        else if(cIn[i] == ')'){
            double n2 = num;
            double n1 = getLastDouble(c);
            char x = getLastExp(c);
            num = calculate(n1,x,n2);
            cout << num << endl;
        }
    }
    return num;
}

int main() {
    Calculator c;
    start(c);

    char expression[] = "(((2+3)*4)-(5/2))";
    double result = realize(c, expression);
    cout << "Result: " << result << endl;

    return 0;
}
