#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TourNode
{
    char destination[50];
    int days;
    struct TourNode *prev;
    struct TourNode *next;
};

void tourTraversal(struct TourNode *head)
{
    struct TourNode *ptr = head;
    printf("Destination: %s, Days: %d\n", ptr->destination, ptr->days);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        printf("Destination: %s, Days: %d\n", ptr->destination, ptr->days);
    }
    printf("---------------------\n");
}

struct TourNode *insertAtFirst(struct TourNode *head, char destination[], int days)
{
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;

    strcpy(ptr->destination, destination);
    ptr->days = days;

    head = ptr;
    return head;
}

struct TourNode *insertInBetween(struct TourNode *head, char destination[], int days, int pos)
{
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *p;
    ptr->prev = NULL;
    ptr->next = NULL;
    strcpy(ptr->destination, destination);
    ptr->days = days;

    p = head;
    int i = 1;
    while (i < (pos - 1))
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    ptr->next->prev = ptr;

    return head;
}

struct TourNode *insertAtEnd(struct TourNode *head, char destination[], int days)
{
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *p = (struct TourNode *)malloc(sizeof(struct TourNode));
    ptr->prev = NULL;
    ptr->next = NULL;
    strcpy(ptr->destination, destination);
    ptr->days = days;

    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

struct TourNode *createNode(struct TourNode *head)
{
    while (1)
    {
        tourTraversal(head);

        char choice;
        printf("\nDo you want to create a node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            char destination[50];
            int days;

            printf("Enter destination: ");
            scanf("%s", destination);

            printf("Enter days: ");
            scanf("%d", &days);

            // Add the new node at the end of the list
            head = insertAtFirst(head, destination, days);
            printf("Node created successfully.\n");
        }
        else if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    }

    return head;
}

int main()
{
    struct TourNode *n1 = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *n2 = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *n3 = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *n4 = (struct TourNode *)malloc(sizeof(struct TourNode));

    strcpy(n1->destination, "Paris");
    n1->days = 3;
    n1->prev = NULL;
    n1->next = n2;

    strcpy(n2->destination, "Tokyo");
    n2->days = 5;
    n2->prev = n1;
    n2->next = n3;

    strcpy(n3->destination, "New York");
    n3->days = 4;
    n3->prev = n2;
    n3->next = n4;

    strcpy(n4->destination, "Rome");
    n4->days = 2;
    n4->prev = n3;
    n4->next = NULL;

    tourTraversal(n1);
    n1 = createNode(n1);
    tourTraversal(n1);

    return 0;
}
