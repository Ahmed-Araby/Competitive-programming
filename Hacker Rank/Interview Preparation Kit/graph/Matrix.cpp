#include <bits/stdc++.h>
#define ll long long
#define pi pair<int ,int>
#define pll pair<long long , long long>

using namespace std;

int get_root(int n, bool *machine)
{
    for(int i=0; i<n; i++)
        if(!machine[i])
            return i;
    return -1;
}

ll get_cost(vector<pi> *g, int n)
{
    ll cost = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<(int)g[i].size(); j++)
            cost += g[i][j].second;
    }
    return cost / 2;
}


pll destroy_roads(int root, int dad, vector<pi> *g, bool *machines, bool *vis)
{
    vis[root] = 1;
    ll max = 0, sum = 0;
    for(int i=0; i<(int)g[root].size(); i++)
    {
        int child = g[root][i].first;
        int ti = g[root][i].second;
        if(child == dad) continue;
        
        // {max, sum} = {leave for now, must be destoried} of the bellow subtree
        pll tmp = destroy_roads(child,  root, g, machines, vis);
        sum += tmp.second;
        ll tmax = tmp.first;
        
        if(machines[child]) // then tmp.first will be zero.
            tmax = ti;
        
        tmax = min(tmax, (ll)ti);
        if(tmax > max){
            sum +=max;
            max =tmax;
        }
        else
            sum += tmax;
    }    
    
    // take decision on how to destroy roads.
    if(machines[root]){
        sum += max;
        max = 0;
    }
    return {max, sum};
}

int main()
{
    int n , k;
    cin>>n>>k;
    
    vector<pi> *g = new vector<pi>[n+2];
    bool *machine = new bool[n+2];
    for(int i=0; i<=n; i++)
        machine[i] = 0;
        
    for(int i=1; i<n; i++){
        int f, t, co;
        cin>>f>>t>>co;
        g[f].push_back({t, co});
        g[t].push_back({f, co});
    }
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        machine[x] = 1;
    }
    
    int root = get_root(n, machine);
    if(root == -1)
        cout<<get_cost(g, n)<< endl;
    else {
        
        ll ans = 0;
        bool *vis = new bool[n+1];
        for(int i=0; i<=n; i++)
            vis[i] = 0;
        
        for(int i=0; i<n; i++){
            if(machine[i] || vis[i]) continue;
            pll tmp = destroy_roads(root, -1, g, machine, vis);
            ans += tmp.second;
        }
        cout<<ans<< endl;
    }
    
    delete []g;
    delete [] machine;
    return 0;
}
