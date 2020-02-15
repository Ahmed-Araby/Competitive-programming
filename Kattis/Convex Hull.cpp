//////////////////////////////////////
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>

using namespace std;
const double eps = 1e-8;

bool dcmp(double a , double b)
{
    if(fabs(a-b) <= eps)
        return 1;
    return 0;
}

struct point
{// point in coordinate system
    /*
        to be converted to class
        and override all the needed operators
    */
    double x , y;
    point(){}
    point(double _x , double _y)
    {
        x = _x;
        y = _y;
    }
    bool operator == (point & obj) const
    {
        if(dcmp(x , obj.x) && dcmp(y , obj.y))
            return 1;
        return 0;
    }

    bool operator <(point &obj) const
    {
        if(dcmp(x , obj.x))
            return y<obj.y;
        return x<obj.x;
    }

    void get_input()
    {
        cin>>x>>y;
        return ;
    }
};
int orientation_3points(point a , point b , point c)
{
    // points in order {a , b, c }
    // vector1 a to b  , vector2 a to c
    // implemented as in my collage literature
    point v1 , v2;
    // vector 1
    v1.x = b.x - a.x;
    v1.y  = b.y - a.y;
    // vector 2
    v2.x = c.x - a.x;
    v2.y = c.y - a.y;

    /*
    [x1 , x2]
    [y1 , y2]
    solve this detirmnant = signed area of the parallelogram
    */
    double signed_area = v1.x*v2.y - v1.y*v2.x;

    if(dcmp(signed_area , 0))
        return 0;
    else if(signed_area > 0)
        return 1; // turn left = CCW
    else if(signed_area <0)
        return -1; // turn right = CW
    else
        return cout<<"************ UN recognized case ************"<< endl , 0;
}

vector<point> graham_scan(vector<point> p , bool clock_wise = true)
{
    /*
        why we don't deal with the height Y
        inside cases like up and low
    */

    if(p.size()==1)
        return p;

    // get the lowest and highest points
    sort(p.begin() , p.end());

    vector<point> up , low;
    up.push_back(p[0]);
    low.push_back(p[0]);

    for(int i=0; i<p.size(); i++)
    {
        point current_p = p[i];
        int ori = orientation_3points(p[0] , current_p , p[p.size()-1]);

        // upper part  , low to current to high is cw = right turn
        if(ori < 0 || i==p.size()-1)
        {
            while(up.size()>1)
            {
                int sz = up.size();
                int inori = orientation_3points(up[sz-2] , up[sz-1] , current_p);
                if(inori < 0)
                    break;
                else
                    up.pop_back();
            }
            up.push_back(current_p);
        }

        // lower part , left turn
        if(ori > 0 || i==p.size()-1)
        {
            while(low.size()>1)
            {
                int sz = low.size();
                int inori = orientation_3points(low[sz-2], low[sz-1], current_p);
                if(inori >0)
                    break;
                else
                    low.pop_back();
            }
            low.push_back(current_p);
        }
    }

    p.clear();
    for(int i=0; i<up.size(); i++)
        p.push_back(up[i]);
    for(int i=low.size()-2; i>0; i--)
        p.push_back(low[i]);
    if(!clock_wise)
        reverse(p.begin() , p.end());

    // case of 2 identical points
    if(p.size()>=2 && p.back()== p[p.size()-2])
        p.pop_back();
    return p;
}

//////////////////////////////////////////////////////

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        vector<point> v;
        for(int i=0; i<n; i++){
            int x , y;
            cin>>x>>y;
            v.push_back(point(x , y));
        }
        vector<point> hull = graham_scan(v , false);
        cout<<hull.size()<< endl;
        for(int i=0; i<hull.size(); i++)
            cout<<hull[i].x<<" "<<hull[i].y<< endl;
    }
    return 0;
}
