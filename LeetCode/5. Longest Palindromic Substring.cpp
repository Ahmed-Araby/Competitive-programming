/*
  there is a plenty of powerfull algos 
  that can solve this problem 
*/
class Solution {
public:
    string str;
    int mem[1005][1005];
    int solve(int s , int e)
    {
        if(s>=e)
            return 1;
        
        int &ret=mem[s][e];
        if(ret!=-1)
            return ret;
        ret=0;
        if(str[s]==str[e])
            return solve(s+1 , e-1);
        return 0;
    }
    string longestPalindrome(string s) {
        
        //  initialization 
        for(int i=0; i<s.size(); i++)
            for(int j=i; j<s.size(); j++)
                mem[i][j]=-1;
        
        str=s;
        int maxi=0 , mi=0, mj=0;
        for(int i=0; i<s.size(); i++)
            for(int j=i; j<s.size(); j++)
                if(solve(i  , j)==1 && j-i+1>maxi){
                    maxi=j-i+1;
                    mi=i;
                    mj=j;
                }
        string ans="";
        for(int i=mi; i<=mj; i++)
            ans+=s[i];
        return ans;
    }
};
