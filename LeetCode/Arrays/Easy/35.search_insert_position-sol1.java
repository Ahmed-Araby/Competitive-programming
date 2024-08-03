class Solution {
    public int searchInsert(int[] nums, int target) {
        // basically we are binary searching for the first element equal to or greater than the target.
        int lIndex = 0, rIndex = nums.length - 1;
        int mid, possibleIndex = nums.length;
        while (lIndex <= rIndex) {
            mid = (lIndex + rIndex) / 2;
            if(nums[mid] >= target) {
                possibleIndex = mid;
                rIndex = mid - 1;
            } else {
                lIndex = mid + 1;
            }
        }
        return possibleIndex;
    }
}
