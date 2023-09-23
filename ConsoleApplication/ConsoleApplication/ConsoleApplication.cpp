#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

class BankAccount {

private:
    int balance;
    int secretCode;
    string owner;
    int uniqueCode[4];
    string id = "";

public:

    void Deposit(int input) {
        balance += input;
        cout << "\nowner " << owner << endl;
        cout << "\nyour balance update" << endl;
        cout << "number card:" << uniqueCode[0] << " " << uniqueCode[1] << " " 
            << uniqueCode[2] << " " << uniqueCode[3] << endl;
        cout << "balance:" << balance << endl;
    }

    string getid() {
        return id;
    }

    int startWithdraw() {
        int operationTRUE;
        cout << "\nDo you want withdraw from card by number " << uniqueCode[0] << " " << uniqueCode[1] << " " 
            << uniqueCode[2] << " " << uniqueCode[3] << ", right?" << endl;
        cout << "(yes or no)input:";
        string yesNo;
        cin >> yesNo;
        if (yesNo == "yes") {
            operationTRUE = Withdraw("yes");
        }
        return operationTRUE;
    }

    int Withdraw(string input) {
        if (input == "yes") {
            
            cout << "okey, input secret code for your card" << endl;
            int inputSC;
            cout << "Code ";
            cin >> inputSC;
            if (inputSC == secretCode) {
                cout << "\ngood, how much do you want to withdraw" << endl;
                inputSC = -999;
                cout << "input withdraw:";
                cin >> inputSC;

                if (inputSC > 0 && inputSC < balance % 70) {
                    balance -= inputSC;
                }

                else while (inputSC < 0 || inputSC != -223) {
                    cout << "\nerror your code is wrong or less than 100" << endl;
                    cout << "input withdraw or -223 to exit:";
                    cin >> inputSC;
                }

                if (inputSC > 0 && inputSC < balance % 70) {
                    balance -= inputSC;
                }
            }

            else while (inputSC != secretCode || inputSC != -223) {
                cout << "input withdraw or -223 to exit:";
                cin >> inputSC;
            }

            if (inputSC == secretCode) {
                cout << "\ngood, how much do you want to withdraw" << endl;
                inputSC = -999;
                cout << "input withdraw:";
                cin >> inputSC;

                if (inputSC > 0 && inputSC < balance % 30) {
                    balance -= inputSC;
                }

                else while (inputSC < 0 || inputSC != -223) {
                    cout << "\nerror your code is wrong or less than 100" << endl;
                    cout << "input withdraw or -223 to exit:";
                    cin >> inputSC;
                }

                if (inputSC > 0 && inputSC < balance % 70) {
                    int i = inputSC;
                    balance -= i;
                    return inputSC;
                }
            }

            cout << "\nowner " << owner << endl;
            cout << "\nyour balance update" << endl;
            cout << "number card:" << uniqueCode[0] << " " << uniqueCode[1] << " "
                << uniqueCode[2] << " " << uniqueCode[3] << endl;
            cout << "balance:" << balance << endl;
        }
    }

    void GetBalance() {
        cout << "\nblance " << balance;
    }

    void DisplayInfo() {
        cout << "\nowner " << owner << endl;
        cout << "\ID " << id << endl;
        cout << "\nyour balance update" << endl;
        cout << "number card:" << uniqueCode[0] << " " << uniqueCode[1] << " "
            << uniqueCode[2] << " " << uniqueCode[3] << endl;
        cout << "balance:" << balance << endl;
    }

    BankAccount() {
        owner = "Bob";
        uniqueCode[0] = rand() % 9999;
        uniqueCode[1] = rand() % 9999;
        uniqueCode[2] = rand() % 9999;
        uniqueCode[3] = rand() % 9999;
        balance = rand() % 100000;
        secretCode = rand() % 999;

        int startid = rand() % 9999;
        
        if (startid < 1000) {
            while(startid > 1000)startid = rand() % 9999;
        }
        id = to_string(startid);

        while (secretCode < 100)secretCode = rand() % 999;
    }
};

class Bank {
public:
    string name = "no name";
    BankAccount Account[2];
};

