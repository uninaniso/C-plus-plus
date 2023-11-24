#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Time {
    string hours;
    string minutes;
    bool madeDelete = true;

public:
    string start(int hours, int minutes) {
        if (madeDelete) {
            if (hours <= 23 && minutes <= 59) {
                this->hours = to_string(hours);
                this->minutes = to_string(minutes);
                if (hours < 10) this->hours = "0" + this->hours;
                if (minutes < 10) this->minutes = "0" + this->minutes;
                madeDelete = false;
                return this->hours + ":" + this->minutes;
            }
            madeDelete = false;
        }
        return this->hours + ":" + this->minutes;
    }

    string Show() {
        return this->hours + ':' + this->minutes;
    }
};

class Month {
    Time time;
    int day;
    string nameMonth;
    bool madeDelete = true;

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

    void start(int day, int hours, int minutes) {
        if (madeDelete) {
            if (day >= 1 && day <= 30) {
                this->day = day;
                time.start(hours, minutes);
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
            nameMonth = "January";
            break;
        }
    }
};

class Year {
    Month m[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int nm;
    int year;

public:
    string Info(int infoMonthDates[12][100], int quantityDates) {
        infoMonthDates[nm - 1][quantityDates] = quantityDates + 1;
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

        int hours;
        cout << "hours:";
        cin >> hours;

        int minutes;
        cout << "minutes:";
        cin >> minutes;

        if (month >= 1 && month <= 12) {
            m[month - 1].start(day, hours, minutes);
            nm = month;
        }
        else {
            m[0].start(1, 0, 0);
            nm = 1;
        }
    }
};

class Book {
    int infoMonthDates[12][100] = {};
    string infoDates[100];
    int quantityDates = 0;

    string GetAllInfo(Year year) {
        return year.Info(infoMonthDates, quantityDates);
    }

public:
    void AddDates() {
        quantityDates++;
        Year year;
        infoDates[quantityDates - 1] = GetAllInfo(year);
    }

    int AllDates() {
        for (int i = 0; i < quantityDates; i++) {
            cout << "date " << i << infoDates[i] << endl;
        }
        return quantityDates;
    }

    void SearchByMonth(int month) {
        for (int i = 0; i < quantityDates; i++) {
            if (infoMonthDates[month - 1][i] != 0) {
                cout << "Month " << month << endl;
                cout << "Date " << infoMonthDates[month - 1][i] << endl;
            }
        }
    }

    string Show(int num) const {
        cout << infoDates[num - 1];
        return infoDates[num - 1];
    }

    Book() {
        Year year;
        infoDates[0] = GetAllInfo(year);
    }
};

int main() {
    Book a;
    int i = 99;
    while (i != 0) {
        cout << "close program - 0, add new date - 1, show date - 2, all date - 3, search by month - 4" << endl;
        cout << "in@user$:";
        cin >> i;

        switch (i) {
        case 1:
            a.AddDates();
            break;
        case 2:
            int ia;
            cout << "number date:";
            cin >> ia;
            a.Show(ia);
            break;
        case 3:
            ia = a.AllDates();
            cout << "all number dates " << ia;
            break;
        case 4:
            int ii = 1;
            cout << "number month:";
            cin >> ii;
            a.SearchByMonth(ii);
            break;
        }

        int p;
        cout << "\npress enter ";
        cin >> p;

        system("cls");
    }
}
