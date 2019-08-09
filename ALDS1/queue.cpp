#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string> Q;
    Q.push("red");
    Q.push("yellow");
    Q.push("yellow");
    Q.push("blue");
    cout << Q.front() << endl;
    Q.pop();
    cout << Q.front() << endl;
    Q.pop();
    cout << Q.front() << endl;
    Q.pop();
    Q.push("green");
    cout << Q.front() << endl;
    Q.pop();
    cout << Q.front() << endl;
}