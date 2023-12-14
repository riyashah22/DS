#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Destination
{
    char name[50];
    struct Destination *next;
};

void displayTour(struct Destination *head)
{
    struct Destination *ptr = head;

    while (ptr->next != head)
    {
        printf("Destination: %s\n", ptr->name);
        ptr = ptr->next;
    }
    printf("Destination: %s\n", ptr->name);
    printf("-----------------\n");
}

struct Destination *deleteFirst(struct Destination *head)
{
    struct Destination *p;
    struct Destination *ptr;
    p = head;
    head = head->next;
    free(p);
    return head;
}

struct Destination *deleteEnd(struct Destination *head)
{
    struct Destination *p;
    struct Destination *ptr;
    p = head;
    ptr = p->next;
    while (ptr->next != head)
    {
        p = p->next;
        ptr = ptr->next;
    }

    free(ptr);
    p->next = head;

    return head;
}

struct Destination *deleteInBetween(struct Destination *head, int pos)
{
    int i = 1;
    struct Destination *ptr;
    struct Destination *p = head;
    ptr = p->next;
    while (i < (pos - 1))
    {
        p = p->next;
        ptr = p->next;
        i++;
    }
    p->next = ptr->next;
    free(ptr);

    return head;
}

int main()
{
    struct Destination *head = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *second = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *third = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *fourth = (struct Destination *)malloc(sizeof(struct Destination));

    strcpy(head->name, "Paris");
    head->next = second;

    strcpy(second->name, "Rome");
    second->next = third;

    strcpy(third->name, "Tokyo");
    third->next = fourth;

    strcpy(fourth->name, "New York");
    fourth->next = head;

    char choice;

    while (1)
    {
        displayTour(head);

        char choice;
        printf("\nDo you want to delete a node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            int position;
            printf("\nEnter the position of the destination which needs to be deleted: ");
            scanf("%d", &position);

            head = deleteInBetween(head, position);
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

    return 0;
}
