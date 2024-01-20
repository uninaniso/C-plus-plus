#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

bool KEY[256];

void GetKEY()
{
    int i = 0;
    while (i < 256)
    {
        if (GetAsyncKeyState(i)) {
            KEY[i] = 1;
        }
        else {
            KEY[i] = 0;
        }
        i++;
    }
}

void GameMenu() {
    cout << "                              BBBB   L       A     CCCC  K   K        J  A     CCCC  K   K\n";
    cout << "                              B   B  L      A A   C      K  K        J  A A   C      K  K\n";
    cout << "                              BBBB   L     AAAAA  C      KKK        J  AAAAA  C      KKK\n";
    cout << "                              B   B  L    A     A C      K  K   J   J  A     C      K  K\n";
    cout << "                              BBBB   LLLLL A     A  CCCC  K   K   JJJ  A     A  CCCC  K   K\n\n\n";

    cout << "                                                   -------------------\n";
    cout << "                                                   |    START GAME    |\n";
    cout << "                                                   |   PRESS  -ENTER- |\n";
    cout << "                                                   -------------------\n";

    while (true) {
        GetKEY();
        if (KEY[13])
        {
            cout << "\033[2J\033[1;1H";
            cout << "launch game...";
            Sleep(1000);
            cout << "\033[2J\033[1;1H";
            break;
        }
    }
}

int random(int min, int max) {
    return (rand() % (max - min) + min);
}

string displayCard(int rank) {
    string cardRank = "";

    switch (rank) {
    case 3:
        cardRank = "A";
        break;
    case 2:
        cardRank = "J";
        break;
    case 1:
        cardRank = "Q";
        break;
    case 0:
        cardRank = "K";
        break;
    default:
        cardRank = to_string(rank);
    }

    return cardRank;
}

void GameCard(int numberCard, int* username) {
    // чуть ниже в комментариях названия карт

    switch (numberCard) {
    case 0: // King
        *username += 10;
        break;
    case 1: // Queen
        *username += 12;
        break;
    case 2: // Jack
        *username += 10;
        break;
    case 3: // Ace
        if (*username < 21)
            *username += 11;
        else if (*username >= 21)
            *username += 1;
        break;
    case 4: // 2
        *username += 2;
        break;
    case 5: // 3
        *username += 3;
        break;
    case 6: // 4
        *username += 4;
        break;
    case 7: // 5
        *username += 5;
        break;
    case 8: // 6
        *username += 6;
        break;
    case 9: // 7
        *username += 7;
        break;
    case 10: // 8
        *username += 8;
        break;
    case 11: // 9
        *username += 9;
        break;
    case 12: // 10
        *username += 10;
        break;
    }
}

void DrawScreen(int* mainuser, int* bot1, int* bot2, int* bot3, int* bot4, int* Dil, string* mainuser_display,
    string* Dil_display, string* bot1_display, string* bot2_display, string* bot3_display, string* bot4_display, bool start, int* round, int Money) {
    system("cls");

    char g[] = {218, 191, 179, 192, 196, 217};

    cout << "round:" << *round;
    if (start)cout << "                      Z - взять карту, X - пропустить ход";
    cout << "\nMoney:" << Money << "\n";

    cout << "      Dil              Main User              Bot 1              Bot 2              Bot 3              Bot 4" << "\n";
    cout << "       " << *Dil << "               " << *mainuser << "                       " << *bot1 << "                  " << *bot2 << "                 " << *bot3 << "                 " << *bot4 << "\n\n";

    /*
    if (Dil_display[0] == "K")cout << "       " << g[0] << g[4] << g[4] << g[4] << g[1] << "               ";
    else cout << "                          ";

    if (mainuser_display[0] == "K")cout << "       " << g[0] << g[4] << g[4] << g[4] << g[1] << "               ";
    else cout << "                           ";

    if (bot1_display[0] == "K")cout << "       " << g[0] << g[4] << g[4] << g[4] << g[1] << "               ";
    else cout << "                      ";

    if (bot2_display[0] == "K")cout << "       " << g[0] << g[4] << g[4] << g[4] << g[1] << "               ";
    else cout << "                      ";

    if (bot3_display[0] == "K")cout << "       " << g[0] << g[4] << g[4] << g[4] << g[1] << "               ";
    else cout << "                      ";

    if (bot4_display[0] == "K")cout << g[0] << g[4] << g[4] << g[4] << g[1] << "\n";
    else cout << "     \n";

    if (Dil_display[0] == "K")cout << "       " << g[2] << " K " << g[2] << "               ";
    else cout << "                           ";

    if (mainuser_display[0] == "K")cout << "       " << g[2] << " K " << g[2] << "               ";
    else cout << "                            ";

    if (bot1_display[0] == "K")cout << "       " << g[2] << " K " << g[2] << "               ";
    else cout << "                       ";

    if (bot2_display[0] == "K")cout << "       " << g[2] << " K " << g[2] << "               ";
    else cout << "                      ";

    if (bot3_display[0] == "K")cout << "       " << g[2] << " K " << g[2] << "               ";
    else cout << "                      ";

    if (bot4_display[0] == "K")cout << g[2] << " K " << g[2] << "\n";
    else cout << "     \n";

    if (Dil_display[0] == "K")cout << "       " << g[3] << g[4] << g[4] << g[4] << g[5] << "               ";
    else cout << "                           ";

    if (mainuser_display[0] == "K")cout << "       " << g[3] << g[4] << g[4] << g[4] << g[5] << "               ";
    else cout << "                            ";

    if (bot1_display[0] == "K")cout << "       " << g[3] << g[4] << g[4] << g[4] << g[5] << "               ";
    else cout << "                       ";

    if (bot2_display[0] == "K")cout << "       " << g[3] << g[4] << g[4] << g[4] << g[5] << "               ";
    else cout << "                      ";

    if (bot3_display[0] == "K")cout << "       " << g[3] << g[4] << g[4] << g[4] << g[5] << "               ";
    else cout << "                      ";

    if (bot4_display[0] == "K")cout << g[3] << g[4] << g[4] << g[4] << g[5] << "\n";
    else cout << "     \n\n";*/
}

