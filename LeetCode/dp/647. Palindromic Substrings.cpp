class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        
        bool ** dp = new bool* [n+1];
        for(int i=n-1; i>=0; i--){
            dp[i] = new bool [n+1];
            
            for(int j=0; j<n; j++){
                if(i>j)
                    dp[i][j] = 0;
                
                // handle odd and even length palindrom
                else if(i==j || (i==j-1 && s[i]==s[j]))
                    dp[i][j] = 1;
                
                else if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                    
                else
                    dp[i][j] = 0;
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cnt+=int(dp[i][j]);
        return cnt;
        
    }
};
