import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;

public class Main2 {
  private static final int BIG_ENOUGH_NUM = 100_000 * 10_000;
  private static int getMinCostToReachNthStone(int nthStone, int[] stoneH, int[] cost) {
    cost[nthStone] = 0;
    for(int currStone = nthStone-1; currStone>=0; currStone--) {
      final int nextStoneStepCost = Math.abs(stoneH[currStone] - stoneH[currStone + 1]) + cost[currStone+1];
      int postNextStoneStepCost = BIG_ENOUGH_NUM;
      if(currStone + 2 <= nthStone) {
        postNextStoneStepCost = Math.abs(stoneH[currStone] - stoneH[currStone + 2]) + cost[currStone + 2];
      }
      cost[currStone] = Math.min(nextStoneStepCost, postNextStoneStepCost);
    }
    return cost[0];
  }
  
  public static void main(String[] argv) {
    final Scanner scanner = new Scanner(System.in);
    
    final int stoneCnt = scanner.nextInt();
    
    final int[] stoneH = new int[stoneCnt];
    for(int i=0; i<stoneCnt; i++) {
      final int ithStoneH = scanner.nextInt();
      stoneH[i] = ithStoneH;
    }
    
    final int[] cost = new int[stoneCnt];
    final int minCost = getMinCostToReachNthStone(stoneCnt -1, stoneH, cost);
    System.out.println(minCost);
  }
}


