#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Лямбда-функция 1
    auto lambda1 = []() {
        cout << "Лямбда-функция 1" << endl;
        };

    // Лямбда-функция 2
    auto lambda2 = [](int x, int y) {
        return x + y;
        };

    // Лямбда-функция 3
    auto lambda3 = [](const string& s) {
        cout << "Длина строки: " << s.length() << endl;
        };

    // Лямбда-функция 4
    auto lambda4 = [](double a, double b) -> double {
        return a * b;
        };

    // Лямбда-функция 5
    auto lambda5 = [](int n) {
        return n * n;
        };

    // Лямбда-функция 6
    auto lambda6 = [](bool flag) {
        return flag ? "Истина" : "Ложь";
        };

    // Лямбда-функция 7
    auto lambda7 = [](const string& s1, const string& s2) {
        return s1 + s2;
        };

    // Лямбда-функция 8
    auto lambda8 = [](int n) {
        cout << "Квадрат числа: " << n * n << endl;
        };

    // Лямбда-функция 9
    auto lambda9 = [](float f) {
        return f + 1.5f;
        };

    // Лямбда-функция 10
    auto lambda10 = []() {
        cout << "Привет, мир!" << endl;
        };


    lambda1();

    cout << "Сумма: " << lambda2(3, 4) << endl;

    lambda3("Hello, Lambda!");

    cout << "Умножение: " << lambda4(2.5, 3.5) << endl;

    cout << "Квадрат: " << lambda5(7) << endl;

    cout << "Результат: " << lambda6(true) << endl;

    cout << "Сцепление строк: " << lambda7("Hello, ", "Lambda!") << endl;

    lambda8(6);

    cout << "Результат: " << lambda9(3.0f) << endl;

    lambda10();

    return 0;
}
