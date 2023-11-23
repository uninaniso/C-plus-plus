#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Time {
    string hourse;
    string minets;
    bool madeDelete = true;

public:
    string start(int hourse, int minets) {
        if (madeDelete) {
            if (hourse <= 23 && minets <= 60) {
                this->hourse = to_string(hourse);
                this->minets = to_string(minets);
                if (hourse < 10) this->hourse = "0" + this->hourse;
                if (minets < 10) this->minets = "0" + this->minets;
                madeDelete = false;
                return this->hourse + ":" + this->minets;
            }
            madeDelete = false;
        }
        return "";
    }

    string Show() {
        return this->hourse + ':' + this->minets;
    }
};

class Month {
    Time time;
    int day;
    string nameMonth;
    bool madeDelete;

public:

    int DayInfo() {
        return day;
    }

    string NameMonth() {
        return nameMonth;
    }

    string ShowTime() {
        return time.Show();
    }

    void start(int day, int hourse, int minets) {
        if (madeDelete) {
            if (day >= 1 && day <= 30) {
                this->day = day;
                time.start(hourse, minets);
            }
        }
        madeDelete = false;
    }

    Month(int month) {
        switch (month) {
        case 2:
            nameMonth = "February";
            break;

        case 3:
            nameMonth = "March";
            break;

        case 4:
            nameMonth = "April";
            break;

        case 5:
            nameMonth = "May";
            break;

        case 6:
            nameMonth = "June";
            break;

        case 7:
            nameMonth = "July";
            break;

        case 8:
            nameMonth = "August";
            break;

        case 9:
            nameMonth = "September";
            break;
        case 10:
            nameMonth = "October";
            break;

        case 11:
            nameMonth = "November";
            break;

        case 12:
            nameMonth = "December";
            break;

        default:
            nameMonth = "Jenuary";
            break;
        }
    }
};

class Year {
    Month m[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int nm;
    int year;

public:
    string Info() {
        //cout << "1. " << m[nm - 1].DayInfo() << '.' << nm << "." << year << endl;
        //cout << "2. day " << m[nm - 1].DayInfo() << " month " << m[nm - 1].NameMonth() << " year " << year << endl;

        //cout << m[nm - 1].ShowTime();

        return to_string(m[nm - 1].DayInfo()) + '.' + to_string(nm) + '.' + to_string(year) + '\n' + m[nm - 1].ShowTime();
    }

    Year() {
        cout << "year:";
        cin >> this->year;

        int month;
        cout << "month:";
        cin >> month;

        int day;
        cout << "day:";
        cin >> day;

        int hourse;
        cout << "hourse:";
        cin >> hourse;

        int minets;
        cout << "minets:";
        cin >> minets;

        if (month >= 1 && month <= 12) {
            m[month - 1].start(day, hourse, minets);
            nm = month;
        }
        else {
            m[0].start(1, 0, 0);
            nm = 1;
        }
    }
};

class Book {
    string infoDates[100];
    int quantityDates = 0;

    string GetAllInfo(Year year) {
        return year.Info();
    }

public:

    void AddDates() {
        quantityDates++;
        Year year;
        infoDates[quantityDates] = GetAllInfo(year);
    }

    int AllDates() {
        for (int i = 0; i < quantityDates; i++) {
            cout << "date " << i << infoDates[i] << endl;
        }
        return quantityDates + 1;
    }

    string Show(int num) const {
        cout << infoDates[num];
        return infoDates[num];
    }

    Book() {
        Year year;
        infoDates[0] = GetAllInfo(year);
    }
};

int main() {
    Book a;
    int i = 1;
    while (i != 0) {
        cout << "close program - 0, add new date - 1, show date - 2, all date - 3" << endl;
        cout << "in@user:";
        cin >> i;

        switch (i) {
        case 1:
            a.AddDates();
            break;
        case 2:
            int ia;
            cout << "number date:";
            cin >> ia;
            a.Show(ia + 1);
            Sleep(5000);
            break;
        case 3:
            ia = a.AllDates();
            cout << "all number dates " << ia;
            Sleep(5000);
            break;
        }
        system("cls");
    }
}
