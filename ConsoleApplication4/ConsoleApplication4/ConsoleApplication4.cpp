#include <iostream>
#include <time.h>

using namespace std;

class Subsequence {
    int first;
    int second;
    int result;

public:
    void search(int number) {
        if (this->first == number) {
            this->result = number;
        }

        else if (this->second == number) {
            this->result = number;
        }

        else cout << "\nerror" << endl;
    }

    Subsequence() {
        this->first = rand() % 100;
        this->second = rand() % 100;

        cout << "\nfirst " << this->first;
        cout << "\nsecond " << this->second;

        int number;
        cout << "\nnumber:";
        cin >> number;
        search(number);
        if (this->result != this->first && this->result != this->second)this->result = 0;
        cout << "result " << this->result;
    }
};

int main()
{
    Subsequence s;
}