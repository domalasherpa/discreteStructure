#include <stdio.h>

long long int fibonacci(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n * fibonacci(n -1);
}
int main(){
    int num;

    printf("enter a number: ");
    scanf("%d", &num);

    printf("Factorial of %d =  %lld", num, fibonacci(num));
    return 0;
}