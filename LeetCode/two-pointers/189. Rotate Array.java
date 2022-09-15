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
