#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cctype>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;

// Menu
void menu();
void playWithComputer();
void playWithPlayerNormalMode();
void playWithPlayerSpeedMode();
void gameInstructions();

// Input
int getPlayerChoice();
int getPlayerChoice1();
int getComputerChoice();

// Process
int getResult(int a, int b);
void updateScore(int result);

//score
int playerScore = 0;
int computerScore = 0;

//text color
void colorRed();
void colorBlue();
void colorGreen();
void colorYellow();
void colorDefault();

//countdown
void countdown();
void computerThinking();

//icon
void printTwoIcons(int a, int b);

int main() {
    srand(time(NULL));// initialize the seed
    menu();
    return 0;
}

void menu() {
    char choice;
    do {
        colorBlue();
        cout << "  +----------------------------------------+\n";
        cout << "  | __   __     _________       (\\   /)    |\n";
        cout << "  | ||   ||    //00O0O00O\\\\      (\\ /)     |\n";
        cout << "  | |(@@)||    //09O00O09O0\\\\     (X)      |\n";
        cout << "  |(@@@@@@)    \\\\9080O600O0O//    /_\\      |\n";
        cout << "  |(@@@@@@@)    \\\\9080OO809//    /| |\\     |\n";
        cout << "  | (@@@@@@)     \\\\9080OO80/    /_| |_\\    |\n";
        cout << "  +----------------------------------------+\n";
        colorRed();
        cout << "  |        * ROCK  PAPER  SCISSORS *       |\n";
        colorGreen();
        cout << "  +----------------------------------------+\n";
        cout << "  |    [1] Play with computer              |\n";
        cout << "  |    [2] Play with another player(Normal)|\n";
        cout << "  |    [3] Play with another player(Speed) |\n";
        cout << "  |    [9] Game instructions               |\n";
        cout << "  |    [0] Exit                            |\n";
        cout << "  +----------------------------------------+\n";
        colorYellow();
        cout << "  Choose: ";
        cin >> choice;
        colorDefault();
        if (choice == '1'){
            system("cls");
            playWithComputer();
        }
        else if (choice == '2'){
            system("cls");
            playWithPlayerNormalMode();
        }
        else if (choice == '3'){
            system("cls");
            playWithPlayerSpeedMode();
        }
        else if (choice == '9'){
            system("cls");
            gameInstructions();
        }
        system("cls");
    } while (choice != '0');

}

int getPlayerChoice() {
    char c;
    do {
        colorGreen();
        cout << "\n  +------------------+\n  | Choose player 1: ";
        colorDefault();
        c = _getch();
        if(c < '1' || c > '3'){
            cout << "\33[1A\33[2K\r";
            cout << "\33[0A\33[2K\r";
        }
    } while (c < '1' || c > '3');
    colorGreen();
    cout<< " |\n";
    cout<<"  +------------------+\n";
    colorDefault();
    return c - '0';
}

int getPlayerChoice1() {
    char c;
    do {
        colorRed();
        cout << "\n  +------------------+\n  | Choose player 2: ";
        colorDefault();
        c = _getch();
        if(c < '7' || c > '9'){
            cout << "\33[1A\33[2K\r";
            cout << "\33[0A\33[2K\r";
        }
    } while (c < '7' || c > '9');
    colorRed();
    cout<< " |\n";
    cout<< "  +------------------+\n";
    colorDefault();
    return c - '0';
}


int getComputerChoice() {
    return (rand() % 3 + 1) + 6; // choice 6–9
}

int getResult(int a, int b) {
    if (a + 6 == b) return 0; // Draw

    if ((a == 1 && b == 9) ||
        (a == 2 && b == 7) ||
        (a == 3 && b == 8))
        return 1; // Player 1 wins

    return 2; // Computer / Player 2 wins
}

void updateScore(int result) {
    if (result == 1) playerScore++;
    else if (result == 2) computerScore++;
}

void playWithComputer() {
    string items[3] = {"Rock", "Paper", "Scissors"};
    char exitKey;
    do {
        colorRed();
        cout << "  +------------------------------------------+\n";
        cout << "  |            PLAY WITH COMPUTER            |\n";
        cout << "  +------------------------------------------+\n";
        colorGreen();
        cout << "  |       [1]Rock [2]Paper [3]Scissors       |\n";
        cout << "  +------------------------------------------+\n";
        colorDefault();
        cout << "     (\\___/)              ___!___\n";
        cout << "     ( '- ')              [A~ I ]\n";
        cout << "     (\")__(\")             />____<\\\n";
        colorBlue();
        cout << "  +----------------- SCORE ------------------+\n";
        colorGreen();
        cout<< "  |     You: " << playerScore << "             ";
        colorRed();
        cout<< "Computer: " << computerScore;
        colorBlue();
        cout << "       |\n  +------------------------------------------+\n";
        colorDefault();
        int playerChoice = getPlayerChoice();
        int computerChoice = getComputerChoice();
        int result = getResult(playerChoice, computerChoice);
        updateScore(result);
        computerThinking();
        colorGreen();
        cout << "\n  " << items[playerChoice - 1];
        colorDefault();
        cout << "   vs   ";
        colorRed();
        cout<< items[computerChoice - 7] << endl << endl;
        colorDefault();
        printTwoIcons(playerChoice, computerChoice - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow(); cout << "  |          Result: Draw                    |\n"; }
        else if (result == 1) { colorGreen(); cout << "  |          Result: You win!                |\n"; }
        else { colorRed(); cout << "  |          Result: Computer wins!          |\n"; }
        colorDefault();
        cout << "  +------------------------------------------+\n";
        cout << "  |   Press Y to exit, any key to continue.  |\n";
        cout << "  +------------------------------------------+\n";
        exitKey = tolower(_getch());
        system("cls");
    } while (exitKey != 'y');
}

