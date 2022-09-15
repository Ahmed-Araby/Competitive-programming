class Solution {
    public int[] sortedSquares(int[] nums) {
        int l = -1, r = -1;
        
        // position pointers
        if(nums[0] >= 0)
            r = 0;
        else if(nums[nums.length -1] < 0){
            r = nums.length;
            l = nums.length -1;
        }
        
        for(int i=0; i < nums.length -1; i++){
            if(nums[i] < 0 && nums[i+1] >= 0){
                l = i;
                r = i+1;
                break;
            }
        }
        
        // walk with the pointers to build the required array
        int index = 0;
        int[] sortedSq = new int[nums.length];
        while(l >= 0 || r < nums.length){
            int lVal = (l >= 0 ? nums[l] * nums[l]: (int)1e9);
            int rVal = (r < nums.length ? nums[r] * nums[r]: (int)1e9);
            
            if(lVal < rVal){
                sortedSq[index++] = lVal;
                l -=1;
            }
            else{
                sortedSq[index++] = rVal;
                r +=1;
            }
        }
        
        return sortedSq;
    }
}
