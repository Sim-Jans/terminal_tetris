#include "Block.h"


Block::Block() {
    int* block1 = (int*)this->block1;
    int* block2 = (int*)this->block2;
    int* block3 = (int*)this->block3;
    int* block4 = (int*)this->block4;
    int* block5 = (int*)this->block5;

    vector<int*> blockVector(5);

    blockVector[0] = block1;
    blockVector[1] = block2;
    blockVector[2] = block3;
    blockVector[3] = block4;
    blockVector[4] = block5;

    this->blockVector = blockVector;
    
}

vector<int*> Block::getBlockVector() {
    return this->blockVector;
}