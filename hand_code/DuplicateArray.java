import java.util.HashSet;
import java.util.Set;

public class DuplicateArray {

    public boolean isDuplicated(int[] array) {
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < array.length; i++) {
            int num = array[i];
            if (set.contains(num)) {
                return true;
            }
            set.add(num);
        }
        return false;
    }
}
