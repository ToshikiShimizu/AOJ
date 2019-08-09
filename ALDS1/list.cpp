#include<bits/stdc++.h>
using namespace std;
int main(){
    list<char> L;
    L.push_front('b');
    L.push_back('c');
    L.push_front('a');

    cout << L.front() << endl;
    cout << L.back() << endl;

    L.pop_front();
    L.push_back('d');
    cout << L.front() << endl;
    cout << L.back() << endl;
}