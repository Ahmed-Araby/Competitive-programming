class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        /*
        just get the join probability
        */
        /*
        float prop = 1;
        for(int i=n; i>=1; i--)
            prop *= 1.0/(float)i;
        return prop;
        */
        
        /*
        nope this is wrong as 
        we have rpopbability to be certain to set on your chair and 
        another one to select a chair in random way 
        
        
        can get his seat phrase  include the random and the determin operation.
        */
        
        float *dp = new float[n+2];
        dp[n] = 1; // only one choice to do 
        for(int i=n-1; i>=1; i--)
        {
            if(i==1)
                dp[i] = dp[i+1] * 1.0/(float)(n-i+1);
            
            else{
                dp[i] = dp[i+1];
                dp[i] += dp[i+1]* 1.0/(float)(n-i+1);
                //cout<<i<<" "<<dp[i]<< endl;
            }
        }
        return dp[1];
        
    }
};
