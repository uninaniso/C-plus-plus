#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solver {
    map<char, int> variables;

    char findOperation(string& expression) {
        for (char& c : expression) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                return c;
            }
        }
        return ' ';
    }

    int findNumber(string& expression) {
        string numberStr;
        for (char& c : expression) {
            if (isdigit(c)) {
                numberStr += c;
            }
        }
        return stoi(numberStr);
    }

public:
    void inline setVariable(char var, int value) { variables[var] = value; }

    int solveExpression(string expression) {
        int value;

        for (int i = 0; i < expression.length(); i++)
        {
            if (isalpha(expression[i])) {
                int n;
                if (i - 2 != 0)n = expression[i - 1] + expression[i - 2] + expression[i - 3];
                else if (i - 1 != 0)n = expression[i - 1] + expression[i - 2];
                else n = expression[i - 1];

                value = variables[expression[i]] * n;
            }
        }

        char operation = findOperation(expression);
        int number = findNumber(expression);

        switch (operation) {
        case '+':
            value += number;
            break;
        case '-':
            value -= number;
            break;
        case '*':
            value *= number;
            break;
        case '/':
            if (number != 0) {
                value /= number;
            }
            else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
        default:
            cout << "Неизвестная операция: " << operation << endl;
        }

        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Solver solver;
    solver.setVariable('r', 50);  // Задайте значение для 'r'
    solver.setVariable('u', 10);  // Задайте значение для 'u'
    cout << "Результат выражения 100-3r: " << solver.solveExpression("100-3r") << endl;
    cout << "Результат выражения 12/4u: " << solver.solveExpression("12/4u") << endl;
    return 0;
}