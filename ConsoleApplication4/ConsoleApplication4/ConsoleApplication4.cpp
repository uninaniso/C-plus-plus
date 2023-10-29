#include <iostream>
#include <time.h> 

using namespace std;

class Shape {
    unsigned result;
protected:
    int width;
    int height;

public:
    unsigned getArea() {
        this->result = 0;
        return this->result;
    }

    void Result() {
        cout << "\n" << result << endl;
    }

    Shape() {
        this->width = rand() % 100;
        this->height = rand() % 100;
        getArea();
    }

    Shape(int width, int height) {
        this->width = width;
        this->height = height;
        getArea();
    }
};

class Rectangle : public Shape {
    unsigned result;
public:
    unsigned getArea() {
        this->result = this->width * this->height;
        cout << "\n" << result << endl;
        return this->result;
    }

    Rectangle() {
        this->width = rand() % 100;
        this->height = rand() % 100;
        getArea();
    }

    Rectangle(int width, int height) {
        this->width = width;
        this->height = height;
        getArea();
    }
};

class Triangle : public Shape {
    unsigned result;
public:
    unsigned getArea() {
        this->result = 0.5 * this->width * this->height;
        cout << "\n" << this->result << endl;
        return this->result;
    }

    Triangle() {
        this->width = rand() % 100;
        this->height = rand() % 100;
        getArea();
    }

    Triangle(int width, int height) {
        this->width = width;
        this->height = height;
        getArea();
    }
};

int main()
{
    Shape a;
    a.Result();
    Rectangle r;
    Triangle t;

}