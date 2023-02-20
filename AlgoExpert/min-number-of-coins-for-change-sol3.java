// iterative solution
import java.util.*;

class Program {
  public static int minNumberOfCoinsForChange(int n, int[] denoms) {
    // Write your code here.
    long notAcceptableValue = n + 1;
    long [][] cache = new long[n+1][denoms.length+1];
    for(int amount = 0; amount <= n; amount++){
      for(int index = denoms.length; index >=0; index--){
        if(index == denoms.length){
          if(amount == 0){
            cache[amount][index] = 0L;
          } else {
            cache[amount][index] = notAcceptableValue;
          }
        } else{
          int maxCoinInstances = amount / denoms[index];
          cache[amount][index] = notAcceptableValue;
          for(int instances = 0; instances <= maxCoinInstances; instances++){
            int remainingAmount = amount - (instances * denoms[index]);
            cache[amount][index] = Math.min(
              cache[amount][index], 
              cache[remainingAmount][index+1] + instances
            );
          }
        }
      }
    }
    return cache[n][0] == notAcceptableValue ? -1 : (int)cache[n][0];
  }
}
