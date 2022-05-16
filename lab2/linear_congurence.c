#include  <stdio.h>

int gcdExtended(int a, int b, int* x, int* y){
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; 
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int main(){

    /*
        ax = b (mod m)
        ( a % m ) = (b % m)
        m =  a + gcd
        if(gcd !| b or gcd * k != b) then it is not solvable,.
    */

   int a, b, m, gcd, x, y;

    printf("Enter value of a , b and m: ");
    scanf("%d %d %d", &a , &b, &m);

    gcd = gcdExtended(a, m, &x, &y);

    if((b % gcd) != 0){
        printf("Unsolvable.");
        return 0;
    }

    if(gcd != b){
        x*= (b / gcd);
    }
    
    printf("x = %d + %d * k; where k is any integer.",x, m);


}