#include<bits/stdc++.h>
using namespace std;
static const int N = 1000;

int lcs(string X, string Y){
    int dp[N+1][N+1];
    dp[0][0] = 0;
    for (int i=0;i<N;i++){
        dp[0][i+1] = 0;
        dp[i+1][0] = 0;
    }
    int x_size = X.size();
    int y_size = Y.size();
    for (int i=0;i<x_size;i++)
        for (int j=0;j<y_size;j++){
            if(X[i]==Y[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    return dp[x_size][y_size];
}

int main(){
    int q;
    string s1,s2;
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}