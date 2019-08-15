#include<bits/stdc++.h>
using namespace std;
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

int main(){
    int n;
    int H[500000];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> H[i];
    }
    // printHeap(H, n);
    buildMaxHeap(H, n);
    for (int i=0;i<n;i++){
        cout << " " <<  H[i];
    }
    cout << endl;
}