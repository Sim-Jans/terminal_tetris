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
    //�� ���� 4��
    //0->1, 1->2,  3->0
    int blockStatus = 0;
    
    //�浹���� ���
    boolean blockCrash = true;

    //int a = 0;
    while (true) {
        //�浹����
        if (blockCrash) {
            //�� ����
            gameSet.createBlock(blockX, blockY, blockKind);
            
            //�� ����
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
                //�浹 ����
                blockCrash = true;

            }
        }
        
        //��ǥ 0, 0
        gameSet.gotoxy(0, 0);
        //�ٽ� �׸���
        gameSet.drawBackground();
    }
    
    
    


    return 0;
}
