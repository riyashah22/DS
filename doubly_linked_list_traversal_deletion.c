#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Destination
{
    char name[50];
    struct Destination *prev;
    struct Destination *next;
};

void displayTour(struct Destination *head)
{
    struct Destination *ptr = head;
    printf("Destinations: ");
    while (ptr != NULL)
    {
        printf("%s ", ptr->name);
        ptr = ptr->next;
    }
}

struct Destination *removeFirstDestination(struct Destination *head)
{
    if (head == NULL)
    {
        printf("Tour is empty.\n");
        return NULL;
    }

    struct Destination *newHead = head->next;
    if (newHead != NULL)
    {
        newHead->prev = NULL;
    }
    free(head);
    return newHead;
}

struct Destination *removeDestinationInBetween(struct Destination *head, int pos)
{
    struct Destination *ptr = NULL;
    struct Destination *temp = head;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return head;
    }

    ptr = temp->prev;
    if (temp->next != NULL)
    {
        ptr->next = temp->next;
        temp->next->prev = ptr;
    }
    free(temp);
    return head;
}

struct Destination *removeLastDestination(struct Destination *head)
{
    if (head == NULL)
    {
        printf("Tour is empty.\n");
        return NULL;
    }

    struct Destination *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL)
    {
        ptr->prev->next = NULL;
    }
    free(ptr);
    return head;
}

int main()
{
    struct Destination *destination1 = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *destination2 = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *destination3 = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *destination4 = (struct Destination *)malloc(sizeof(struct Destination));

    strcpy(destination1->name, "Paris");
    destination1->prev = NULL;
    destination1->next = destination2;

    strcpy(destination2->name, "Rome");
    destination2->prev = destination1;
    destination2->next = destination3;

    strcpy(destination3->name, "Tokyo");
    destination3->prev = destination2;
    destination3->next = destination4;

    strcpy(destination4->name, "Italy");
    destination4->prev = destination3;
    destination4->next = NULL;

    while (1)
    {
        displayTour(destination1);

        char choice;
        printf("\nDo you want to delete a node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            int pos;
            printf("\nEnter the position of the node to be deleted: ");
            scanf("%d", &pos);
            destination1 = removeDestinationInBetween(destination1, pos);
        }
        else if (choice == 'n' || choice == 'N')
        {
            printf("Have a Good Day.\n");
            exit(1);
        }
        else
        {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}
