#include<bits/stdc++.h>
using namespace std;
static const int MAX = 1000;
static const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX];//ソート後の数列を格納するための配列
int T[VMAX+1];//値を与えると、Bの何番目の要素に当たるかを返す


int solve(){
    int ans = 0;
    bool V[MAX];
    for (int i=0;i<n;i++){
        B[i] = A[i];
        V[i] = false;
    }
    sort(B,B+n);
    for (int i=0;i<n;i++)T[B[i]] = i;
    for (int i=0;i<n;i++){
        if (V[i])continue;//すでに処理済みのサイクルには入らない
        int cur = i;
        int S = 0;
        int m = VMAX;
        int an = 0;
        while(1){
            V[cur] = true;
            an++;//サイクル内の要素数をカウント
            int v = A[cur];
            m = min(m,v);//cycle min
            S+=v;
            cur = T[v];//サイクルの移動
            if (V[cur])break;//サイクルを一周したかを判定
        }
        ans+=min(S+(an-2)*m,m+S+(an+1)*s);

    }
    return ans;
}

int main(){
    cin >> n;
    s = VMAX;
    for (int i=0;i<n;i++){
        cin >> A[i];
        s = min(s,A[i]);//global min
    }
    int ans = solve();
    cout << ans << endl;
}