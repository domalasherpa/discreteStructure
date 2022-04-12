#include <stdio.h>
#include <stdlib.h>

char BinarySearch(int *arr, int l, int u, int num){
	
	if(u >= l){
		int mid = ( u + l)/2;
		
		if(arr[mid] == num){
			return 'Y';
		}
		if(arr[mid] > num){
			return BinarySearch(arr, l , mid - 1,  num);
		}
		
		return BinarySearch(arr, mid + 1, u, num);
	}
	
	return 'N';
	
}

void sort(int *arr, int n){
	int i , j;
    for(i = 0; i < n; i++){
        for( j = 0; j < n; j++){
            if(arr[i] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
        }
    }
}

int main(){
    int n, num, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
	
	fflush(stdin); 
    sort(arr, n);
    
    printf("Enter a  number to find: ");
    scanf("%d", &num);

    printf("Aviability: %c" , BinarySearch(arr,0,  n, num));

}
