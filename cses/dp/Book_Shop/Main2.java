import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

// this solution got accepted in some cases and Time Limit Exceeded in others
public class Main2 {
 
    private static int getMaxPageCountToBePurchased(final int[] bookPriceL, final int[] bookPageCntL, final int maxSpend) {
        final int[][] cache = new int[bookPriceL.length+1][maxSpend+1];
 
        for(int bookIndex = bookPriceL.length-1; bookIndex>=0; bookIndex--) {
            for(int spend = 0; spend<=maxSpend; spend++) {
                if(spend >= bookPriceL[bookIndex]) {
                    // buy the book 
                    final int remSpend = spend - bookPriceL[bookIndex];
                    cache[bookIndex][spend] = bookPageCntL[bookIndex] + cache[bookIndex+1][remSpend];
                }
                // don't buy the book
                cache[bookIndex][spend] = Math.max(cache[bookIndex][spend], cache[bookIndex+1][spend]);
            }
        }
 
        return cache[0][maxSpend];
    }
 
    public static void main(String[] argv) {
        final Scanner scanner = new Scanner(System.in);
        
        final int bookCnt = scanner.nextInt();
        final int maxSpend = scanner.nextInt();
        
 
        final int[] bookPriceL = new int[bookCnt];
        final int[] bookPageCntL = new int[bookCnt];
        for(int i=0; i<bookCnt; i++) {
            bookPriceL[i] = scanner.nextInt();
        }
        for(int i=0; i<bookCnt; i++) {
            bookPageCntL[i] = scanner.nextInt();
        }
 
        final int maxPageCnt = getMaxPageCountToBePurchased(bookPriceL, bookPageCntL, maxSpend);
        System.out.println(maxPageCnt);
    }
}