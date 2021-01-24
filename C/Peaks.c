// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stdbool.h>

enum
{
  MaxSize = 100 * 1000 / 2,
  PeakExistsInThePreviousBlock = true,
  StillLookingForAPeak = false
};

static bool TheLastBlockHasAPeak(bool previousBlockHasIt, int lastBlockTouched, int indexOfLastBlock)
{
  return previousBlockHasIt && lastBlockTouched == indexOfLastBlock;
}

static bool BlocksAreValid(
    int numberOfElements,
    int numberOfBlocks,
    int *indicesOfPeaks,
    int numberOfPeaks)
{
  bool result = false;
  if (numberOfElements % numberOfBlocks == 0)
  {
    int unit = numberOfElements / numberOfBlocks;

    int currentBlockIndex = 0;
    for (int i = 0; i < numberOfPeaks; i++)
    {
      int start = currentBlockIndex * unit;
      int end = (1 + currentBlockIndex) * unit - 1;

      if (indicesOfPeaks[i] >= start && indicesOfPeaks[i] <= end)
      {
        result = PeakExistsInThePreviousBlock;
      }
      else if (result)
      {
        currentBlockIndex++;
        i--;
        result = StillLookingForAPeak;
      }
      else
      {
        break;
      }
    }
    result = TheLastBlockHasAPeak(result, currentBlockIndex, numberOfBlocks - 1);
  }

  return result;
}

int solution(int A[], int N)
{
  // write your code in C99 (gcc 6.2.0)
  int indicesOfPeaks[MaxSize] = {0};
  int numberOfPeaks = 0;

  int result = 0;
  if (N >= 3)
  {
    for (int i = 1; i < N - 1; i++)
    {
      if (A[i - 1] < A[i] && A[i] > A[i + 1])
      {
        indicesOfPeaks[numberOfPeaks++] = i;
      }
    }

    if (numberOfPeaks >= 1)
    {
      result = 1;
      for (int numberOfBlocks = numberOfPeaks; numberOfBlocks > 1; numberOfBlocks--)
      {
        if (BlocksAreValid(N, numberOfBlocks, indicesOfPeaks, numberOfPeaks))
        {
          result = numberOfBlocks;
          break;
        }
      }
    }
  }

  return result;
}