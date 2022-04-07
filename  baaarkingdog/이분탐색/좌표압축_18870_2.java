package 이분탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class 좌표압축_18870_2 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n;
    private static List<Integer> original = new ArrayList<>();
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(st.nextToken());
            original.add(num);
        }

        List<Integer> sorted = original.stream().distinct()
                                       .sorted()
                                       .collect(Collectors.toList());

        for (int i = 0; i < n; i++) {
            sb.append(lowerBound(sorted, original.get(i))).append(" ");
        }
        System.out.println(sb.toString());
    }

    private static int lowerBound(List<Integer> sorted, Integer target) {
        int start = 0;
        int end = sorted.size();

        while (start < end) {
            int mid = (start + end) / 2;

            if (target <= sorted.get(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }

}
