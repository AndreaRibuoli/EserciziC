#include "quiz.h"

int quiz(int x, int y) {
    int r;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }    
    return x;
}    

