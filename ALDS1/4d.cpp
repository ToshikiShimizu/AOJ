#include<bits/stdc++.h>
using namespace std;

bool judge(int W[], long int n, long int p,long int k){
    long int current = 0;
    long int truck = 1;
    for (long int i=0;i<n;){
        if (current + W[i] <= p){
            current += W[i];
            i++;
        }
        else{
            truck += 1;
            current = 0;
            if (truck>k)return false;
        }
    }
    return true;
    
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

long int solve(int W[], long int n, long int k){
    long int left = 0;
    long int right = 100000*100000;
    long int mid;
    while(left+1<right){
        mid = (left+right)/2;
        if(judge(W, n, mid, k)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;

}
int main(){
    long int n, k;
    cin >> n >> k;
    long int max_size = 100000;
    int W[max_size];
    for (long int i=0;i<n;i++){
        cin >> W[i];
    }
    cout << solve(W, n, k) << endl;
}