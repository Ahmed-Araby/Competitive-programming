class Solution {
public:
    int hash(deque<char> tmp)
    {
        int index = 0;
        int n = tmp.size();
        for(int i=n-1; i>=0; i--){
            int bit = tmp[i] -'0';
            index = index + bit * pow(2, n-i-1);
        }
        return index;
    }
    
    int count_subStrs(string &s, bool *vis,  int k)
    {
        int n = s.size();
        int cnt  = 0, need = pow(2, k);
        deque<char> tmp;
        
        
        for(int i=0; i<n && cnt < need; i++)
        {
            tmp.push_back(s[i]);
            
            if(tmp.size() == k){
                int index = hash(tmp);
                tmp.pop_front();
                if(vis[index] == 0){
                    cnt +=1;
                    vis[index] = 1;
                }
            }
        }
        
        return cnt;
    }
    
    bool hasAllCodes(string s, int k) {
        
        int need = pow(2, k);
        bool *vis= new bool[need+1];
        for(int i=0; i<=need; i++)
            vis[i] = 0;
        
        
        int cnt = count_subStrs(s, vis, k);
        return cnt == need;
    }
};
