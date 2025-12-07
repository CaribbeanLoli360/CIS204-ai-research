#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Add a new book to the inventory
// Algorithm: Prompt user for book details (title, author, genre, year)
//            Store the book in the next available position in the array
//            Increment the count of books
void addBook(struct Book inventory[], int *count) {
    // TODO: Check if inventory is full (count >= 100) 
    // TODO: Prompt user to enter title, author, genre, and year
    // TODO: Read user input using scanf or fgets
    // TODO: Store the new book in inventory[*count]
    // TODO: Increment *count
    // TODO: Display a confirmation message
        // Check if inventory is full (max 100 books)
        if (*count >= 100) {
            printf("Cannot add book: inventory is full (max 100).\n");
            return;
        }

        // Pointer to the next available book slot
        struct Book *b = &inventory[*count];

        // Prompt the user and read the book details using fgets-based helper
        char buf[64];

        printf("Enter title: ");
        readLine(b->title, sizeof b->title);

        printf("Enter author: ");
        readLine(b->author, sizeof b->author);

        printf("Enter genre: ");
        readLine(b->genre, sizeof b->genre);

        printf("Enter year: ");
        readLine(buf, sizeof buf);
        // Convert to int; if conversion fails, year will be 0
        b->year = atoi(buf);

        // Increment the book count
        (*count)++;

        // Confirmation message
        printf("Book added successfully. Total books: %d\n", *count);
}

// Display all books in the inventory
// Algorithm: Loop through all books in the inventory (from 0 to count)
//            Print each book's details (title, author, genre, year)
void displayBooks(struct Book inventory[], int count) {
    // If there are no books, notify the user
    if (count == 0) {
        printf("No books in the inventory.\n");
        return;
    }

    // Print a header for readability
    printf("\nCurrent Books in Inventory (total: %d):\n", count);
    printf("----------------------------------------------------\n");

    // Loop through each book and print its details
    for (int i = 0; i < count; i++) {
        printf("%d) Title : %s\n", i + 1, inventory[i].title);
        printf("   Author: %s\n", inventory[i].author);
        printf("   Genre : %s\n", inventory[i].genre);
        printf("   Year  : %d\n", inventory[i].year);
        printf("----------------------------------------------------\n");
    }
}

// Helper to read a line from stdin and trim the trailing newline.
void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        // EOF or error; produce an empty string
        if (size > 0) buffer[0] = '\0';
        return;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        // If the buffer did not contain a newline, there may be leftover chars
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

// Remove a book from the inventory by title
// Algorithm: Search for the book with the matching title
//            If found, shift all books after it one position to the left
//            Decrement the count
//            Display a success or not-found message
void removeBook(struct Book inventory[], int *count, char title[]) {
    if (*count == 0) {
        printf("Inventory is empty. Nothing to remove.\n");
        return;
    }

    // Find the book by title
    int idx = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Book titled '%s' not found.\n", title);
        return;
    }

    // Shift books after idx one position to the left
    for (int j = idx; j < (*count) - 1; j++) {
        inventory[j] = inventory[j + 1];
    }

    // Decrement the count
    (*count)--;
    printf("Book '%s' removed successfully. Total books: %d\n", title, *count);
}

// Update a book's information by title
// Algorithm: Search for the book with the matching title
//            If found, prompt user to enter new information
//            Update the book's fields
//            Display a success or not-found message
void updateBook(struct Book inventory[], int count, char title[]) {
    if (count == 0) {
        printf("Inventory is empty. Nothing to update.\n");
        return;
    }

    // Search for the book by title
    int idx = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Book titled '%s' not found.\n", title);
        return;
    }

    // Prompt user for new information and update fields
    printf("Updating book '%s' (leave field empty to keep current value)\n", title);

    // Temporary buffers to read new values
    char buffer[50];

    printf("Enter new title: ");
    scanf(" %49[^\n]", buffer);
    if (strlen(buffer) > 0) {
        strncpy(inventory[idx].title, buffer, sizeof(inventory[idx].title));
        inventory[idx].title[sizeof(inventory[idx].title)-1] = '\0';
    }

    printf("Enter new author: ");
    scanf(" %49[^\n]", buffer);
    if (strlen(buffer) > 0) {
        strncpy(inventory[idx].author, buffer, sizeof(inventory[idx].author));
        inventory[idx].author[sizeof(inventory[idx].author)-1] = '\0';
    }

    printf("Enter new genre: ");
    scanf(" %49[^\n]", buffer);
    if (strlen(buffer) > 0) {
        strncpy(inventory[idx].genre, buffer, sizeof(inventory[idx].genre));
        inventory[idx].genre[sizeof(inventory[idx].genre)-1] = '\0';
    }

    printf("Enter new year (0 to keep current): ");
    int year;
    if (scanf("%d", &year) == 1) {
        if (year != 0) {
            inventory[idx].year = year;
        }
    } else {
        // clear invalid input
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    printf("Book updated successfully.\n");
}

// Search for a book by title and return its index
// Algorithm: Loop through all books in the inventory
//            Compare the title parameter with each book's title
//            If a match is found, return the index
//            If no match is found after checking all books, return -1
int searchBook(struct Book inventory[], int count, char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

