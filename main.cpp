#include "Snake.h"



int main() {
    srand(time(NULL));
    Snake sn;
    while (sn.windowStat())
    {
        sn.update();

        sn.render();
    }
}
