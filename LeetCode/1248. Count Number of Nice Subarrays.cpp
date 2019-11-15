class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> cs;
        if(nums[0]%2)
            cs.push_back(1);
        else
            cs.push_back(0);
        for (int i=1; i<nums.size(); i++){
            if(nums[i]%2)
                cs.push_back(cs[i-1]+1);
            else
                cs.push_back(cs[i-1]);
        }

        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(cs[i]>=k)
            {
                //cout<<i<< endl;
                int rem=cs[i]-k;
                int index1= lower_bound(cs.begin() , cs.end() , rem)-cs.begin();
                int index2=upper_bound(cs.begin() , cs.end() , rem)-cs.begin();
                cnt+=(index2-index1)+(rem==0);
            }
        }
        return cnt;
    }
};
