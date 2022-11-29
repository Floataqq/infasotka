import java.util.*;

public class Java2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Input a number: ");
    int num = sc.nextInt();
    sc.close();

    if ((num % 2 == 0) || (num <= 0)) {
      System.out.print("Input number must be odd and >0");
      System.exit(0);
    }

    int[][] magic_square = new int[num][num];

    int row_num = num / 2;
    int col_num = num - 1;
    magic_square[row_num][col_num] = 1;

    for (int i = 2; i <= num * num; i++) {
      if (magic_square[(row_num - 1 + num) % num][(col_num + 1) % num] == 0) {
        row_num = (row_num - 1 + num) % num;
        col_num = (col_num + 1) % num;
      } else {
        col_num = (col_num - 1 + num) % num;
      }
      magic_square[row_num][col_num] = i;
    }

    for (int i = 0; i < num; i++) {
      for (int j = 0; j < num; j++) {
        if (magic_square[i][j] < 10) {
          System.out.print(" ");
        }
        if (magic_square[i][j] < 100) {
          System.out.print(" ");
        }
        System.out.print(magic_square[i][j] + " ");
      }
      System.out.println();
    }
  }
}
