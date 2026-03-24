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

//language
void chooseLanguage();

enum Language {
    VIETNAMESE,
    ENGLISH
};

Language currentLang = ENGLISH;

// cau truc cho ngon ngu
struct GameText {
    string tieuDeKeoBuaBao;                              //1
    string luaChon;                                      //2
    string nguoiChoi1;                                   //3
    string nguoiChoi2;                                   //4
    string choiVoiMay;                                   //5
    string luaChonKeoBuaBao;                             //6
    string hoa;                                          //7
    string banThang;                                     //8
    string mayTinhThang;                                 //9
    string thoatHoacTiepTuc;                             //10
    string choiVoiNguoiKhac;                             //11
    string cheDoThuong;                                  //12
    string luaChonCuaNguoiChoi1;                         //13
    string luaChonCuaNguoiChoi2;                         //14
    string cheDoTangToc;                                 //15
    string huongDanChoiGame;                             //16
    string quyTacChoi;                                   //17
    string daThangKeo;                                   //18
    string keoThangGiay;                                 //19
    string giayThangDa;                                  //20
    string cheDoChoi;                                    //21
    string nguoiChoi1Tu1Den3NguoiChoi2Tu7Den9Thuong;     //22
    string phanXaNhanhQuyetDinhChienThang;               //23
    string nhanPhimYDeQuayLai;                           //24
    string cheDoChoiCungMayTinh;                         //25
    string cheDoChoiCungNguoiKhacCheDoThuong;            //26
    string cheDoChoiCungNguoiKhacCheDoTangToc;           //27
    string nguoiChoi1Tu1Den3NguoiChoi2Tu7Den9TangToc;    //28
    string ketQuaHoa;                                    //29
    string ketQuaNguoi1Thang;                            //30
    string ketQuaNguoi2Thang;                            //31
    string ban;                                          //32
    string mayTinh;                                      //33
    string mayTinhSuyNghi;                               //34
    string xong;                                         //35
    string da;                                           //36
    string giay;                                         //36
    string keo;                                          //36

};
// tieng viet
GameText langVI = {
    "  |       * DA       GIAY      KEO *       |\n",           //1
    "  |   [1] Choi Voi May                     |\n"
    "  |   [2] Choi Voi Nguoi (Binh Thuong)     |\n"
    "  |   [3] Choi Voi Nguoi(Tang Toc)         |\n"
    "  |   [8] Doi Ngon Ngu                     |\n"
    "  |   [9] Huong Dan Choi                   |\n"
    "  |   [0] Thoat                            |\n",           //2
    "  |   Nguoi choi So 1                        |",           //3
    "  |   Nguoi choi So 2                        |",           //4
    "  |   CHOI VOI MAY                           |\n",         //5
    "  |      [1] DA [2] GIAY [3] KEO             |\n",         //6
    "  |         KET QUA: HOA                     |\n",         //7
    "  |         KET QUA: BAN THANG               |\n",         //8
    "  |         KET QUA: MAY TINH THANG          |\n",         //9
    "  |Nhan Phim Y De Thoat, Bat Ki De Tiep Tuc  |\n",         //10
    "  |        Choi Voi Nguoi Choi Khac          |\n",         //11
    "  |        ******Che Do Thuong******         |\n",         //12
    "  | Nguoi Choi 1: [1]DA [2]GIAY [3]KEO       |\n",         //13
    "  | Nguoi Choi 2: [7]DA [8]GIAY [9]KEO       |\n",         //14
    "  |        ******Che Do Tang Toc******       |\n",         //15
    "  |            HUONG DAN CHOI GAME                   |\n", //16
    "  |        QUY TAC CHOI DA - GIAY - KEO:             |\n", //17
    "  |          DA       Thang      KEO                 |\n", //18
    "  |          KEO      Thang      GIAY                |\n", //19
    "  |          GIAY     Thang      DA                  |\n", //20
    "  |  CHE DO CHOI:                                    |\n", //21
    "  |   Nguoi Choi 1: 1-3  |  Nguoi Choi 2: 7-9        |\n", //22
    "  |  *Phan Xa Nhanh Quyet Dinh Chien Thang*          |\n", //23
    "  |   Nhan Phim Y De Quay Lai Menu Chinh.            |\n", //24
    "  |  [1] Choi Cung May Tinh                          |\n", //25
    "  |  [2] Choi Cung Nguoi Khac (Che Do Thuong)        |\n", //26
    "  |  [3] Choi Cung Nguoi Khac (Che Do Tang Toc)      |\n", //27
    "  |   Nguoi Choi 1: 1-3  |  Nguoi Choi 2: 7-9        |\n", //28
    "  |         KET QUA: HOA                     |\n",         //29
    "  |         KET QUA: NGUOI CHOI 1 THANG      |\n",         //30
    "  |         KET QUA: NGUOI CHOI 2 THANG      |\n",         //31
    "  |     Ban: " ,                                           //32
    " May Tinh: " ,                                             //33
    "  | May Tinh Suy Nghi",                                    //34
    " Xong             |\n",                                    //35
    "DA",                                                       //36
    "GIAY",                                                     //37
    "KEO"                                                       //38

};
// tieng anh
GameText langEN = {
    "  |        * ROCK  PAPER  SCISSORS *       |\n",           //1
    "  |    [1] Play with computer              |\n"
    "  |    [2] Play with another player(Normal)|\n"
    "  |    [3] Play with another player(Speed) |\n"
    "  |    [8] Choose Language                 |\n"
    "  |    [9] Game instructions               |\n"
    "  |    [0] Exit                            |\n",           //2
    "  |    Player 1                              |",           //3
    "  |    Player 2                              |",           //4
    "  |    PLAY WITH COMPUTER                    |\n",         //5
    "  |    [1]Rock [2]Paper [3]Scissors          |\n",         //6
    "  |          Result: Draw                    |\n",         //7
    "  |          Result: You Win                 |\n",         //8
    "  |          Result: Computer Win            |\n",         //9
    "  |   Press Y to exit, any key to continue.  |\n",         //10
    "  |         PLAY WITH ANOTHER PLAYER         |\n",         //11
    "  |         ******NORMAL MODE******          |\n",         //12
    "  | PLAYER 1: [1]Rock [2]Paper [3]Scissors   |\n",         //13
    "  | PLAYER 2: [7]Rock [8]Paper [9]Scissors   |\n",         //14
    "  |         ******SPEED MODE******           |\n",         //15
    "  |            GAME INSTRUCTIONS                     |\n", //16
    "  |        ROCK - PAPER  ytujmgk ujggkh jm- SCISSORS RULES:            |\n", //17
    "  |         Rock        beats      Scissors          |\n", //18
    "  |         Scissors    beats      Paper             |\n", //19
    "  |         Paper       beats      Rock              |\n", //20
    "  |  GAME MODES:                                     |\n", //21
    "  |      Player 1: 1-3   |   Player 2: 7-9           |\n", //22
    "  |      *Fast reaction decides the winner*          |\n", //23
    "  |   Press Y to return to the main menu.            |\n", //24
    "  |  [1] Play with Computer                          |\n", //25
    "  |  [2] Play with Another Player (Normal Mode)      |\n", //26
    "  |  [3] Play with Another Player (Speed Mode)       |\n", //27
    "  |      Player 1: 1-3   |   Player 2: 7-9           |\n", //28
    "  |          Result: Draw                    |\n",         //29
    "  |          Result: Player 1 wins!          |\n",         //30
    "  |          Result: Player 2 wins!          |\n",         //31
    "  |     You: ",                                            //32
    " Computer: ",                                              //33
    "  | Computer thinking",                                    //34
    " Done!             |\n",                                   //35
    "ROCK",                                                     //36
    "PAPER",                                                    //37
    "SCISSORS"                                                  //38

};


