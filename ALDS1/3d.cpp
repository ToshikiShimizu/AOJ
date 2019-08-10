#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> S1;
    stack<pair<int, int> > S2;
    string  S;
    cin >> S;
    int sum = 0;
    for (int i=0;i<S.size();i++){
        if (S[i] == '\\')
            S1.push(i);
        else if(S[i] == '/' && S1.size()>0){
            int left = S1.top();
            int current = i - left;
            sum += current;
            S1.pop();
            while(S2.size()>0 && left<S2.top().first){
                current += S2.top().second;
                S2.pop();
            }
            S2.push(make_pair(left, current));
        }
        else;

    }
    cout << sum << endl;
    cout << S2.size();
    list<int> ans;
    while(S2.size()>0){
        ans.push_front(S2.top().second);
        S2.pop();
    }
    for (list<int>::iterator it = ans.begin(); it != ans.end(); it++){
        cout<<" ";
        cout << *it;
    }
    cout << endl;
}