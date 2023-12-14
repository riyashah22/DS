#include <stdio.h>

// Define the size of the matrices
#define NUM_RATINGS 3 // You can change this to your desired number of RATINGS

int i, j;

// Function to add two regional party vote matrices using pointers
void AddTwoDestinationRatings(int (*destinationRating)[NUM_RATINGS], int (*destination2Rating)[NUM_RATINGS], int (*resultVotes)[NUM_RATINGS])
{
    for (i = 0; i < NUM_RATINGS; i++)
    {
        for (j = 0; j < NUM_RATINGS; j++)
        {
            resultVotes[i][j] = destinationRating[i][j] + destination2Rating[i][j];
        }
    }
}

// Function to subtract two regional party vote matrices using pointers
void SubtractTwoDestinationRating(int (*destinationRating)[NUM_RATINGS], int (*destination2Rating)[NUM_RATINGS], int (*resultVotes)[NUM_RATINGS])
{
    for (i = 0; i < NUM_RATINGS; i++)
    {
        for (j = 0; j < NUM_RATINGS; j++)
        {
            resultVotes[i][j] = destination2Rating[i][j] - destinationRating[i][j];
        }
    }
}

// Function to display regional party vote matrix
void displayDestinationRatings(int (*destinationRating)[NUM_RATINGS])
{
    for (i = 0; i < NUM_RATINGS; i++)
    {
        for (j = 0; j < NUM_RATINGS; j++)
        {
            printf("%d\t", destinationRating[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int destinationRating[NUM_RATINGS][NUM_RATINGS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int destination2Rating[NUM_RATINGS][NUM_RATINGS] = {
        {5, 15, 25},
        {35, 45, 55},
        {65, 75, 85}};

    int resultAddition[NUM_RATINGS][NUM_RATINGS];
    int resultSubtraction[NUM_RATINGS][NUM_RATINGS];

    printf("Destination Rating Matrix 1:\n");
    displayDestinationRatings(destinationRating);

    printf("\nDestination Rating Matrix 2:\n");
    displayDestinationRatings(destination2Rating);

    // Perform addition and subtraction using the new function names
    AddTwoDestinationRatings(destinationRating, destination2Rating, resultAddition);
    SubtractTwoDestinationRating(destinationRating, destination2Rating, resultSubtraction);

    printf("\nDestination Rating Matrix 1 + Destination Rating Matrix 2:\n");
    displayDestinationRatings(resultAddition);

    printf("\nDestination Rating Matrix 2 - Destination Rating Matrix 1:\n");
    displayDestinationRatings(resultSubtraction);

    return 0;
}