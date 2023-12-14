#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct
{
    int top;
    unsigned capacity;
    int *array;
} Stack;

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function to check precedence of operators
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix)
{
    Stack *stack = createStack(MAX_SIZE);
    int i, k;

    printf("Postfix expression: ");
    for (i = 0, k = -1; infix[i]; ++i)
    {
        if (isalnum(infix[i]))
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                printf("%c", pop(stack));
            }
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                printf("Invalid expression");
                return;
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
            {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
    {
        printf("%c", pop(stack));
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix)
{
    Stack *stack = createStack(MAX_SIZE);
    int i, operand1, operand2;

    for (i = 0; postfix[i]; ++i)
    {
        if (isdigit(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        else
        {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i])
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }

    return pop(stack);
}

int main()
{
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    // 456*+
    printf("\nEnter the postfix expression: ");
    char postfix[MAX_SIZE];
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}