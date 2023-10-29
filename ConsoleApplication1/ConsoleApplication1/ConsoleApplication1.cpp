#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};

class Line : public Point {
public:
    Point p1;
    Point p2;
    double lenght = 0;

    Line() {
        cout << "\nerror" << endl;
    }

    Line(int i) {
        if(i != -2892) cout << "\nerror" << endl;
    }

    Line(Point p1, Point p2, string color, double thickness) {
        this->color = color;
        this->thickness = thickness;
        if (p1.x > p2.x)lenght += p1.x += p1.y -= p2.x += p2.y;
        else lenght = p2.x + p2.y - p1.x + p1.y;
        cout << "lenght:" << lenght << endl;
        cout << "color:" << this->color << endl;
        cout << "thickness:" << this->thickness << endl;
    }
};

class Figur : public Line{
public:
    Line l1{ -2892 };
    Line l2{ -2892 };
    Line l3{ -2892 };
    Line l4{ -2892 };

    Figur(Line l1, Line l2, Line l3) {
        l1.lenght = l1.lenght;
        l2.lenght = l2.lenght;
        l3.lenght = l3.lenght;
        cout << "\nl1: " << l1.lenght << endl;
        cout << "l2: " << l2.lenght << endl;
        cout << "l3: " << l3.lenght << endl;
        cout << "l_1+2+3: " << l1.lenght + l2.lenght + l3.lenght << endl;
        cout << "kut: 3" << endl;
        cout << endl;
    }

    Figur(Line l1, Line l2, Line l3, Line l4) {
        l1.lenght = l1.lenght;
        l2.lenght = l2.lenght;
        l3.lenght = l3.lenght;
        l4.lenght = l4.lenght;
        cout << "\nl1: " << l1.lenght << endl;
        cout << "l2: " << l2.lenght << endl;
        cout << "l3: " << l3.lenght << endl;
        cout << "l4: " << l4.lenght << endl;
        cout << "l_1+2+3=4: " << l1.lenght + l2.lenght + l3.lenght + l4.lenght << endl;
        cout << "kut: 4" << endl;
        cout << endl;
    }
};

int main()
{
    Point point1{10, 20};
    Point point2{30, 40};
    Line line1{ point1, point2, "blue", 5.29};
    Line line2{ point1, point2, "blue", 9.00 };
    Line line3{ point1, point2, "blue", 2.40 };
    Line line4{ point1, point2, "blue", 7.11 };

    Figur figur1{ line1, line2, line3, line4 };


    Point point3{ 40, 80 };
    Point point4{ 20, 32 };
    Line line5{ point3, point4, "dark blue", 80.01 };
    Line line6{ point3, point4, "dark blue", 90.00 };
    Line line7{ point3, point4, "dark blue", 20.40 };

    Figur figur2{ line5, line6, line7 };
}
