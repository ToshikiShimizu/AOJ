#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[1000000], n, q, k, sum;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> k;
        if(*lower_bound(A,A+n,k)==k)sum++;
    }
    cout << sum << endl;

}