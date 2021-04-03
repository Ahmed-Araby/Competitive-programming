// https://vjudge.net/contest/430686#problem/H
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, w;
    cin>>n>>w;
    int *we = new int [n+2];
    int *val = new int[n+2];
    for(int i=0; i<n; i++)
        cin>>we[i]>>val[i];

    ll **dp = new ll*[n+2];
    for(int i=0; i<=n; i++){
        dp[i] = new ll[w+2];
        for(int j=0; j<=w; j++)
            dp[i][j] = -1;
    }

    // tabular solution
    for(int i=n; i>=0; i--){
        for(int j=w; j>=0; j--){
            if(i==n || j==0)
                dp[i][j] = 0;
            else{
                dp[i][j] = dp[i+1][j];
                if(we[i] <= j)
                    dp[i][j] = max(dp[i][j], dp[i+1][j-we[i]] + val[i]);
            }
        }
    }
    cout<<dp[0][w]<< endl;
    return 0;
}