GameText *text;

int main() {
    srand(time(NULL));// initialize the seed
    text = &langEN;
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
        cout << text->tieuDeKeoBuaBao;
        colorGreen();
        cout << "  +----------------------------------------+\n";
        cout << text->luaChon;
        cout << "  +----------------------------------------+\n";
        colorYellow();

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
        else if (choice == '8'){
            system("cls");
            chooseLanguage();
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

    colorGreen();
    cout << "\n  +------------------------------------------+\n";
    cout << text->nguoiChoi1;
    colorDefault();

    do {
        c = _getch();

        if (c < '1' || c > '3') {
            colorGreen();
            cout << "\r" << text->nguoiChoi1;
            colorDefault();
        }

    } while (c < '1' || c > '3');

    colorGreen();
    cout << "\n";
    cout << "  +------------------------------------------+\n";
    colorDefault();

    return c - '0';
}

int getPlayerChoice1() {
    char c;

    colorRed();
    cout << "\n  +------------------------------------------+\n";
    cout << text-> nguoiChoi2;

    colorDefault();

    do {
        c = _getch();

        if (c < '7' || c > '9') {
            colorRed();
            cout << "\r"<< text-> nguoiChoi2;
        }

    } while (c < '7' || c > '9');

    colorRed();
    cout << "\n";
    cout << "  +------------------------------------------+\n";
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
    string items[3] = {text->da, text->giay, text->keo};
    char exitKey;
    do {
        colorRed();
        cout << "  +------------------------------------------+\n";
        cout << text->choiVoiMay;
        cout << "  +------------------------------------------+\n";
        colorGreen();
        cout << text->luaChonKeoBuaBao;
        cout << "  +------------------------------------------+\n";
        colorDefault();
        cout << "     (\\___/)              ___!___\n";
        cout << "     ( '- ')              [A~ I ]\n";
        cout << "     (\")__(\")             />____<\\\n";
        colorBlue();
        cout << "  +----------------- SCORE ------------------+\n";
        colorGreen();
        cout << text->ban<< playerScore << "             ";
        colorRed();
        cout << text->mayTinh<< computerScore;
        colorBlue();
        cout << "     |\n";
        cout << "  +------------------------------------------+\n";
        colorDefault();
        int playerChoice = getPlayerChoice();
        int computerChoice = getComputerChoice();
        int result = getResult(playerChoice, computerChoice);
        updateScore(result);
        computerThinking();
        colorGreen();
        cout << "\n           " << items[playerChoice - 1];
        colorDefault();
        cout << "   vs   ";
        colorRed();
        cout<< items[computerChoice - 7] << endl << endl;
        colorDefault();
        printTwoIcons(playerChoice, computerChoice - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow(); cout << text->hoa; }
        else if (result == 1) { colorGreen(); cout << text->banThang; }
        else { colorRed(); cout << text->mayTinhThang; }
        colorDefault();
        cout << "  +------------------------------------------+\n";
        cout << text->thoatHoacTiepTuc;
        cout << "  +------------------------------------------+\n";
        exitKey = tolower(_getch());
        system("cls");
    } while (exitKey != 'y');
}

void playWithPlayerNormalMode() {
    char exitKey;
    string items[3] = {text->da, text->giay, text->keo};
    do {
        colorYellow();
        cout<< "  +------------------------------------------+\n";
        cout << text->choiVoiNguoiKhac;
        cout << text->cheDoThuong;
        cout<< "  +------------------------------------------+\n";
        colorGreen();
        cout << text->luaChonCuaNguoiChoi1;
        colorRed();
        cout << text->luaChonCuaNguoiChoi2;
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
        cout<< "\n             " << items[player1 - 1];
        colorDefault();
        cout<< "   vs   ";
        colorRed();
        cout<< items[player2 - 7] << endl << endl;
        colorDefault();
        printTwoIcons(player1, player2 - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow(); cout << text->ketQuaHoa; }
        else if (result == 1) { colorGreen(); cout << text->ketQuaNguoi1Thang;}
        else { colorRed(); cout << text->ketQuaNguoi2Thang; }
        colorDefault();
        cout << "  +------------------------------------------+\n";
        cout << text->thoatHoacTiepTuc;
        cout << "  +------------------------------------------+\n";
        exitKey = tolower(_getch());
        system("cls");
    } while (exitKey != 'y');
}

void playWithPlayerSpeedMode() {
    char exitKey;
    string items[3] = {text->da, text->giay, text->keo};
    do {
        int i = 0, choiceP1 = 0, choiceP2 = 0, result;
        colorYellow();
        cout<< "  +------------------------------------------+\n";
        cout << text->choiVoiNguoiKhac;
        cout << text->cheDoTangToc;
        cout<< "  +------------------------------------------+\n";
        colorGreen();
        cout << text->luaChonCuaNguoiChoi1;
        colorRed();
        cout << text->luaChonCuaNguoiChoi2;
        cout<< "  +------------------------------------------+\n";
        colorDefault();
        cout << "     (\\___/)              (\\___/)\n";
        cout << "     ( '- ')              (*- * )\n";
        cout << "     (\")__(\")            (\\____/)\n";
        cout<< "  +------------------------------------------+\n";
        while(i <= 100){
            switch(i){
                 case 5: cout<< "              1__...";break;
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
        cout<< "  +------------------------------------------+\n";
        if(choiceP1 == 0 && choiceP2 == 0){
            result = 0;
            cout << "  +------------------------------------------+\n";
            colorYellow();
            cout << text->ketQuaHoa;
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 != 0 && choiceP2 == 0){
            result = 1;
            cout << "  +------------------------------------------+\n";
            colorGreen();
            cout << text->ketQuaNguoi1Thang;
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 == 0 && choiceP2 != 0){
            result = 2;
            cout << "  +------------------------------------------+\n";
            colorRed();
            cout << text->ketQuaNguoi2Thang;
            colorDefault();
            cout << "  +------------------------------------------+\n";
        }
        if(choiceP1 != 0 && choiceP2 != 0){
        result = getResult(choiceP1, choiceP2);
        colorGreen();
        cout<< "\n             " << items[choiceP1 - 1];
        colorDefault();
        cout<< "   vs   ";
        colorRed();
        cout<< items[choiceP2 - 7] << endl << endl;
        colorDefault();
        printTwoIcons(choiceP1, choiceP2 - 6);
        cout << "  +------------------------------------------+\n";
        if (result == 0) { colorYellow();
         cout << text->ketQuaHoa;
          }
        else if (result == 1) { colorGreen();
         cout << text->ketQuaNguoi1Thang;
          }
        else { colorRed();
         cout << text->ketQuaNguoi2Thang;
 }
        colorDefault();
        }
        cout << "  +------------------------------------------+\n";
        cout << text->thoatHoacTiepTuc;
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
        cout << text->huongDanChoiGame;
        cout << "  +--------------------------------------------------+\n";
        colorYellow();
        cout << text->quyTacChoi;
        colorGreen();
        cout << text->daThangKeo;
        cout << text->keoThangGiay;
        cout << text->giayThangDa;
        colorBlue();
        cout << "  +--------------------------------------------------+\n";
        colorYellow();
        cout << text->cheDoChoi;
        colorGreen();
        cout << text->cheDoChoiCungMayTinh;
        cout << text->cheDoChoiCungNguoiKhacCheDoThuong;
        cout << text->nguoiChoi1Tu1Den3NguoiChoi2Tu7Den9Thuong;
        colorRed();
        cout << text->cheDoChoiCungNguoiKhacCheDoTangToc;
        cout << text->phanXaNhanhQuyetDinhChienThang;
        cout << text->nguoiChoi1Tu1Den3NguoiChoi2Tu7Den9TangToc;
        colorBlue();
        cout << "  +--------------------------------------------------+\n";
        colorGreen();
        cout << text->nhanPhimYDeQuayLai;
        cout << "  +--------------------------------------------------+\n";
        colorDefault();

        exitKey = _getch();
        system("cls");
    }while(exitKey != 'y');
    system("cls");
}

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
    cout<< "  +------------------------------------------+\n";
    colorRed();   cout << "            [3]..."; Sleep(200);
    colorYellow(); cout << " [2]..."; Sleep(200);
    colorGreen();  cout << " [1]...";
    cout<< " GO!\n"; Sleep(250);
    colorDefault();
    cout<< "  +------------------------------------------+\n";
}

void computerThinking() {
    colorBlue();
    cout << "\n  +------------------------------------------+\n";
     cout << text->mayTinhSuyNghi;
    for (int i = 0; i < 5; i++) { cout << "."; Sleep(150); }
    cout << text->xong;
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
        cout << "        " << icon1[i] << "   " << icon2[i] << endl;
}
void chooseLanguage() {
    int c;
    colorGreen();
    cout << "  +------------------------------------------+\n";
    cout << "  |          1. Tieng Viet                   |\n";
    cout << "  +------------------------------------------+\n";
    colorRed();
    cout << "  +------------------------------------------+\n";
    cout << "  |          2. English                      |\n";
    cout << "  +------------------------------------------+\n";
    colorYellow();
    cout << "  |       Choose language:                   |\n";
    cout << "  +------------------------------------------+\n";
    cin >> c;

    if (c == 1) {
        currentLang = VIETNAMESE;
        text = &langVI;
    }
    else {
        currentLang = ENGLISH;
        text = &langEN;
    }
}
