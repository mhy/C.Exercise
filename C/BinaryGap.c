// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdbool.h>

static short BitStateFrom(int number, short index)
{
    return !!(number & (1 << index));
}

static int FindMaxGap(int number)
{
    short maxGap = 0;
    short currentGap = 0;
    bool beingCounted = false;

    for(short i = 31 ; i >= 0 ; i--)
    {
        // printf("%d/", BitStateFrom(number, i));
        if(BitStateFrom(number, i))
        {
            if(beingCounted)
            {
                maxGap = currentGap > maxGap ? currentGap : maxGap;
                currentGap = 0;
            }
            else
            {
                beingCounted = true;
            }
        }
        else
        {
            if(beingCounted)
            {
                currentGap++;
            }
        }

    }
    // printf("\n");

    return maxGap;
}

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    return FindMaxGap(N);
}