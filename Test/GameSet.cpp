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
void GameSet::GetKeyboardInput(int* x, int* y, int* blockKind)
{
    string status = "";
    char mInput = _getch();
    switch (mInput) {
    case 72:            // �� ����Ű
        //cout << "�� \n";
        moveBlock(x, y, "up", blockKind);
        break;
    case 75:            // ���� ����Ű
        //cout << "���� \n";
      
        moveBlock(x, y, "left", blockKind);
        break;
    case 77:            // ������ ����Ű
        //cout << "������ \n";
   
        moveBlock(x, y, "right", blockKind);
        break;
    case 80:            // �Ʒ��� ����Ű
        //cout << "�Ʒ��� \n";
    
        moveBlock(x, y, "down", blockKind);
        break;
    case 32:            // �����̽� ��
        //cout << "�����̽� \n";
        break;
    default:
        break;
    }
    
}

/*
    ��� �̵���
*/
void GameSet::moveBlock(int* x, int* y, string status, int* blockKind) {
    
    vector<int> oneVector(4, 0);
    //4 4 ���� ��ǥ
    vector<vector<int>> blockStatus(4, oneVector);
    //�� �̵� Ȯ���ϱ�
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            if (table[i + *y][j + *x] == 2) {
                //x
                if (status.compare("left") == 0 && table[i + *y][j + *x - 1] == 1) {
                    cout << "����\n";
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

    //table���� ��� ����
    //y ��ǥ
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            if (table[i+ *y][j+ *x] == 2) {
                table[i + *y][j + *x] = 0;
            }

        }
    }
    //�������
    vector<int*> blockVector = getBlockVector();

    int* blockData = blockVector[*blockKind];
    //�� ���� ����
    //y
    for (int i = 0; i < 4; i++) {
        //�����ǥ
        int* blockX = (int*)(blockData + i * 4);
        //x
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
                //������ �ʿ�
            }
            else if (blockX[j] == 2) {
                blockStatus[j][i] = blockX[j];
            }

        }

    }
    
    //����
    if (status.compare("left") == 0){
        *x - 1 > 0 ? *x -= 1: *x = 0;
        
    }
    //������
    else if (status.compare("right") == 0) {
        *x >= this->x  ? *x = this->x -1 : *x += 1;
        
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

    }



    //�� ���
    for (int i = 0; i < 4; i++) {
        //x��ǥ
        for (int j = 0; j < 4; j++) {
            if (blockStatus[i][j] == 2) {
                table[i + *y][j + *x] = blockStatus[i][j];
            }
        }
    }
    /*
    //ùĭ
            if (j == 0 && table[i + *y][j + *x-1] == 1) {
                return;
            }
            //������
            else if (j == 3 && table[i + *y][j + *x + 1] == 1) {
                return;
            }
            //y ùĭ
            else if (i == 0 && table[i + *y-1][j + *x] == 1) {
                return;
            }
            //������
            else if (i == 3 && table[i + *y + 1][j + *x] == 1) {
                return;
            }
    */
    
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
