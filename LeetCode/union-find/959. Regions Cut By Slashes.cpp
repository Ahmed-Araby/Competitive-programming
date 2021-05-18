struct sq
{
    int l, r, u, d;
    sq()
    {
        
    }
};


struct dsu
{
    int *p;
    int *r;
    int n;
    dsu(int _n)
    {
        n = _n;
        p = new int[n+1];
        r = new int[n+1];
        for(int i=0; i<=n; i++)
        {
            p[i] = i;
            r[i] = 0;
        }
        return ;
    }
    
    int find(int a)
    {
        return p[a] == a?a:p[a] = find(p[a]);
    }
    
    void _union(int a, int b)
    {
        int ra = find(a);
        int rb = find(b);
        if(ra == rb)
            return ;
        if(r[ra] > r[rb])
            p[rb] = ra;
        else if(r[rb] > r[ra])
            p[ra] = rb;
        else {
            p[rb] = ra;
            r[ra] +=1;
            r[rb] = 0;
        }
        return ;
    }
};

class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int id = 1;
        
        sq **dirs = new sq* [n+1];
        for(int i=0; i<=n; i++)
            dirs[i] = new sq[n+1];

        dsu _dsu(n*n*2+2);
        
        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    dirs[i][j].l = dirs[i][j].u = id++;
                    dirs[i][j].r = dirs[i][j].d = id++;
                }
                else if(grid[i][j]=='\\'){
                    dirs[i][j].l = dirs[i][j].d = id++;
                    dirs[i][j].r = dirs[i][j].u = id++;
                }
                else 
                    dirs[i][j].r = dirs[i][j].u = dirs[i][j].l = dirs[i][j].d = id++;

                // connect to build the disjoint set
                if(valid(i-1, j, n, n))
                    _dsu._union(dirs[i-1][j].d, dirs[i][j].u);
                if(valid(i, j-1, n, n))
                    _dsu._union(dirs[i][j-1].r, dirs[i][j].l);
            }
        }
        
        // count different disjoint sets
        set<int> s;
        for(int i=1; i<id; i++)
            s.insert(_dsu.find(i));
        
        return s.size();
        
    }
};
