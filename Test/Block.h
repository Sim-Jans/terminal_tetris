#pragma once
#include <vector>
#include <string>
#include <list>
using namespace std;

class Block {
	private:
        vector<int*> blockVector;

        /*1번 블럭*/
        const int block1[4][4][4] = {
                {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {2, 2, 2, 2},
                                {0, 0, 0, 0}
                },
                {
                                {2, 0, 0, 0},
                                {2, 0, 0, 0},
                                {2, 0, 0, 0},
                                {2, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {2, 2, 2, 2},
                                {0, 0, 0, 0}
                },
                {
                                {2, 0, 0, 0},
                                {2, 0, 0, 0},
                                {2, 0, 0, 0},
                                {2, 0, 0, 0}
                }
        };
        /*2번 블럭*/
        const int block2[4][4][4] = {
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {0, 2, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {0, 2, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {0, 2, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {0, 2, 2, 0},
                                {0, 0, 0, 0}
                }
        };
        /*3번 블럭*/
        const int block3[4][4][4] = {
                {
                                {0, 2, 0, 0},
                                {0, 2, 0, 0},
                                {0, 2, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 2},
                                {0, 2, 0, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 2, 2, 0},
                                {0, 0, 2, 0},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 0, 2, 0},
                                {2, 2, 2, 0},
                                {0, 0, 0, 0}
                }
        };
        /*4번 블럭*/
        const int block4[4][4][4] = {
                {
                                {0, 0, 0, 0},
                                {0, 2, 0, 0},
                                {0, 2, 2, 0},
                                {0, 0, 2, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {2, 2, 0, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 0, 0},
                                {0, 2, 2, 0},
                                {0, 0, 2, 0}
                },
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 0},
                                {2, 2, 0, 0},
                                {0, 0, 0, 0}
                }
        };
        /*5번 블럭*/
        const int block5[4][4][4] = {
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 2},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                { 0, 2, 0, 0},
                                { 2, 2, 0, 0},
                                { 0, 2, 0, 0},
                                { 0, 0, 0, 0}
                },
                {
                                {0, 0, 2, 0},
                                {0, 2, 2, 2},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 2, 0},
                                {0, 0, 2, 2},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0}
                }
        };

	public:
        Block();
        vector<int*> getBlockVector();

};
