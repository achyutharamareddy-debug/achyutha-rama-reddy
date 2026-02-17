#include <stdio.h>
struct student {
    char name[50];
    int marks;
};
int main() {
    int n, i,count=0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student s[n];   
    for(i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter marks of %s: ", s[i].name);
        scanf("%d", &s[i].marks);
    
     if(s[i].marks>=50)
     {   
          count++;
	 }
}
	 printf("\n count %d",count);
    return 0;
}

