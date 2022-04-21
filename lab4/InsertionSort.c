#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}
int main(){

    int n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    for(int i = 0; i< n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++){
        int temp1 = arr[i];
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            print(&arr[0], n);
            printf("\n");
        }
    }
    free(arr);
    return 0;
}
