#include <bits/stdc++.h>
using namespace std;

void show(int A[], int N){
    for (int i=0; i<N;i++){
        cout << A[i] << endl;
    }
}

void insertionSort(int A[],int N, int g, long long& cnt){
    int v, j;
    for (int i=g; i<N; i++){
        v = A[i];
        j = i - g;
        while(j>=0 and A[j] > v){
            A[j+g] = A[j];
            j-=g;
            A[j+g] = v;
            cnt++;
        }
    }
}

void shellSort(int A[], int N){
    long long cnt = 0;
    vector<int> G;

    
    for (int i=1;;){
        if (i>N)break;
        G.push_back(i);
        i = 3*i+1;
    }
    cout << G.size() << endl;
    for (int i=G.size()-1;i>=0;i--){
        insertionSort(A, N, G[i], cnt);
        cout << G[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;
}

int main(){

    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N;i++){
        cin >> A[i];
    }
    shellSort(A, N);
    show(A, N);
}