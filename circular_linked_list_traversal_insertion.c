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

struct Destination *insertFirst(struct Destination *head, const char *name)
{
    struct Destination *ptr = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *p;
    p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    strcpy(ptr->name, name);
    ptr->next = head;
    p->next = ptr;
    head = ptr;
    return head;
}

struct Destination *insertEnd(struct Destination *head, const char *name)
{
    struct Destination *ptr = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *p;
    p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    strcpy(ptr->name, name);
    ptr->next = head;
    p->next = ptr;

    return head;
}

struct Destination *insertInBetween(struct Destination *head, const char *name, int pos)
{
    struct Destination *ptr = (struct Destination *)malloc(sizeof(struct Destination));
    struct Destination *p;
    p = head;

    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }

    strcpy(ptr->name, name);
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Destination *head = NULL;
    char choice;

    do
    {
        printf("Do you want to create a node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            char name[50];
            printf("Enter the name of the destination: ");
            scanf("%s", name);

            if (head == NULL)
            {
                head = (struct Destination *)malloc(sizeof(struct Destination));
                strcpy(head->name, name);
                head->next = head;
            }
            else
            {
                head = insertEnd(head, name);
            }

            displayTour(head);
        }
        else if (choice != 'n' && choice != 'N')
        {
            printf("Invalid choice. Please enter 'y' or 'n'.\n");
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
