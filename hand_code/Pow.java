public class Pow {

    public double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            double half = myPow(x, n / 2 * -1);

            if (n % 2 == 0) {
                return 1 / (half * half);
            } else {
                return 1 / (x * half * half);
            }
        } else {
            double half = myPow(x, n / 2);

            if (n % 2 == 0) {
                return half * half;
            } else {
                return x * half * half;
            }
        }
    }
}
