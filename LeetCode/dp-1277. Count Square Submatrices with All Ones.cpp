class Solution {
public:
    int get_sum(int **dp, int si, int sj, int ei , int ej)
    {
        int sum = dp[ei][ej];
        if(si-1>=0)
            sum -= dp[si-1][ej];
        if(sj-1>=0)
            sum -=dp[ei][sj-1];
        if(si-1>=0 && sj-1>=0)
            sum +=dp[si-1][sj-1];
        return sum;
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ** dp  = new int*[n];

        // H 
        for(int i=0; i<n; i++)
        {
            dp [i] = new int [m];
            dp[i][0] = matrix[i][0];
            for(int j=1; j<m; j++)
                dp[i][j] = dp[i][j-1] + matrix[i][j];
        }
        
        // v 
        for(int j=0; j<m; j++)
            for(int i=1; i<n; i++)
                dp[i][j] +=dp[i-1][j];
        
        
        int cnt = 0;
        // check square matrices 
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                for(int side=1; side<=min(n, m); side++)
                {
                    int ei = i+side-1;
                    int ej = j+ side-1;
                    if(ei >=n || ej >=m)
                        continue;
                    int sum = side==1?matrix[i][j]:get_sum(dp, i, j, ei, ej);
                    if(sum == side*side)
                        cnt+=1;
                }
        return cnt;
    }
};
