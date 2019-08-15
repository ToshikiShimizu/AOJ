#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string cmd, str;
    map<string, bool> S;
    for (int i=0;i<n;i++){ 
        cin >> cmd >> str;
        if (cmd=="insert"){
            S[str] = true;
        }else{
            cout <<  S[str] << endl;
            if(S[str]){
            cout << "yes" << endl;
            }else{
            cout <<"no"<<endl;
        }
        }
    }
}