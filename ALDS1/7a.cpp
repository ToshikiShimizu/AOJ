#include<bits/stdc++.h>
# define MAX 100001
# define NIL -1
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
    int depth;
    string type;
};
int getRoot(Node nodes[], int n){
    for (int i=0;i<n;i++){
        if(nodes[i].parent == NIL){
            return i;
        }
    }
}
void setDepth(Node nodes[], int id){
    if (nodes[id].parent == NIL){
        nodes[id].depth=0;
    }
    else{
        nodes[id].depth = nodes[nodes[id].parent].depth + 1;
    }
    if (nodes[id].left != NIL){
        setDepth(nodes, nodes[id].left);
    }
    if (nodes[id].right != NIL){
        setDepth(nodes, nodes[id].right);
    }
}

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
        nodes[i].depth = NIL;
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
    int root;
    root = getRoot(nodes, n);
    setDepth(nodes, root);
    for(int i=0;i<n;i++){
        if (nodes[i].parent == NIL){
            nodes[i].type = "root";
        }else if(nodes[i].left != NIL){
            nodes[i].type = "internal node";
        }else{
            nodes[i].type = "leaf";
        }
    }

    for(int i=0;i<n;i++){
        cout << "node" << " " << i << ": ";
        cout << "parent = " << nodes[i].parent << ", ";
        cout << "depth = " << nodes[i].depth << ", ";
        cout << nodes[i].type << ", ";
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


	
