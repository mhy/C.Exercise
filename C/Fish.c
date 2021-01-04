// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <string.h>

enum
{
    Direction_Upstream = 0
};

typedef struct
{
    int *size;
    int current;
    int numberOfFishes;
} FishesGoingDown_t;

static char ThereIsAFishGoingDownstream(FishesGoingDown_t *fishes)
{
    return fishes->current > 0;
}

static int PullTheLastest(FishesGoingDown_t *fishes)
{
    int sizeOfTheLatest = fishes->size[--fishes->current];
    return sizeOfTheLatest;
}

static void AddToTheFishery(FishesGoingDown_t *fishes, int sizeOfTheNewFish)
{
    fishes->size[fishes->current++] = sizeOfTheNewFish;
}

int solution(int A[], int B[], int N) {
    // write your code in C99 (gcc 6.2.0)

    FishesGoingDown_t fishesGoingDown = { .size = (int *)malloc(sizeof(int) * N), .current = 0, .numberOfFishes = N };

    int killCounter = 0;
    for(int i = 0 ; i < N ; i++)
    {
        int currentFishSize = A[i];

        if(B[i] == Direction_Upstream)
        {
            while(ThereIsAFishGoingDownstream(&fishesGoingDown))
            {
                killCounter++; //either of them must die
                int sizeOfTheFishGoingDown = PullTheLastest(&fishesGoingDown);
                if(currentFishSize < sizeOfTheFishGoingDown)
                {
                    AddToTheFishery(&fishesGoingDown, sizeOfTheFishGoingDown);
                    break;
                }
            }
        }
        else    //Downstream
        {
            AddToTheFishery(&fishesGoingDown, currentFishSize);
        }
    }

    free(fishesGoingDown.size);

    return N - killCounter;
}