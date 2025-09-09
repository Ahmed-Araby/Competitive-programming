// 2D memoization
// time limit exceeded on 3 test cases
import java.util.Scanner;

public class Main {
    private static final int BIG_ENOUGH_NUM = 1_000_001;

    private static int makeUpSumWithMinNumOfCoins(final int sum, final int[] coinList) {
        final int[][] cache = new int[coinList.length + 1][sum + 1];
        // there is no remaining sum
        // for(int coinIndex = 0; coinIndex <= coinList.length; coinIndex++) {
        //     cache[coinIndex][0] = 0;
        // }
        // there is still remaining sum, and there is no more coins to use
        for(int remSum = 1; remSum <= sum; remSum++) {
            cache[coinList.length][remSum] = BIG_ENOUGH_NUM;
        }


        for(int coinIndex = coinList.length - 1; coinIndex >= 0; coinIndex--) {
            for(int remSum = 1; remSum <= sum; remSum++) {
                // options
                // 1- don't use this coin and try to solve the problem using the remaining coins
                // 2- use this coin once and try to solve the problem using the remaining coins
                // 3- use this coin once and try to solve the problem with the remaining sum using the same coin (mimics using the same coin multiple times)
                // and this approach will avoid the iterations on the cached solutions, actually it will enable us to get the cached result higher in the hierarchy

                // option#1
                cache[coinIndex][remSum] = cache[coinIndex + 1][remSum];
                if(coinList[coinIndex] <= remSum) {
                    // option#2
                    final int newRemSum = remSum - coinList[coinIndex];
                    cache[coinIndex][remSum] = Math.min(cache[coinIndex][remSum], 1 + cache[coinIndex + 1][newRemSum]);
                    // option#3
                    cache[coinIndex][remSum] = Math.min(cache[coinIndex][remSum], 1 + cache[coinIndex][newRemSum]);
                }
            }
        }
        return cache[0][sum] == BIG_ENOUGH_NUM ? -1 : cache[0][sum];
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