#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Car {
private:
    string engine;
    string model;
    string brand;
    string battery;
    bool electric;
    bool diesel;
    bool petrol;
    bool security;
    int speed;
    int volumeEngine;
    int year;

public:
    void setEngine(string engine) {
        this->engine = engine;
    }

    void setModel(string model) {
        this->model = model;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    void setBattery(string battery) {
        this->battery = battery;
    }

    void setElectric(bool electric) {
        this->electric = electric;
    }

    void setDiesel(bool diesel) {
        this->diesel = diesel;
    }

    void setPetrol(bool petrol) {
        this->petrol = petrol;
    }

    void setSecurity(bool security) {
        this->security = security;
    }

    void setSpeed(int speed) {
        this->speed = speed;
    }

    void setVolumeEngine(int volumeEngine) {
        this->volumeEngine = volumeEngine;
    }

    void setYear(int year) {
        this->year = year;
    }

    void ShowInfo() {
        cout << "\nEngine " << this->engine << endl;
        cout << "Model " << this->model << endl;
        cout << "Brand " << this->brand << endl;
        cout << "Battery " << this->battery << endl;
        cout << "electric " << this->electric << endl;
        cout << "Diesel " << this->diesel << endl;
        cout << "Petrol " << this->petrol << endl;
        cout << "Security " << this->security << endl;
        cout << "Speed " << this->speed << endl;
        cout << "Volume Engine " << this->volumeEngine << endl;
        cout << "Year " << this->year << endl;
    }

    Car() {
        setEngine(to_string(rand()));
        setModel(to_string(rand()));
        setBrand(to_string(rand()));
        setBattery(to_string(rand()));
        setElectric(rand() % 1);
        setDiesel(rand() % 1);
        setPetrol(rand() % 1);
        setSecurity(rand() % 1);
        setSpeed(rand() % 200);
        setVolumeEngine(rand());
        setYear(rand() % 2023);
        ShowInfo();
    }
};

int main()
{
    Car MyCar;
}


