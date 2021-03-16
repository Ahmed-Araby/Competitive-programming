#define ll long long

class Solution {
public:
    int build_subRect(int r1, int c1, int target,
                     ll **cs, int n, int m)
    {
        int freq = 0;
        for(int i=r1; i<n; i++){
            for(int j=c1; j<m; j++){
                ll sum = get_sum(r1, c1, i, j, cs);
                //cout<<"sum is : "<<sum<< endl;
                if(sum == target)
                    freq+=1;
            }
        }
        return freq;
    }
    
    ll get_sum(int r1, int c1, int r2, int c2, ll **cs){
        ll s1 = 0, s2 = 0, s3 = 0;
        if(r1-1 >=0)
            s1  = cs[r1-1][c2];
        if(c1-1 >=0)
            s2 = cs[r2][c1-1];
        if(r1-1>=0 && c1-1>=0)
            s3 = cs[r1-1][c1-1];
        return cs[r2][c2] - s1 - s2 + s3;
    }
    
    int numSubmatrixSumTarget(vector<vector<int> >& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        // cs
        ll **cs = new ll*[r];
        for(int i=0; i<r; i++){
            cs[i] = new ll [c];
            for(int j=0; j<c; j++)
                cs[i][j] = 0;
        }
        
        // col wise 
        for(int i=0; i<r; i++){
            cs[i][0] = matrix[i][0];
            for(int j=1; j<c; j++)
                cs[i][j] = cs[i][j-1] + matrix[i][j];
        }
        
        // row wise 
        for(int j=0; j<c; j++){
            for(int i=1; i<r; i++)
                cs[i][j] += cs[i-1][j];
        }
        
        
        /*for(int i=0; i<r; i++){
            for(int j=0; j<c; j++)
                cout<<cs[i][j]<<" ";
            cout<< endl;
        }*/
        
            
        // get sum for the subqueries.
        // begining of the subRect.
        int freq = 0;
        for(int r1=0; r1<r; r1++)
            for(int c1=0; c1<c; c1++){
                int cnt = build_subRect(r1, c1, target,
                                       cs, r, c);
                freq +=cnt;
            }
        return freq;
    }
};
