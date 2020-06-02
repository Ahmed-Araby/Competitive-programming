class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        
        int ** dp = new int*[n+2];
        for(int i=0; i<n+2; i++)
            dp[i] = new int [n+2];
        
        // base case 
        
        for(int i=n; i>=0; i--)
        {
            // try all columns 
            for(int j=0; j<n; j++)
            {
                // base case
                if(i==n){
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = A[i][j] + dp[i+1][j];
                if(j>0)
                    dp[i][j] = min(dp[i][j] , A[i][j]+dp[i+1][j-1]);
                if(j+1<n)
                    dp[i][j] = min(dp[i][j], A[i][j]+dp[i+1][j+1]);
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
            ans = min(ans, dp[0][i]);
        return ans;
    }       
};
