/*
    자바로 처음 풀어봤는데, 익숙하지 않아서 불편했다.
    풀긴했지만 풀면서도 깔끔하지 못하다는 느낌을 많이 받았고 +1점 밖에 받지 못했다.
    map에 스킬 선행순서를 인덱스로 구분하여 저장하고,
    유저들의 스킬트리를 돌면서 인덱스를 비교하여 풀었다.

    정규식을 이용한 풀이가 있어서 첨부하였다. 완전히 이해하지 못하였다.
*/
import java.util.*;

// 나의 풀이
class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        Map<Character, Integer> check = new HashMap<>();
            
        for(int i=0;i<skill.length();i++) {
            check.put(skill.charAt(i), i);
        }
        
        for(String s : skill_trees) {
            int idx=-1;
            boolean flag=false;
            for(int i=0;i<s.length();i++) {
                for(Character c : check.keySet()) {
                    if(s.charAt(i)==c) {
                        if(idx!=check.get(c)-1) {
                            flag=true;
                        }else if(idx>check.get(c)) {
                            flag=true;
                        } else {
                           idx=check.get(c); 
                        }
                        break;
                    }
                }
                if(flag) break;
                if(i==s.length()-1) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}

class Solution2 {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        for(int i=0;i<skill_trees.length;i++) {
            int idx=0;
            boolean flag = true;

            String[] skills = skill_trees[i].split(""); // 한 글자씩 자르기 
            
            for(String s : skills) {
                // skill에서 한 글자씩 자른 문자가 몇번째 인덱스에 있는지 확인하여
                if(idx==skill.indexOf(s)) idx++; // 같은 인덱스면 인덱스 증가
                else if(idx<skill.indexOf(s)) { // 더 뒤에 있다면 불가능한 경우 
                    flag=false;
                    break;
                }
            }
            if(flag) answer++;
        }

        return answer;
    }
}

// 정규식을 이용한 풀이 
class Solution3 {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        ArrayList<String> skillTrees = new ArrayList<String>(Arrays.asList(skill_trees));

        Iterator<String> it = skillTrees.iterator();

        while (it.hasNext()) {
            
            if (skill.indexOf(it.next().replaceAll("[^" + skill + "]", "")) != 0) {
                it.remove();
            }
        }
        answer = skillTrees.size();
        return answer;
    }
}
