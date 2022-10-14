#include "GameSet.h"

//GameSet::GameSet(int x, int y) : Block() {
//    this->x = x;
//    this->y = y;
//
//    //▦: 1
//    //■: 2
//    vector<int> oneVector(x,0);
//    
//    vector<vector<int>> doubleVector(y, oneVector);
//    //첫줄
//    vector<int> firstVector(x, 1);
//
//    doubleVector[0].swap(firstVector);
//
//    
//    //마지막 줄
//    vector<int> finalVector(x, 1);
//    doubleVector[y-1].swap(finalVector);
//
//    //라인 생성하기
//    for (int i = 0; i < doubleVector.size(); i++) {
//        doubleVector[i][0] = 1;
//        doubleVector[i][x-1] = 1;
//    }
//    //저장
//    this->table = doubleVector;
//
//
//}

void GameSet::drawBackground() {

    
    for (int i = 0; i < table.size(); i++) {
        //x
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == 1) {
                cout << "▦";
            }
            else if (table[i][j] == 2) {
                cout << "■";
            }
            else {
                cout << "  ";
            }
            
        }
        cout << "\n";
    }
    
   

}
/*
    키보드 클릭
*/
void GameSet::GetKeyboardInput(int* x, int* y, int* blockKind)
{
    string status = "";
    char mInput = _getch();
    switch (mInput) {
    case 72:            // 위 방향키
        //cout << "위 \n";
        moveBlock(x, y, "up", blockKind);
        break;
    case 75:            // 왼쪽 방향키
        //cout << "왼쪽 \n";
      
        moveBlock(x, y, "left", blockKind);
        break;
    case 77:            // 오른쪽 방향키
        //cout << "오른쪽 \n";
   
        moveBlock(x, y, "right", blockKind);
        break;
    case 80:            // 아래쪽 방향키
        //cout << "아래쪽 \n";
    
        moveBlock(x, y, "down", blockKind);
        break;
    case 32:            // 스페이스 바
        //cout << "스페이스 \n";
        break;
    default:
        break;
    }
    
}

/*
    블록 이동함
*/
void GameSet::moveBlock(int* x, int* y, string status, int* blockKind) {
    
    vector<int> oneVector(4, 0);
    //4 4 공간 좌표
    vector<vector<int>> blockStatus(4, oneVector);
    //블럭 이동 확인하기
    for (int i = 0; i < 4; i++) {
        //x좌표
        for (int j = 0; j < 4; j++) {
            if (table[i + *y][j + *x] == 2) {
                //x
                if (status.compare("left") == 0 && table[i + *y][j + *x - 1] == 1) {
                    cout << "멈춤\n";
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

    //table에서 블록 제거
    //y 좌표
    for (int i = 0; i < 4; i++) {
        //x좌표
        for (int j = 0; j < 4; j++) {
            if (table[i+ *y][j+ *x] == 2) {
                table[i + *y][j + *x] = 0;
            }

        }
    }
    //블록정보
    vector<int*> blockVector = getBlockVector();

    int* blockData = blockVector[*blockKind];
    //블럭 정보 저장
    //y
    for (int i = 0; i < 4; i++) {
        //블록좌표
        int* blockX = (int*)(blockData + i * 4);
        //x
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
                //블록출력 필요
            }
            else if (blockX[j] == 2) {
                blockStatus[j][i] = blockX[j];
            }

        }

    }
    
    //왼쪽
    if (status.compare("left") == 0){
        *x - 1 > 0 ? *x -= 1: *x = 0;
        
    }
    //오른쪽
    else if (status.compare("right") == 0) {
        *x >= this->x  ? *x = this->x -1 : *x += 1;
        
    }
    //아래
    else if (status.compare("down") == 0) {
        *y += 1;
    }
    //위
    else if (status.compare("up") == 0) {
        *y -= 1;
    }
    //방향전환
    else if (status.compare("space") == 0) {

    }



    //블럭 출력
    for (int i = 0; i < 4; i++) {
        //x좌표
        for (int j = 0; j < 4; j++) {
            if (blockStatus[i][j] == 2) {
                table[i + *y][j + *x] = blockStatus[i][j];
            }
        }
    }
    /*
    //첫칸
            if (j == 0 && table[i + *y][j + *x-1] == 1) {
                return;
            }
            //마지막
            else if (j == 3 && table[i + *y][j + *x + 1] == 1) {
                return;
            }
            //y 첫칸
            else if (i == 0 && table[i + *y-1][j + *x] == 1) {
                return;
            }
            //마지막
            else if (i == 3 && table[i + *y + 1][j + *x] == 1) {
                return;
            }
    */
    
}


/*콘솔 커서 위치 이동*/
void GameSet::gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*블록 생성*/
void GameSet::createBlock(int x, int y, int blockKind) {
    
    //블록정보
    vector<int*> blockVector = getBlockVector();
    //블록한개정보
    int* blockData = blockVector[blockKind];
    //출력
    //y
    for (int i = 0; i < 4; i++) {
        //블록좌표
        int* blockX = (int*)(blockData + i*4);

       
        for (int j = 0; j < 4; j++) {
            if (blockX[j] == 0) {
                continue;
            //블록출력 필요
            }else if(blockX[j] == 2){
                table[y + j][x + i] = blockX[j];
            }
            
            
            
        }
 
    }
    
}
