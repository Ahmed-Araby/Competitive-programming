/*
  the whole idea to think in reveresed way 
  instead of saying I will choose the ballon to brust right now 
  say I will choose the ballon that will be the last to be brusted 
  
  cuz this enable us to divide the sequence into two independent parts
  as the left part for the last ballon to be brusted would be able to locate his right ballon 
  which is the last one to be brusted same hold for right part 
  
  but in case of the staritforward thinking 
  left and right part will be affected with each other 
  imagine that we solved each of the left and right part in brute force then
  you will be ablt to see that at some point they will need the result of each other or 
  last ballon of each other 
*/
class Solution {
public:
    int mem[505][505];
    vector<int> *v;
    int get(int index)
    {
        if(index>=v->size() || index<0)
            return 1;
        return v->at(index);
    }
    
    int solve(int l , int r)
    {// it's a bout to choose last ballon to brust 
        
        // base case 
        if(l>r)
            return 0;
        
        // mem
        int &ret=mem[l][r];
        if(ret!=-1)
            return ret;
        // trials 
        // choose the last ballong to brust 
        ret=0;
        for(int i=l; i<=r; i++)
            ret=max(ret , v->at(i)*get(r+1)*get(l-1)+solve(i+1 , r)+solve(l, i-1));
        return ret;
    }
    
    int maxCoins(vector<int>& nums) {
        v=&nums;
        for(int i=0; i<nums.size(); i++)
            for(int j=i; j<=nums.size(); j++)
                mem[i][j]=-1;
        
        return solve(0 , nums.size()-1);    
    }
};
