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

void insertionSort(int A[],int N){
    int v, j;
    int cnt = 0;
    for (int i=1; i<N; i++){
        v = A[i];
        j = i - 1;
        while(j>=0 and A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
            cnt++;
        }
        show(A, N);
        
    }
    cout << cnt << endl;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N;i++){
        cin >> A[i];
    }
    show(A, N);
    insertionSort(A, N);
}