class Solution {
public:
    string str;
    int mem[1005][1005];
    int solve(int s , int e)
    {
        if(s==e)
            return 1;
        else if(s>e)
            return 0;
        
        int &ret=mem[s][e];
        if(ret!=-1)
            return ret;
        ret=0;
        
        if(str[s]==str[e])
            ret=2+solve(s+1 , e-1);
        else{ // skip strategy 
            ret=solve(s+1 , e);
            ret=max(ret , solve(s , e-1));
        }
        return ret;
    }
    
    int longestPalindromeSubseq(string s) {
        str=s;
        for(int i=0; i<s.size(); i++)  
            for(int j=i; j<s.size(); j++)
                mem[i][j]=-1;
        int maxi=0;
        for(int i=0; i<s.size(); i++)
            for(int j=i; j<s.size(); j++)
                maxi=max(maxi , solve(i , j));
        return maxi;
    }
};
