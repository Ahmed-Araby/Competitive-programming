// https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-i
class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length -1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else 
                left = right = mid;
        }
        if(left == right && nums[left] == target)
            return left;
        return -1;
    }
}
