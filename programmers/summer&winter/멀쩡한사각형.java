/*
    코드 자체는 매우 간단한데, 나는 규칙을 찾지를 못했다.

    최대공약수 문제였다.
    이 문제는 반복되는 패턴이 존재했고, 그 패턴이 최대공약수만큼 반복된다.
    패턴은 (가로/최대공약수 + 세로/최대공약수 -1)이다.
    따라서 전체 갯수에서 (가로/최대공약수 + 세로/최대공약수 -1)*최대공약수 = 가로+세로-최대공약수 가 정답이다. 
    
    1차 함수를 이용한 풀이도 첨부하였다. 이해를 잘 하지 못하였다.
*/
// 최대공약수 풀이
class Solution {
    
    // 최대 공약수를 구해주는 함수 
    public long gcd(long max, long min) {
        if(max%min==0) {
            return min;
        }
        return gcd(min, max%min);
    }
    
	public long solution(int w, int h) {
		long answer = 0;
		long min = (long)h;
		long max = (long)w;
        
		if (w < h) {
			min = (long)w;
			max = (long)h;
		}

		answer = (long)w * (long)h - ((long)w + (long)h - gcd(max, min));
		return answer;
	}
}

// 1차 함수 풀이
/*class Solution {
    public long solution(int w, int h) {
        long answer = 0;
        
        for(int i=0;i<w;i++) {
            answer+=(Long.valueOf(h)*i)/Long.valueOf(w);
        }
        
        return answer*2;
    }
}
*/