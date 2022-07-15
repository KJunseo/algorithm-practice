public class Fibonacci {

    public int fiboLoop(int n) {
        if (n <= 1) {
            return n;
        }

        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }

    public int fiboRecursive(int n) {
        if (n <= 1) {
            return n;
        }
        return fiboRecursive(n - 1) + fiboRecursive(n - 2);
    }


    public int fiboDp(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 1;
        return fibo(dp, n);
    }

    public int fibo(int[] dp, int n) {
        if (dp[n] != 0) {
            return dp[n];
        }
        return dp[n] = fibo(dp, n - 1) + fibo(dp, n - 2);
    }
}
