#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> S, int key){
    int N = S.size();
    for(int n=0;n<N;n++){
        if (S[n] == key){
            return true;
        }
    }
    return false;
}

bool binarySearch(vector<int> S, int key){
    int right = S.size();
    int left = 0;
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if (S[mid] == key){
            return true;
        }else if(S[mid]<key){
            left = mid+1;
        }else
        {
            right = mid;
        }
    }
    return false;
}

int main(){
    vector<int> S;
    vector<int> T;
    int N, Q;
    int s, t;
    cin >> N;
    for (int n=0;n<N;n++){
        cin >> s;
        S.push_back(s);
    }
    cin >> Q;
    for (int q=0;q<Q;q++){
        cin >> t;
        T.push_back(t);
    }
    int sum = 0;
    for(int q=0;q<Q;q++){
        if (binarySearch(S,T[q]))sum++;
        }    
    cout << sum << endl;
}