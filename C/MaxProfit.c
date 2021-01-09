// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int max = A[0];
    int min = A[0];
    int profit = 0;

    for(int i = 1 ; i < N ; i++)
    {
        max = A[i] > max ? A[i] : max;

        if(A[i] < min)
        {
            min = A[i];
            max = A[i];
        }

        profit = max - min > profit ? max - min : profit;
    }

    return profit;
}