// gready
import java.util.*;

class Program {
  public static int[] calcLeftDecSegLength(int[] array){
    int [] leftDecSegLength = new int[array.length];
    
    for(int i=1; i<array.length; i++){
      if(array[i] > array[i-1])
        leftDecSegLength[i] = 1 + leftDecSegLength[i-1];
    }

    return leftDecSegLength;
  }

  public static int[] calcRightDecSegLength(int[] array){
    int [] rightDecSegLength = new int[array.length];

    for(int i = array.length -2; i>=0; i--){
      if(array[i] > array[i+1])
        rightDecSegLength[i] = 1 + rightDecSegLength[i+1];
    }

    return rightDecSegLength;
  }

  public static int getMaxPeakLength(int[] leftDecSegLength, int[] rightDecSegLength){
    int maxPeakLength = 0;
    for(int i = 0; i<leftDecSegLength.length; i++){
      if(leftDecSegLength[i] >= 1 && rightDecSegLength[i] >= 1){
        maxPeakLength = Math.max(
          maxPeakLength, 
          1 + leftDecSegLength[i] + rightDecSegLength[i]
        );
      }
    }
    return maxPeakLength;
  }
  public static int longestPeak(int[] array) {
    // Write your code here.
    int[] leftDecSegLength = calcLeftDecSegLength(array);
    int[] rightDecSegLength = calcRightDecSegLength(array);
        
    return getMaxPeakLength(leftDecSegLength, rightDecSegLength);
  }
}
