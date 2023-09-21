#include <iostream>
#include <time.h>


using namespace std;

class Student {

public:
    string name;
    int mathAssessment = rand() % 12;
    int physicsAssessment = rand() % 12;
    


    int sumOfGrade = mathAssessment += physicsAssessment;

    Student() {
        int name = rand() % 5;
        if (name == 1)this->name = "Ivan";
        else if (name == 2)this->name = "Vova";
        else if (name == 3)this->name = "Dmitry";
        else if (name == 4)this->name = "Arthur";
    }
};

void out(Student allStudent, int* ID, bool* outStart = false, int* i) {
    if (outStart) {
        cout << i << "name:" << allStudent.name;
        cout << " :" << allStudent.sumOfGrade << endl;
        cout << "id:" << ID << "\n\n";
    }

    else {
        cout << i << " name:" << allStudent.name;
        cout << " :" << allStudent.sumOfGrade << endl;
        cout << "id:" << ID << "\n\n";
    }
}

class SchoolClass {
private:
    Student allStudent[26];
    int ID[26];


public:
    int i;

    SchoolClass() {

        for (int i = 0; i < 26; i++) {
            ID[i] = rand() % 1000;
            for (int w = 0; w < 26; w++) {
                if (ID[i] == ID[w])ID[i] = rand() % 1000;
            }
        }

        int averageOfsum = 0;
        int maxOfsum = 0;
        string maxName;
        string averageName;

        for (int i = 1; i < 26; i++) {
            if (allStudent[i].sumOfGrade > maxOfsum) {
                averageOfsum = maxOfsum;
                if (i != 0)averageName = allStudent[i - 1].name;
                maxOfsum = allStudent[i].sumOfGrade;
                maxName = allStudent[i].name;
            }
        }
        cout << "Max of sum: " << maxOfsum << endl;
        cout << "Name Student: " << maxName << endl;
        cout << "Average of sum: " << averageOfsum << endl;
        cout << "Name Student: " << averageName << endl;

        cout << "---------------------------------------------------------------------" << endl;



    }
};
int main()
{
    SchoolClass A7;

    return 0;
}