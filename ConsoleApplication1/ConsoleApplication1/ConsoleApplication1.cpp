#include <iostream>
#include <time.h>

using namespace std;

class Animal {
public:
    string name;
    int yearsOld;

    void AnimalSpeak() {
        cout << "\nthis Animal are speak!" << endl;
    }

    Animal() {

    }

    Animal(string name, int yearsOld) {
        this->name = name;
        this->yearsOld = yearsOld;
        cout << "\nname " << name << endl;
        cout << "\years old " << yearsOld << endl;
    }
};


class Dog : public Animal {
public:

    void speak() {
        cout << "gaf-gaf-gaf" << endl;

    }

    Dog(string name, int yearsOld) {
        this->name = name;
        this->yearsOld = yearsOld;
        cout << "\nthis dog" << endl;
        cout << "\nname " << name << endl;
        cout << "\years old " << yearsOld << endl;
        AnimalSpeak();
        speak();
    }
};

class Cat : public Animal {
public:

    void speak() {
        cout << "may" << endl;
    }

    Cat(string name, int yearsOld) {
        this->name = name;
        this->yearsOld = yearsOld;
        cout << "\nthis cat" << endl;
        cout << "\nname " << name << endl;
        cout << "\years old " << yearsOld << endl;
        AnimalSpeak();
        speak();
    }
};

int main()
{
    Animal animal{"Ben", 5};
    Dog dog{"Mike", 3};
    Cat cat{"lee", 8};
}
