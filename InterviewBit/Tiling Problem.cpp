// https://www.interviewbit.com/problems/tiling-problem/#
/*
// recursive method 
// the issue with this approach is the stack over flow from the recursive function calls 
int solve2(int index , int lim, int *dp)
{
    if(index>lim)
        return 0;
        
    if(index==lim)
        return 1; // valid tilling 
    
    int &ret = dp[index];
    if(ret!=-1)
        return ret;
    
    // H 
    ret = solve2(index+2, lim ,dp) % (int)(1e9 + 7);
    // V 
    ret = (ret +solve2(index+1 , lim , dp)) % (int)(1e9 + 7);
    return ret;

}
*/


int Solution::solve(int A) {
    int *dp = new int[A+2];
    /*for(int i=0; i<=A; i++)
        dp[i] = -1;*/
    
    // table method
    dp[A+1] = 0; // invalid case 
    dp[A] = 1;
    for(int i=A-1; i>=0; i--)
        dp[i] = (dp[i+1] + dp[i+2]) % (int)(1e9+7); // vertically + horizontally
    return dp[0];
}
