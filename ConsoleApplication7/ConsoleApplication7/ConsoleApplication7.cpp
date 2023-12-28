#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
	double x = 0,
		y = 0;

	vector <Point> system = { {0.0,0.0},{10.0,7.0} };

public:

	void createCenter(double point1, double point2) { this->system.push_back({ point1, point2 }); }

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void showCoords() {
		cout << "x: " << this->x << endl;
		cout << "y: " << this->y << "\n" << endl;
	}
	double getX() { return this->x; }
	double getY() { return this->y; }
	double Distance(Point p) {
		double newx = p.getX() - this->x;
		double newY = p.getY() - this->y;
		return sqrt((newx * newx) + (newY * newY));
	}
	double createCenter(Point p) {
		return 0;
	}
};

int main()
{
	Point p = {9,9};
}