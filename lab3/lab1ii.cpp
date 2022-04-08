#include <iostream>

using namespace std;

int main(){
	
	int p[2] = {0, 1};
	int q[2] = {0, 1};
	int r[2] = {0, 1};
	
	
	//Biconditional is true iif both are T or F
	
	cout << "P\tQ\tR\t" << "(p n (~q v r)) <-> (~p v r)\n"; 
	for(int i = 0; i < 2; i++){//p
		for(int j = 0; j <2; j++){//q
			for(int k = 0; k < 2;k++){//r
				
				cout << p[i] << "\t" << q[j] << "\t"<< r[k]<<"\t";
				
				if(p[i] && (!q[j] || r[k])){ //left
					if((!p[i] || r[k])){  //right 
						cout << "1\n"; 
					}
					else{
						cout << "0\n";
					}
				}
				
				else{
					if(!(!p[i] || r[k])){ //right 
						cout << "1\n";  
					}
					else{
						cout << "0\n";
					}
					
				}
				
			}
		}
	}
	
	
	/*

	for(int i =0; i <2; i++){
		for(int j = 0; j< 2;j++){
			for(int k=0; k < 2; k++){
				cout << p[i] << "\t" << q[j] << "\t"<< r[k]<<"\n";
		    }
		}
	}
	*/


	return 0;
}