void main()
{
    string installed[2];
    cout << "install bank ORE or BMPNE" << "(install BMPNE/ORE or install BMPNE ORE and to play program open ORE/BMPNE)\ncommand line:";
    string* inputLine = new string;
    
    getline(cin, *inputLine);
    while (true) {

        if (*inputLine == "install ORE" && installed[0] != "ORE") {
            int* i = new int;
            *i = 0;
            string* load = new string;
            *load = "";

            while (*i < 100) {
                cout << "instalation ORE\n";
                cout << *i << "% " << *load;
                *load += '=';
                *i += 1;
                Sleep(100);
                system("cls");
            }

            installed[0] = "ORE";
            cout << "ORE installed\n";
            cout << *i << "% " << *load << endl;

            delete i;
        }

        else if (*inputLine == "install ORE BMPNE" || *inputLine == "install BMPNE ORE") {
            if (installed[0] == "ORE" || installed[1] == "BMPNE")break;
            int* i = new int;
            *i = 0;
            string* load = new string;
            *load = "";

            while (*i < 100) {
                cout << "instalation ORE\n";
                cout << *i << "% " << *load;
                *load += '=';
                *i += 1;
                Sleep(100);
                system("cls");
            }
            installed[0] = "ORE";
            cout << "ORE installed\n";
            cout << *i << "% " << *load << endl;

            *load = "";
            *i = 0;

            while (*i < 100) {
                cout << "instalation BMPNE\n";
                cout << *i << "% " << *load;
                *load += '=';
                *i += 1;
                Sleep(100);
                system("cls");
            }
            installed[1] = "BMPNE";
            cout << "BMPNE installed\n";
            cout << *i << "% " << *load << endl;

            delete i;
        }

        else if (*inputLine == "install BMPNE" && installed[1] != "BMPNE") {
            int* i = new int;
            *i = 0;
            string* load = new string;
            *load = "";

            while (*i < 100) {
                cout << "instalation BMPNE\n";
                cout << *i << "% " << *load;
                *load += '=';
                *i += 1;
                Sleep(100);
                system("cls");
            }
            installed[1] = "BMPNE";
            cout << "BMPNE installed\n";
            cout << *i << "% " << *load << endl;

            delete i;
        }
        if (*inputLine != "open BMPNE" || *inputLine != "open ORE") {
            if (installed[0] == "ORE" || installed[1] == "BMPNE") {
                *inputLine = "";
                cout << "\ncommand line:";
                getline(cin, *inputLine);
                if (*inputLine == "open ORE" && installed[0] == "ORE" || *inputLine == "open BMPNE" && installed[1] == "BMPNE")break;
            }
        }

    }

    Bank ORE = { "ORE" };
    Bank BMPNE = { "BMPNE" };
    int DefaultAccount[2] = { 0,0 };

    while (true) {

        if (*inputLine != "open ORE" || *inputLine != "open BMPNE") {
            *inputLine = "";
            cout << "\ncommand line:";
            getline(cin, *inputLine);
        }

        if (*inputLine == "open BMPNE" && installed[1] == "BMPNE") {

            while (true) {
        

                system("cls");
                cout << "  ____   __  __ _____ _   _ ______ _ \n";
                cout << " |  _ \\|  \\/  |  __ \\ \\ | |  ____| |\n";
                cout << " | |_) | \\  / | |__) |\\| | |__  | |\n";
                cout << " |  _ <| |\\/| |  ___/  ` |  __| | |\n";
                cout << " | |_) | |  | | |   | |\\  | |____|_|\n";
                cout << " |____/|_|  |_|_|   |_| \\_|______(_)\n";
                cout << "----------------------------------------------------------------------\n";
                cout << "\n exit - e, change defualt Account - da 1-2, Deposit - d, Withdraw - w\nGetBalance - gb, DisplayInfo - di\n";


                *inputLine = "";
                cout << "command line BMPNE:";
                getline(cin, *inputLine);

                if (*inputLine == "e") {
                    *inputLine == "";
                    break;
                }
                else if (*inputLine == "da 2")DefaultAccount[1] = 1;
                else if (*inputLine == "da 1")DefaultAccount[1] = 0;
                else if (*inputLine == "d") {
                    cout << "\nhow much to put:";
                    int giveDeposit = 0;
                    cin >> giveDeposit;
                    BMPNE.Account[DefaultAccount[1]].Deposit(giveDeposit), Sleep(10000);
                }
                else if (*inputLine == "w") {
                    int timeWithdraw;
                    timeWithdraw = BMPNE.Account[DefaultAccount[1]].startWithdraw();
                    cout << "\nwhere to withdraw?\nAccount id:";
                    string i = "";
                    cin >> i;

                    string getid = BMPNE.Account[DefaultAccount[1]].getid();
                    if (DefaultAccount[1] == 0) {
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw);
                        }
                    }

                    else if (DefaultAccount[1] != 0) {
                        DefaultAccount[1] = 0;
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw);
                            DefaultAccount[1] = 1;
                        }
                    }
                    //----------------------------------------------------------------
                    else if (DefaultAccount[1] == 1) {
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw);
                        }
                    }

                    else if (DefaultAccount[1] != 1) {
                        DefaultAccount[1] = 1;
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw);
                            DefaultAccount[1] = 0;
                        }
                    }


                    //LL----------------------------XXXX--------------------------------------LL

                    else if (DefaultAccount[0] == 0) {
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw % 98);
                        }
                    }

                    else if (DefaultAccount[0] != 0) {
                        DefaultAccount[0] = 0;
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw % 98);
                            DefaultAccount[0] = 1;
                        }
                    }
                    //----------------------------------------------------------------
                    else if (DefaultAccount[0] == 1) {
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw % 98);
                        }
                    }

                    else if (DefaultAccount[0] != 1) {
                        DefaultAccount[0] = 1;
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw % 98);
                            DefaultAccount[0] = 0;
                        }
                    }
                    Sleep(10000);
                }
                else if (*inputLine == "gb")BMPNE.Account[DefaultAccount[1]].GetBalance(), Sleep(10000);
                else if (*inputLine == "di")BMPNE.Account[DefaultAccount[1]].DisplayInfo(), Sleep(10000);
            }
        }

        else if (*inputLine == "open ORE" && installed[0] == "ORE") {

            while (true) {
                system("cls");
                cout << "  ____  _____ ______ \n";
                cout << " / __ \\|  __ \\  ____|\n";
                cout << "| |  | | |__) | |__   \n";
                cout << "| |  | |  _  /|  __|  \n";
                cout << "| |__| | | \\ \\| |____ \n";
                cout << " \\____/|_|  \\_\\______|\n";
                cout << "----------------------------------------------------------------------\n";
                cout << "\n exit - e, change defualt Account - da, Deposit - d, Withdraw - w\nGetBalance - gb, DisplayInfo - di\n";


                *inputLine = "";
                cout << "command line ORE:";
                getline(cin, *inputLine);

                if (*inputLine == "e") {
                    *inputLine == "";
                    break;
                }
                else if (*inputLine == "da 2")DefaultAccount[0] = 1;
                else if (*inputLine == "da 1")DefaultAccount[0] = 0;
                else if (*inputLine == "d") {
                    cout << "\nhow much to put:";
                    int giveDeposit = 0;
                    cin >> giveDeposit;
                    ORE.Account[DefaultAccount[0]].Deposit(giveDeposit), Sleep(10000);
                }
                else if (*inputLine == "w") {
                    int timeWithdraw;
                    timeWithdraw = ORE.Account[DefaultAccount[0]].startWithdraw();
                    cout << "\nwhere to withdraw?\nAccount id:";
                    string i = "";
                    cin >> i;

                    string getid = ORE.Account[DefaultAccount[0]].getid();
                    if (DefaultAccount[0] == 0) {
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw);
                        }
                    }

                    else if (DefaultAccount[0] != 0) {
                        DefaultAccount[0] = 0;
                        if (getid == i) {
                            ORE.Account[DefaultAccount[1]].Deposit(timeWithdraw);
                            DefaultAccount[0] = 1;
                        }
                    }
                    //----------------------------------------------------------------
                    else if (DefaultAccount[0] == 1) {
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw);
                        }
                    }

                    else if (DefaultAccount[0] != 1) {
                        DefaultAccount[0] = 1;
                        if (getid == i) {
                            ORE.Account[DefaultAccount[0]].Deposit(timeWithdraw);
                            DefaultAccount[0] = 0;
                        }
                    }


                    //LL----------------------------XXXX--------------------------------------LL

                    else if (DefaultAccount[1] == 0) {
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw % 98);
                        }
                    }

                    else if (DefaultAccount[1] != 0) {
                        DefaultAccount[1] = 0;
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw % 98);
                            DefaultAccount[1] = 1;
                        }
                    }
                    //----------------------------------------------------------------
                    else if (DefaultAccount[1] == 1) {
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw % 98);
                        }
                    }

                    else if (DefaultAccount[1] != 1) {
                        DefaultAccount[1] = 1;
                        if (getid == i) {
                            BMPNE.Account[DefaultAccount[1]].Deposit(timeWithdraw % 98);
                            DefaultAccount[1] = 0;
                        }
                    }
                    Sleep(10000);
                }
                else if (*inputLine == "gb")BMPNE.Account[DefaultAccount[1]].GetBalance(), Sleep(10000);
                else if (*inputLine == "di")BMPNE.Account[DefaultAccount[1]].DisplayInfo(), Sleep(10000);
            }
        }
    }
}