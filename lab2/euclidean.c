#include <stdio.h>


int findgcd(int n1, int n2){
	// int rem;
	// rem = n1 % n2;
	// n1 = n2; 
	// n2 = rem;
	
	if(n1 % n2 == 0){
		return n1;
	}
	
	return findgcd(n2, n1%n2);
}

int gcdExtended(int a, int b, int* x, int* y){
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; 
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


int main(){
	
	int n1, n2;
	
	printf("Enter two numbers: ");
	scanf("%d %d", &n1 , &n2);
	
	int gc = findgcd(n1, n2);
	
	printf("%d\n", gc);
	
	int a = 0, b = 0;
	
	gc = gcdExtended(n1, n2, &a, &b);
	printf("x = %d\t y = %d", a , b);
	return 0;
}
