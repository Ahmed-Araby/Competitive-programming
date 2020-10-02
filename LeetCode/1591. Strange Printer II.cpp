/*
this case will take down my condition 
which is overlap > 2 mean there is no way to paint 

- - - -
1 1 1 -
1 2 2 3
- 3 3 3 


greedy solution 
paint the color with biggest abstruct rect first
*/

#define pi pair<int, int>

struct rect
{
    int x1, y1;
    int x2, y2;
    rect(){
        x1 = INT_MAX;
        y1 = INT_MAX;
        x2 = -1;
        y2 = -1;
    }
};


class Solution {
public:
    void buildGraph(rect *r, vector<vector<int>>& targetGrid, vector<int> *g)
    {
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        
        for(int i=1; i<61; i++)
            if(r[i].x1 != INT_MAX){
                for(int x=r[i].x1; x<=r[i].x2; x++)
                    for(int y=r[i].y1; y<=r[i].y2; y++)
                        if(targetGrid[x][y]!=i)
                            g[i].push_back(targetGrid[x][y]);  
            }
        return ;
    }
    
    bool dfs_cycleExist(int root, vector<int> *g,
                        bool *vis, bool *dad)
    {
        if(dad[root])
            return true;
        
        if(vis[root])
            return false;
        
        vis[root] = true;
        dad[root] = true;
        
        for(int i=0; i<g[root].size(); i++)
        {
            int child = g[root][i];
            if(dfs_cycleExist(child, g, vis, dad))
                return true;
        }
        
        dad[root] = false;
        return false;
    }
    
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size();
        int m = targetGrid[0].size();
        
        // build abstruct rectangles
        rect r[61];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int color = targetGrid[i][j];
                r[color].x1 = min(r[color].x1, i);
                r[color].y1 = min(r[color].y1, j);
                
                r[color].x2 = max(r[color].x2, i);
                r[color].y2 = max(r[color].y2, j);
            }
        }
        
        // build the grph 
        vector<int> g[61];
        buildGraph(r, targetGrid, g);
        
        // check graph for cycles
        bool vis[61]={0}, dad[61]={0};
        for(int i=1; i<=60; i++)
        {
            if(vis[i])
                continue;
            if(dfs_cycleExist(i, g, vis, dad))
                return false;
        }
        return true;
    }

};
