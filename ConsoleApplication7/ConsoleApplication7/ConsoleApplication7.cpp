#include <iostream>
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
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    ExpressionSolver solver;
    solver.Math();

    return 0;
}
