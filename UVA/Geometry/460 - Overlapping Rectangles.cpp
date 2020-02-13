#include <bits/stdc++.h>
#define rect pair<point , point>
using namespace std;
struct point
{
    int x , y;
    point(){}
    point(int _x , int _y)
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
rect get_intersect(point pl1 , point ph1 , point pl2 , point ph2)
{
    int lx = max(pl1.x , pl2.x);
    int ly = max(pl1.y , pl2.y);

    int hx = min(ph1.x , ph2.x);
    int hy = min(ph1.y , ph2.y);

    point pl(lx , ly);
    point ph (hx ,hy);
    rect r;
    r = {pl , ph};
    return r;
}
bool check_rect(rect r)
{
    // no intersection
    point pl = r.first;
    point ph = r.second;
    if(pl.x > ph.x)
        return 0;
    else if(pl.y > ph.y)
        return 0;

    // degenerate rectangle
    if(pl==ph)  // point
        return 0;
    if(pl.x ==ph.x || pl.y==ph.y)  // line
        return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        // first box
        point pl1, ph1;
        pl1.get_input();
        ph1.get_input();
        // second box
        point pl2, ph2;
        pl2.get_input();
        ph2.get_input();

        rect r = get_intersect(pl1 , ph1 , pl2 , ph2);

        if(check_rect(r)){
            cout<<r.first.x<<" "<<r.first.y<<" ";
            cout<<r.second.x<<" "<<r.second.y<<  endl;
        }

        else
            cout<<"No Overlap"<< endl;
        if(t)
            cout<< endl;

    }
    return 0;
}
