class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        // in order traversal made 
        // the transation so easy 
        
        int n = arr.size();
        int **dp = new int*[n+2];
        for(int i=0; i<n; i++)
            dp [i] = new int[n+2];
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++){
                // i is the start 
                // j is the end
                if(i==j)
                {
                    dp[i][j] = 0; // leaf 
                    continue;
                }
                dp[i][j] = INT_MAX;
                
                for(int k=i; k<j; k++){    // split
                    int maxl = -1 , maxr = -1;
                    // get min and max 
                    // we can use segment tree here to 
                    // make the code faster 
                    for(int q=i; q<=k; q++)
                        maxl= max(maxl, arr[q]);
                    for(int q=k+1; q<=j; q++)
                        maxr = max(maxr, arr[q]);
                    dp[i][j] = min(dp[i][j], 
                                   maxr*maxl + dp[i][k]  + dp[k+1][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
