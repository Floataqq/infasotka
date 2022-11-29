import java.util.Scanner;

public class Java3 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a number: ");
    int n = scanner.nextInt();

    System.out.println(func(n));
  }

  public static boolean func(int n) {
    if (n == 2) {
      return true;
    }
    if (n < 2 || n % 2 == 0) {
      return false;
    }
    for (int i = 3, limit = (int)Math.sqrt(n); i <= limit; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
