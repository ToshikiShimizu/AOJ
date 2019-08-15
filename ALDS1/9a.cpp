#include<bits/stdc++.h>
using namespace std;
void print_heap(int H[], int i, int n){
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
int main(){
    int n;
    int H[250];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> H[i];
    }
    for (int i=0;i<n;i++)
        print_heap(H, i, n);
}