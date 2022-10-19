#include <iostream>

#include "GameSet.h"
#include "MainMenu.h"

/*
공백 = 0
▦ = 1
■ = 2
이미 쌓인 블럭은 = 3
블럭이 쌓이는 맨 밑바닥 = 4
*/


int main(void) {
    /*
        상 하 자 우 여분 4칸식 설정
    */

    MainMenu mainMenu;
    //시작 메뉴 생성
    mainMenu.startText();

    system("mode con cols=100 lines=40 | title C++ Tetris"); //상태창 설정

    int x = 12;
    int y = 20;
    int spacePlace = 4;
    GameSet gameSet(x, y, spacePlace);//게임 테이블 설정
    //배경출력
    gameSet.drawBackground();
    //블록 생성
    int blockX = x / 2;
    int blockY = spacePlace;
    //블록 종류 5개
    int blockKind = 2;
    //블럭 상태 4개
    //0->1, 1->2,  3->0
    int blockStatus = 0;
    
    //충돌여부 토글
    boolean blockCrash = true;

    //int a = 0;
    while (true) {
        //충돌여부
        if (blockCrash) {
            //블럭 생성
            gameSet.createBlock(blockX, blockY, blockKind);
            
            //블럭 생성
            blockCrash = false;
        }
        else {
            gameSet.GetKeyboardInput(&blockX, &blockY, &blockKind, &blockStatus);

            string data = gameSet.toouchDownBlock(&blockX, &blockY);
            cout << "data:  " << data << "\n";
            if (data.compare("crash") == 0) {
                blockX = x / 2;
                blockY = spacePlace;

                blockStatus = 0;
                if (blockKind == 4) {
                    blockKind = 0;
                }
                else {
                    blockKind++;
                }
                //충돌 성공
                blockCrash = true;

            }
        }
        
        //좌표 0, 0
        gameSet.gotoxy(0, 0);
        //다시 그리기
        gameSet.drawBackground();
    }
    
    
    


    return 0;
}
