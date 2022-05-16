#include <stdio.h>
#include <stdlib.h>

int i, row, col1, col2; //row2 == col1

void mat_join(int mat1[], int mat2[]){

    printf("\nMatrix Join: \n");
	for(i= 0; i < (row * col1); i++){
        if(mat1[i] || mat2[i]){
            printf("1\t");
        }
        else{
            printf("0\t");
        }
        if((i + 1) % col1 == 0){
            printf("\n");
        }
    }

}

void mat_meet(int mat1[], int mat2[]){
    printf("\nMatrix Meet: \n");
    for(i= 0; i < (row * col1); i++){
        if(mat1[i] && mat2[i]){
            printf("1\t");
        }
        else{
            printf("0\t");
        }
        if((i + 1) % col1 == 0){
            printf("\n");
        }
    }
}


void mat_product(int mat1[], int mat2[]){
    int flag = 0, j, k;
    printf("\nMatrix product: \n");
    for(i= 0; i < row; i++){
        for(j = 0; j < col2; j++){
            for(k = 0; k < col1; k++){
                if(mat1[i * col1 + k] * mat2[j + k * col1]){
                    flag = 1;
                    break;
                }
            
            }
            if(flag){
                printf("1\t");
            }
            else{
                printf("0\t");
            }
            flag = 0;
        }
        printf("\n");
        
    }
}

int main(){

    int *mat1= (int *)malloc(sizeof(int) * row * col1);
    int *mat2 = (int *)malloc(sizeof(int) * col1 * col2);

    printf("Enter row and col fpr first mat: ");
    scanf("%d %d", &row , &col1);

    printf("Entert the col for second matrix: \n");
    scanf("%d", &col2);

    printf("Enter the first Matrix: \n");
    for( i = 0;  i < (row * col1); i++){
        scanf("%d", &mat1[i]);
    }

    printf("Enter the second Matrix: \n");
    for(i = 0; i < (col1 * col2); i++){
        scanf("%d", &mat2[i]);
    }

    mat_join(mat1, mat2);
    mat_meet(mat1, mat2);
    mat_product(mat1, mat2);
	
	return 0;
    
}
