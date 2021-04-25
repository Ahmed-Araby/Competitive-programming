// https://atcoder.jp/contests/dp/tasks/dp_c?lang=en

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int hap[n+1][4];
    for(int i=0; i<n; i++)
        cin>>hap[i][1]>>hap[i][2]>>hap[i][3];

    int dp[n+1][4]; // [][0] mean first day.
    for(int i=n; i>=0; i--)
    {
        for(int j=0; j<=3; j++) // previous decision.
        {
            if(i==n)
                dp[i][j] = 0;
            else{
                dp[i][j] = 0;
                for(int k=0; k<=3; k++){
                    if(k==j || k==0) continue;
                    dp[i][j] = max(dp[i][j], dp[i+1][k] + hap[i][k]);
                }
            }
        }
    }

    cout<<dp[0][0]<< endl;
    return 0;

}
