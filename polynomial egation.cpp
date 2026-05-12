#include <stdio.h>
#include<stdlib.h>
int main() {
    int n, i;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    int coeff[n + 1];

    printf("Enter coefficients from highest degree to constant:\n");
    for(i = 0; i <= n; i++) {
        scanf("%d", &coeff[i]);
    }

    printf("Polynomial equation: P(x) = ");

    for(i = 0; i <= n; i++) {
        if(coeff[i] == 0) continue; 

        int power = n - i;

    
        if(i != 0 && coeff[i] > 0) {
            printf("+ ");
        }

        
        if(power == 0) {
            printf("%d ", coeff[i]);
        } else if(power == 1) {
            printf("%dx ", coeff[i]);
        } else {
            printf("%dx^%d ", coeff[i], power);
        }
    }

    printf("\n");

    return 0;
}
