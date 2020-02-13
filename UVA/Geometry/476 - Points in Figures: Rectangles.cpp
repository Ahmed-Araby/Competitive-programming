#include <bits/stdc++.h>
#define rect pair<point , point>
using namespace std;
struct point
{
    double x , y;
    point(){}
    point(double _x , double _y)
    {
        x = _x;
        y = _y;
        return ;
    }
    void get_input()
    {
        cin>>x>>y;
    }
    bool operator ==(point &obj) const
    {
        return x==obj.x && y==obj.y;
    }
};

bool inside(point p , rect r)
{
    point pl = r.first;
    point ph = r.second;
    if(p.x > pl.x && p.y  < pl.y)
        if(p.x < ph.x && p.y > ph.y)
            return 1;
    return 0;
}
bool check_inside(point p, vector<rect> &r, int index)
{
    bool ok=0;
    for(int i=0; i<r.size(); i++)
    {
        rect tmp = r[i];
        if(inside(p , tmp)){
            cout<<"Point "<<index<<" is contained in figure "<<i+1<< endl;
            ok=1;
        }
    }
    return ok;
}

int main()
{
    // get rectangles
    vector<rect> r;
    while(true)
    {
        char t;
        cin>>t;
        if(t=='*')
            break;
        // upper left and lower right corner
        point pl , ph;
        pl.get_input();
        ph.get_input();
        r.push_back(rect{pl , ph});
    }
    // get points
    int index = 1;
    while(true)
    {
        point p;
        p.get_input();
        if(p.x==9999.9 && p.y == 9999.9)
            break;

        bool inside = check_inside(p , r,index);
        if(!inside)
            cout<<"Point "<<index<<" is not contained in any figure"<< endl;
        index +=1;
    }
    return 0;
}
