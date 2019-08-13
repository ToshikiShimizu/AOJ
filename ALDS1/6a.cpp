#include<bits/stdc++.h>
#define MAX_N 2000000
#define MAX_A 10000
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[MAX_N];
    int B[MAX_N];
    int C[MAX_A+1];
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    for (int i=0;i<MAX_A+1;i++){
        C[i]=0;
    }
    for (int i=0;i<n;i++){
        C[A[i]]++;
    }
    int sum = 0;
    for (int i=0;i<MAX_A+1;i++){
        C[i]+=sum;
        sum = C[i];
    }
     for (int i=0;i<n+1;i++){
        int j = n-i;
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }  
    for (int i=0;i<n;i++){
        cout << B[i];
        if (i!=n-1)cout << " ";
    }
    cout << endl;
}