import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main4 {

    private static int getMaxPageCountToBePurchased(final int[] bookPriceL, final int[] bookPageCntL, final int maxSpend) {
        final int[] cache = new int[maxSpend+1];
        for(int bookIndex = bookPriceL.length-1; bookIndex>=0; bookIndex--) {
            for(int spend = maxSpend; spend>=bookPriceL[bookIndex]; spend--) {
                if(spend >= bookPriceL[bookIndex]) {
                    final int remSpend = spend - bookPriceL[bookIndex];
                    cache[spend] = Math.max(cache[spend], // don't buy the book
                     bookPageCntL[bookIndex] + cache[remSpend]); // buy the book
                }
            }
        }

        return cache[maxSpend];
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