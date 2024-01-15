#include <iostream>
#include <vector>
#include <mutex>
#include <future>
#include <chrono>
#include <thread>

using namespace std;

class Calculator {
    vector<string> history;
    vector<int> resultHistory;
    vector<float> duration;

    static mutex calcMutex;

    static inline int Plus(const int number1, const int number2) { return number1 + number2; }
    static inline int Minus(const int number1, const int number2) { return number1 - number2; }
    static inline int Division(const int number1, const int number2) { return number1 / number2; }
    static inline int Multiplication(const int number1, const int number2) { return number1 * number2; }
    static inline int Percent(const int number1, const int number2) { return number1 % number2; }

    static void checkLetterOrSpace(string& info) {
        string letterOrSymbol = "qwertyuiop[]|asdfghjkl;'zxcvbnm,.:<>?,{}~!@#$%^&()_^$!`№QWERTYUIOPASDFGHJKLZXCVBNM ";

        for (const char& c : letterOrSymbol) {
            info.erase(remove(info.begin(), info.end(), c), info.end());
        }
    }

    static int decryption(int* number1, int* number2, int* i, const string& info) {
        string str = "";

        while (*i < info.size() && info[*i] != '-' && info[*i] != '+' && info[*i] != '/' && info[*i] != '*' && info[*i] != '%') {
            str += info[*i];
            (*i)++;
        }

        *number1 = stoi(str);

        str = "";

        const int m = *i;

        (*i)++;

        while (*i < info.size()) {
            str += info[*i];
            (*i)++;
        }

        *number2 = stoi(str);

        return m;
    }

public:
    inline string GetTheLatestHistory() const { return history.empty() ? "" : history.back(); }

    inline int GetTheLatestResultHistory() const { return resultHistory.empty() ? 0 : resultHistory.back(); }

    inline float GetTheLatestDuration() const { return duration.empty() ? 0.0f : duration.back(); }

    void AllHistory() {
        for (int i = 0; i < history.size(); i++) {
            cout << "history" << "     " << "result history" << "     " << "duration" << endl;
            cout << history[i] << "     " << resultHistory[i] << "     " << duration[i] << endl;
        }

        this_thread::sleep_for(chrono::seconds(5));
    }

    int Math(const string& mathInfo) {
        auto start_time_point = chrono::steady_clock::now();

        int i = 0;
        int number1, number2;
        checkLetterOrSpace(const_cast<string&>(mathInfo));

        const int m = decryption(&number1, &number2, &i, mathInfo);

        {
            lock_guard<mutex> lock(calcMutex);

            switch (mathInfo[m]) {
            case '-':
                resultHistory.push_back(Minus(number1, number2));
                break;
            case '+':
                resultHistory.push_back(Plus(number1, number2));
                break;
            case '/':
                resultHistory.push_back(Division(number1, number2));
                break;
            case '*':
                resultHistory.push_back(Multiplication(number1, number2));
                break;
            case '%':
                resultHistory.push_back(Percent(number1, number2));
                break;
            default:
                return 0;
            }

            history.push_back(to_string(number1) + mathInfo[m] + to_string(number2) + "=" + to_string(resultHistory.back()));
        }

        auto end_time_point = chrono::steady_clock::now();
        auto d = chrono::duration_cast<chrono::microseconds>(end_time_point - start_time_point);
        duration.push_back(static_cast<float>(d.count()));

        return resultHistory.back();
    }
    
    Calculator(const string& mathInfo) {
        try {
            if (mathInfo.empty()) throw runtime_error("Input data was empty");
            Math(mathInfo);
        }
        catch (const exception&) {}
    }

    Calculator() {}
};

mutex Calculator::calcMutex;


class Display {
    static mutex displayMutex;

    static bool checkNumberAndSymbol(const string& info) {
        const string number = "1234567890";
        const string symbol = "-+/*%";

        bool numbers = any_of(info.begin(), info.end(), [&](char c) {
            return number.find(c) != string::npos;
            });

        bool symbols = any_of(info.begin(), info.end(), [&](char c) {
            return symbol.find(c) != string::npos;
            });

        return numbers && symbols;
    }

public:
    void OutputToTheScreen(string result) {
        lock_guard<mutex> lock(displayMutex);
        system("cls");

        cout << "________________________\n";
        cout << result << endl;
        cout << "_________________________\n";
        cout << "|  7  |  8  |  9  |  /  |\n";
        cout << "|-----------------------|\n";
        cout << "|  4  |  5  |  6  |  *  |\n";
        cout << "|-----------------------|\n";
        cout << "|  1  |  2  |  3  |  -  |\n";
        cout << "|-----------------------|\n";
        cout << "|  0  |  +  |  =  |  C  |\n";
        cout << "-------------------------\n";
    }

    string OutputToTheScreen() {
        lock_guard<mutex> lock(displayMutex);
        system("cls");

        cout << "________________________\n";
        cout << "        HOLD ON         \n";
        cout << "_________________________\n";
        cout << "|  7  |  8  |  9  |  /  |\n";
        cout << "|-----------------------|\n";
        cout << "|  4  |  5  |  6  |  *  |\n";
        cout << "|-----------------------|\n";
        cout << "|  1  |  2  |  3  |  -  |\n";
        cout << "|-----------------------|\n";
        cout << "|  0  |  +  |  =  |  C  |\n";
        cout << "-------------------------\n";

        string input;
        while (!checkNumberAndSymbol(input)) {
            input = "";
            cout << "\ninput ";
            cin >> input;
        }

        return input;
    }
};

mutex Display::displayMutex;

int main() {
    int input;

    Display display = {};
    Calculator calculator = {};

    while (true) {
        system("cls");

        cout << "command ";
        while (!(cin >> input) || (input < 1 || input > 6)) {
            cin.clear();
            cin.ignore(2147483647, '\n');
            cout << "Invalid input. Enter a valid command (1-6): ";
        }

        switch (input) {

        case 1: {
            string result = display.OutputToTheScreen();
            calculator.Math(result);
            display.OutputToTheScreen(result);

            string s;
            cin >> s;
            break;
        }

        case 2:
            calculator.AllHistory();
            break;

        case 3:
            calculator.GetTheLatestHistory();
            break;

        case 4:
            calculator.GetTheLatestResultHistory();
            break;

        }
    }

    return 0;
}
