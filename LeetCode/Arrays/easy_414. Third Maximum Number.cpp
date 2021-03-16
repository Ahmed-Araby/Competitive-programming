class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxi;
        set<int> ex;
        for(int i=0; i<nums.size(); i++){
            
            if(ex.find(nums[i]) !=ex.end())
                continue;
            ex.insert(nums[i]);
            
            maxi.push_back(nums[i]);
            if(maxi.size() == 4){
                sort(maxi.begin(), maxi.end(), greater<int>() );
                maxi.pop_back();
            }
        }
        
        sort(maxi.begin(), maxi.end()); // in num.size() < 4
        if(maxi.empty())
            return 0;
        else if(maxi.size() == 3)
            return maxi[0];
        else 
            return maxi.back();
    }
};
