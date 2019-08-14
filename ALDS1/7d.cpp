#include<bits/stdc++.h>
using namespace std;
int n, pos;
vector<int> pre, in, post;

void rec(int left, int right){
    if(left>=right){
        return;
    }
    int root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(left,m);
    rec(m+1,right);
    post.push_back(root);
}

void solve(){
    pos = 0;
    rec(0, pre.size());
    for (int i=0; i<n;i++){
        if (i) cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main(){
    int k;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k;
        pre.push_back(k);
    }
    for (int i=0;i<n;i++){
        cin >> k;
        in.push_back(k);
    }
    solve();
}