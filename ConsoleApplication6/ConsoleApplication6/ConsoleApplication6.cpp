#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>


using namespace std;

class Weapon {
protected:
    unsigned short damage;
    unsigned short weight;
    unsigned short numberOfCartridgesInTheClip;
    unsigned short numberOfClips;
    unsigned short accuracy; // 0.1 -> 0.9
    double rateOfFire; // 0.1 -> 0.9

    virtual void setDamage(unsigned short damage) { this->damage = damage; }
    virtual void setWeight(unsigned short weight) { this->weight = weight; }
    virtual void setNumberOfCartridgesInTheClip(unsigned short numberOfCartridgesInTheClip) { this->numberOfCartridgesInTheClip = numberOfCartridgesInTheClip; }
    virtual void setNumberOfClips(unsigned short numberOfClips) { this->numberOfClips = numberOfClips; }
    virtual void setAccuracy(unsigned short accuracy) { this->accuracy = accuracy; }
    virtual void setRateOfFire(unsigned short rateOfFire) { this->rateOfFire = rateOfFire; }

public:
    virtual int getDamage() { return this->damage; }
    virtual int getWeight() { return this->weight; }
    virtual int getNumberOfCartridgesInTheClip() { return this->numberOfCartridgesInTheClip; }
    virtual int getNumberOfClips() { return this->numberOfClips; }
    virtual int getAccuracy() { return this->accuracy; }
    virtual int getRateOfFire() { return this->rateOfFire; }

};

class Empty : public Weapon {
    //Game* gameId = nullptr;

public:
    
    /*void SetOptionWeapon(Game* gameId) {
        if (this->gameId == gameId) {
            string command = "";
            cout << "GameSpace@DefaultPlayr#";
            cin >> command;
            if (command == "setDamage") {
                getDamage();
                cout << "\nset:";
                int i = 1;
                cin >> i;

                setDamage(i);
                command = "";
            }
        }
    }*/

    Empty() {
        setDamage(5);
        setWeight(1);
        setNumberOfCartridgesInTheClip(1);
        setNumberOfClips(-99);
        setAccuracy(100);
        setRateOfFire(3);
    }
};

class Glock : public Weapon {
public:
    Glock() {
        setDamage(10);
        setWeight(8);
        setNumberOfCartridgesInTheClip(10);
        setNumberOfClips(10);
        setAccuracy(70);
        setRateOfFire(1);
    }
};

class AK47 : public Weapon {
public:
    AK47() {
        setDamage(55);
        setWeight(56);
        setNumberOfCartridgesInTheClip(100);
        setNumberOfClips(50);
        setAccuracy(55);
        setRateOfFire(1);
    }
};

class M4A1 : public Weapon {
public:
    M4A1() {
        setDamage(60);
        setWeight(90);
        setNumberOfCartridgesInTheClip(125);
        setNumberOfClips(50);
        setAccuracy(70);
        setRateOfFire(1);
    }
};

class ShotGun : public Weapon {
public:
    ShotGun() {
        setDamage(120);
        setWeight(56);
        setNumberOfCartridgesInTheClip(10);
        setNumberOfClips(10);
        setAccuracy(67);
        setRateOfFire(4);
    }
};

class Character {
protected:
    // unsigned short 0 -> 65535
    unsigned short hp = 100;
    unsigned short speed = 255;
    unsigned short armor = rand() % 150;
    unsigned short stamina = 100;
public:

    int hereIs = 0;

    //void search(Player player) {}
    //void search(Bot bot) {}

    virtual int SetGetHp(unsigned short hp) { this->hp = hp; return this->hp; }
    virtual int SetGetHp() { return this->hp; }
    virtual int SetGetSpeed(unsigned short speed) { this->speed = speed; return this->speed; }
    virtual int SetGetSpeed() { return this->speed; }
    virtual int SetGetArmor(unsigned short armor) { this->armor = armor; return this->armor; }
    virtual int SetGetArmor() { return this->armor; }
    virtual int SetGetStamina(unsigned short stamina) { this->stamina = stamina; return this->stamina; }
    virtual int SetGetStamina() { return this->stamina; }
};

class Bot : public Character {
    static int numBot;
    string name;
    Weapon w;

    bool setWeapon = true;

public:

    void setName(string name) { this->name = name; }
    string getName() { return this->name; }

    void OneStartAutoChoiceWeapon(int i) {
        switch (i) {
        case 0:
            w = Empty();
            break;
        case 1:
            w = Glock();
            break;
        case 2:
            w = AK47();
            break;
        case 3:
            w = M4A1();
            break;
        case 4:
            w = ShotGun();
            break;
        }
    }

    Bot() {
        if (numBot != 0)numBot++;
        else if (numBot == 0)numBot = 1;
        setName("Bot" + to_string(numBot));
    }
};

class Player : public Character {
    string name;
    Weapon w;
    bool setWeapon = true;

public:

    void setName(string name) { this->name = name; }
    string getName() { return this->name; }

    void OneStartAutoChoiceWeapon(int i) {
        switch (i) {
        case 0:
            w = Empty();
            break;
        case 1:
            w = Glock();
            break;
        case 2:
            w = AK47();
            break;
        case 3:
            w = M4A1();
            break;
        case 4:
            w = ShotGun();
            break;
        }
        setWeapon = false;
    }

    Player(string name) { setName(name); }
    Player() { setName("it's me!!!"); }
};

class Game {
    Player gamer;
    Bot bots[49];

    void PrepartionForTheGame() {
        int i = rand() % 4;

        gamer.OneStartAutoChoiceWeapon(i);

        string load = "[                                                                                                    ] %";
        for (int p = 0; p < 49; p++) {
            Sleep(500);
            bots[p].OneStartAutoChoiceWeapon(i);
            load[p+1] = '#';
            system("cls");
            cout << "                      " << load << p + 1 << endl;
            cout << "                                        please wait, we buld weapon for player" << endl;
        }
        system("cls");
    }
public:

    void ProccesGame() {
        string WhereAreI = "surface";
        string command = "";

        gamer.hereIs = 0;

        while (true) {
            system("cls");
            for (int i = 0, int p = 0; i < 49; i++) {
                p = rand() % 2;
                bots[i].hereIs = p;
                Sleep(100);
            }

            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "| | | | | | | | | | | | | | | | | | | | | |GAME| | | | | | | | | | | | | | | | | | | | | |" << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "|  Name" << gamer.getName() << "                                                         |" << endl;
            cout << "|  HP" << gamer.SetGetHp() << " ARMOR" << gamer.SetGetArmor() << "                       |" << endl;
            cout << "|  STAMINA" << gamer.SetGetStamina() << "                                                |" << endl;
            cout << "|                                                                                        |" << endl;
            cout << "|" << WhereAreI << "                                                                                        | " << endl;
            cout << "|                                                                                        |" << endl;
            cout << "|                                                                                        |" << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;

            cout << "z - fire, a + option - Where to" << endl;
            cout << "Where should i go:";
            cin >> command;

            if (command == "z") {
                bool timeOut = true;
                int y = rand() % 49;
                while (timeOut) {
                    if (bots[y].hereIs == gamer.hereIs) {
                        
                    }
                }
            }
        }
    }
};

int main()
{
    Game game;
}