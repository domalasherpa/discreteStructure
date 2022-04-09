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

void proof(int first, int sec, int third){
    
    if(first && sec && third){
        cout << "T\t";
        cout << "I buy a new goat.";
    }
    else{
         cout << "F\t";
    }
    cout << "\n";
}

void hypothesis(int *first, int *sec, int *third, int p, int q, int r){
    if(p || q){
        cout << "T\t";
        *first = 1;
    }
    else{
         cout << "F\t";
         *first = 0;
    }
               
     if((p && q) && !r){
        cout << "T\t";
        *sec = 1;
     }
     else{
         cout << "F\t";
        *sec = 0;
    }

    if(q && !r){
        cout << "T\t";
        *third = 1;
    }
    else{
        cout << "F\t";
        *third = 0;
    }
}


int main(){

/*
    I will buy a new goat  = p
    I will buy a new Yugo = q
    I will need a loan    = r

    p V q
    p n q -> r
    q n ~r

    therfore ~p
*/
    int p[2] = {0, 1};
    int q[2] = {0, 1};
    int r[2] = {0, 1};

    cout<<"P\tQ\tR\t";
    cout << "P V Q\t" << "(P n Q) -> R\t" << "Q n ~R\t" ;
    cout << "Conclusion\n";
    cout << "---------------------------------------------------------------------\n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int first , sec, third;
    
                print(p[i]); cout <<"\t";
                print(q[j]); cout << "\t";
                print(r[k]); cout << "\t";

                hypothesis(&first, &sec, &third, p[i], q[j], r[k]);
                proof(first, sec, third);
                
            }
        }
    }
    return 0;
}