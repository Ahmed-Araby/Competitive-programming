class Solution {
    public void moveZeroes(int[] nums) {
        int zpp = -1;
        int mp = 0;
        while(mp < nums.length){
            if(zpp == -1 && nums[mp] == 0){  // first zero encounter
                zpp = mp;
            }
            else if(nums[mp] != 0 && zpp != -1){ // swap the non zero element left 
                nums[zpp] = nums[mp];
                zpp ++;
                nums[mp]  = 0;
            }
            mp++;
        }
    }
}
