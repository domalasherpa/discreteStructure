#include <stdio.h>

int main(){
	
	float number;
	int i, n ;
	
	printf("No of test cases: ");
	scanf("%d", &n);
	
	
	for(i = 0; i < n; i++){
		
		printf("Real number: ");
		scanf("%f", &number);

		//if there is number after decimal: 
		if(number - (float)((int)number)){
			if(number > 0){
				printf("Ceiling: %d\n", (int)number + 1);
				printf("Floor: %d\n", (int)number);
			}
			else{
				printf("Ceiling: %d\n", (int)number);
				printf("Floor: %d\n", (int)number - 1);
				
			}
		}
		else{
			printf("Ceiling: %d\n", (int)number);
			printf("Floor  : %d\n", (int)number);
		}
		
	}
	
	return 0;
}
