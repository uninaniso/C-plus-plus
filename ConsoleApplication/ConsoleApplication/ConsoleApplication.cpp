#include <iostream>

using namespace std;

class Figure {
public:
	string name;
	int square;
	int lineThinkness;
	string lineColor;
	string follColor;
};

class Rectangle : public Figure {
public:
	int height1;//on the up
	int height2;//on the down
	int width1;//on the left
	int width2;//on the right


	Rectangle(int height1, int height2, int width1, int width2) {
		this->height1 = height1;
		this->height2 = height2;
		this->width1 = width1;
		this->width2 = width2;


	}
};

int main()
{
	Rectangle name{ 80,80,80,80 };
}