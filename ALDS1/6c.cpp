#include<bits/stdc++.h>
using namespace std;
struct Card{
    char suit;
    int value;
};

int partition(Card A[],int p,int r){
    int x = A[r].value;
    int i = p-1;
    for (int j=p;j<r;j++){
        if (A[j].value<=x){
            i++;
            swap(A[i],A[j]);
            //swap(A[i].value,A[j].value);
            //swap(A[i].suit,A[j].suit);
        }
    }
    swap(A[i+1],A[r]);
    //swap(A[i+1].value,A[r].value);
    //swap(A[i+1].suit,A[r].suit);
    return i+1;
}

void quickSort(Card A[],int left, int right){
    if (left<right){
        int st;
        st = partition(A,left,right);
        quickSort(A,left, st-1);
        quickSort(A,st+1,right);
    }
}

void merge(Card A[], int left, int mid, int right){
    Card L[100001];
    Card R[100001];
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++){
        L[i].value = A[left+i].value;
        L[i].suit= A[left+i].suit;
    }
    for (int i = 0; i < n2; i++){
        R[i].value = A[mid+i].value;
        R[i].suit = A[mid+i].suit;
    }
    L[n1].value = 2000000000; // sentinel value
    R[n2].value = 2000000000; // sentinel value
    int i=0,j=0;
    for (int k=left;k<right;k++){

        if (L[i].value<=R[j].value){
            A[k].value = L[i].value;
            A[k].suit = L[i].suit;
            i++;
        }else{
            A[k].value = R[j].value;
            A[k].suit = R[j].suit;
            j++;
        }
    }

}

void mergeSort(Card A[], int left, int right){
    if (left+1<right){
        
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A,left,mid,right);

    }
}

bool judge(Card A[], Card B[], int n){
    for (int i=0;i<n;i++){
        if(A[i].suit!=B[i].suit)return false;
    }
    return true;
}



int main(){
    int n;
    Card card_q[100000];
    Card card_m[100000];
    int value;
    char suit;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> suit >> value;
        card_q[i].suit = suit;
        card_m[i].suit = suit;
        card_q[i].value = value;
        card_m[i].value = value;
    }
    quickSort(card_q,0,n-1);
    mergeSort(card_m,0,n);
    if (judge(card_q, card_m, n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for (int i=0;i<n;i++){
        cout << card_q[i].suit << " " <<  card_q[i].value << endl;
    }    
}