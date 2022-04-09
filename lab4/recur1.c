#include <stdio.h>


int recur(int a, int n){
    if(n == 0){
        return 1;
    }
    return a * recur(a, n - 1);
}

int main(){

    //a^0 = 1
    // a^1 = a * a^0
    int a;
    int n;

    printf("Enter Base and Exponent: ");
    scanf("%d %d", &a, &n);

    printf("On recursion %d^%d = %d", a, n, recur(a, n));

    return 0;
}