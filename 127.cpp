#include <stdio.h>
void swap(int* x, int* y);
int partition(int a[], int low, int high) {   
    int pivot = a[high];    
    int i = low-1; 
    for (int j = low;j <= high-1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }   
    swap(&a[i + 1], &a[high]);  
    return i + 1;
}
int quickSort(int a[], int low, int high) {
    if (low < high) {      
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
void swap(int* x, int* y ){
    int t = *x;
    *x = *y;
    *y = t;
}
int main() {
    int a[] = {10,11 , 16,2 ,3 ,4,1,8,5 };
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }   
    return 0;
}
