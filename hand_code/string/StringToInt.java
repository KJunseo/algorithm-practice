package string;

public class StringToInt {

    public int stringToInt(String num) {
        int sum = 0;
        int mul = 1;
        for (int i = num.length() - 1; i >= 0; i--) {
            int value = num.charAt(i) - '0';
            sum += value * mul;
            mul *= 10;
        }
        return sum;
    }
}
