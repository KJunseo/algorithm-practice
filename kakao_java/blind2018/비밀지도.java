package blind2018;

public class 비밀지도 {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i = 0; i < n; i++) {
            String map1 = convertToBinary(n, arr1[i]);
            String map2 = convertToBinary(n, arr2[i]);

            StringBuilder result = new StringBuilder();
            for (int j = 0; j < n; j++) {
                if (map1.charAt(j) == '1' || map2.charAt(j) == '1') {
                    result.append('#');
                } else if (map1.charAt(j) == '0' && map2.charAt(j) == '0') {
                    result.append(' ');
                }
            }
            answer[i] = result.toString();
        }

        return answer;
    }

    private String convertToBinary(int n, int num) {
        StringBuilder result = new StringBuilder();
        while (num > 0) {
            result.append(num % 2);
            num /= 2;
        }
        while (result.length() < n) {
            result.append("0");
        }

        result.reverse();
        return result.toString();
    }
}
