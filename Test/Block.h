#pragma once
#include <vector>
#include <string>
#include <list>
using namespace std;

class Block {
	private:
        vector<int*> blockVector;

        /*1�� ����*/
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
        /*2�� ����*/
        const int block2[4][4][4] = {
                {
                                {2, 2, 0, 0},
                                {2, 2, 0, 0},
                                {0, 0, 0, 0},
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
        /*3�� ����*/
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
        /*4�� ����*/
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
        /*5�� ����*/
        const int block5[4][4][4] = {
                {
                                {0, 0, 0, 0},
                                {0, 2, 2, 2},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0}
                },
                {
                                {0, 0, 2, 0},
                                {0, 2, 2, 0},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0}
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