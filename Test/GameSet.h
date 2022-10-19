#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <conio.h> //_getch가 포함되어있는 헤더
#include <windows.h>
#include <string>
#include <list>

#include "Block.h"
using namespace std;



class GameSet : public Block{
	private:
        //x, y 크기
		int x, y;
		vector<vector<int>> table;
        //여분 공간 추가한 X
        int totalX;
        //여분 공간 추가한 Y
        int totalY;
        //출력 하면 안되는 죄표 시작점
        //이하면 출력 불가
        int min ;
        //이상 출력 불가
        int maxX;
        int maxY;
        
	public:
        /*
            int x:          x 크기
            int y:          y 크기
            //상 하 좌 우 각각 여분칸 4씩 존재함
            ubt spacePlace: 여분 공간
        */
		GameSet(int x, int y, int spacePlace) : Block() {
            //x 칸 총 개수
            this->x = x;
            //y 칸 총 개수
            this->y = y;
            //상 하 좌 우 각각 여분칸 4씩 존재함
            
            //여분 공간 추가한 X
            int totalX =   x + spacePlace * 2;
            //여분 공간 추가한 Y
            int totalY = y + spacePlace * 2;

            this->totalX;
            this->totalY;

            //0 : 없음
            //▦: 1
            //■: 2
            //x 크기
            vector<int> oneVector(totalX, 0);
            //x, y 좌표
            vector<vector<int>> doubleVector(totalY, oneVector);
            
            //라인 생성하기
            /*for (int i = 0; i < doubleVector.size(); i++) {
                doubleVector[i][0] = 1;
                doubleVector[i][x - 1] = 1;
            }*/
            
            //출력 하면 안되는 죄표 시작점
            int min = spacePlace;
            int maxX = totalX - spacePlace - 1;
            int maxY = totalY - spacePlace - 1;

            this->min = min;
            this->maxX = maxX;
            this->maxY = maxY;

            //y 좌표
            for (int i = 0; i < totalY; i++) {
                //숨기는 좌표
                if (i < min || maxY < i) { 
                    continue; 
                }

                //x 좌표
                for (int j = 0; j < totalX; j++) {
                    //숨기는 좌표
                    /*if (j < min || maxX < j) {
                        continue;
                    }*/

                    //상위 라인
                    if (i == min) {
                        doubleVector[i][j] = 1;
                    }
                    //하위 라인
                    else if (i == maxY) {
                        doubleVector[i][j] = 1;
                    }
                    //좌 라인
                    else if (j == min) {
                        doubleVector[i][j] = 1;
                    }
                    //우 라인
                    else if (j == maxX) {
                        doubleVector[i][j] = 1;
                    }
                }

            }
            //저장
            this->table = doubleVector;
		};
		//그리기
		void drawBackground();
		//키보드 이벤트
		void GetKeyboardInput(int *x, int *y, int* blockKind, int* blockStatus);
		//콘솔 죄표 변경
		void gotoxy(int x, int y);
		//블록 생성
		void createBlock(int x, int y, int blockKind);
        //블록이동
        void moveBlock(int *x, int *y, string status, int* blockKind, int* blockStatus);
        //블록 모양 변경
        void changeBlock(int* x, int* y, int* blockKind, int* blockStatus);
        //블록이 충돌
        string toouchDownBlock(int* x, int* y);

};