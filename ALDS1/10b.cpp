#include<bits/stdc++.h>
using namespace std;
static const int MAX_N = 100;
int main(){
    int n;
    int m[MAX_N+1][MAX_N+1];
    int p[MAX_N+1];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> p[i] >> p[i+1];
    }
    for (int i=0;i<n;i++){
        m[i+1][i+1] = 0;
    }
    for (int s=2; s<=n; s++){
        for (int i=1;i<=n-s+1;i++){
            int j = i + s - 1;
            m[i][j] = (1<<21);
            for (int k=i; k<=j-1; k++){
                m[i][j] = min(m[i][j],m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << m[1][n] << endl;
}