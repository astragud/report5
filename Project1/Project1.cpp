#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

struct element
{
    int data;
};

struct element stack[MAX];
int top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow.\n");
        return;
    }
    top++;
    stack[top].data = data;
}

int pop()
{
    int data;
    if (top < 0)
    {
        printf("Stack underflow.\n");
        return -1;
    }
    data = stack[top].data;
    top--;
    return data;
}

int main()
{
    int i, data, rand_num;
    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        rand_num = rand() % 100 + 1;
        printf("Random number generated: %d\n", rand_num);

        if (rand_num % 2 == 0)
        {
            printf("Pushing %d to the stack.\n", rand_num);
            push(rand_num);
        }

        else
        {
            printf("Popping %d from the stack.\n", pop());
        }
    }

    return 0;
}