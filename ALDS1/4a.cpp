#include<bits/stdc++.h>
using namespace std;
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
    //cout << T.size() << endl;
    for(int q=0;q<Q;q++){
        for(int n=0;n<N;n++){
            if (S[n] == T[q]){
                sum++;
                break;
            }
        }
    }
    cout << sum << endl;
}