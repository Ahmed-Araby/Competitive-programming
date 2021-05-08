#define ll long long
class Solution {
    static const int mod = 1e9+7;
    
public:
    void generateTiles(int index, string cur,
                       char opts[], vector<string> &tiles)
    {
        if(index == 3){
            tiles.push_back(cur);
            return ;
        }
        
        for(int i=0; i<3; i++){
            if(index==0  || opts[i] !=cur[index-1]){
                string tmp = cur + opts[i];
                generateTiles(index+1, tmp, opts, tiles);
            }
        }
        
        return ;
    }
    
    
    bool paired(string a, string b)
    {
        for(int i=0; i<3; i++)
            if(a[i]==b[i])
                return 0;
        return 1;
    }
    
    int add_mod(ll a, ll b)
    {
        a = a %mod;
        b = b % mod;
        return (a+b) % mod;
    }
    
    int countGrids(int index, int prevR,
                   int **dp, 
                  int n, vector<string> &tiles )
    {
        if(index==n)
            return 1;
        int &ret = dp[index][prevR];
        if(ret!=-1)
            return ret;
        
        ret = 0;
        
        for(int i=1; i<=12; i++){
            if(paired(tiles[prevR], tiles[i])){
                //cout<<"here "<<i<< endl;
                ret = add_mod(ret, countGrids(index+1, i, dp, n, tiles));
            }
        }
        return ret;
    }
    int numOfWays(int n) {
        vector<string> tiles;
        tiles.push_back("---");
        char opts[] = {'r', 'y', 'g'};
        generateTiles(0, "", opts, tiles);
        
        // dp sol
        int **dp = new int* [n+1];
        for(int i=0; i<=n; i++){
            
            dp[i] = new int[13];
            for(int j=0; j<13; j++)
                dp[i][j] = -1;
        }
        
        return countGrids(0, 0, dp, n, tiles);
    }
};
