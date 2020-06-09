class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int ** dp = new int*[n+2];
        for(int i=0; i<n+2; i++)
            dp[i] = new int [m+2];
        
        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                if(i==n || j==m)
                    dp[i][j] = 0;
                else{
                    if(text1[i] == text2[j])
                        dp[i][j] = 1 + dp[i+1][j+1];
                    else 
                    {
                        dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                        dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
                    }
                }
            }      
        }
         return dp[0][0];
    }
};
