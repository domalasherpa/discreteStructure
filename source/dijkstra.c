#include <stdio.h>
#define inf 1000
#define n 6

int distance[n];

void init(){
    for(int i = 0 ;i < n ; i++){
        distance[i] = inf;
    }
    distance[0] = 0;
}

void findShortest(int current, int mat[][n]){
    for(int node = 0; node < n ; node++){
        if(mat[current][node]){
            if((distance[current] + mat[current][node]) < distance[node]){
                distance[node] = distance[current] + mat[current][node];
                printf("Distance:from %d to %d is %d\n", current, node, distance[node]);
            }
        }
    }
}

//to find the shortest path from a to all the points
void dijkstra(int mat[][n]){
    init();
    for(int i= 0; i < n - 1; i++){
        for(int i = 0; i < n - 1 ;i++){
            findShortest(i, mat);
        }
        
    }
}


int main(){

    int mat1[][6] = {{0, 2, 3, 0, 0, 0},
                     {2, 0, 0, 5, 2, 0},
                     {3, 0, 0, 0, 5, 0}, 
                     {0, 5, 0, 1, 0, 2},
                     {0, 2, 5, 1, 0, 4}};
                     
    
    dijkstra(mat1);
    for(int i = 0; i < n; i++){
        printf("%d\n", distance[i]);
    }


    return 0;
}