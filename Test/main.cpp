#include <iostream>

#include "GameSet.h"
#include "MainMenu.h"

/*
���� = 0
�� = 1
�� = 2
�̹� ���� ���� = 3
���� ���̴� �� �عٴ� = 4
*/


int main(void) {
    /*
        �� �� �� �� ���� 4ĭ�� ����
    */

    MainMenu mainMenu;
    //���� �޴� ����
    mainMenu.startText();

    system("mode con cols=100 lines=40 | title C++ Tetris"); //����â ����

    int x = 12;
    int y = 20;
    int spacePlace = 4;
    GameSet gameSet(x, y, spacePlace);//���� ���̺� ����
    //������
    gameSet.drawBackground();
    //��� ����
    int blockX = x / 2;
    int blockY = spacePlace;
    //��� ���� 5��
    int blockKind = 2;
    gameSet.createBlock(blockX, blockY, blockKind);
    //��ǥ 0, 0
    gameSet.gotoxy(0,0);
    //�ٽ� �׸���
    gameSet.drawBackground();

    //int a = 0;
    while (true) {
        
        gameSet.GetKeyboardInput(&blockX, &blockY, &blockKind);
        //��ǥ 0, 0
        gameSet.gotoxy(0, 0);
        //�ٽ� �׸���
        gameSet.drawBackground();
    }
    
    
    


    return 0;
}
