// https://atcoder.jp/contests/abc061/tasks/abc061_b
import java.util.Scanner;

public class Main {


    public static void main(String[] argv) {
        int n, m;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        int[] connCnt = new int[n+1];
        for(int i=0; i<m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            connCnt[a]++;
            connCnt[b]++;
        }

        for(int i=1; i<=n; i++) {
            System.out.println(connCnt[i]);
        }
    }
}
