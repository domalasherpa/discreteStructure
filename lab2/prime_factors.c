//find the prime factors of the numbers

//the input num could either be 


/*  
    1. zero
    2. Prime number
    3. Even 
    4. Odd
*/

#include <stdio.h>

void primeFact(int);

int check_prime(int num){
    int flag = 1;
    for(int i= 2; i <= (num/2); i++){
            if(num % i ==0){
                flag = 0;
                return 0;
            }
    }
    if(flag){
            return 1;
    }
}


void leftFactor(int left){

    if(check_prime(left)){
        printf("left: %d\n", left);
    }
    else{
        primeFact(left);
    }
    
}


void rightFactor(int right){

    if(check_prime(right)){
        printf("Right: %d\n", right);
    }
    else{
        primeFact(right);
    }
    
}

void primeFact(int num){

    int flag = 0;
    int left = 0 , right = 0, i, j;

    for(i = 2; i <= num/2; i++){
        for(j = 2; j <= i; j++){
            if(i * j == num){
                left = i;
                right = j;
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }


    leftFactor(left);
    rightFactor(right);
    

}


int main(){

    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number == 0){
        printf("%d\n", number);
    }
    else if(check_prime(number)){
        printf("%d, %d\n", 1, number);
    }
    else{
        primeFact(number);
    }


    return 0;
}