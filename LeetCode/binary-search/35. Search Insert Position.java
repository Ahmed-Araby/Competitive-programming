class Solution {
    public int searchInsert(int[] nums, int target) {
        int lIndex = 0, rIndex = nums.length - 1, mid = 0;
        while(lIndex < rIndex){
            mid = lIndex + (rIndex - lIndex) / 2;
            if(nums[mid] >= target)
                rIndex = mid;
            else 
                lIndex = mid + 1;
        }
        return nums[rIndex] >= target ? rIndex : rIndex + 1;
        
    }
}
