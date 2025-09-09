// 2D memoization
// time limit exceeded on 3 test cases
import java.util.Scanner;

public class Main2 {
    private static final int BIG_ENOUGH_NUM = 1_000_001;

    private static int makeUpSumWithMinNumOfCoins(final int sum, final int[] coinList) {
        final int[] cache = new int[sum + 1];
        // cache[0] = 0;

        for(int remSum = 1; remSum <= sum; remSum++) {
            cache[remSum] = BIG_ENOUGH_NUM;
            for(int coinIndex = coinList.length - 1; coinIndex >= 0; coinIndex--) {
                if(coinList[coinIndex] <= remSum) {
                    final int newRemSum = remSum - coinList[coinIndex];
                    cache[remSum] = Math.min(cache[remSum], 1 + cache[newRemSum]);
                }
            }
        }

        return cache[sum] == BIG_ENOUGH_NUM ? -1 : cache[sum];
    }

    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        final int coinCnt = scanner.nextInt();
        final int sum = scanner.nextInt();
        
        final int[] coinList = new int[coinCnt];
        for(int i=0; i<coinCnt; i++) {
            coinList[i] = scanner.nextInt();
        }

        final int minNumOfCoins = makeUpSumWithMinNumOfCoins(sum, coinList);
        System.out.println(minNumOfCoins);
    }
}