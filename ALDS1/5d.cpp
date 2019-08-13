#include<bits/stdc++.h>
using namespace std;

long long merge(int A[], int left, int mid, int right, long long cnt){
    int L[500000];
    int R[500000];
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1] = 2000000000; // sentinel value
    R[n2] = 2000000000; // sentinel value
    int i=0,j=0;
    for (int k=left;k<right;k++){
        if (L[i]<=R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            cnt += (n1-i);
        }
    }
    return cnt;
}

long long mergeSort(int A[], int left, int right, long long cnt){
    if (left+1<right){
        int mid = (left + right)/2;
        cnt = mergeSort(A, left, mid, cnt);
        cnt = mergeSort(A, mid, right, cnt);
        cnt = merge(A,left,mid,right, cnt);
    }
    return cnt;
}

int main(){
    long long cnt = 0;
    int n;
    int A[500000];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    cnt = mergeSort(A,0,n,cnt);
    cout << cnt << endl;

}