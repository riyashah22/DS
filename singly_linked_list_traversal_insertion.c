#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a tour node
struct TourNode
{
    char destination[50];
    int days;
    struct TourNode *next;
};

// Function to traverse and print the tour list
void tourTraversal(struct TourNode *ptr)
{
    while (ptr != NULL)
    {
        printf("Destination: %s, Days: %d\n", ptr->destination, ptr->days);
        ptr = ptr->next;
    }
    printf("------------------\n");
}

// Function to insert a tour at the beginning of the list
struct TourNode *insertFirst(struct TourNode *head, char destination[], int days)
{
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    strcpy(ptr->destination, destination);
    ptr->days = days;
    ptr->next = head;
    head = ptr;
    return head;
}

// Function to insert a tour at the end of the list
struct TourNode *insertEnd(struct TourNode *head, char destination[], int days)
{
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *p = head;
    strcpy(ptr->destination, destination);
    ptr->days = days;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Function to insert a tour in between the list at a specified position
struct TourNode *insertInBetween(struct TourNode *head, char destination[], int days, int pos)
{
    int i = 1;
    struct TourNode *ptr = (struct TourNode *)malloc(sizeof(struct TourNode));
    struct TourNode *p = head;

    while (i < (pos - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    strcpy(ptr->destination, destination);
    ptr->days = days;

    return head;
}

int main()
{
    struct TourNode *head = NULL; // Initialize head to NULL
    char userChoice;

    do
    {
        printf("Do you want to create a node? (y/n): ");
        scanf(" %c", &userChoice);

        if (userChoice == 'y' || userChoice == 'Y')
        {
            char destination[50];
            int days;

            printf("Enter destination: ");
            scanf("%s", destination);

            printf("Enter number of days: ");
            scanf("%d", &days);

            // Insert a tour at the end
            head = insertFirst(head, destination, days);
            tourTraversal(head);
        }
    } while (userChoice == 'y' || userChoice == 'Y');

    return 0;
}
