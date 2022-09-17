// binary search solution
class Solution {
    int bs(int nums[], int s, int target){
        int lIndex = s, rIndex = nums.length -1, mid = 0;
        while(lIndex <= rIndex){
            mid = lIndex + (rIndex - lIndex) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                lIndex = mid + 1;
            else
                rIndex = mid - 1;
        }
        return -1;
    }
    public int[] twoSum(int[] numbers, int target) {
        int indices[] = new int[2];
        for(int i=0; i<numbers.length; i++){
            int index = bs(numbers, i+1, target - numbers[i]);
            if(index != -1){
                indices[0] = i+1;
                indices[1] = index + 1;
                break;
            }
        }
        
        return indices;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 2 pointers solution

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0, r = numbers.length -1;
        int [] indices = new int[2];
        while(l <= r){
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                indices[0] = l + 1;
                indices[1] = r + 1;
                break;
            }
            else if(sum > target) 
                r -=1;
            else 
                l +=1;
        }
        return indices;
    }
}
