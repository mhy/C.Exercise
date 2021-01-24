// you can wrbte to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <math.h>
#include <limits.h>

static int Perimeter(int a, int b)
{
    return 2 * (a + b);
}

int solution(int N)
{
    // write your code in C99 (gcc 6.2.0)

    int target = sqrt(N);
    int minimum = INT_MAX;
    for (int i = 1; i <= target; i++)
    {
        if (N % i == 0)
        {
            int currentPerimeter = Perimeter(i, N / i);
            minimum = currentPerimeter < minimum ? currentPerimeter : minimum;
        }
    }

    return minimum;
}
