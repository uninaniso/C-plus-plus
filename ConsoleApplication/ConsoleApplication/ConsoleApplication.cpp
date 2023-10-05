#include <iostream>

using namespace std;

class Bird {
public:
	string color;
	float weight;
	float height;
};

class HomeParrot : public Bird{
public:
	string name;
	bool isSpeak;
	bool trained;
	void Say(string word) {
		cout << word << endl;
	}

	void info() {
		cout << "name:" << name << endl;
		cout << "trained:" << trained << endl;
		cout << "isSpeak:" << isSpeak << endl;
		cout << "color:" << color << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;

		string speak;
		cout << "speak:";
		cin >> speak;
		Say(speak);
	}

	HomeParrot() {
		name = "Lolo";
		trained = true;
		color = "Grey";
		isSpeak = true;
		weight = 2000;
		height = 0.3;
	}
};

class Owl : public Bird {
public:
	string name;
	bool predator;
	bool trained;
	int visibility;
	bool nightLife;
	Owl() {
		name = "BB";
		predator = true;
		trained = true;
		visibility = 360;
		nightLife = true;
		color = "Grey";
		weight = 2000;
		height = 0.3;
	}

	void info() {
		cout << "predator:" << predator << endl;
		cout << "trained:" << trained << endl;
		cout << "visibility:" << visibility << endl;
		cout << "nightLife:" << nightLife << endl;
		cout << "color:" << color << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
	}
};

class Penguin : public Bird {
public:
	string name;
	bool trained;
	bool predator;
	bool swim;
	bool noFly;
	
	Penguin() {
		name = "Jim";
		trained = true;
		color = "Black";
		weight = 2000;
		height = 0.3;
		swim = true;
		noFly = true;
	}

	void info() {
		cout << "predator:" << predator << endl;
		cout << "trained:" << trained << endl;
		cout << "color:" << color << endl;
		cout << "weight:" << weight << endl;
		cout << "height:" << height << endl;
		cout << "swim:" << swim << endl;
		cout << "noFly:" << noFly << endl;
	}
};



int main() {
	cout << "\nHomeParrot" << endl;
	HomeParrot homeParrot;
	homeParrot.info();

	cout << "\nPenguin" << endl;
	Penguin penguin;
	penguin.info();
	cout << endl;

	cout << "\nOwl" << endl;
	Owl owl;
	owl.info();
	cout << endl;
}