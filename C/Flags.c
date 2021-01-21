// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdbool.h>

enum
{
  MaxNumberOfPeaks = 400000 / 2
};

static bool PeakIsMade(int *dots, int index)
{
  return dots[index - 1] < dots[index] && dots[index] > dots[index + 1];
}

static bool CapableOf(int N, int counter)
{
  return 1 + (counter * (counter - 1)) <= N;
}

static bool FlagsArePossible(int *peaks, int numberOfPeaks, int numberOfFlags)
{
  int flagUsed = 1;
  int diffSum = 0;

  bool result = false;
  for (int i = 0; i < numberOfPeaks - 1; i++)
  {
    int diff = peaks[i + 1] - peaks[i];
    diffSum += diff;

    if (diff >= numberOfFlags || diffSum >= numberOfFlags)
    {
      flagUsed++;
      diffSum = 0;
    }

    if (flagUsed >= numberOfFlags)
    {
      result = true;
      break;
    }
  }

  return result;
}

int solution(int A[], int N)
{
  // write your code in C99 (gcc 6.2.0)}
  int result = 0;

  int peaks[MaxNumberOfPeaks] = {0};
  int counter = 0;
  int maximumPossibleFlags = 0;

  if (N >= 3)
  {
    for (int i = 1; i < N - 1; i++)
    {
      if (PeakIsMade(A, i))
      {
        peaks[counter++] = i;

        if (CapableOf(N, counter))
        {
          maximumPossibleFlags += 1;
        }
      }
    }

    if (counter == 1)
    {
      result = 1;
    }
    else if (counter > 1)
    {
      for (int i = 0; i < maximumPossibleFlags; i++)
      {
        if (FlagsArePossible(peaks, counter, result + 1))
        {
          result++;
        }
        else
        {
          break;
        }
      }
    }
  }

  return result;
}