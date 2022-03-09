//find the union, intersection, difference, symmetric of two sets
#include <stdio.h>


int* make_set(int *set, int *n){
	int i, j, k = 0;
	int *m_set = (int*) malloc(*n *sizeof(int));
	
	for(i = 0; i < *n; i++){
		int flag = 0;
		for(j = i + 1; j < *n; j++){
			if(set[i] == set[j]){
				flag = 1;
				break;	
			}
		}
		if(!flag){
			m_set[k] = set[i];
			k++;	
		}
	}
	
	free(set);
	m_set = (int*)realloc(m_set, k *sizeof(int));
	*n = k;
	
	return m_set;
	
}

void uni_sets(int set1[], int set2[], int n1, int n2){
	
	int i , j;
	int first = 1;
	
	difference(set1, set2, n1, n2);
	
	for(i = 0; i < n2; i++){
		printf(", %d", set2[i]);
	}
	
	
}


void inter_sets(int set1[], int set2[], int n1, int n2){
	int i, j;
	int first = 1;
	
	for(i = 0; i < n1; i++){
		for(j = 0; j < n2; j++){
			if(set1[i] == set2[j]){
				if(first){
					printf(" %d", set1[i]);
					first = 0;
				}
				else{
					printf(", %d", set1[i]);
				}
				break;
			}
		}
		
	}

}


void difference(int set1[], int set2[], int n1, int n2){
	int i , j, first = 1;

	for(i = 0; i < n1; i++){
		int flag = 0;
		for(j = 0; j < n2; j++){
			if(set1[i] == set2[j]){
				flag = 1;
				break;	
			}
		}
		if(!flag){
				if(first){
					printf(" %d", set1[i]);
					first = 0;
				}
				else{
					printf(", %d", set1[i]);
				}
		}
	}
}


void symmetric_diff(int set1[], int set2[], int n1, int n2){
	
	difference(set1, set2, n1, n2);
	printf(", ");
	difference(set2, set1, n2, n1);

}



int main(){
	int n1, n2, i;
	printf("Enter the number of sets: ");
	scanf("%d %d", &n1, &n2);
	
	int *setA = (int*) malloc(n1 * sizeof(int));
	int *setB = (int*) malloc(n2 * sizeof(int));
	
	
	for(i = 0; i < n1; i++){
		scanf("%d", &setA[i]);
	}
	
	for( i= 0; i < n2; i++){
		scanf("%d", &setB[i]);
	}
	
	setA = make_set(setA, &n1);
	setB = make_set(setB, &n2);
	
	printf("\n\nUnioun : { ");
	uni_sets(setA, setB, n1, n2);
	printf("}\n");
	
	printf("Intersection: { ");
	inter_sets(setA, setB, n1, n2);
	printf("}\n");
	
	printf("Difference: {");
	difference(setA, setB, n1, n2);
	printf("}\n");
	
	printf("Symmetric Difference: {");
	symmetric_diff(setA, setB, n1, n2);\
	printf("}\n");
	
	
	free(setA);
	free(setB);
	
	
	return 0;
}

