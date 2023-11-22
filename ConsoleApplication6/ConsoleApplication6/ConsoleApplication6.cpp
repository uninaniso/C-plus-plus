#include <iostream>
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
                if (hourse < 10)this->hourse = "0" + this->hourse;
                if (minets < 10)this->minets = "0" + this->minets;
                madeDelete = false;
                return this->hourse + ":" + this->minets;
            }
        }
    }


    string Show() {
        if (!madeDelete) {
            return this->hourse + ':' + this->minets;
        }
    }
};

class Month {
    Time time;
    int day;
    string nameMonth;
    bool madeDelete;

public:

    int DayInfo() {
        if (!madeDelete) {
            return day;
        }
    }

    string NameMonth() {
        return nameMonth;
    }

    string ShowTime() {
        if (!madeDelete) {
            return time.Show();
        }
    }

    void start(int day, int hourse, int minets) {
        if (madeDelete) {
            if (day >= 1 || day <= 30) {
                this->day = day;
                time.start(hourse, minets);
            }
        }

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
    Month m[12] = { {1},{2}, {3}, {4}, {5}, {6}, {7}, {8}, {9},{10},{11},{12} };
    int nm;
    int year;
public:
    string Info() {
        cout << "1. " << m[nm].DayInfo() << '.' << nm << "." << year << endl;
        cout << "2. day " << m[nm].DayInfo() << " month " << m[nm].NameMonth() << " year " << year << endl;

        cout << m[nm].ShowTime();

        return m[nm].DayInfo() + '.' + nm + "." + year + '\n' + m[nm].ShowTime();
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


        if (month >= 1 || month <= 12) {
            m[month-1].start(day, hourse, minets);
            nm = month;
        }
        else {
            m[0].start(1, 0, 0);
            nm = 0;
        }
    }
};

class Book {
    string* infoDates[1];
    Year* year[1];
    int quantityDates = 0;

    string GetAllInfo(Year year) {
        return year.Info();
    }

public:

    void AddDates() {
        quantityDates++;
        infoDates[quantityDates] = new string;
        year[quantityDates] = new Year;
        *infoDates[quantityDates] = GetAllInfo(*year[quantityDates]);
    }

    string Show(int num) {
        cout << *infoDates[quantityDates];
        return *infoDates[quantityDates];
    }

    Book() {
        infoDates[0] = new string;
        year[0] = new Year;
        *infoDates[0] = GetAllInfo(*year[0]);
    }
};

int main()
{
    Book a;
    a.AddDates();
    a.Show(1);
}