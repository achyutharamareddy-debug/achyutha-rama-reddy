#include <stdio.h>

// Define structure
struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    // Declare structure variablesN
    struct Student s1, s2;

    // Input values for first structure
    printf("Enter Roll Number: ");
    scanf("%d", &s1.roll);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("Enter Marks: ");
    scanf("%f", &s1.marks);

    // Copy s1 into s2
    s2 = s1;

    // Display copied values
    printf("\nCopied Details:\n");
    printf("Roll Number: %d\n", s2.roll);
    printf("Name: %s\n", s2.name);
    printf("Marks: %.2f\n", s2.marks);

    return 0;
}
