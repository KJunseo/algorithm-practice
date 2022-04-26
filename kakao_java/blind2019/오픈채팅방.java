package blind2019;

import java.util.*;

public class 오픈채팅방 {
    private Map<String, String> map;

    private StringTokenizer st;

    public String[] solution(String[] records) {
        map = new HashMap<>();
        for (String record : records) {
            st = new StringTokenizer(record);

            String command = st.nextToken();
            String id = st.nextToken();

            if ("Enter".equals(command)) {
                String nickName = st.nextToken();
                map.put(id, nickName);
            } else if ("Change".equals(command)) {
                String nickName = st.nextToken();
                map.put(id, nickName);
            }
        }

        List<String> result = new ArrayList<>();
        for (String record : records) {
            st = new StringTokenizer(record);

            String command = st.nextToken();
            String id = st.nextToken();

            if ("Enter".equals(command)) {
                result.add(map.get(id) + "님이 들어왔습니다.");
            } else if ("Leave".equals(command)) {
                result.add(map.get(id) + "님이 나갔습니다.");
            }
        }

        String[] answer = new String[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        return answer;
    }
}
