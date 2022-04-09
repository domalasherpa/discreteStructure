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

void premise(int a, int b){

    static int true_ = 0;
    static int pair = 0;

    pair ++;

    if(a && !b){
        cout << "F\t";
    }
    else { 
        cout << "T\t";
        true_ ++;
    }

    if(pair == 2){
        if(true_ == 2){
            cout << "T";
        }
        else{
            cout << "F";
        }
        true_ = 0;
        pair = 0;
    }


    
}

int main(){

    /*
        If i go to mall      = p
        I will buy new jeans = q
        I will buy shirt     = r  

        p -> q
        q -> r

        p -> r  [reduction]
    
     */

    int p[2] = {0, 1}, q[2] = {0, 1}, r[2] = {0, 1};

    cout << "P\tQ\tR\t" << "P -> Q\t" << "Q -> R\t" << "(P -> Q) && (Q -> R)\n";
    cout << "---------------------------------------------------------------\n";

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                
                print(p[i]); cout <<"\t";
                print(q[j]); cout << "\t";
                print(r[k]); cout << "\t";

                premise(p[i], q[j]);
                premise(q[j], r[k]);

                cout << "\n";
            }
        }
    }

    return 0;
}