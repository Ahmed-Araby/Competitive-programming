// http://www.usaco.org/index.php?page=viewproblem2&cpid=766#

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
            vector<int> g[], int color[],
            int **dp)
{
    if(color[node]==0) // no const color
        dp[node][1] = dp[node][2] = dp[node][3] = 1;
    else{
        dp[node][1] = dp[node][2] = dp[node][3] = 0;
        dp[node][color[node]] = 1;
    }

    for(int i=0; i<g[node].size(); i++){
        int child = g[node][i];
        if(child == dad) continue;

        paint(child, node, g, color, dp);

        // node colored in 1
        int tmp = sum_mod(dp[child][2], dp[child][3]);
        dp[node][1] = mul_mod(dp[node][1] , tmp);

        // node colored in 2
        tmp = sum_mod(dp[child][1], dp[child][3]);
        dp[node][2] = mul_mod(dp[node][2], tmp);

        // node colored in 3
        tmp = sum_mod(dp[child][1], dp[child][2]);
        dp[node][3] = mul_mod(dp[node][3], tmp);

    }

    return ;
}

int main()
{

    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int n,k;
    cin>>n>>k;

    vector<int> g[n+1];
    int color[n+1] = {0};

    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    int root = 1;
    for(int i=0; i<k; i++){
        int node, c;
        cin>>node>>c;
        color[node] = c;
        root = node;
    }

    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++)
        dp[i] =  new int [4];

    paint(root, -1, g, color, dp);
    int ans = sum_mod(dp[root][1], dp[root][2]);
    ans = sum_mod(ans, dp[root][3]);
    cout<<ans<< endl;

    return 0;
}
