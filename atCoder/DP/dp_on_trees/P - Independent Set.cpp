#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9+7;


int sum_mod(ll a, ll b){
    return (a+b) % mod;
}

int mul_mod(ll a, ll b){
    return (a*b) % mod;
}

void paint(int node, int dad,
        vector<int> g[], int **dp)
{
    dp[node][1] = dp[node][0] = 1;

    for(int i=0; i<g[node].size(); i++){
        int child = g[node][i];
        if(child == dad)
            continue;
        paint(child, node, g, dp);
        ll tmp = sum_mod(dp[child][1] , dp[child][0]);
        dp[node][1] =  mul_mod(dp[node][1], tmp);  // number of ways that subtree rooted at node with node painted in white can be colored.
        dp[node][0] =  mul_mod(dp[node][0], dp[child][1]);
    }

    return ;
}

int main()
{
    int n;
    cin>>n;

    vector<int> g[n+1];
    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int **dp = new int*[n+1];  // dp[][0] = black , dp[][1] = white
    for(int i=0; i<=n; i++){
        dp[i] = new int[2];
        dp[i][0] = dp[i][1] = -1; // no need for this step
    }

    paint(1, -1, g, dp);

    cout<<sum_mod(dp[1][0] ,dp[1][1])<<endl;
    delete []dp;
    return 0;
}
