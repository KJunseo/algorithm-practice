public class 상호평가 {

    public String solution(int[][] scores) {
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < scores[0].length; j++) {
            int divide = scores.length;
            int max = 0;
            int min = 101;
            int sum = 0;
            for (int i = 0; i < scores.length; i++) {
                max = Math.max(max, scores[i][j]);
                min = Math.min(min, scores[i][j]);
                sum += scores[i][j];
            }

            if (scores[j][j] == max || scores[j][j] == min) {
                sum -= scores[j][j];
                divide--;
            }

            sb.append(getGrade(sum, divide));
        }

        return sb.toString();
    }

    public String getGrade(int sum, int divide) {
        double avg = (double) sum / divide;

        if (avg >= 90) {
            return "A";
        } else if (avg >= 80) {
            return "B";
        } else if (avg >= 70) {
            return "C";
        } else if (avg >= 50) {
            return "D";
        } else {
            return "F";
        }
    }
}
