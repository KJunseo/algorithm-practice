package intern2019;

import java.util.*;

public class 불량사용자 {
    private List<String>[] users;
    private Set<String> result;

    public int solution(String[] user_id, String[] banned_id) {
        users = new List[banned_id.length];
        for (int i = 0; i < banned_id.length; i++) {
            users[i] = new ArrayList<>();
        }
        for (String user : user_id) {
            for (int i = 0; i < banned_id.length; i++) {
                if (match(user, banned_id[i])) {
                    users[i].add(user);
                }
            }
        }

        result = new HashSet<>();
        dfs(0, new ArrayList<>());

        return result.size();
    }

    private void dfs(int index, List<String> cur) {
        if (index == users.length) {
            Collections.sort(cur);
            String temp = "";
            for (String s : cur) {
                temp += s;
            }
            result.add(temp);
            return;
        }

        List<String> list = users[index];
        for (String s : list) {
            if (cur.contains(s)) {
                continue;
            }
            cur.add(s);
            dfs(index + 1, cur);
            cur.remove(s);
        }
    }

    private boolean match(String user, String banned) {
        if (user.length() != banned.length()) {
            return false;
        }

        for (int i = 0; i < user.length(); i++) {
            if (banned.charAt(i) == '*') {
                continue;
            }
            if (user.charAt(i) != banned.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
