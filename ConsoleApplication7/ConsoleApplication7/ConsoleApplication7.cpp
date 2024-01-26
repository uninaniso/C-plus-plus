#include <iostream>
<<<<<<< Updated upstream
#include <vector>
#include <string>
#include <thread>

using namespace std;

class ExpressionSolver {
    vector<int> num;
    vector<char> nameNum;
    string letterSymbol;
    string letter = "";
    string symbol = "";

    void find(vector<char>& info, int q, string& mathInfo) {
        for (int i = 0; i < mathInfo.size(); i++) {
            for (int p = 0; p < info.size(); p++) {
                if (mathInfo[i] == info[p]) {
                    if (q == 1) {
                        this->letter += info[p];
                    }
                    else {
                        this->symbol += info[p];
                    }
                }
            }
        }
    }

public:
    void Math() {
        string letter = "abcdefghij";
        string symbol = "-+/*(";

        bool scope = false;
        char afr = '\0';

        // Определение используемых переменных в выражении
        vector<char> usedVariables;
        cout << "Введите математическое выражение: ";
        string mathInfo;
        getline(cin, mathInfo);

        for (char var : letter) {
            if (mathInfo.find(var) != string::npos) {
                usedVariables.push_back(var);
            }
        }

        // Ввод значений только для используемых переменных
        vector<int> values;
        for (char var : usedVariables) {
            int value;
            cout << "Введите " << var << ": ";
            cin >> value;
            values.push_back(value);
        }

        // Очистим буфер ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        thread findSymbol(&ExpressionSolver::find, this, ref(usedVariables), 1, ref(mathInfo));

        findSymbol.join();

        if (this->letter.empty()) {
            cout << "Ошибка: недостаточно данных для вычисления." << endl;
            return;
        }

        thread inputNum([&]() {
            int num = 1;
            for (int i = 0; i < this->letter.size(); i++) {
                this->nameNum.push_back(this->letter[i]);

                cout << "Введите " << this->letter[i] << ": ";
                cin >> num;
                this->num.push_back(num);
            }
            });

        this->letterSymbol = this->letter + this->symbol;

        thread findScope([&]() {
            for (char var : this->symbol) {
                if (var == '(') {
                    scope = true;
                    break;
                }
            }
            });

        for (int i = 0; i < this->symbol.size(); i++) {
            if (this->symbol[i] == '-') {
                afr = '-';
                break;
            }
            else if (this->symbol[i] == '+') {
                afr = '+';
                break;
            }
            else if (this->symbol[i] == '/') {
                afr = '/';
                break;
            }
            else if (this->symbol[i] == '*') {
                afr = '*';
                break;
            }
        }
        findScope.join();
        inputNum.join();

        // Обработка введенного математического выражения
        if (!this->num.empty()) {
            int result = 0;

            for (int i = 0; i < this->num.size(); i++) {
                result += values[i] * this->num[i];
            }

            cout << "Результат: " << result << endl;
        }
        else {
            cout << "Ошибка: недостаточно данных для вычисления." << endl;
        }
=======
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

        return value;

>>>>>>> Stashed changes
    }
};

int main() {
<<<<<<< Updated upstream
    setlocale(LC_ALL, "Russian");

    ExpressionSolver solver;
    solver.Math();

=======
    Solver solver;
    solver.setVariable('r', 50);  // Задайте значение для 'r'
    solver.setVariable('u', 10);  // Задайте значение для 'u'
    cout << "Результат выражения 100-3r: " << solver.solveExpression("100-3r") << endl;
    cout << "Результат выражения 12/4u: " << solver.solveExpression("12/4u") << endl;
>>>>>>> Stashed changes
    return 0;
}
