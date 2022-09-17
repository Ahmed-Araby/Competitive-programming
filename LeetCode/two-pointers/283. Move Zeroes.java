/**
my approach to the problem

we need to find the amount of positions we need to shift every cell to the left
the amount of shift left positions we need to do for cell at pos x
equals to the number of zeros before any cell x, 

as a starting solution and we can do this using a aux array to keep number of 
shift left steps we need to apply for each cell


1 0 2 3 4 5

1 2 3 4 5 0 -> our out put array  

O(N)
O(N)  
number of writes on the original array is optimal cuz we are doing 1 swap for each non zero element that has at least one zero before it.


1 0 0 0 2 4
1 2 0 0 0 4
1 2 4 0 0 0 -> output


to enhance the solution in terms of space complexity, we can get rid of the 
auxalary array.

by using 2 pointers approach

slow and fast
slow one will keep track of the most left cell with zero in it as this is the cell we need to swap non zero elements with it.

    | 0 
1 2 0 2 3 4 
all elements between the slow and fast pointer will be zeros not including the fast pointer
*/

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
