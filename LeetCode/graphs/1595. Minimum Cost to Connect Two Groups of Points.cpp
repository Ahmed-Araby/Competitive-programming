class Solution {
public:
    
    bool allSelected(int state, int len)
    {
        return state == pow(2, len) - 1;
    }
    
    
    
    int connect(int leftNode, int rightGS, int cho,
                int n, int m,
                vector<vector<int>>& cost,
                int ***dp)
    {
        if(leftNode == n){
            if(allSelected(rightGS, m))
                return 0;
            return 1e9;
        }
        
        int &ret = dp[leftNode][rightGS][cho];
        if(ret!=-1)
            return ret;
        
        ret = 1e9;
       
        for(int i=0; i<m; i++){
            int bitPos = (1<<i);

            int tmpCost = connect(leftNode+1, rightGS|bitPos, 0,
                             n, m, 
                             cost, 
                             dp) + cost[leftNode][i];
            if(cho < m)
                tmpCost = min(tmpCost,  connect(leftNode, rightGS|bitPos, cho+1, 
                                 n, m, 
                                 cost, 
                                 dp) + cost[leftNode][i]);
            //cout<<leftNode<<" "<<rightGS<<" "<<(rightGS|bitPos)<<" "<<tmpCost<< endl;
            ret = min(ret, tmpCost);
        }
    
        
        return ret;
    }
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        int ***dp = new int**[n+1];
        
        for(int i=0; i<=n; i++){
            
            dp[i] = new int*[1<<m];
            
            for(int j=0; j<(1<<m); j++){
                dp[i][j] = new int[m+1];
               
                for(int k=0; k<=m; k++)
                    dp[i][j][k] = -1;
            }
        }
        return connect(0, 0, 0, n, m, cost, dp);
    }
};
