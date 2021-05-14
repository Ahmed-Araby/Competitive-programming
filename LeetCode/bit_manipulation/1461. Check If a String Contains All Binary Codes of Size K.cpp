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



// using rolling hash technique.

class Solution {
public:
    
    int count_subStrs(string &s, bool *vis,  int k)
    { // rolling hash
        int n = s.size();
        int cnt  = 0, need = pow(2, k);
        int hash = 0;
        
        for(int i=0; i<n && cnt < need; i++){
            
            int bit = s[i]-'0';
            hash = (hash << 1) & (need-1);
            hash |= bit;
            
            if(i >= k-1){
                if(vis[hash] == 0){
                    cnt +=1;
                    vis[hash] = 1;
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
