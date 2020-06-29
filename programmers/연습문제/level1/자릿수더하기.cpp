/*
    +1점
    비트연산을 사용할 수 있지 않을까 생각해보다가 방법을 모르겠어서
    그냥 %와 /를 이용하여 풀었다.
*/
int solution(int n) {
    int answer = 0;

    while(n>0) {
        answer+=n%10;
        n/=10;
    }
    
    return answer;
}