#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Inventory array and counter
    struct Book inventory[100];
    int count = 0;

    // User interaction variables
    int choice = 0;
    char title[50];
    int running = 1;

    while (running) {
        // Display menu
        printf("\n========== Book Inventory System ==========""\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Search for a book\n");
        printf("4. Update a book\n");
        printf("5. Remove a book\n");
        printf("6. Exit the program\n");
        printf("==========================================\n");

        // Read menu choice safely
        printf("Enter your choice (1-6): ");
        char linebuf[32];
        readLine(linebuf, sizeof linebuf);
        choice = atoi(linebuf);

        switch (choice) {
            case 1:
                addBook(inventory, &count);
                break;

            case 2:
                displayBooks(inventory, count);
                break;

            case 3: {
                printf("Enter the title to search: ");
                readLine(title, sizeof title);
                int result = searchBook(inventory, count, title);
                if (result != -1) {
                    printf("Book found at position %d\n", result);
                } else {
                    printf("Book not found\n");
                }
                break;
            }

            case 4:
                printf("Enter the title of the book to update: ");
                readLine(title, sizeof title);
                updateBook(inventory, count, title);
                break;

            case 5:
                printf("Enter the title of the book to remove: ");
                readLine(title, sizeof title);
                removeBook(inventory, &count, title);
                break;

            case 6:
                running = 0;
                printf("Thank you for using the Book Inventory System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
