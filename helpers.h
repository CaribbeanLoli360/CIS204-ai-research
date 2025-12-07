#ifndef HELPERS_H
#define HELPERS_H

// Book struct definition
struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int year;
};

// Function prototypes
void addBook(struct Book inventory[], int *count);
void displayBooks(struct Book inventory[], int count);
void removeBook(struct Book inventory[], int *count, char title[]);
void updateBook(struct Book inventory[], int count, char title[]);
int searchBook(struct Book inventory[], int count, char title[]);

// Read a line of input from stdin into buffer and remove trailing newline
// size is the buffer size (including terminating null)
void readLine(char *buffer, int size);

#endif
