import java.util.Scanner;

public class Main2 {
  private static long getNthLucasNum(int nth, long[] cache) {
    if(nth == 0) {
      return 2;
    } else if(nth == 1) {
      return 1;
    } else if(cache[nth] != 0) { // lucas numbers dons't have zeros.
      return cache[nth];
    }
    return cache[nth] = getNthLucasNum(nth-1, cache) + getNthLucasNum(nth-2, cache);
  }
  
  public static void main(String[] argv) {
    final Scanner scanner = new Scanner(System.in);
    final int nth = scanner.nextInt();
    final long[] cache = new long[nth+1];
    
    final long num = getNthLucasNum(nth, cache);
    System.out.println(num);
  }
}
