#include <stdio.h>
#include <math.h>

int intToBin(int num){
    int bin = 0, i = 0;

    while(num > 0){
        
        bin = (num % 2) * pow(10, i) + bin;
        num /= 2;
        i++;

    }

    return bin;
}
int main(){

    int num1,num2;

    printf("enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nAddition of %d and %d : %d\n", intToBin(num1), intToBin(num2), intToBin(num1 + num2));
    printf("Multiplication of %d and %d: %d\n",intToBin(num1), intToBin(num2), intToBin(num1 * num2));
    printf("Division of %d by %d: %d\n",intToBin(num1), intToBin(num2), intToBin(num1/num2));
    printf("Division of %d by %d: %d\n",intToBin(num2), intToBin(num1), intToBin(num2/num1));

    return 0;
}