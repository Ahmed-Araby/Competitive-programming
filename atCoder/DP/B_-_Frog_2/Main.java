import java.util.Scanner;

import java.util.List;
import java.util.ArrayList;

public class Main {
  private static final int BIG_ENOUGH_NUM = 100_000 * 10_000;
  private static int getMinCostToReachNthStone(int nthStone, int maxJump, int[] stoneH, int[] cost) {
    cost[nthStone] = 0;
    for(int currStone = nthStone-1; currStone>=0; currStone--) {
      for(int jump = 1; jump <=maxJump && currStone + jump <= nthStone; jump++) {
        final int currCost = Math.abs(stoneH[currStone] - stoneH[currStone + jump]) + cost[currStone + jump];
        cost[currStone] = Math.min(cost[currStone], currCost);
      }
    }
    return cost[0];
  }
  
  public static void main(String[] argv) {
    final Scanner scanner = new Scanner(System.in);
    
    final int stoneCnt = scanner.nextInt();
    final int maxJump = scanner.nextInt();
    final int[] stoneH = new int[stoneCnt];
    for(int i=0; i<stoneCnt; i++) {
      final int ithStoneH = scanner.nextInt();
      stoneH[i] = ithStoneH;
    }
    
    final int[] cost = new int[stoneCnt];
    for(int i=0; i<stoneCnt; i++) {
      cost[i] = BIG_ENOUGH_NUM;
    }
    final int minCost = getMinCostToReachNthStone(stoneCnt -1, maxJump, stoneH, cost);
    System.out.println(minCost);
  }
}



