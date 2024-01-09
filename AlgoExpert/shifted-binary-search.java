import java.util.*;

class Program {
  public static boolean isLeftShiftedArray(int[] array, int lowIndex, int midIndex, int highIndex) {
    // +-, inc then dec
    if(array[lowIndex] < array[midIndex] && array[midIndex] > array[highIndex]) { // shift left
      return true;
    }
    return false;
  }
  
  public static int shiftedBinarySearch(int[] array, int target) {
    // Write your code here.
    int lowIndex = 0;
    int highIndex = array.length - 1;
    while(lowIndex <= highIndex) {
      int mid = (lowIndex + highIndex) / 2;
      System.out.println("mid = " + mid);
      if(array[mid] == target) {
        return mid;
      }
      if(array[mid] > target && isLeftShiftedArray(array, lowIndex, mid, highIndex)) {
        if(target >= array[lowIndex]){
          highIndex = mid -1;
        } else {
          lowIndex = mid + 1;
        }
      } else if(array[mid] > target) { // is right shifted array
        highIndex = mid -1; 
      } else if (array[mid] < target && isLeftShiftedArray(array, lowIndex, mid, highIndex)) {
        lowIndex = mid + 1;
      } else if(array[mid] < target) { // is right shifted array
        if(array[highIndex] >= target) {
          lowIndex = mid + 1;
        } else {
          highIndex = mid - 1; 
        }
      }
    }
    return -1;
  }
}
