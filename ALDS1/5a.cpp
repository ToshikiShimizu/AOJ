#include<bits/stdc++.h>
using namespace std;

bool solve(int A[], int n, int i,int m){
    if (m==0){
        return true;
    }else{
        if (i<n){
            return solve(A,n,i+1,m)||solve(A,n,i+1,m-A[i]);
        }else
            return false;
    }
}

int main(){
    int n, A[20], q, m;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> m;
        if (solve(A,n,0,m)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        };
    }

}
