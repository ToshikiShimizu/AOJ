#include<bits/stdc++.h>
using namespace std;

// struct Point{
//     double x, y;
// };
class Point{
    public:
        double x, y;
        void print(){
            cout << x << " " << y << endl;
        }
};
// void print(Point p){
//     cout << p.x << " " << p.y << endl;
// }

void koch(Point begin, Point end, int depth){
    
    if (depth>0){
        Point s,u,t;
        s.x = (2*begin.x + end.x) / 3;
        s.y = (2*begin.y + end.y) / 3;
        t.x = (begin.x + 2*end.x) / 3;
        t.y = (begin.y + 2*end.y) / 3;
        double theta = M_PI * 60 / 180;
        u.x = (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta) + s.x;
        u.y = (t.x - s.x) * sin(theta) + (t.y - s.y) * cos(theta) + s.y;
        
        koch(begin,s,depth-1);
        s.print();
        koch(s,u,depth-1);
        u.print();
        koch(u,t,depth-1);
        t.print();
        koch(t,end,depth-1);
    }
    
}

int main(){
    Point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0; 
    int depth;
    cin >> depth;
    //print (p1);
    p1.print();
    koch(p1,p2,depth);
    //print (p2);
    p2.print();
}