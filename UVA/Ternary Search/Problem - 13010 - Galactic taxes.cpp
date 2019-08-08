/*
no mathematical proof that this function is convex 
*/
#include <bits/stdc++.h>
#define pd pair<ld, int>
#define ld long double
using namespace std;
int n , m;
const int sz=1005;
struct node
{
    int t , a , b;
    node(){}
    node(int pt , int pa , int pb)
    {
        t=pt;
        a=pa;
        b=pb;
    }
};
ld dijkstra(ld t  , vector<node> g[])
{
    priority_queue<pd ,  vector<pd> , greater<pd> > pq;
    ld dis[sz];
    for(int i=0; i<=n; i++)
        dis[i]=1e14;
    dis[1]=0;
    pq.push({0 , 1});
    while(!pq.empty())
    {// we don't move from a node twice thanks to dijkstra.
        int s=pq.top().second;
        ld d=pq.top().first;

        pq.pop();

        // prune
        if(s==n)
            break;

        // relax
        for(int i=0; i<g[s].size(); i++)
        {
            int child=g[s][i].t;
            ld a=g[s][i].a;
            ld b=g[s][i].b;
            ld cost=a*t+b;
            if(dis[child]>cost+d)
            {
                dis[child]=cost+d;
                pq.push({dis[child], child});
            }
        }
    }
    return dis[n];
}
int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);

    while(cin>>n>>m)
    {
        vector<node> g[n+1];
        for(int i=0; i<m; i++)
        {
            int f , t , a , b;
            cin>>f>>t;
            cin>>a>>b;
            g[f].push_back(node(t , a , b));
            g[t].push_back(node(f , a , b));
        }
        //  concave down function we search for global max in range[0 , 24*60]
        ld l=0 , r=24*60 , m1=0 , m2=0 , maxi=-1;
        for(int i=0; i<200; i++)
        {
            ld dis=(r-l)/3;
            m1=l+dis;
            m2=r-dis;
            ld fl=dijkstra(m1, g);
            ld fr=dijkstra(m2 , g);
            //cout<<fl<<" "<<fr<< endl;
            maxi=max(maxi , max(fl , fr));
            if(fl<fr)
                l=m1;
            else // both fl>fr and fl==fr
                r=m2;
        }
        cout<<fixed<<setprecision(5)<<maxi<< endl;
    }
    return 0;
}
