#include <bits/stdc++.h>
using namespace std;
static const int MAX = 200000;
int main(){
    int R[MAX], N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> R[i];
    }
    int mx = -1000000000;
    int mn = R[0];
    for  (int i=1; i<N; i++){
        mx = max(mx, R[i]-mn);
        mn = min(mn, R[i]);
    }
    cout << mx << endl;
    return 0;
}