// wrong answer
#define pi pair<int, int>

class Solution {
public:

    

    void dfs(int node, int dad, vector<int> g[],
             int *od)
    {
        if(dad!=-1)
            od[node] = 1;
        
        for(int i=0; i<g[node].size(); i++){
            int child = g[node][i];
            if(child == dad) continue;
            
            od[node] +=1;
            dfs(child, node, g, od);
        }

        return ;
    }
    
    void removeConnections(int node, vector<int> g[], int *od, queue<int> &auxLeafs)
    {
        //cout<<"node : "<<node<< endl;
        for(int i=0; i<g[node].size(); i++){
            int child = g[node][i]; 
            if(od[child] >1){ // not leaf, not deleted before
                od[child] -=1;
                if(od[child] == 1) // leaf 
                    auxLeafs.push(child);
            }
        }
    }
    
    vector<int> getCentroids(queue<int> &leafs, int *od, 
                      vector<int> g[])
    {
        queue<int> auxLeafs;
        vector<int> centroids;
        while(true)
        {
            while(!leafs.empty())
            {
                int node = leafs.front();
                leafs.pop();
                removeConnections(node, g, od, auxLeafs);
            }
            
            if(auxLeafs.size() <=2){
                while(!auxLeafs.empty()){
                    centroids.push_back(auxLeafs.front());
                    auxLeafs.pop();
                }
                break;
            }
            
            else {
                while(!auxLeafs.empty()){
                    leafs.push(auxLeafs.front());
                    auxLeafs.pop();
                }
            }
        }
        
        return centroids;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
                
        if(n <=2)
        {
            vector<int> ans;
            for(int i=0; i<n; i++)
                ans.push_back(i);
            return ans;
        }
        vector<int> g[n+1];
        for(int i=0; i<n-1; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int *oD = new int[n+1];
        for(int i=0; i<=n; i++)
            oD[i] = 0;
        
        queue<int> leafs;
        dfs(0, -1, g, oD);
        for(int i=0; i<n; i++)
            if(oD[i] == 1)
                leafs.push(i);
        /*
        for(int i=0; i<n; i++)
            cout<<oD[i]<<" ";
        cout<< endl;
       */
        vector<int> centroids = 
            getCentroids(leafs, oD, g);
        return centroids;
        

    }
};
