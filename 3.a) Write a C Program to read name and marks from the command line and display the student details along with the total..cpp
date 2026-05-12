#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, total = 0;

    // Check for correct number of arguments
    if (argc < 3) {
        printf("Usage: %s Name Marks...\n", argv[0]);
        return 1;
    }

    // Display student name
    printf("Student Name : %s\n", argv[1]);

    // Read marks and calculate total
    printf("Marks : ");
    for (i = 2; i < argc; i++) {
        int mark = atoi(argv[i]);
        printf("%d ", mark);
        total += mark;
    }

    // Display total
    printf("\nTotal Marks : %d\n", total);

    return 0;
}