void TakeCard(int* score)
{
    int randomCard = random(0, 12);
    GameCard(randomCard, score);
}

int ChoseRound() {
    system("cls");
    cout << "                                                   ------------------------------------\n";
    cout << "                                                   |         CHOSE ROUND GAME         |\n";
    cout << "                                                   |   E = 1000 ROUNDS OR Q = 3 ROUND |\n";
    cout << "                                                   ------------------------------------\n";

    while (true) {
        GetKEY();
        if (KEY[69])
        {
            cout << "\033[2J\033[1;1H";
            cout << "launch game...";
            Sleep(1500);
            cout << "\033[2J\033[1;1H";
            return 1000;
        }

        else if (KEY[81])
        {
            cout << "\033[2J\033[1;1H";
            cout << "launch game...";
            Sleep(1500);
            cout << "\033[2J\033[1;1H";
            return 3;
        }
    }
}

void ProccesGame(int* Money, int* XMoney) {
    int randomCard;
    int round;
    int Dil = 0;
    int Mainuser = 0;
    int MaxExp;
    bool nonStop = true;
    int bot1 = 0, bot2 = 0, bot3 = 0, bot4 = 0;
    int X;

    *Money = *Money - *XMoney;

    round = ChoseRound();
    if (round == 1000)X = 5;
    else X = 2;

    if (round == 1000)MaxExp = 500, nonStop = false;
    else if (round == 3)MaxExp = 21;

    string* Mainuser_DisplayCard = new string[4];
    string* Dil_DisplayCard = new string[4];
    string* bot1_DisplayCard = new string[4];
    string* bot2_DisplayCard = new string[4];
    string* bot3_DisplayCard = new string[4];
    string* bot4_DisplayCard = new string[4];



    randomCard = random(0, 12);
    GameCard(randomCard, &Dil);
    Dil_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
    Sleep(500);

    randomCard = random(0, 12);
    GameCard(randomCard, &Mainuser);
    Mainuser_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
    Sleep(500);

    randomCard = random(0, 12);
    GameCard(randomCard, &bot1);
    bot1_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
    Sleep(500);

    randomCard = random(0, 12);
    GameCard(randomCard, &bot2);
    bot2_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
    Sleep(500);

    randomCard = random(0, 12);
    GameCard(randomCard, &bot3);
    bot3_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);

    Sleep(500);

    randomCard = random(0, 12);
    GameCard(randomCard, &bot4);
    bot4_DisplayCard[randomCard] = displayCard(randomCard);
    DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
        &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
    --round;
    Sleep(500);

    int stop_or_go = 1;

    while (true) {
        if (round <= 0) {
            if(Mainuser <= 21 && Mainuser > Dil)*Money += *XMoney * X;
            break;
        }

        if (Dil > MaxExp && MaxExp == 21) {
            if (Mainuser <= 21)*Money += *XMoney * X;
            break;
        }

        else if (Dil > MaxExp && MaxExp == 500) {
            if (Mainuser <= 500)*Money += *XMoney * X;
            break;
        }

        if (Dil == 21)stop_or_go = -200;
        else if (Dil >= 14)stop_or_go = 2;
        int BrainBot = rand() % stop_or_go;

        while (true) {

            if (BrainBot == 0)
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &Dil);
                Dil_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
                break;
            }

            else if (BrainBot >= 1)break;
        }
        Sleep(2000);

        bool* one = new bool;
        *one = true;

        while (true) {
            if (*one) {
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], true, &round, *Money);
                *one = false;
            }

            GetKEY();

            if (KEY['Z'] || KEY['z'])
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &Mainuser);
                Mainuser_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], true, &round, *Money);
            }

            else if (KEY['X'] || KEY['x'])break;
        }
        delete one;

        if (bot1 == 21)stop_or_go = -200;
        else if (bot1 >= 14)stop_or_go = 2;
        BrainBot = rand() % stop_or_go;

        while (true) {

            if (BrainBot == 0)
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &bot1);
                bot1_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
                break;
            }

            else if (BrainBot >= 1)break;
        }

        Sleep(2000);

        if (bot2 == 21)stop_or_go = -200;
        else if (bot2 >= 14)stop_or_go = 2;
        BrainBot = rand() % stop_or_go;

        while (true) {

            if (BrainBot == 0)
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &bot2);
                bot2_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
                break;
            }

            else if (BrainBot >= 1)break;
        }
        Sleep(2000);

        if (bot3 == 21)stop_or_go = -200;
        else if (bot3 >= 14)stop_or_go = 2;
        BrainBot = rand() % stop_or_go;

        while (true) {

            if (BrainBot == 0)
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &bot3);
                bot3_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
                break;
            }

            else if (BrainBot >= 1)break;
        }
        Sleep(2000);

        if (bot4 == 21)stop_or_go = -200;
        else if (bot4 >= 14)stop_or_go = 2;
        BrainBot = rand() % stop_or_go;

        while (true) {

            if (BrainBot == 0)
            {
                randomCard = random(0, 12);
                GameCard(randomCard, &bot4);
                bot4_DisplayCard[randomCard] = displayCard(randomCard);
                DrawScreen(&Mainuser, &bot1, &bot2, &bot3, &bot4, &Dil, &Mainuser_DisplayCard[4],
                    &Dil_DisplayCard[4], &bot1_DisplayCard[4], &bot2_DisplayCard[4], &bot3_DisplayCard[4], &bot4_DisplayCard[4], false, &round, *Money);
                break;
            }

            else if (BrainBot >= 1)break;
        }
        Sleep(2000);

        BrainBot = rand() % stop_or_go;

        --round;
    }
    system("cls");
}

