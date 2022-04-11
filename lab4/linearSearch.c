#include <stdio.h>
#define n 10

char linearSearch(int *arr, int num ){
    static int i;

    if(i > n){
        return 'N';
    }
    if(arr[i] == num){
        return 'Y';
    }
    i++;
    return linearSearch(arr, num);
}

int main(){

    int arr[n] = {0, 2, 4, 5, 6, 23, 6, 75, 29, 65} ;
    int num;

    printf("Enter the number to find: ");
    scanf("%d", &num);

    printf("Aviability: %c", linearSearch(arr, num));


    return 0;
}