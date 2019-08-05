#include <bits/stdc++.h>
using namespace std;

void show(int A[], int N){
    for (int i=0; i<N;i++){

        cout << A[i];
        if  (i+1==N){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
}


int selectionSort(int A[],int N){
    int cnt = 0;
    for (int i=0; N>i; i++){
        int min_j = i;
        for (int j=i+1; N>j; j++){
            if (A[min_j] > A[j]){
                min_j = j;   
            }
        }
        if (min_j != i){
            cnt++;
            swap(A[min_j],A[i]);
        }
    }
    show(A,N);
    return cnt;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N;i++){
        cin >> A[i];
    }
    int cnt = selectionSort(A, N);
    cout << cnt << endl;

}