void playWithPlayerNormalMode() {
    char exitKey;
    string items[3] = {"Rock", "Paper", "Scissors"};
    do {
        colorYellow();
        cout<< "  +------------------------------------------+\n";
        cout<< "  |         PLAY WITH ANOTHER PLAYER         |\n";
        cout<< "  |         ******NORMAL  MODE******         |\n";
        cout<< "  +------------------------------------------+\n";
        colorGreen();
        cout<< "  | P1: [1]Rock [2]Paper [3]Scissors         |\n";
        colorRed();
        cout<< "  | P2: [7]Rock [8]Paper [9]Scissors         |\n";
        cout<< "  +------------------------------------------+\n";
        colorDefault();
        cout << "     (\\___/)              (\\___/)\n";
        cout << "     ( '- ')              (*- * )\n";
        cout << "     (\")__(\")            (\\____/)\n";

        int player1 = getPlayerChoice();
        int player2 = getPlayerChoice1();
        int result = getResult(player1, player2);

        countdown();

        colorGreen();
        cout<< "\n    " << items[player1 - 1];
        colorDefault();
        cout<< "   vs   ";
        colorRed();
        cout<< items[player2 - 7] << endl << endl;
        colorDefault();
        printTwoIcons(player1, player2 - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow(); cout << "  |           Result: Draw                    |\n"; }
        else if (result == 1) { colorGreen(); cout << "  | Result: Player 1 wins!          |\n"; }
        else { colorRed(); cout << "  | Result: Player 2 wins!          |\n"; }
        colorDefault();
        cout << "  +------------------------------------------+\n";
        cout << "  |   Press Y to exit, any key to continue.  |\n";
        cout << "  +------------------------------------------+\n";
        exitKey = tolower(_getch());
        system("cls");
    } while (exitKey != 'y');
}

void playWithPlayerSpeedMode() {
    char exitKey;
    string items[3] = {"Rock", "Paper", "Scissors"};
    do {
        int i = 0, choiceP1 = 0, choiceP2 = 0, result;
        colorYellow();
        cout<< "  +------------------------------------------+\n";
        cout<< "  |         PLAY WITH ANOTHER PLAYER         |\n";
        cout<< "  |         ******(SPEED MODE)******         |\n";
        cout<< "  +------------------------------------------+\n";
        colorGreen();
        cout<< "  | P1: [1]Rock [2]Paper [3]Scissors         |\n";
        colorRed();
        cout<< "  | P2: [7]Rock [8]Paper [9]Scissors         |\n";
        cout<< "  +------------------------------------------+\n";
        colorDefault();
        cout << "     (\\___/)              (\\___/)\n";
        cout << "     ( '- ')              (*- * )\n";
        cout << "     (\")__(\")            (\\____/)\n";

        while(i <= 100){
            switch(i){
                 case 5: cout<< " 1__...";break;
                 case 50: cout<< "2__...";break;
                 case 95: cout<< "3__....\n";break;
            }
            if (_kbhit()) {
                int temp = _getch();

                if(temp >= '1' && temp <= '3' && choiceP1 == 0)
                    choiceP1 = temp - '0';

                if(temp >= '7' && temp <= '9' && choiceP2 == 0)
                    choiceP2 = temp - '0';
            }
            Sleep(20);
            i++;
        }
        if(choiceP1 == 0 && choiceP2 == 0){
            result = 0;
            cout << "  +------------------------------------------+\n";
            colorYellow();
            cout << "  |           Result: Draw                   |\n";
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 != 0 && choiceP2 == 0){
            result = 1;
            cout << "  +------------------------------------------+\n";
            colorGreen();
            cout << "  |           Result: Player 1 wins!         |\n";
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 == 0 && choiceP2 != 0){
            result = 2;
            cout << "  +------------------------------------------+\n";
            colorRed();
            cout << "  |           Result: Player 2 wins!         |\n";
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 != 0 && choiceP2 != 0){
        result = getResult(choiceP1, choiceP2);

        countdown();

        colorGreen();
        cout<< "\n    " << items[choiceP1 - 1];
        colorDefault();
        cout<< "   vs   ";
        colorRed();
        cout<< items[choiceP2 - 7] << endl << endl;
        colorDefault();
        printTwoIcons(choiceP1, choiceP2 - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow(); cout << "  |           Result: Draw                   |\n"; }
        else if (result == 1) { colorGreen(); cout << "  |           Result: Player 1 wins!         |\n"; }
        else { colorRed(); cout << "  |           Result: Player 2 wins!         |\n"; }
        colorDefault();
        }
        cout << "  +------------------------------------------+\n";
        cout << "  |   Press Y to exit, any key to continue.  |\n";
        cout << "  +------------------------------------------+\n";
        exitKey = tolower(_getch());
        system("cls");
    } while (exitKey != 'y');
}

