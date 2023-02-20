// no sortign as we will try all possible solutions
import java.util.*;

class Program {
  private static long nonAcceptableValue; // should be original amount + 1
  private static long getMinNumOfCoins(int amount, int index, int [] denoms, long[][] cache){
    if(index == -1) {
      if(amount == 0)
        return 0L;
      return nonAcceptableValue;
    }
    
    if(cache[amount][index] != -1){ // subproblem that we computed before
      return cache[amount][index];
    }
  
    long maxCoinInstanceToBeUsed = (long)(amount / denoms[index]);
    cache[amount][index] = nonAcceptableValue;
    for(int instances=0; instances <= maxCoinInstanceToBeUsed; instances++){
      cache[amount][index] = Math.min(
        cache[amount][index],
        instances + getMinNumOfCoins(amount - (int)(denoms[index] * instances), index - 1, denoms, cache)
      );
    }
    
    return cache[amount][index];
  }

  public static void init2DArr(int rows, int cols, long [][]arr, long initVal){
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        arr[i][j] = initVal;
      }
    }
  }
  
  public static int minNumberOfCoinsForChange(int n, int[] denoms) {
    // Write your code here.
    nonAcceptableValue = n + 1;
    
    long [][] cache = new long[n + 1][denoms.length];
    init2DArr(n + 1, denoms.length, cache, -1L);
    
    long count = getMinNumOfCoins(n, denoms.length - 1, denoms, cache);
    
    if(count == nonAcceptableValue)
      return -1;
    
    return (int)count;
  }
}
