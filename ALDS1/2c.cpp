#include <bits/stdc++.h>
using namespace std;

struct Card {char suit, value;};
void bubbleSort(struct Card A[],int N){
    int flag = 1;
    for (int i=0; flag==1; i++){
        flag = 0;
        for (int j=N-1; j>=i+1; j--){
            if (A[j-1].value > A[j].value){
                swap(A[j-1],A[j]);
                flag = 1;
            }
        }
    }
}

void selectionSort(struct Card A[],int N){
    for (int i=0; N>i; i++){
        int min_j = i;
        for (int j=i+1; N>j; j++){
            if (A[min_j].value > A[j].value){
                min_j = j;   
            }
        }
        if (min_j != i){
            swap(A[min_j],A[i]);
        }
    }
}

void show(struct Card A[], int N){
    for (int i=0; i<N;i++){

        cout << A[i].suit << A[i].value;
        if  (i+1==N){
            cout << endl;
        }else{
            cout << ' ';
        }
    }
}

bool isStable(struct Card A[], struct Card B[],int N){
    for (int i=0;i<N;i++){
        if (A[i].suit != B[i].suit) return false;
    }
    return true;
}

int main(){
    int N;
    Card C1[36], C2[36];
    cin >> N;    
    for (int i=0; i < N; i++){
        cin >> C1[i].suit >> C1[i].value;
    }
    for (int i=0; i < N; i++) C2[i] = C1[i];
    bubbleSort(C1, N);
    show(C1,N);
    cout << "Stable" << endl;
    selectionSort(C2, N);
    show(C2,N);
    if (isStable(C1, C2, N )){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

}