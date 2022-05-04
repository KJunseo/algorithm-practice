package intern2019;

import java.util.Arrays;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.groupingBy;

public class 튜플 {

    public int[] solution(String s) {
        s = s.substring(1, s.length() - 1);
        s = s.replaceAll("[{}]", "");
        String[] split = s.split(",");
        return Arrays.stream(split)
                     .collect(groupingBy(Function.identity(), Collectors.counting()))
                     .entrySet()
                     .stream()
                     .sorted((a, b) -> b.getValue().compareTo(a.getValue()))
                     .map(Map.Entry::getKey)
                     .map(Integer::parseInt)
                     .mapToInt(Integer::intValue)
                     .toArray();
    }

}
