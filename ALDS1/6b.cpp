#include<bits/stdc++.h>
using namespace std;

long partition(int A[],long p,long r){
    int x = A[r];
    long i = p-1;
    for (long j=p;j<r;j++){
        if (A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int main(){
    long n;
    long idx;
    int A[200000];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    idx = partition(A,0,n-1);
    for (int i=0;i<n;i++){
        if (i==idx)cout << "[";
        cout << A[i];
        if (i==idx)cout << "]";
        if (i!=n-1)cout << " ";
    }
    cout << endl;
}