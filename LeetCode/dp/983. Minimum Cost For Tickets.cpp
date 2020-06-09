
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ** dp = new int*[n+2];
        
        for(int i=0; i<n+2; i++)
            dp[i] = new int[396];
        int ticket [] = {1 , 7 , 30};
        
        
        
        for(int i=n; i>=0; i--)
        {
            for(int j=1; j<=395; j++)
            {
                if(i==n)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = INT_MAX;
                    
                    if(j > days[i])  // still covered
                            dp[i][j] = dp[i+1][j];
                    else
                        for(int k=0; k<3; k++)
                            dp[i][j] = min(dp[i][j] , costs[k] + dp[i+1][days[i]+ticket[k]]);
                }
            }
        }
        return dp[0][1];
    }
};
