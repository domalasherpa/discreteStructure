// represent the graph in adjacency matrix
//test its properties
//Reflexive
//Symmetric
// Assymmetric
// Antisymmetric
//transitive

#include <stdio.h>
#include <stdbool.h>

#define n 4

void isReflexive(int mat[][n]){
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(!mat[i][i]){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("It is not Reflexive\n");
    }
    else{
        printf("It is reflexive\n");
    }
}

void issymmetric(int mat[][n]){
    int flag = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                break;
            }
            if(mat[i][j] != mat[j][i]){
                flag = 1;
                break;
            }
        }
    }

    if(flag){
        printf("It is not symmetric.\n");
    }
    else{
        printf("It is symmetric.\n");
    }
}

void isassymmetric(int mat[][n]){


    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(mat[i][j] == mat[j][i] && mat[i][j] != 0){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        printf("It is not assymmetric.\n");
    }
    else{
        printf("It is assymmetric.\n");
    }
}

void isantiymmetric(int mat[][n]){

    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == mat[j][i] && mat[i][j] != 0 && i != j){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        printf("It is not antisymmetric.\n");
    }
    else{
        printf("It is antisymmetric.\n");
        
    }
}

bool checkTransitive(int start, int end, int mat[][n]){
    for(int otherEnd = 0; otherEnd < n; otherEnd++){
        if(mat[end][otherEnd]){
            if(!mat[start][otherEnd]){
                return false;
            }
        }
    }
    return true;

}

void isTransitive(int mat[][n]){
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]){
                if(!checkTransitive(i, j, mat)){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            printf("It is not transitive.\n");
            break;
        }
    }
    if(!flag){
        printf("It is transitive.");
    }
}

int main(){

    int mat[][4] = {{1, 1, 1, 1}, 
                    {0, 0, 0, 1},
                    {1, 1, 0, 0}, 
                    {0, 1, 1, 1}};

    isantiymmetric(mat);
    isassymmetric(mat);
    isReflexive(mat);
    issymmetric(mat);
    isTransitive(mat);

    return 0;
}