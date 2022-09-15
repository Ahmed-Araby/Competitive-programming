class Solution {
    public void rotate(int[] nums, int k) {
        // solution #1
        // using auxlary array to do the rotation then write it into the original array (nums)
        // O(n) memory complexity
        // O(N) time complexity
        int[] auxArr = new int[nums.length];
        k = k % nums.length;
        
        int index = 0;
        
        for(int i = nums.length - k; i < nums.length; i++)
            auxArr[index++] = nums[i];
        for(int i=0; i< (nums.length - k); i++)
            auxArr[index++] = nums[i];
        for(int i=0; i<nums.length; i++)
            nums[i] = auxArr[i];
    }
}

///////////////////////////////////////////////////////////////////

// very smart solution https://leetcode.com/problems/rotate-array/discuss/2579709/Java-or-2-Different-Approaches-or-Easy-or-Understandable-Code
class Solution {
    public void rotate(int[] nums, int k) {
        // solution #2
        // in place rotation solution 
        // O(1) memory complexity
        // O(k) + O(N) time complexity
        k = k % nums.length;
        reverse(nums, 0, nums.length - k - 1);
        reverse(nums, nums.length - k, nums.length -1);
        reverse(nums, 0, nums.length - 1);
    }
    
    public void reverse(int[] nums, int l, int r){
        while(l < r){
            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
}
