#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cin >> n;
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

    
}