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

void setHeight(Node nodes[], int id){

        int left_height = -1;
        int right_height = -1;
        if(nodes[id].left!=NIL){
            setHeight(nodes, nodes[id].left);
            left_height = nodes[nodes[id].left].height;
        }
        if(nodes[id].right!=NIL){
            setHeight(nodes, nodes[id].right);
            right_height = nodes[nodes[id].right].height;
        }
        nodes[id].height =  max(left_height, right_height) + 1;
}

void setType(Node nodes[], int n){
    for(int i=0;i<n;i++){
        if (nodes[i].parent == NIL){
            nodes[i].type = "root";
        }else if(nodes[i].left != NIL || nodes[i].right != NIL){
            nodes[i].type = "internal node";
        }else{
            nodes[i].type = "leaf";
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

void setSibling(Node nodes[], int id){
    if ((nodes[id].left!=NIL) && (nodes[id].right!=NIL)){
        nodes[nodes[id].left].sibling = nodes[id].right;
        nodes[nodes[id].right].sibling = nodes[id].left;

    }
    if(nodes[id].left!=NIL)setSibling(nodes, nodes[id].left);
    if(nodes[id].right!=NIL)setSibling(nodes, nodes[id].right);
}

void setDegree(Node nodes[], int id){
    if (nodes[id].left != NIL){
        setDegree(nodes, nodes[id].left);
        nodes[id].degree++;
    }
    if (nodes[id].right != NIL){
        setDegree(nodes, nodes[id].right);
        nodes[id].degree++;
    }
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
        nodes[i].depth = NIL;
        nodes[i].sibling = NIL;
        nodes[i].degree = 0;
    }
    for(int i=0;i<n;i++){
        cin >> id >> left >> right;
        nodes[id].right = right;      
        nodes[id].left = left;
 
    }

    setParent(nodes, n);
    int root;
    root = getRoot(nodes, n);
    setDepth(nodes, root);
    setType(nodes, n);
    setHeight(nodes, root);
    setSibling(nodes, root);
    setDegree(nodes, root);


    for(int i=0;i<n;i++){
        cout << "node" << " " << i << ": ";
        cout << "parent = " << nodes[i].parent << ", ";
        cout << "sibling = " << nodes[i].sibling << ", ";
        cout << "degree = " << nodes[i].degree << ", ";
        cout << "depth = " << nodes[i].depth << ", ";
        cout << "height = " << nodes[i].height << ", ";
        cout << nodes[i].type;
        cout << endl;
    }
}


	
