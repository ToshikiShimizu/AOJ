#include<bits/stdc++.h>
using namespace std;
static const int N_MAX = 100000;
void bfs(int colors[], int n, int i,vector<int> V[]){
    int color = colors[i];
    queue<int> q;
    q.push(i);
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for (int w=0;w<V[u].size();w++){
            //cout << u <<"-" << w<< endl;
            int v = V[u][w];
            if(colors[v]!=-1)
                continue;
            colors[v] = color;
            q.push(v);
        }
    }
}


int main(){
    int n, m;
    vector<int> V[N_MAX];
    int s, t;
    cin >> n >> m;
    int q;
    for (int i=0;i<m;i++){
      cin >> s >> t;
      V[s].push_back(t);
      V[t].push_back(s);
    }

    int colors[n];
    for (int i=0; i<n; i++){
        colors[i] = -1;
    }
    for (int i=0; i<n; i++){
        if(colors[i] == -1){
            colors[i] = i;
        }
        //cout << "a"<< colors[i] <<endl;
        bfs(colors,n,i,V);
    }    

    cin >> q;
    for (int i=0;i<q;i++){
        cin >> s >> t;
        if (colors[s]==colors[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}