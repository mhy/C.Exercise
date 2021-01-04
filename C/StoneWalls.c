// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stdlib.h>

typedef unsigned int HeightType_t;

typedef struct
{
    HeightType_t *height;
    int maxNumberOfHeights;
    int currentIndex;
} Heights_t;

static void Push(Heights_t *heights, HeightType_t h)
{
    heights->height[heights->currentIndex++] = h;
}

static HeightType_t Pop(Heights_t *heights)
{
    HeightType_t returnValue = 0;
    if(heights->currentIndex != 0)
    {
        returnValue = heights->height[--heights->currentIndex];
    }
    return returnValue;
}

static HeightType_t MatchingHeightFound(Heights_t *heights, HeightType_t toFind)
{
    HeightType_t height = Pop(heights);
    while(height != 0)
    {
        if(height == toFind)
        {
            break;
        }
        else if(height < toFind)
        {
            Push(heights, height);
            height = 0;
            break;
        }
        height = Pop(heights);
    }

    return height;
}

int solution(int H[], int N)
{
    // write your code in C99 (gcc 6.2.0)
    Heights_t heights = 
    { 
        .height = (HeightType_t *)malloc(sizeof(HeightType_t) * N),
        .maxNumberOfHeights = N, 
        .currentIndex = 0
    };

    //count the first stone
    int counter = 1;
    Push(&heights, H[0]);

    //continue counting if there are more
    if(N > 1)
    {
        for(int i = 1 ; i < N ; i++)
        {
            if(H[i] > H[i - 1])
            {
                counter++;
                Push(&heights, H[i]);
            }
            else if(H[i - 1] > H[i])
            {
                HeightType_t storedHeight = MatchingHeightFound(&heights, H[i]);
                if(storedHeight == 0)
                {
                    counter++;
                }
                Push(&heights, H[i]);
            }
        }
    }

    return counter;
}

int main(int argc, char **argv)
{
  int test[] = {8, 8, 5, 7, 9, 8, 7, 4, 8};
  solution(test, sizeof(test) / sizeof(int));
}