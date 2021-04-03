// dividing coins
#include <bits/stdc++.h>
using namespace std;
const int sz = 105;
const int maxSum = 500*100+1;
const int maxSum_2 = 2 * maxSum;
const int step = 500*100;  // solve the negative issue
int dp[sz][maxSum_2];  // store absolute dif

 
int main()
{
    int t;
    cin>>t;
    int *coins = new int[sz];

    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        for(int i=0; i<n; i++){
            cin>>coins[i];
            sum +=coins[i];  // +ve coins always.
        }
/*
        for(int i=0; i<=n; i++)
            for(int j=0; j<=2*sum+2; j++)
                dp[i][j] = -1;
*/
        // solve in tabular manner
        for(int i=n; i>=0; i--){
            for(int dif=-sum; dif<=sum; dif++){
                if(i==n)
                    dp[i][dif+step] = 0;
                else{
                    int ans1 = 1e9, ans2=1e9;
                    // give the coin to person a
                    int tmpDiff = dif + coins[i];
                    if(abs(tmpDiff) <=sum)
                        ans1 = dp[i+1][tmpDiff+step] + coins[i];

                    // give the coin to person b
                    tmpDiff = dif - coins[i];
                    if(abs(tmpDiff) <= sum)
                        ans2 = dp[i+1][tmpDiff+step] - coins[i];

                    //cout<<i<<" "<<dif<< endl;
                    //cout<<"ans1 :"<<ans1<<"  ans2 :"<<ans2<< endl;
                    //cout<< endl;

                    if(abs(ans1+dif) <= abs(ans2+dif))
                        dp[i][dif+step] = ans1;
                    else
                        dp[i][dif+step] = ans2;
                }
            }
        }

        cout<<abs(dp[0][0+step])<< endl;
    }
    return 0;
}
