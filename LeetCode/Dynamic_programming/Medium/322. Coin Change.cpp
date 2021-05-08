// 1D sol 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int *dp = new int [amount+1];
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            
            dp[i] = 1e9;
            
            for(int j=0; j<n; j++)
                if(coins[j] <=i)
                    dp[i]= min(dp[i], 1 + dp[i-coins[j]]);
        }
        
        if(dp[amount]==1e9)
            return -1;
        return dp[amount];
    }
};



// 2D sol 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int **dp = new int*[n+1];
        for(int i=0; i<=n; i++)
            dp[i] = new int [amount+1];
        
        
        
        for(int i=n; i>=0; i--){
            for(int j=0; j<=amount; j++){
                if(i==n && j==0)
                    dp[i][j] = 0;
                else if(j==0)
                    dp[i][j]= 0;
                else if(i==n)
                    dp[i][j] = 1e9;
                else{
                    dp[i][j] = dp[i+1][j];
                    if(coins[i]<=j){
                        dp[i][j] = min(dp[i][j], dp[i+1][j-coins[i]] + 1);
                        dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1);
                    }
                    dp[i][j] = min(dp[i][j], (int)1e9);
                }
            }
        }
        if(dp[0][amount] == 1e9)
            return -1;
        return dp[0][amount];
    }
};
