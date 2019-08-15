#include<bits/stdc++.h>
using namespace std;
#define INFTY (1<<30)
void printHeap(int H[], int n){
    for (int i=0;i<n;i++){
        cout << "node " << i+1 << ": ";
        cout << "key = " << H[i] << ", ";
        int v = (i+1)/2-1;
        if ( 0 <= v && v < n)
            cout << "parent key = " << H[v] << ", ";
        v = 2*(i+1)-1;
        if ( 0 <= v && v < n)
            cout << "left key = " << H[v] << ", ";
        v = 2*(i+1);
        if ( 0 <= v && v < n)
            cout << "right key = " << H[v] << ", ";
        cout << endl;
    }
}

void maxHeapify(int H[], int s, int n){
    if(s >= n/2)return;
    int max = H[s];
    int argmax = s;
    int left = 2*(s+1)-1;
    // cout << max << "  " << argmax << endl;
    if (left < n)
        if (H[left]>max){
            max = H[left];
            argmax = left;
        }
    int right = 2*(s+1);
    if (right < n)
        if (H[right]>max){
            max = H[right];
            argmax = right;
        }
    // cout << max << " " << argmax << endl;
    if (max!=H[s]){
        swap(H[s],H[argmax]);
        // cout << "swap" << endl;
        maxHeapify(H, argmax, n);
    }
}

void buildMaxHeap(int H[], int n){
    int s = n/2 - 1;
    for (int i=s;i>=0;i--){
        maxHeapify(H, i, n);
    }
}
void heapIncreaseKey(int H[], int n, int key){
    H[n] = key;
    while(n>0 && H[(n+1)/2-1] < H[n]){
        swap(H[(n+1)/2-1],H[n]);
        n = (n+1)/2-1;
    }
}
void insert(int H[], int n, int key){
    heapIncreaseKey(H, n ,key);
}



int heapExtractMax(int H[], int n){
    int max = H[0];
    H[0] = H[n-1];
    maxHeapify(H, 0, n);
    return max;
}

int main(){

    int n = 0;
    int H[2000000];
    string cmd;
    int key;
    while(1){
        cin >> cmd;
        if (cmd == "insert"){
            cin >> key;
            insert(H, n, key);
            n++;
        }else if(cmd == "extract"){
            cout << heapExtractMax(H, n) << endl;
            n--;
        }else{
            break;
        }
        
    }
}