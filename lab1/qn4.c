#include <stdio.h>
#define n 5


void fuzzyunion(char set[][20], float deg[][2]){
	int first = 1, i;
	for(i = 0; i < n; i++){
		if(deg[i][0] > deg[i][1]){
			if(first){
				printf(" (%s, %.2f) ", set[i], deg[i][0]);
				first = 0;
			}
			else{
				printf(", (%s, %.2f) ", set[i], deg[i][0]);

			}
		}
		else{
			if(first){
				printf(" (%s, %.2f) ", set[i], deg[i][1]);
				first = 0;
			}
			else{
				printf(", (%s, %.2f) ", set[i], deg[i][1]);

			}
				
		}
	
	}
}


void fuzzyinter(char set[][20], float deg[][2]){
	int first = 1, i;
	for(i = 0; i < n; i++){
			if(deg[i][0] < deg[i][1]){
				if(first){
					printf(" (%s, %.2f) ", set[i], deg[i][0]);
					first = 0;
				}
				else{
					printf(", (%s, %.2f) ", set[i], deg[i][0]);

				}
			}
			else{
				if(first){
					printf(" (%s, %.2f) ", set[i], deg[i][1]);
					first = 0;
				}
				else{
					printf(", (%s, %.2f) ", set[i], deg[i][1]);

				}
			}
	
	}
}

int main(){
	
	char set[n][20];
	int age[n][1];
	float deg[n][2];
	int i;
	
	for( i = 0 ; i< n; i++){
		scanf("%s %d", &set[i], &age[i]);
	}
	
	for( i = 0; i < n; i++){
		if(age[i][0] <= 20){
			deg[i][0] = 1;
		}
		else if(age[i][0] <= 30){
			deg[i][0] = (30 - age[i][0])/10.0;
		}
		else{
			deg[i][0] = 0;
		}
	}
	
	//Question no a
	printf("\n(a):\n");
	printf("{ ");
	for( i = 0; i< n; i++){
		if(i != n - 1){
			printf("(%s, %.2f), ", set[i], deg[i][0]);
		}
		else{
			printf("(%s, %.2f)", set[i], deg[i][0]);
		}		
	}
	printf(" }");
	
	
	for( i = 0; i < n; i++){
		if(age[i][0] <= 15){
			deg[i][1] = 1;
		}
		else if(age[i][0] <= 30){
			deg[i][1] = (35 - age[i][0])/20.0;
		}
		else{
			deg[i][1] = 0;
		}
		
	}
	
	//Question number b
	printf("\n\n(b): \n");
	printf("{ ");
	for(i = 0; i< n; i++){
		if(i != n - 1){
			printf("(%s, %.2f), ", set[i], deg[i][1]);
		}
		else{
			printf("(%s, %.2f) ", set[i], deg[i][1]);
		}
		
	}
	printf("} ");


	printf("\nUnion: {");
	fuzzyunion(set, deg);
	printf("} \n");

	printf("\nIntersection: {");
	fuzzyinter(set, deg);
	printf("} \n");
	
	return 0;
}