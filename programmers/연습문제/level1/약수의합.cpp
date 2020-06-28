/*
    +1점
    두 수의 곱이 n이 나오면 그 두 수는 n의 약수이다. 또 제곱 수보다 클 수는 없다.
    만약 하나의 수가 약수라면 n/i도 약수이다.
    i가 서로 같다면 i하나만 더해준다.
*/
int solution(int n) {
    int i;
    int answer = 0;
    
    for(i=1;i*i<n;i++) {
        if(n%i==0) {
            answer+=i;
            answer+=n/i;
        }
    }
    
    if(i*i==n) answer+=i;
    
    return answer;
}