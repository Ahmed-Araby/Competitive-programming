import java.util.Scanner;

public class Main {
  public static void main(String[] argv) {
    final Scanner scanner = new Scanner(System.in);
    final int nth = scanner.nextInt();
    long last = 2, secondLast = -1;
    long curr = 1;
    
    for(int i=1; i<=nth; i++) {
      curr = last + secondLast;
      secondLast = last;
      last = curr;
    }
    System.out.println(curr);
  }
}
