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

// Function to delete the first tour from the list
struct TourNode *deleteFirst(struct TourNode *head)
{
    struct TourNode *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Function to delete the last tour from the list
struct TourNode *deleteEnd(struct TourNode *head)
{
    struct TourNode *ptr;
    struct TourNode *p = head;

    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    ptr = p->next;
    while (ptr->next != NULL)
    {
        p = p->next;
        ptr = p->next;
    }
    p->next = NULL;
    free(ptr);

    return head;
}

// Function to delete a tour in between at a specified position
struct TourNode *deleteInBetween(struct TourNode *head, int pos)
{
    int i = 0;
    struct TourNode *ptr;
    struct TourNode *p = head;

    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (pos == 0)
    {
        head = deleteFirst(head);
        return head;
    }

    ptr = p->next;
    while (i < (pos - 2))
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
    struct TourNode *head = NULL;
    struct TourNode *second = NULL;
    struct TourNode *third = NULL;
    struct TourNode *fourth = NULL;

    // Create nodes for tour destinations
    head = (struct TourNode *)malloc(sizeof(struct TourNode));
    second = (struct TourNode *)malloc(sizeof(struct TourNode));
    third = (struct TourNode *)malloc(sizeof(struct TourNode));
    fourth = (struct TourNode *)malloc(sizeof(struct TourNode));

    // Initialize tour destinations
    strcpy(head->destination, "Paris");
    head->days = 3;
    head->next = second;

    strcpy(second->destination, "Tokyo");
    second->days = 5;
    second->next = third;

    strcpy(third->destination, "New York");
    third->days = 4;
    third->next = fourth;

    strcpy(fourth->destination, "Rome");
    fourth->days = 2;
    fourth->next = NULL;

    char choice;
    do
    {
        // Print the initial tour list
        tourTraversal(head);

        printf("Do you want to delete a node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            // Check if the list is empty before attempting deletion
            if (head == NULL)
            {
                printf("Linked list is empty. Cannot delete.\n");
            }
            else
            {
                // Delete a tour in between at a specified position
                int position;
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                head = deleteInBetween(head, position);
                // Print the updated tour list
                tourTraversal(head);
            }
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
