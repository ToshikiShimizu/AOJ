#include<bits/stdc++.h>
# define MAX 100001
# define NIL -1
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
    int depth;
    int height;
    int sibling;
    int degree;
    int id;
    string type;
};
int getRoot(Node nodes[], int n){
    for (int i=0;i<n;i++){
        if(nodes[i].parent == NIL){
            return i;
        }
    }
}

void setParent(Node nodes[], int n){
    for (int i=0;i<n;i++){
        if(nodes[i].left!=NIL){
            nodes[nodes[i].left].parent = i;
        }
        if(nodes[i].right!=NIL){
            nodes[nodes[i].right].parent = i;
        }
    }
}


void preorderTreeWalk(Node nodes[], int id){
    cout  << " "<< id;
    if (nodes[id].left!=NIL){
        preorderTreeWalk(nodes, nodes[id].left);
    }
    if (nodes[id].right!=NIL){
        preorderTreeWalk(nodes, nodes[id].right);
    }
}

void inorderTreeWalk(Node nodes[], int id){
    
    if (nodes[id].left!=NIL){
        inorderTreeWalk(nodes, nodes[id].left);
    }
    cout  << " "<< id;
    if (nodes[id].right!=NIL){
        inorderTreeWalk(nodes, nodes[id].right);
    }
}

void postorderTreeWalk(Node nodes[], int id){

    if (nodes[id].left!=NIL){
        postorderTreeWalk(nodes, nodes[id].left);
    }
    if (nodes[id].right!=NIL){
        postorderTreeWalk(nodes, nodes[id].right);
    }
     cout  << " "<< id;
}

int main(){
    Node nodes[MAX];
    int n;
    int id;
    int parent;
    int left;
    int right;
    cin >> n;
    for(int i=0;i<n;i++){
        nodes[i].parent = NIL;
        nodes[i].left = NIL;
        nodes[i].right = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> id >> left >> right;
        nodes[id].right = right;      
        nodes[id].left = left;
    }
    setParent(nodes, n);
    int root;
    root = getRoot(nodes, n);
    cout << "Preorder" << endl;
    preorderTreeWalk(nodes, root);
    cout << endl;
    cout << "Inorder" << endl;
    inorderTreeWalk(nodes, root);
    cout << endl;
    cout << "Postorder" << endl;
    postorderTreeWalk(nodes, root);
    cout << endl;
}


	
