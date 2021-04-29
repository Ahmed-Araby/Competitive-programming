/*
https://atcoder.jp/contests/dp/tasks/dp_o
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;

int add_mod(ll a, ll b)
{
    a = a%mod;
    b = b%mod;
    return (a+b) % mod;
}

int solve(int manIndex, int mask,
          int n, bool comp[][22],
          int **dp)
{
    if(manIndex == n)
        return 1;
    if(dp[manIndex][mask]!=-1)
        return dp[manIndex][mask];

    int &ret = dp[manIndex][mask];
    ret = 0;

    for(int i=0; i<n; i++)
    {
        if(!comp[manIndex][i] || mask & (1<<i)) // already paired
            continue;
        int tmp = solve(manIndex + 1, mask | (1<<i), n, comp, dp);
        ret = add_mod(ret, tmp);
    }
    return ret;
}

int count_pairing(int n, bool comp[][22])
{
    int **dp = new int *[n+2];
    for(int i=0; i<=n; i++){
        dp[i] = new int [1<<21]; // pow(2, 21) -1 = 21 BIT each = 1
        int m = 1<<21;
        for(int j=0; j<m; j++)
            dp[i][j] = -1;
    }
    return solve(0, 0,
          n, comp,
          dp);
}

int main()
{

    int n;
    cin>>n;

    bool comp[22][22];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>comp[i][j];

    cout<<count_pairing(n, comp)<< endl;
    return 0;
}


////////////////////////////////////////////////////////////////////////////
/*
    tabular solution will get TLE as this sol 
    will build all the table including the cases that will never happen.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;

int add_mod(ll a, ll b)
{
    a = a%mod;
    b = b%mod;
    return (a+b) % mod;
}

int count_pairing(int n, bool comp[][22])
{
    int **dp = new int *[n+2];
    for(int i=0; i<=n; i++)
        dp[i] = new int [1<<n]; // pow(2, 21) -1 = 21 BIT each = 1

    for(int i=n; i>=0; i--)
    {
        for(int j = (1<<n) -1; j>=0; j--)
        {
            if(i==n )
                dp[i][j] = 1;
            else if(j==(1<<n) - 1) // cant happen in real life.
                dp[i][j] = -1;
            else
            {
                dp[i][j] = 0;
                for(int k=0; k<n; k++)
                {
                    if(!comp[i][k] || (j & (1<<k)))
                        continue;
                    dp[i][j] = add_mod(dp[i][j], dp[i+1][j|(1<<k)]);
                }
            }
        }
    }
    return dp[0][0];
}

int main()
{

    int n;
    cin>>n;

    bool comp[22][22];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>comp[i][j];

    cout<<count_pairing(n, comp)<< endl;
    return 0;
}
