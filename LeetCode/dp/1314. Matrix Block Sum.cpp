#define pi pair<int, int>
class Solution {
public:
    
    
    void disp(int **cs, int n, int m)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<cs[i][j]<<" ";
            }
            cout<< endl;
        }
        return ;
    }
    
    void cs_rows(int **cs, int n, int m)
    {
        for(int j=0; j<m; j++)
            for(int i=1; i<n; i++)
                cs[i][j] += cs[i-1][j];
        return ;
    }
    
    void cs_cols(vector<vector<int>>& mat, int **cs)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            cs[i][0] = mat[i][0];
            for(int j=1; j<m; j++)
                cs[i][j] = cs[i][j-1] + mat[i][j];
            
        }
        return ;
    }
    
    pi getLP(int i, int j, int n, int m, int k)
    {
        i +=k;
        j +=k;
        i = min(i, n-1);
        j = min(j, m-1);
        return {i, j};
    }
    
    pi getUP(int i, int j, int n, int m, int k)
    {
        i -=k;
        j -=k;
        i = max(0, i);
        j = max(0, j);
        return {i, j};
    }
    
    bool valid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int getSum(pi p,  int **cs, int n, int m)
    {
        if(!valid(p.first, p.second, n, m))
            return 0;
        return cs[p.first][p.second];
    }
    
    int getSum(pi up, pi lp, int **cs, int n, int m)
    {
        pi ru = make_pair(up.first-1, lp.second);
        pi ld = make_pair(lp.first, up.second -1);
        pi lu = make_pair(up.first -1, up.second -1);
        
        return getSum(lp, cs, n, m) 
            - getSum(ru, cs, n, m) 
            - getSum(ld, cs, n, m)
            + getSum(lu, cs, n, m);
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int **cs = new int *[n+1];
        for(int i=0; i<=n; i++){
            cs[i] = new int [m+1];
            for(int j=0; j<=m; j++)
                cs[i][j]  = 0;
        }
        
        cs_cols(mat, cs);        
        cs_rows(cs, n, m);
        vector<vector<int> >res(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pi l = getLP(i, j, n, m, k);
                pi u = getUP(i, j, n, m , k);
                //cout<<i<<" "<<j<<" "<<u.first<<" "<<u.second<< endl<<endl;
                int tmpRes = getSum(u, l, cs, n, m);
                res[i].push_back(tmpRes);
            }
        }
        return res;
    }
};
