#include "GameSet.h"

//GameSet::GameSet(int x, int y) : Block() {
//    this->x = x;
//    this->y = y;
//
//    //��: 1
//    //��: 2
//    vector<int> oneVector(x,0);
//    
//    vector<vector<int>> doubleVector(y, oneVector);
//    //ù��
//    vector<int> firstVector(x, 1);
//
//    doubleVector[0].swap(firstVector);
//
//    
//    //������ ��
//    vector<int> finalVector(x, 1);
//    doubleVector[y-1].swap(finalVector);
//
//    //���� �����ϱ�
//    for (int i = 0; i < doubleVector.size(); i++) {
//        doubleVector[i][0] = 1;
//        doubleVector[i][x-1] = 1;
//    }
//    //����
//    this->table = doubleVector;
//
//
//}

void GameSet::drawBackground() {

    
    for (int i = 0; i < table.size(); i++) {
        //x
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == 1) {
                cout << "��";
            }
            else if (table[i][j] == 2) {
                cout << "��";
            }
            //
            else if (table[i][j] == 3) {
                cout << "**";
            }
            //
            else {
                cout << "  ";
            }
            
        }
        cout << "\n";
    }
    
   

}
/*
    Ű���� Ŭ��
*/
void GameSet::GetKeyboardInput(int* x, int* y, int* blockKind, int* blockStatus)
{
    string status = "";
    char mInput = _getch();
    switch (mInput) {
    case 72:            // �� ����Ű
        //cout << "�� \n";
        moveBlock(x, y, "up", blockKind, blockStatus);
        break;
    case 75:            // ���� ����Ű
        //cout << "���� \n";
      
        moveBlock(x, y, "left", blockKind, blockStatus);
        break;
    case 77:            // ������ ����Ű
        //cout << "������ \n";
   
        moveBlock(x, y, "right", blockKind, blockStatus);
        break;
    case 80:            // �Ʒ��� ����Ű
        //cout << "�Ʒ��� \n";
    
        moveBlock(x, y, "down", blockKind, blockStatus);
        break;
    case 32:            // �����̽� ��
        //cout << "�����̽� \n";
        moveBlock(x, y, "space", blockKind, blockStatus);
        break;
    default:
        break;
    }
    
}

/*
    ��� �̵���
*/
void GameSet::moveBlock(int* x, int* y, string status, int* blockKind, int* blockStatus) {
    
    vector<int> oneVector(4, 0);
    //4 4 ���� ��ǥ
    vector<vector<int>> blockCoordinate(4, oneVector);
    //�� �̵� Ȯ���ϱ�
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            if (table[i + *y][j + *x] == 2) {
                //x
                if (status.compare("left") == 0 && table[i + *y][j + *x - 1] == 1) {
                    return;
                }
                else if (status.compare("right") == 0 && table[i + *y][j + *x + 1] == 1) {
                    return;
                }
                else if (status.compare("down") == 0 && table[i + *y + 1][j + *x] == 1) {
                    return;
                }
                else if (status.compare("up") == 0 && table[i + *y - 1][j + *x] == 1) {
                    return;
                }
                
            }

        }
    }

    //�������
    vector<int*> blockVector = getBlockVector();
    //��� ����
    int* blockData = blockVector[*blockKind];

    //�� ���� ����
    //y
    for (int i = 0; i < 4; i++) {
        int cnt = *blockStatus * 16;
        //�����ǥ
        int* blockX = (int*)(blockData + i * 4 + cnt);
        //x
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
                //������ �ʿ�
            }
            else if (blockX[j] == 2) {
                blockCoordinate[j][i] = blockX[j];
            }

        }

    }
 
    //��� ����
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            
            if ((blockCoordinate[i][j] == table[i + *y][j + *x]) && (table[i + *y][j + *x] == 2)) {
                table[i + *y][j + *x] = 0;
            }
         
        }
       
    }
    //����
    if (status.compare("left") == 0) {
        *x - 1 > 0 ? *x -= 1 : *x = 0;

    }
    //������
    else if (status.compare("right") == 0) {
        *x += 1;

    }
    //�Ʒ�
    else if (status.compare("down") == 0) {
        *y += 1;
    }
    //��
    else if (status.compare("up") == 0) {
        *y -= 1;
    }
    //������ȯ
    else if (status.compare("space") == 0) {
        int data = *blockStatus;

        if (data == 3) {
            *blockStatus = 0;
        }
        else {
            data++;
            *blockStatus +=1;
        }
        
    }
    

    blockCoordinate.assign(4, oneVector);
    //�� ���� ����
    //y
    for (int i = 0; i < 4; i++) {
        int cnt = *blockStatus * 16;
        //�����ǥ
        int* blockX = (int*)(blockData + i * 4 + cnt);
        //x
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
                //������ �ʿ�
            }
            else if (blockX[j] == 2) {
                blockCoordinate[j][i] = blockX[j];
            }

        }

    }
    /*cout << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", blockCoordinate[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";*/

    //y ��ǥ    
    //�� ���
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            if (blockCoordinate[i][j] == 2) {
                table[i + *y][j + *x] = blockCoordinate[i][j];
            }
        }
    }
    
}


/*�ܼ� Ŀ�� ��ġ �̵�*/
void GameSet::gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*��� ����*/
void GameSet::createBlock(int x, int y, int blockKind) {
    
    //�������
    vector<int*> blockVector = getBlockVector();
    //����Ѱ�����
    int* blockData = blockVector[blockKind];
    //���
    //y
    for (int i = 0; i < 4; i++) {
        //�����ǥ
        int* blockX = (int*)(blockData + i*4);

       
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
            //������ �ʿ�
            }else if(blockX[j] == 2){
                table[y + j][x + i] = blockX[j];
            }
            
        }
 
    }
    
}

/*
    ��� �ϴ� �浹
*/
string GameSet::toouchDownBlock(int* x, int* y, int* blockKind, int* blockStatus) {
    
    string data = "safe";
    //������ ��� ����
    boolean finalBlockToggle = false;
    //�������
    vector<int*> blockVector = getBlockVector();
    //��� ����
    int* blockData = blockVector[*blockKind];
    
    cout << "x:" << *x << "\n";
    cout << "y:" << *y << "\n";
    
    //int cnt = 3;
    //y��ǥ
    for (int i = 0; i < 4; i++) {
            //x��ǥ
            for (int j = 0; j < 4; j++) {
                //x��ǥ
                int lineX = (int) * x + j;
                //y��ǥ
                int lineY = (int) * y + i ;

                //�����ǥ
                if (table[lineY][lineX] == 2) {
                    //���� ��� ���� ��� ��� ��
                    if (i < 3) {
                        //���� ��� ��� ��ǥ
                        int* blockX = (int*)(blockData + (i + 1) * 4);
                        //���� ��翡�� ����� ���� ���
                        if (blockX[lineX] == 2) {
                            cout << "�ѱ�";
                            continue;
                        }
                    }
                    //������
                    if (table[lineY+1][lineX] == 1) {
                        data = "crash";
                        finalBlockToggle = true;
                        break;
                    }
                }

            }
            //cnt--;
            if (data.compare("crash") == 0) break;
            //����� ������ x������ ����
            if (finalBlockToggle) {
                
                break;
            }
    }

    /*
    for (int i = 0; i < 4; i++) {
        int cnt = *blockStatus * 16;
        //�����ǥ
        int* blockX = (int*)(blockData + i * 4);
        //x
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
                //������ �ʿ�
            }
            else if (blockX[j] == 2) {
                blockCoordinate[j][i] = blockX[j];
            }

        }

    }
    
    */
    return data;
}
