import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        for (int i = 1; i <= 10; i++) {
            // Using printf for clean formatting
            System.out.printf("%d x %d = %d%n", N, i, N * i);
        }
        
        sc.close();
    }
}
