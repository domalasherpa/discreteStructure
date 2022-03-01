//find the cartessian product of two or more sets

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
	
	m_set = (int*)realloc(m_set, k *sizeof(int));
	*n = k;
	
	return m_set;
	
}

void cartesian(int setA[], int setB[], int n1, int n2){
	
	int i , j;
	for(i = 0; i < n1; i++){
		for(j = 0; j < n2; j++){
			if(i == 0 && j == 0){
				printf("(%d, %d)", setA[i], setB[j]);
			}
			else{
				printf(", (%d, %d)", setA[i], setB[j]);
			}
		}
	}
		
}


int main(){
	
	
	int n1, n2, i;
	
	scanf("%d %d", &n1, &n2);
	
	int *setA = (int)malloc(n1 * sizeof(int));
	int *setB = (int) malloc(n2 * sizeof(int));
	
//	int setA[n1], setB[n2];	
	
	for( i = 0; i < n1; i++){
		scanf("%d", &setA[i]);
	}
	
	for(i = 0; i < n2; i++){
		scanf("%d", &setB[i]);
	}
	
	setA = make_set(setA, &n1);
	setB = make_set(setB, &n2);
	
	printf("Cartesian Prodict: { ");
	cartesian(setA, setB, n1, n2);
	printf(" }");
	
	return 0;
}
