#include<bits/stdc++.h>
using namespace std;
static const int N = 100;
static const int INFTY = (1<<21);

int n, A[N][N];

void prim(){
    int visited[n];
    int parent[n];
    for (int i = 0;i<n;i++){
        visited[i] = 0;
        parent[i] = -1;
    }
    int cur = 0;
    visited[0] = 1;
    tuple<int,int,int> t;
    priority_queue<std::tuple<int,int,int>> PQ;
    int cost = 0;
    while (!PQ.empty()||cur==0){
        for (int i=0; i<n;i++){
            if (A[cur][i]!=-1&&visited[i]==0){
                PQ.push(make_tuple(-A[cur][i],cur,i));
            }
        }
        t = PQ.top();
        PQ.pop();
        if (visited[get<2>(t)])continue;
        cur = get<2>(t);
        cost -= get<0>(t);
        visited[cur] = 1;
        parent[cur] = get<1>(t);
        //cout << cur << endl;
    }
    cout << cost << endl;
}

int main(){
    int a;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> a;
            A[i][j] = a;
        }
    }
    prim();
    }