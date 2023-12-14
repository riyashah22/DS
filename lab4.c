#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Tourist
{
    char name[50];
    char passport[15];
    float budget;
    struct Tourist *next;
};

// Node for regular queue
struct Node
{
    struct Tourist *data;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

// Node for priority queue
struct PQNode
{
    struct Tourist *data;
    int priority;
    struct PQNode *next;
};

struct PriorityQueue
{
    struct PQNode *front;
};

// Circular Queue
#define MAX_SIZE 5
struct Tourist *circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to create a new Tourist node
struct Tourist *createTourist(char name[], char passport[], float budget)
{
    struct Tourist *newTourist = (struct Tourist *)malloc(sizeof(struct Tourist));
    if (newTourist == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newTourist->name, name);
    strcpy(newTourist->passport, passport);
    newTourist->budget = budget;
    newTourist->next = NULL;
    return newTourist;
}

// Regular Queue Operations
struct Node *newNode(struct Tourist *tourist)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = tourist;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, struct Tourist *tourist)
{
    struct Node *temp = newNode(tourist);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

void dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
}

void displayQueue(struct Queue *queue)
{
    struct Node *temp = queue->front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Tourists in the Queue:\n");
    while (temp != NULL)
    {
        printf("Name: %s | Passport: %s | Budget: %.2f\n", temp->data->name, temp->data->passport, temp->data->budget);
        temp = temp->next;
    }
}

// Priority Queue Operations
struct PQNode *newPQNode(struct Tourist *tourist, int p)
{
    struct PQNode *temp = (struct PQNode *)malloc(sizeof(struct PQNode));
    temp->data = tourist;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

struct PriorityQueue *createPriorityQueue()
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

void enqueuePQ(struct PriorityQueue *pq, struct Tourist *tourist, int p)
{
    struct PQNode *start = pq->front;
    struct PQNode *temp = newPQNode(tourist, p);

    if (pq->front == NULL || p < pq->front->priority)
    {
        temp->next = pq->front;
        pq->front = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority <= p)
        {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

void dequeuePQ(struct PriorityQueue *pq)
{
    if (pq->front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    struct PQNode *temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
}

void displayPQ(struct PriorityQueue *pq)
{
    struct PQNode *temp = pq->front;
    if (temp == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Tourists in the Priority Queue:\n");
    while (temp != NULL)
    {
        printf("Name: %s | Passport: %s | Budget: %.2f | Priority: %d\n", temp->data->name, temp->data->passport, temp->data->budget, temp->priority);
        temp = temp->next;
    }
}

// Circular Queue Operations
bool isFull()
{
    return ((rear + 1) % MAX_SIZE == front);
}

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

void enqueueCircular(struct Tourist *tourist)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    circularQueue[rear] = tourist;
    printf("Enqueued tourist to Circular Queue\n");
}

void dequeueCircular()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    else if (front == rear)
    {
        printf("Dequeued tourist from Circular Queue\n");
        front = rear = -1;
    }
    else
    {
        printf("Dequeued tourist from Circular Queue\n");
        front = (front + 1) % MAX_SIZE;
    }
}

void displayCircularQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Tourists in Circular Queue:\n");
    while (i != rear)
    {
        printf("Name: %s | Passport: %s | Budget: %.2f\n", circularQueue[i]->name, circularQueue[i]->passport, circularQueue[i]->budget);
        i = (i + 1) % MAX_SIZE;
    }
    printf("Name: %s | Passport: %s | Budget: %.2f\n", circularQueue[rear]->name, circularQueue[rear]->passport, circularQueue[rear]->budget);
}

int main()
{
    struct Queue *queue = createQueue();
    struct PriorityQueue *pq = createPriorityQueue();
    int choice;
    char name[50], passport[15];
    float budget;
    int priority;
    int subChoice;
    int subChoicePQ;
    int subChoiceCircular;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Linear Queue (FIFO)\n");
        printf("2. Priority Queue\n");
        printf("3. Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Linear Queue Operations\n");
            do
            {
                printf("1. Enqueue tourist\n");
                printf("2. Dequeue tourist\n");
                printf("3. Display tourists\n");
                printf("4. Exit\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &subChoice);
                switch (subChoice)
                {
                case 1:
                    printf("Enter tourist's name: ");
                    scanf("%s", name);
                    printf("Enter tourist's passport: ");
                    scanf("%s", passport);
                    printf("Enter tourist's budget: ");
                    scanf("%f", &budget);
                    enqueue(queue, createTourist(name, passport, budget));
                    printf("Tourist added to the queue.\n");
                    break;
                case 2:
                    dequeue(queue);
                    printf("Processed tourist.\n");
                    break;
                case 3:
                    displayQueue(queue);
                    break;
                case 4:
                    printf("Exiting the program...\n");
                    exit(0);
                default:
                    printf("Invalid choice\n");
                }
            } while (subChoice != 4);
            break;

        case 2:
            printf("Priority Queue Operations\n");
            do
            {
                printf("1. Enqueue tourist\n");
                printf("2. Dequeue tourist\n");
                printf("3. Display tourists\n");
                printf("4. Exit\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &subChoicePQ);
                switch (subChoicePQ)
                {
                case 1:
                    printf("Enter tourist's name: ");
                    scanf("%s", name);
                    printf("Enter tourist's passport: ");
                    scanf("%s", passport);
                    printf("Enter tourist's budget: ");
                    scanf("%f", &budget);
                    printf("Enter tourist's priority: ");
                    scanf("%d", &priority);
                    enqueuePQ(pq, createTourist(name, passport, budget), priority);
                    printf("Tourist added to the priority queue.\n");
                    break;
                case 2:
                    dequeuePQ(pq);
                    printf("Processed tourist from priority queue.\n");
                    break;
                case 3:
                    displayPQ(pq);
                    break;
                case 4:
                    printf("Exiting the program...\n");
                    exit(0);
                default:
                    printf("Invalid choice\n");
                }
            } while (subChoicePQ != 4);
            break;

        case 3:
            printf("Circular Queue Operations\n");
            do
            {
                printf("1. Enqueue tourist\n");
                printf("2. Dequeue tourist\n");
                printf("3. Display tourists\n");
                printf("4. Exit\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &subChoiceCircular);
                switch (subChoiceCircular)
                {
                case 1:
                    printf("Enter tourist's name: ");
                    scanf("%s", name);
                    printf("Enter tourist's passport: ");
                    scanf("%s", passport);
                    printf("Enter tourist's budget: ");
                    scanf("%f", &budget);
                    enqueueCircular(createTourist(name, passport, budget));
                    break;
                case 2:
                    dequeueCircular();
                    break;
                case 3:
                    displayCircularQueue();
                    break;
                case 4:
                    printf("Exiting the program...\n");
                    exit(0);
                default:
                    printf("Invalid choice\n");
                }
            } while (subChoiceCircular != 4);
            break;

        case 4:
            printf("Exiting the program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
