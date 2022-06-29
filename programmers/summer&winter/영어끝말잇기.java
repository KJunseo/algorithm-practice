/*
    set을 사용하여 중복여부를 검사했고,
    이전 단어의 끝과 현재 단어의 시작을 비교해서 같은지 여부를 확인했다.

    +1이지만 통과했다..
*/
import java.util.*;

class 영어끝말잇기 {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        Set<String> set = new HashSet<>();
        char prev_last = words[0].charAt(words[0].length()-1);
        set.add(words[0]);
        
        for(int i=1;i<words.length;i++) {
            String temp = words[i];
            int current_user = (i%n)+1;
            int current_turn = (i/n)+1;
            char current_start = words[i].charAt(0);
            
            if(set.contains(temp)) {
                answer[0]=current_user;
                answer[1]=current_turn;
                break;
            } 
            
            if(prev_last!=current_start) {
                answer[0]=current_user;
                answer[1]=current_turn;
                break;
            }
            
            set.add(temp);
            
            prev_last=words[i].charAt(words[i].length()-1);
        }

        return answer;
    }
}
