#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *h = new int[n+2];
    for(int i=0; i<n; i++)
        cin>>h[i];
    int *dp= new int[n+2];
    dp[n] = 0;
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        dp[i] = 1e9+5;
        if(i+2<n)
            dp[i] = dp[i+2] + abs(h[i+2] - h[i]);
        dp[i] = min(dp[i], dp[i+1] + abs(h[i+1]-h[i]));

    }
    cout<<dp[0]<< endl;
    return 0;
}
