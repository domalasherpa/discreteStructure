#include <stdio.h>
int gcdExtended(int a, int b, int* x, int* y)
{
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

    int a1, a2, m1, m2, M;
    int temp, y1, y2;

    printf("Enter a1 and m1: ");
    scanf("%d %d", &a1, &m1);
    printf("Enter a2 and m2: ");
    scanf("%d %d", &a2, &m2);

    M = m1 * m2;
    temp = m1;
    m1 = m2; //M/m1
    m2 = temp; //M/m2

    // gcdExtended(m1, m2, &y1, &temp);
    // gcdExtended(m2, m1, &y2, &temp);

    temp = gcdExtended(m1, m2, &y1, &y2);
    temp = ((m1 * y1 * a1) + (m2 * y2 * a2)) % M;
    printf("X = %d", temp);
    
    return 0;

}