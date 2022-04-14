package blind2018;

import java.util.LinkedHashMap;
import java.util.Map;

public class 캐시 {

    public int solution(int cacheSize, String[] cities) {
        LRUCache cache = new LRUCache(cacheSize);

        int answer = 0;
        for (String city : cities) {
            String name = city.toLowerCase();
            if (cache.get(name)) {
                answer++;
            } else {
                answer += 5;
            }
            cache.put(name, true);
        }

        return answer;
    }

    static class LRUCache extends LinkedHashMap<String, Boolean> {
        private final int capacity;

        public LRUCache(int capacity) {
            super(capacity, 0.75f, true);
            this.capacity = capacity;
        }

        public boolean get(String key) {
            return super.getOrDefault(key, false);
        }

        @Override
        protected boolean removeEldestEntry(Map.Entry eldest) {
            return size() > capacity;
        }
    }
}
