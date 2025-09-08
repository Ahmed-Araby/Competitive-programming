import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;

public class Main {
  private static final int BIG_ENOUGH_NUM = 100_000 * 10_000;
  private static int getMinCostToReachNthStone(int currStone, int nthStone, int[] stoneH, int[] cache) {
    if(currStone >= nthStone) {
      return 0;
    } else if(cache[currStone] != -1) {
      return cache[currStone];
    }
    
    final int nextStoneStepCost = Math.abs(stoneH[currStone] - stoneH[currStone + 1]) 
    + getMinCostToReachNthStone(currStone + 1, nthStone, stoneH, cache);
    int postNextStoneStepCost = BIG_ENOUGH_NUM;
    if(currStone + 2 <= nthStone) {
      postNextStoneStepCost = Math.abs(stoneH[currStone] - stoneH[currStone + 2]) 
      + getMinCostToReachNthStone(currStone + 2, nthStone, stoneH, cache);
    }
    
    return cache[currStone] = Math.min(nextStoneStepCost, postNextStoneStepCost);
  }
  
  public static void main(String[] argv) {
    final Scanner scanner = new Scanner(System.in);
    
    final int stoneCnt = scanner.nextInt();
    
    final int[] stoneH = new int[stoneCnt];
    for(int i=0; i<stoneCnt; i++) {
      final int ithStoneH = scanner.nextInt();
      stoneH[i] = ithStoneH;
    }
    
    final int[] cache = new int[stoneCnt];
    for(int i=0; i<stoneCnt; i++) {
      cache[i] = -1;
    }
    final int minCost = getMinCostToReachNthStone(0, stoneCnt -1, stoneH, cache);
    System.out.println(minCost);
  }
}
