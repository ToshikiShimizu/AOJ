#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> v;
    int n;
    string cmd;
    int x;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> cmd;
        
        if (cmd == "insert"){
            cin >> x;
            v.push_front(x);
        }else if(cmd == "deleteFirst"){
            v.pop_front();
        }else if(cmd == "deleteLast"){
            v.pop_back();
        }else{
            cin >> x;
            for (list<int>::iterator it = v.begin(); it != v.end(); it++){
                if (*it==x){
                    v.erase(it);
                    break;
                }
            }
        }
    }
    int i=0;
    for (list<int>::iterator it = v.begin(); it != v.end(); it++){
        if(i++)cout<<" ";
        cout << *it;
    }
    cout << endl;

}