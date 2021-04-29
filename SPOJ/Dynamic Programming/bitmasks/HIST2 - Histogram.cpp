// https://www.spoj.com/problems/HIST2/
#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

pi get_max_perm(int *h, int n, pi **dp)
{

    for(int i = (1<<n) - 1; i>=1; i--)
    {
        for(int j=0; j<n; j++)
        {
            //cout<<j<<" "<<i<< endl;
            if(i==(1<<n) -1)
                dp[j][i] = {h[j], 1};
            else
            {
                dp[j][i] = {0, 0};
                for(int k=1; k<n; k++)
                {
                    //cout<<"here "<<k<< endl;
                    if(i&(1<<k)) continue;

                    pi tmp = dp[k][i|(1<<k)];

                    tmp.first += abs(h[k] - h[j]);

                    if(tmp.first == dp[j][i].first)
                        dp[j][i].second += tmp.second;
                    else if(tmp.first > dp[j][i].first)
                        dp[j][i] = tmp;
                }
            }
        }
    }

    return dp[0][1];
}

const int sz = 16;
int main()
{
   int *h = new int[sz];
   pi **dp = new pi *[sz];
    for(int i=0; i<sz; i++)
        dp[i] = new pi [1<<(sz)];

   while(true)
   {
       int n;
       cin>>n;
       if(!n) break;
       n+=1;
       h[0] = 0;
       for(int i=1; i<n; i++)
            cin>>h[i];

       pi ans = get_max_perm(h, n, dp);
       cout<<ans.first + 2 * (n - 1)<<" "<<ans.second<< endl;
   }

   delete []h;
   delete [] dp;
   return 0;
}
