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

void my_swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int bubbleSort(int A[],int N){
    int flag = 1;
    int cnt = 0;
    for (int i=0; flag==1; i++){
        flag = 0;
        for (int j=N-1; j>=i+1; j--){
            //show(A,N);
            if (A[j-1] > A[j]){
                swap(A[j-1],A[j]);
                flag = 1;
                cnt++;
            }
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
    int cnt = bubbleSort(A, N);
    cout << cnt << endl;

}