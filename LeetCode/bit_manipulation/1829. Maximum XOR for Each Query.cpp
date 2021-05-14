class Solution {
public:
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = pow(2, maximumBit)  - 1;
        vector<int> ans;
        
        int n = nums.size();
        int xorRes = 0;
        
        for(int i=0; i<n; i++)
            xorRes ^= nums[i];
        
        for(int i=n-1; i>=0; i--){
            int k = maxi ^ xorRes;
            xorRes ^= nums[i]; // remove last element.
            ans.push_back(k);
        }
        
        return ans;
    }
};
