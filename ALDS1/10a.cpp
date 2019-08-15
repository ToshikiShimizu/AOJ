#include<bits/stdc++.h>
using namespace std;
#define SIZE 45

int F[SIZE];


int getFib(int i){
    if (F[i] == -1){
        if (i==0 || i==1){
            F[i] = 1;
        }else{
            F[i] = getFib(i-1) + getFib(i-2);
        }
    }
    return F[i];
}

int main(){
    for (int i=0;i<SIZE;i++){
        F[i] = -1;
    }
    int n;
    cin >> n;
    cout << getFib(n) << endl;
    
}