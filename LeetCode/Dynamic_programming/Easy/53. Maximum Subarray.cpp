class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kedna algorithm.
        int maxSum = -1000000000, tmpSum  = 0;
        int ml = 0, mr = -1;
        int l  = 0, r= 0;
        for(int i=0; i<nums.size(); i++){
            if(tmpSum + nums[i] < 0){
                tmpSum  = 0;
                l = r = i+1;
            }
            else{
                tmpSum +=nums[i];
                if(tmpSum > maxSum){
                    maxSum = tmpSum;
                    ml = l;
                    mr = r;
                }
                r+=1;
            }
        }
        
        // allow negative answers.
        if(mr==-1){
            for(int i=0; i<nums.size(); i++)
                maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
};