void main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    GameMenu();

    int Money = 10000, XMoney;
    bool StopGame = true;

    while (Money > 500 && StopGame) {

        system("cls");
        cout << "                                                   --------\n";
        cout << "                                                   |  BID |\n";
        cout << "                                                   --------\n";
        cout << "bid:";
        cin >> XMoney;

        while (Money > 500) {
            while (true) {
                if (XMoney < 500) {
                    cout << "\nbid:";
                    cin >> XMoney;
                    break;
                }

                else if (Money < 500) {
                    break;
                }

                else break;
            }

            if (Money > 500 && XMoney >= 500) {
                ProccesGame(&Money, &XMoney);
            }

            else break;

            cout << "E - Start, Q - Stop\n\nStart Game?\n- ";

            while (true) {
                GetKEY();
                if (KEY['E'] || KEY['e'])
                {
                    cout << 'E';
                    Sleep(2000);
                    system("cls");
                    cout << "                                                   --------\n";
                    cout << "                                                   |  BID |\n";
                    cout << "                                                   --------\n";
                    cout << "bid:";
                    cin >> XMoney;

                    cout << "\033[2J\033[1;1H";
                    break;
                }

                else if (KEY['Q'] || KEY['q'])
                {
                    cout << 'Q';
                    Sleep(3000);
                    cout << "\033[2J\033[1;1H";
                    StopGame = false;
                    break;
                }
            }
            if (StopGame == false)break;
        }
        system("cls");
        cout << "Thank you for game, bye";
        Sleep(1000);
        system("cls");
    }
}
