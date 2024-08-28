#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEATS 10
#define MAX_NAME_LENGTH 50

typedef struct 
{
    int seatNumber;
    char name[MAX_NAME_LENGTH];
    int age;
    int isBooked;
} Seat;

typedef struct 
{
    char title[MAX_NAME_LENGTH];
    char genre[MAX_NAME_LENGTH];
    int releaseYear;
    Seat seats[MAX_SEATS];
} Movie;


void displaySeats(const Movie* movie)
{
    printf("\n--- %s ---\n", movie->title);
    printf("Genre: %s\n", movie->genre);
    printf("Release Year: %d\n\n", movie->releaseYear);
    printf("Available Seats:\n");
    printf("----------------\n");
    printf("Seat Number Status\n");
    printf("----------------\n");
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (!movie->seats[i].isBooked)
        {
            printf("%d Available\n", movie->seats[i].seatNumber);
        }
    }
    printf("----------------\n");
}


void bookTicket(Movie* movie)
{
    int seatNumber;
    char name[MAX_NAME_LENGTH];
    int age;
    printf("Enter the seat number: ");
    scanf("%d", &seatNumber);
    if (seatNumber < 1 || seatNumber > MAX_SEATS)
    {
        printf("Invalid seat number!\n");
        return;
    }
    Seat* selectedSeat = &movie->seats[seatNumber - 1];
    if (selectedSeat->isBooked)
    {
        printf("Sorry, the seat is already booked.\n");
        return;
    }
    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    printf("Enter your age: ");
    scanf("%d", &age);

    selectedSeat->seatNumber = seatNumber;
    strcpy(selectedSeat->name, name);
    selectedSeat->age = age;
    selectedSeat->isBooked = 1;
    printf("Ticket booked successfully!\n");
}


int main()
{
    Movie movie;
    strcpy(movie.title, "Avengers: Endgame");
    strcpy(movie.genre, "Sci-Fi");
    movie.releaseYear = 2019;
    for (int i = 0; i < MAX_SEATS; i++)
    {
        movie.seats[i].seatNumber = i + 1;
        movie.seats[i].isBooked = 0;
    }
    int choice;
    do
    {
        displaySeats(&movie);
        printf("\nMenu:\n");
        printf("1. Book a Ticket\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                bookTicket(&movie);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 2);
    return 0;
}