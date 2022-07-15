import java.math.BigInteger;

public class Factorial {

    public int factorialLoop(int n) {
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            cur *= i;
        }
        return cur;
    }

    public int factorialRecursive(int n) {
        if (n == 1) {
            return 1;
        }
        return n * factorialRecursive(n - 1);
    }

    public BigInteger factorial(int n) {
        BigInteger cur = new BigInteger("1");
        for (int i = 1; i <= n; i++) {
            cur = cur.multiply(new BigInteger(String.valueOf(i)));
        }
        return cur;
    }
}
