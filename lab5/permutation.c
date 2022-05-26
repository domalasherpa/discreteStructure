#include <stdio.h>


void swap(int *array, int index, int i){
    int temp = array[i];
    
    array[i] = array[index];
    array[index] = temp;
}

void print(int *array, int len){
	printf("\nPermutations:");
	
	int i;
    for( i =0; i < len; i++){
        printf("%d ",array[i]);
    }
}

int permute(int *array, int index, const int len){
	int i ;
	static int count;
	
    if(index >= len){
        return 1;
    }
	
	count = index;
	
    for( i = index; i < len ; i++){
	
    //	printf("inside the loop");
        swap(array, index, i);
        
        permute(array, index + 1, len);
		
        //backtrack
        swap(array, index, i);
		
    }
    
    if(count == index){
    	print(array, len );
	}
	

}

int main(){

    int array[] = {1, 2, 3, 4};

   int n =  permute(array, 0, 4);
   
   return 0;
    
}
