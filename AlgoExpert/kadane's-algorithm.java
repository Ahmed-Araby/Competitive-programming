import java.util.*;

class Program {
  public static int kadanesAlgorithm(int[] array) {
    // Write your code here.
    // no need for keeping track of the actual subarray
    // that is why we do not need to use 2 pointers
    int ptr = 0, mSum = array[0], pSum = 0;
    while(ptr < array.length){
      pSum += array[ptr];
      mSum = Math.max(mSum, pSum);
      if(pSum < 0){
        pSum = 0;
      }
      ptr++;
    }
    return mSum;
  }
}