void gameInstructions(){
    char exitKey ;
    do{
        colorBlue();
        cout << "  +--------------------------------------------------+\n";
        cout << "  |                  GAME INSTRUCTIONS               |\n";
        cout << "  +--------------------------------------------------+\n";
        colorYellow();
        cout << "  |          ROCK - PAPER - SCISSORS RULES:          |\n";
        colorGreen();
        cout << "  |          Rock        beats      Scissors         |\n";
        cout << "  |          Scissors    beats      Paper            |\n";
        cout << "  |          Paper       beats      Rock             |\n";
        colorBlue();
        cout << "  +--------------------------------------------------+\n";
        colorYellow();
        cout << "  |  GAME MODES:                                     |\n";
        colorGreen();
        cout << "  |  [1] Play with Computer                          |\n";
        cout << "  |  [2] Play with Another Player (Normal Mode)      |\n";
        cout << "  |      Player 1: 1-3   |   Player 2: 7-9           |\n";
        colorRed();
        cout << "  |  [3] Play with Another Player (Speed Mode)       |\n";
        cout << "  |      *Fast reaction decides the winner*          |\n";
        cout << "  |      Player 1: 1-3   |   Player 2: 7-9           |\n";
        colorBlue();
        cout << "  +--------------------------------------------------+\n";
        colorGreen();
        cout << "  |   Press Y to return to the main menu.            |\n";
        cout << "  +--------------------------------------------------+\n";
        colorDefault();

        exitKey = _getch();
        system("cls");
    }while(exitKey != 'y');
    system("cls");
}

//text color
void colorRed()  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void colorBlue() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}

void colorGreen() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void colorYellow() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void colorDefault() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void countdown() {
    cout<< "  +-------------------------+\n";
    colorRed();   cout << "  [3]..."; Sleep(200);
    colorYellow(); cout << " [2]..."; Sleep(200);
    colorGreen();  cout << " [1]...";
    cout<< " GO!\n"; Sleep(250);
    colorDefault();
    cout<< "  +-------------------------+\n";
}

void computerThinking() {
    colorBlue();
    cout << "\n  +------------------------------------------+\n";
    cout<<"  | Computer thinking";
    for (int i = 0; i < 5; i++) { cout << "."; Sleep(200); }
    cout<< " Done!             |\n";
    cout<< "  +------------------------------------------+\n";
    colorDefault();
}

void printTwoIcons(int a, int b) {
    string icon1[6], icon2[6];
    if (a == 1) {
        icon1[0] = "  _________     ";
        icon1[1] = "  //00O0O00O\\    ";
        icon1[2] = "  //09O00O09O0\\\\";
        icon1[3] = " \\9080O600O0O// ";
        icon1[4] = " \\9080OO809//   ";
        icon1[5] = "   \\9080OO80/   ";
    }
    else if (a == 2) {
        icon1[0] = " __   __   ";
        icon1[1] = " ||   ||   ";
        icon1[2] = " |(@@)||   ";
        icon1[3] = " (@@@@@@)  ";
        icon1[4] = "(@@@@@@@)  ";
        icon1[5] = " (@@@@@@)  ";
    }
    else if (a == 3) {
        icon1[0] = "(\\   /)   ";
        icon1[1] = " (\\ /)    ";
        icon1[2] = "  (X)     ";
        icon1[3] = "  /_\\     ";
        icon1[4] = " /| |\\    ";
        icon1[5] = "/_| |_\\   ";
    }
    if (b == 1) {
        icon2[0] = "   _________";
        icon2[1] = "  //00O0O00O\\";
        icon2[2] = " //09O00O09O0\\\\";
        icon2[3] = "  \\9080O600O0O//";
        icon2[4] = "   \\9080OO809//";
        icon2[5] = "    \\9080OO80/";
    }
    else if (b == 2) {
        icon2[0] = "  __   __";
        icon2[1] = "  ||   ||";
        icon2[2] = "  ||(@@)||";
        icon2[3] = "  (@@@@@@)";
        icon2[4] = " (@@@@@@@)";
        icon2[5] = "  (@@@@@@)";
    }
    else if (b == 3) {
        icon2[0] = "  (\\   /)";
        icon2[1] = "   (\\ /)";
        icon2[2] = "    (X)";
        icon2[3] = "    /_\\";
        icon2[4] = "   /| |\\";
        icon2[5] = "  /_| |_\\";
    }
    for (int i = 0; i < 6; i++)
        cout << "  " << icon1[i] << "   " << icon2[i] << endl;
}
