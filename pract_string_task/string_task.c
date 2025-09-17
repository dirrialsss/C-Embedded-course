#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to shuffle characters in our string
void shuffle(char str[], int len) {
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
int main() {
    char input[100];
    int len = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Keeping only ASCII characters and remove newline '\n'
    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if ((unsigned char)input[i] <= 127) {
            input[len++] = input[i];
        }
        i++;
    }
    // Remove \n
    input[len] = '\0';
    //different random sequences each time program runs
    srand(time(NULL)); // init random
    //shuffle function
    shuffle(input, len);

    printf("Shuffled string: %s\n", input);

    return 0;
}
