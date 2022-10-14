#include "MainMenu.h"
#include <iostream>
using namespace std;

/**
* 시작 텍스트
*/
void MainMenu::startText() {
    cout << "\n\n\n\n";
    cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
    cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
    cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
    cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
    cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
    cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
    cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
    cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
    system("pause>null");
    system("cls"); // 콘솔 창 clear
}