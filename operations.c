#include <stdio.h>
#include <string.h>

#define MAX_DESTINATIONS 100
#define DEST_NAME_LENGTH 50

// Structure to represent a tourist destination
struct Destination
{
    char name[DEST_NAME_LENGTH];
    int rating;
    float distance;
};

// Function to insert a destination into the array
void insertDestination(struct Destination destinations[MAX_DESTINATIONS], int *numDestinations, const char *name, int rating, float distance)
{
    if (*numDestinations < MAX_DESTINATIONS)
    {
        struct Destination *dest = &destinations[*numDestinations];
        strncpy(dest->name, name, DEST_NAME_LENGTH - 1);
        dest->name[DEST_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        dest->rating = rating;
        dest->distance = distance;
        (*numDestinations)++;
        printf("Destination added.\n");
    }
    else
    {
        printf("Maximum number of destinations reached.\n");
    }
}

// Function to delete a destination from the array
void deleteDestination(struct Destination destinations[MAX_DESTINATIONS], int *numDestinations, const char *name)
{
    for (int i = 0; i < *numDestinations; i++)
    {
        if (strcmp(destinations[i].name, name) == 0)
        {
            for (int j = i; j < *numDestinations - 1; j++)
            {
                destinations[j] = destinations[j + 1];
            }
            (*numDestinations)--;
            printf("Destination deleted.\n");
            return;
        }
    }
    printf("Destination not found.\n");
}

// Function to perform a linear search for a destination by name
int linearSearch(const struct Destination destinations[MAX_DESTINATIONS], int numDestinations, const char *name)
{
    for (int i = 0; i < numDestinations; i++)
    {
        if (strcmp(destinations[i].name, name) == 0)
        {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// Function to update a destination
void updateDestination(struct Destination destinations[MAX_DESTINATIONS], int numDestinations, const char *name, int newRating, float newDistance)
{
    for (int i = 0; i < numDestinations; i++)
    {
        if (strcmp(destinations[i].name, name) == 0)
        {
            destinations[i].rating = newRating;
            destinations[i].distance = newDistance;
            printf("Destination updated.\n");
            return;
        }
    }
    printf("Destination not found.\n");
}

// Function to display all destinations
void displayDestinations(const struct Destination destinations[MAX_DESTINATIONS], int numDestinations)
{
    printf("Tourist Destinations:\n");
    for (int i = 0; i < numDestinations; i++)
    {
        printf("Name: %s, Rating: %d, Distance: %.2f km\n", destinations[i].name, destinations[i].rating, destinations[i].distance);
    }
}

int main()
{
    struct Destination destinations[MAX_DESTINATIONS];
    int numDestinations = 0;

    int choice;
    char name[DEST_NAME_LENGTH];
    int rating;
    float distance;

    while (1)
    {
        printf("\nTour Planner Menu:\n");
        printf("1. Insert Destination\n");
        printf("2. Delete Destination\n");
        printf("3. Update Destination\n");
        printf("4. Search for a Destination\n");
        printf("5. Display Destinations\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice)
        {
        case 1:
            printf("Enter the name of the destination: ");
            fgets(name, DEST_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline
            printf("Enter the rating: ");
            scanf("%d", &rating);
            printf("Enter the distance: ");
            scanf("%f", &distance);
            getchar(); // Consume newline character
            insertDestination(destinations, &numDestinations, name, rating, distance);
            break;

        case 2:
            printf("Enter the name of the destination to delete: ");
            fgets(name, DEST_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline
            deleteDestination(destinations, &numDestinations, name);
            break;

        case 3:
            printf("Enter the name of the destination to update: ");
            fgets(name, DEST_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline
            printf("Enter the new rating: ");
            scanf("%d", &rating);
            printf("Enter the new distance: ");
            scanf("%f", &distance);
            getchar(); // Consume newline character
            updateDestination(destinations, numDestinations, name, rating, distance);
            break;

        case 4:
            printf("Enter the name of the destination to search: ");
            fgets(name, DEST_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the trailing newline
            if (linearSearch(destinations, numDestinations, name))
            {
                printf("Destination found.\n");
            }
            else
            {
                printf("Destination not found.\n");
            }
            break;

        case 5:
            displayDestinations(destinations, numDestinations);
            break;

        case 6:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
