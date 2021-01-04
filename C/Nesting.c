// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

enum
{
    EndOfString = '\0'
};

typedef struct
{
    char *data;
    int size;
    int current;
} Stack_t;

static void PushToStack(Stack_t *stack, char ch)
{
    stack->data[stack->current++] = ch;
}

static char PopFromStack(Stack_t *stack)
{
    return stack->data[--stack->current];
}

static char StackIsEmpty(Stack_t *stack)
{
    return stack->current == 0;
}

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)

    int size = 0;
    while(S[size] != EndOfString)
    {
        size++;
    }
    Stack_t stack = { .data = (char *)malloc(sizeof(char) * size), .size = size, .current = 0};

    int i = 0;
    int result = 1;
    while(S[i] != EndOfString)
    {
        if(S[i] == '(')
        {
            PushToStack(&stack, S[i]);
        }
        else
        {
            if(StackIsEmpty(&stack))
            {
                result = 0;
                break;
            }
            else
            {
                PopFromStack(&stack);
            }
        }
        i++;
    }

    char conditionA = StackIsEmpty(&stack);
    char conditionB = result == 1;

    free(stack.data);

    return conditionA && conditionB;
}