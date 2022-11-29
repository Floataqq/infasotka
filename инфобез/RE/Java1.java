import java.util.Arrays;
import java.util.Random;

public class Java1 {
  public static void main(String[] args) {
    Random random = new Random();

    int size = random.nextInt(100) + 1;
    int[] array = new int[size];

    for (int i = 0; i < size; i++) {
      array[i] = random.nextInt() % 100;
    }

    System.out.println(foo(array));
  }

  public static int foo(int[] array) {
    int min = array[0];

    for (int i = 1; i < array.length; ++i) {
      if (array[i] < min) {
        min = array[i];
      }
    }

    return min;
  }
}
