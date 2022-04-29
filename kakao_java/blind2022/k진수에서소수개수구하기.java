package blind2022;

public class k진수에서소수개수구하기 {

    public int solution(int n, int k) {
        String num = toNumberK(n, k);

        int answer = 0;
        for (String s : num.split("[0]+")) {
            long number = Long.parseLong(s);
            if (isPrime(number)) {
                answer++;
            }
        }

        return answer;
    }

    private String toNumberK(int n, int k) {
        if (k == 10) {
            return String.valueOf(n);
        }
        StringBuilder temp = new StringBuilder();
        while (n > 0) {
            temp.append(n % k);
            n /= k;
        }
        return temp.reverse().toString();
    }

    private boolean isPrime(long number) {
        if (number == 1) {
            return false;
        }

        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}
