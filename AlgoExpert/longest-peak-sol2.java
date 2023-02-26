// given the hint#3 we can prove
// that each element in this array will only be touched twice at max
// which mean our time complexity is O(n)
import java.util.*;


class Program {
  public static int getLeftDecSegLen(int[] array, int index){
    int len = 0;
    while(index >=0 && index-1>=0 && array[index] > array[index-1]){
      len++;
      index--;
    }
    return len;
  }

  public static int getRightDecSegLen(int[] array, int index){
    int len = 0;
    while(index < array.length && index + 1 < array.length && array[index] > array[index+1]){
      len++;
      index++;
    }
    return len;
  }

  
  public static int longestPeak(int[] array) {
    int maxPeakLen = 0;
    for(int i=1; i<array.length-1; i++){
      if(array[i] > array[i-1] && array[i] > array[i+1]){
        maxPeakLen = Math.max(
          maxPeakLen,
          getLeftDecSegLen(array, i) +
          getRightDecSegLen(array, i) +
          1
        );
      }
    }
    return maxPeakLen;
  }
}
