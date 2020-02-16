/*
bug is in checking the point to lie inside a concave polygon
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <set>

using namespace std;
const double eps = 1e-8;

bool vis[1005];
bool dcmp(int a , int b)
{
    if(fabs(a-b) == 0)
        return 1;
    return 0;
}

struct point
{// point in coordinate system
    /*
        to be converted to class
        and override all the needed operators
    */
    int x , y;
    point(){}
    point(int _x , int _y)
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
    int signed_area = v1.x*v2.y - v1.y*v2.x;

    if(dcmp(signed_area , 0))
        return 0;  // colinear
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

bool check_point_inside_convex_polygon(point c , vector<point> &hull , int index)
{
    set<int> d;
    for(int i=0; i<hull.size(); i++)
    {
        if(i==index)
            continue;
        // segment
        point a = hull[i] , b = hull[(i+1)%hull.size()];
        int ori = orientation_3points(a , b , c);
        if(ori==0) // colinear is okay
            continue;
        d.insert(ori);
    }
    return d.size()==1;
}

void solve2(vector<point> &hull , vector<point> &sp)
{
    /*
    cout<<"HULL "<< endl;
    for(int i=0; i<hull.size(); i++)
        cout<<hull[i].x<<" "<<hull[i].y<< endl;
    cout<<"done"<< endl;
    cout<< endl;
    */

    // check for pointes been enclosed using this hull
    for(int i=0; i<sp.size(); i++)
    {
        point tmp_p= sp[i];
        vis[i] = vis[i] |check_point_inside_convex_polygon(tmp_p , hull);
    }
    return ;
}

void solve1(vector<point> &hull , vector<point> &np , vector<point> &sp)
{

    for(int i=0; i<np.size(); i++){
        point tmp_p = np[i];
        if(tmp_p == hull[0] || tmp_p == hull[1] || tmp_p == hull[2])
            continue;

        // enlarage the hull and convert it to concave
        for(int j=0; j<hull.size(); j++)
        {
            // build the current concave hull
            point a , b , c;
            vector<point> tmp_hull;
            for(int k=0; k<j; k++)
                tmp_hull.push_back(hull[k]);
            tmp_hull.push_back(tmp_p);
            for(int k=j; k<hull.size(); k++)
                tmp_hull.push_back(hull[k]);

            if(j==0)
                a = hull[hull.size()-1];
            else
                a = hull[j-1];
            b = tmp_p;
            c = hull[j];

            if(orientation_3points(a , b , c) !=0)
                solve2(tmp_hull , sp);
            /*else{
                cout<<"colinear :"<<j<< endl;
                cout<<a.x<<" "<<a.y<< endl;
                cout<<b.x<<" "<<b.y<< endl;
                cout<<c.x<<" "<<c.y<< endl;
                cout<< endl;
            }*/
        }
    }
    return ;
}

int main()
{
  int n;
  cin>>n;
  vector<point> np;

  // get nazi trops points
  for(int i=0; i<n; i++){
    int x , y;
    cin>>x>>y;
    np.push_back({x , y});
  }

  // get soviet points
  int s;
  cin>>s;
  vector<point> sp;
  for(int i=0; i<s; i++)
  {
    int x , y;
    cin>>x>>y;
    sp.push_back({x ,  y});
  }

  // get the hull
  vector<point> hull = graham_scan(np);



  // small hull but we can enalrage it
  if(hull.size() <4 && np.size()>=4)
    solve1(hull , np , sp);
  // good hull that will enclose all the nazi points
  // so it speeks for all the quadetrial shapes
  else if(hull.size()>=4)
    solve2(hull , sp);

  // count
  int ans = 0;
  for(int i=0; i<s; i++)
    if(vis[i])
        ans+=1;
  cout<<ans<< endl;
  return 0;
}
