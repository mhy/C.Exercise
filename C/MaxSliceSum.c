// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stdbool.h>

static bool NegativeNumbersKeepShowingUp(int arr[], int max, int current)
{
    return max < 0 && arr[current - 1] < 0 && arr[current] < 0;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int max = A[0];
    int positiveAccumulation = A[0] > 0 ? A[0] : 0;

    for(int i = 1 ; i < N ; i++)
    {
        positiveAccumulation = A[i] + positiveAccumulation > 0 ? A[i] + positiveAccumulation : 0;

        if(NegativeNumbersKeepShowingUp(A, max, i))
        {
            max = A[i] > A[i - 1] ? A[i] : A[i - 1];
        }
        else
        {
            max = max > positiveAccumulation ? max : positiveAccumulation;
        }
    }

    return max;
}