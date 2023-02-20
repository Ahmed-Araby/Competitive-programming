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
          cache[amount][index] = notAcceptableValue;
          
          cache[amount][index] = Math.min( // do not use coin at all
            cache[amount][index],
            cache[amount][index+1]
          );
          
          if(amount >= denoms[index]){
            cache[amount][index] = Math.min( // use 1 coin and and may be we will use more coins of this denom
              cache[amount][index], 
              cache[amount - denoms[index]][index] + 1
            );
            
            cache[amount][index] = Math.min( // use 1 coin of the current denom and move forward
              cache[amount][index],
              cache[amount - denoms[index]][index+1] + 1
            );
          }
        }
      }
    }
    return cache[n][0] == notAcceptableValue ? -1 : (int)cache[n][0];
  }
}
