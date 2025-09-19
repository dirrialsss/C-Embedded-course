#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Book structure
struct Book {
    char title[50];
    double price;
    int pages;
    char language[50];
    double weight;
    int year;
    struct Book* next;
};
// Function to create a new book
struct Book* createBook(char title[], double price, int pages,
                       char language[], double weight, int year) {
    struct Book* newBook = malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}
// Function to add a book to the end of the list
void addBook(struct Book** head, struct Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
        return;
    }
    struct Book* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Adding new book to the end
    current->next = newBook;
}
// Function to display all books
void printBooks(struct Book* head) {
    struct Book* current = head;
    int count = 1;
    printf("HARRY POTTER BOOK SERIES\n\n");
    while (current != NULL) {
        printf("    Book %d:\n", count);
        printf("  Title: %s\n", current->title);
        printf("  Price: %.2f $\n", current->price);
        printf("  Pages: %d\n", current->pages);
        printf("  Language: %s\n", current->language);
        printf("  Weight: %.2f g\n", current->weight);
        printf("  Year: %d\n", current->year);
        printf("---------------------------\n");
        current = current->next;
        count++;
    }
}
// Function to free allocated memory
void freeList(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    struct Book* head = NULL;
    // Add Harry Potter books to the list
    addBook(&head, createBook("Harry Potter and the Philosopher's Stone", 11.25, 223, "English", 287.5, 1997));
    addBook(&head, createBook("Harry Potter and the Chamber of Secrets", 13.75, 251, "English", 315.0, 1998));
    addBook(&head, createBook("Harry Potter and the Prisoner of Azkaban", 13.75, 317, "English", 350.8, 1999));
    addBook(&head, createBook("Harry Potter and the Goblet of Fire", 14.99, 636, "English", 610.3, 2000));
    addBook(&head, createBook("Harry Potter and the Order of the Phoenix", 14.99, 766, "English", 720.1, 2003));
    addBook(&head, createBook("Harry Potter and the Half-Blood Prince", 14.99, 607, "English", 590.6, 2005));
    addBook(&head, createBook("Harry Potter and the Deathly Hallows", 14.99, 607, "English", 595.4, 2007));
    printBooks(head);
    freeList(head);
    return 0;
}