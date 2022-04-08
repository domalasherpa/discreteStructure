#include <iostream>

using namespace std;

void print(int val){
	if(val){
		cout << "T";
	}
	else{
		cout << "F";
	}
}

int main(){
	
	int p[2] = {0, 1};
	int q[2] = {0, 1};
	int r[2] = {0, 1};
	
	//conditional if false only if Left is true but right is false 
	//otherwise true.
	
	cout << "P\tQ\tR\t" << "(p n (~q v r)) -> (~p v r)\n";
	
	for(int i = 0; i < 2; i++){        //p
		for(int j = 0; j <2; j++){     //q
			for(int k = 0; k < 2;k++){ //r
				
				print(p[i]); cout <<"\t";
				print(q[j]); cout << "\t";
				print(r[k]); cout << "\t";

				if(p[i] && !q[j] || r[k]){ //Left
				
					if(!(!p[i] || r[k])){
						cout << "0\n";  //right 
					}
					else{
						cout << "1\n";
					}
				}
				else{
					
					cout << "1\n";
				}
				
			}
		}
	}
	
	return 0;
}
