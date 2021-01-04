// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

static int Leader(int arr[], int numberOfArr)
{
    int candidate = arr[0];
    int counter = 1;
    for(int i = 1 ; i < numberOfArr ; i++)
    {
        if(arr[i] == candidate)
        {
            counter++;
        }
        else
        {
            counter = counter > 0 ? counter - 1 : 0;
            if(counter == 0)
            {
                candidate = arr[i];
                counter = 1;
            }
        }
    }

    if(counter > 0)
    {
        counter = 0;
        for(int i = 0 ; i < numberOfArr ; i++)
        {
            if(arr[i] == candidate)
            {
                counter++;
            }
        }
    }

    return counter > numberOfArr / 2 ? candidate : 0;
}

static void PopulateCountOfLeaders(int leader, int *countOfLeaders, int *arr, int numberOfArr)
{
    int counter = 0;
    for(int i = 0 ; i < numberOfArr ; i++)
    {
        if(arr[i] == leader)
        {
            countOfLeaders[i] = ++counter;
        }
        else
        {
            countOfLeaders[i] = counter;
        }
    }
}

static char ValidateLeader(int leader, int *countOfLeaders, int from, int to)
{
    char result = 0;
    if(from == 0)
    {
        result = countOfLeaders[to] > (to + 1) / 2;
    }
    else
    {
       result = countOfLeaders[to] - countOfLeaders[from - 1] > (to - from + 1) / 2;
    }
    return result;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int leader = Leader(A, N);
    // printf("%d", leader);

    int *countOfLeaders = (int *)malloc(sizeof(int) * N);
    PopulateCountOfLeaders(leader, countOfLeaders, A, N);
    // for(int i = 0 ; i < N ; i++)
    // {
    //     printf("%d, ", countOfLeaders[i]);
    // }

    int numberOfEquiLeaders = 0;
    for(int i = 0 ; i < N ; i++)
    {
        // printf("%d : %d, %d\n", i, ValidateLeader(leader, countOfLeaders, 0, i), ValidateLeader(leader, countOfLeaders, i + 1, N - 1));
        if(ValidateLeader(leader, countOfLeaders, 0, i) && ValidateLeader(leader, countOfLeaders, i + 1, N - 1))
        {
            numberOfEquiLeaders++;
        }
    }

    return numberOfEquiLeaders;
}