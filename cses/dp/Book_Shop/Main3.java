import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

// this solution got Accepted
public class Main3 {

    private static int getMaxPageCountToBePurchased(final int[] bookPriceL, final int[] bookPageCntL, final int maxSpend) {
        final int[][] cache = new int[2][maxSpend+1];
        int writeOverRowIndex = 0;
        for(int bookIndex = bookPriceL.length-1; bookIndex>=0; bookIndex--) {
            for(int spend = 0; spend<=maxSpend; spend++) {
                if(spend >= bookPriceL[bookIndex]) {
                    // buy the book 
                    final int remSpend = spend - bookPriceL[bookIndex];
                    cache[writeOverRowIndex][spend] = bookPageCntL[bookIndex] + cache[1 - writeOverRowIndex][remSpend];
                }
                // don't buy the book
                cache[writeOverRowIndex][spend] = Math.max(cache[writeOverRowIndex][spend], cache[1 - writeOverRowIndex][spend]);
            }
            writeOverRowIndex = 1 - writeOverRowIndex;
        }

        return cache[1 - writeOverRowIndex][maxSpend];
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