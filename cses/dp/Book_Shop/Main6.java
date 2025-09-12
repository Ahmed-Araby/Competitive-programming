import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.StringTokenizer;

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

// this solution got accepted in some cases and Time Limit Exceeded in others
public class Main6 {

    private static int getMaxPageCountToBePurchased(
        final int[] bookPriceL, final int[] bookPageCntL, 
        final int bookIndex, final int maxSpend, final int[][] cache) {

            if(bookIndex == bookPriceL.length) {
                return 0;
            }
            else if(cache[bookIndex][maxSpend] != -1) {
                return cache[bookIndex][maxSpend];
            }

            // try to buy it
            if(maxSpend >= bookPriceL[bookIndex]) {
                cache[bookIndex][maxSpend] = bookPageCntL[bookIndex] + getMaxPageCountToBePurchased(bookPriceL, bookPageCntL, bookIndex + 1, maxSpend - bookPriceL[bookIndex], cache);
            }
            // leave it
            cache[bookIndex][maxSpend] = Math.max(cache[bookIndex][maxSpend], getMaxPageCountToBePurchased(bookPriceL, bookPageCntL, bookIndex+1, maxSpend, cache));

            return cache[bookIndex][maxSpend];
            
    }

    public static void main(String[] argv) throws IOException{
        final Scanner scanner = new Scanner();

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

        final int[][] cache = new int[bookCnt][maxSpend+1];
        for(int i=0; i<bookCnt; i++) {
            for(int j=0; j<= maxSpend; j++) {
                cache[i][j] = -1;
            }
        }

        final int maxPageCnt = getMaxPageCountToBePurchased(bookPriceL, bookPageCntL, 0, maxSpend, cache);
        System.out.println(maxPageCnt);

    }


    private static class Scanner {
        private final BufferedReader br;
        private StringTokenizer st;

        public Scanner() {
            final InputStreamReader sr = new InputStreamReader(System.in);
            br = new BufferedReader(sr);
        }

        private String nextToken() throws IOException {
            while(st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException{
            return Integer.parseInt(nextToken());
        }
    }
}