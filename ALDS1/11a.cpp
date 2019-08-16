#include<bits/stdc++.h>
using namespace std;
static const int N = 100;
int main(){
    int n;
    int u, k;
    int v;
    int A[N][N];
    cin >> n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            A[i][j]=0;
        }
        cin >> u >> k;
        for (int j=0;j<k;j++){
            cin >> v;
            A[i][v-1] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j!=0)cout<< " ";
            cout <<  A[i][j];
        }
        cout << endl;
    }
}