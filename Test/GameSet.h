#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <conio.h> //_getch�� ���ԵǾ��ִ� ���
#include <windows.h>
#include <string>
#include <list>

#include "Block.h"
using namespace std;



class GameSet : public Block{
	private:
        //x, y ũ��
		int x, y;
		vector<vector<int>> table;
        //���� ���� �߰��� X
        int totalX;
        //���� ���� �߰��� Y
        int totalY;
        //��� �ϸ� �ȵǴ� ��ǥ ������
        //���ϸ� ��� �Ұ�
        int min ;
        //�̻� ��� �Ұ�
        int maxX;
        int maxY;
        
	public:
        /*
            int x:          x ũ��
            int y:          y ũ��
            //�� �� �� �� ���� ����ĭ 4�� ������
            ubt spacePlace: ���� ����
        */
		GameSet(int x, int y, int spacePlace) : Block() {
            //x ĭ �� ����
            this->x = x;
            //y ĭ �� ����
            this->y = y;
            //�� �� �� �� ���� ����ĭ 4�� ������
            
            //���� ���� �߰��� X
            int totalX =   x + spacePlace * 2;
            //���� ���� �߰��� Y
            int totalY = y + spacePlace * 2;

            this->totalX;
            this->totalY;

            //0 : ����
            //��: 1
            //��: 2
            //x ũ��
            vector<int> oneVector(totalX, 0);
            //x, y ��ǥ
            vector<vector<int>> doubleVector(totalY, oneVector);
            
            //���� �����ϱ�
            /*for (int i = 0; i < doubleVector.size(); i++) {
                doubleVector[i][0] = 1;
                doubleVector[i][x - 1] = 1;
            }*/
            
            //��� �ϸ� �ȵǴ� ��ǥ ������
            int min = spacePlace;
            int maxX = totalX - spacePlace - 1;
            int maxY = totalY - spacePlace - 1;

            this->min = min;
            this->maxX = maxX;
            this->maxY = maxY;

            //y ��ǥ
            for (int i = 0; i < totalY; i++) {
                //����� ��ǥ
                if (i < min || maxY < i) { 
                    continue; 
                }

                //x ��ǥ
                for (int j = 0; j < totalX; j++) {
                    //����� ��ǥ
                    /*if (j < min || maxX < j) {
                        continue;
                    }*/

                    //���� ����
                    if (i == min) {
                        doubleVector[i][j] = 1;
                    }
                    //���� ����
                    else if (i == maxY) {
                        doubleVector[i][j] = 1;
                    }
                    //�� ����
                    else if (j == min) {
                        doubleVector[i][j] = 1;
                    }
                    //�� ����
                    else if (j == maxX) {
                        doubleVector[i][j] = 1;
                    }
                }

            }
            //����
            this->table = doubleVector;
		};
		//�׸���
		void drawBackground();
		//Ű���� �̺�Ʈ
		void GetKeyboardInput(int *x, int *y, int* blockKind, int* blockStatus);
		//�ܼ� ��ǥ ����
		void gotoxy(int x, int y);
		//��� ����
		void createBlock(int x, int y, int blockKind);
        //����̵�
        void moveBlock(int *x, int *y, string status, int* blockKind, int* blockStatus);
        //��� ��� ����
        void changeBlock(int* x, int* y, int* blockKind, int* blockStatus);
        //����� �浹
        string toouchDownBlock(int* x, int* y);

};