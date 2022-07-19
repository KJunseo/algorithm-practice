package string;

import java.util.Stack;

public class ReverseString {

    public String reverse(String string) {
        StringBuilder sb = new StringBuilder(string);
        sb.reverse();
        return sb.toString();
    }

    public String reverseUsingStack(String string) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < string.length(); i++) {
            stack.add(string.charAt(i));
        }

        String result = "";
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }

    public String reverseUsingArray(String string) {
        int n = string.length();
        char[] array = string.toCharArray();
        for (int i = 0; i < n / 2; i++) {
            char temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
        }
        return new String(array);
    }
}
