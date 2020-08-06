class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int adep = 0 , bdep = 0;
        int ae=0 , be=0;
        
        int n = seq.size();
        vector<int> mark(n);
        vector<int> end(n);
        
        // assign ends 
        
        stack<int> s;
        for(int i=0; i<n; i++){
            if(seq[i]==')'){
                end[s.top()] = i;
                end[i] = -1;
                s.pop();
            }
            else
                s.push(i);
        }
        
        for(int i=0; i<n; i++){
            if(end[i]==-1){ // end 
                if(mark[i]==0)
                    ae--;
                else 
                    be--;
                continue;
            }
            
            int endi = end[i];
            
            if(ae + 1 <= be +1)
            {
                adep = max(adep , ae+1);
                ae ++;
                mark[i] = mark[endi] = 0;
            }
            else{
                bdep = max(bdep, be+1);
                be ++;
                mark[i] = mark[endi] = 1;
            }
        }
        return mark;
    }
};
