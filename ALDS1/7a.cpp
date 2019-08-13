#include<bits/stdc++.h>
# define MAX 100001
# define NIL -1
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};
int main(){
    Node nodes[MAX];
    int n;
    int id, degree;
    int par;
    int cur;
    int left;
    cin >> n;
    for(int i=0;i<n;i++){
        nodes[i].parent = NIL;
        nodes[i].left = NIL;
        nodes[i].right = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> par >> degree;
        for (int j=0;j<degree;j++){
            cin >> cur;
            if (j==0){
                nodes[par].left = cur;
            }else{
                nodes[left].right = cur;
            }
            left = cur;
            nodes[cur].parent = par;
        }
    }
    for(int i=0;i<n;i++){
        cout << "node" << " " << i << ": ";
        cout << "parent = " << nodes[i].parent << ", ";

        cout << "[";
        for (int j=nodes[i].left; j!=NIL; j=nodes[j].right){
            if (j!=nodes[i].left){
                cout << ", ";
            }
            cout << j;
        }
        cout << "]";
        cout << endl;
    }
}