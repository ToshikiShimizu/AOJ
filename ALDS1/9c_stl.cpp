#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> PQ;
    string cmd;
    int key;
    while(1){
        cin >> cmd;
        if (cmd == "insert"){
            cin >> key;
            PQ.push(key);
        }else if(cmd == "extract"){
            cout << PQ.top() << endl;
            PQ.pop();
        }else{
            break;
        }
        
    }
}