class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int ** dp = new int* [n+2];
        
        
        /*
        put them in the optimal order to accomidate with the 
        ability to pick the chain in any order
        */
        
        sort(pairs.begin() , pairs.end());
        
        for(int i=0; i<n+2; i++)
            dp[i] = new int [n+2];
    
        for(int i=n; i>=0; i--){  // current
            for(int j=0;j<n; j++){  // previous
                
                if(i==n || j>i)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = 0;
                    
                    if(i==j || pairs[j][1] < pairs[i][0]) // pick 
                        dp[i][j] = 1 + dp[i+1][i];
                    dp[i][j] = max(dp[i][j], dp[i+1][j]);  // leave 
                }
            }
        }
        
        /*
        we may have different starts
        */
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans ,dp[i][i]);
        return ans;
    }
};
