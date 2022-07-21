import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Phone {
    // 1: abc, 2: def, 3: ghi, 4: jkl, 5: mno, 6: pqr, 7: stu, 8: vwx, 9: yz
    private Map<Character, String> map = Map.of(
            '1', "abc",
            '2', "def",
            '3', "ghi",
            '4', "jkl",
            '5', "mno",
            '6', "pqr",
            '7', "stu",
            '8', "vwx",
            '9', "yz"
    );

    private List<String> answer = new ArrayList<>();

    public List<String> solution(int input) {
        char[] nums = String.valueOf(input).toCharArray();

        char[] result = new char[nums.length];
        dfs(nums, result, 0);

        return answer;
    }

    private void dfs(char[] nums, char[] result, int index) {
        if (index == nums.length) {
            answer.add(new String(result));
            return;
        }

        char c = nums[index];
        String candidates = map.get(c);
        for (int i = 0; i < candidates.length(); i++) {
            result[index] = candidates.charAt(i);
            dfs(nums, result, index + 1);
        }
    }
}
