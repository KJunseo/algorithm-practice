/*
    +1점 처음에 num을 int로 사용하니까 3번째 테스트케이스가 맞지 않았다.
    *3씩 계속 될 수 있어서 int를 long long으로 바꿔서해주니 통과했다.
*/
int solution(int num) {
    int answer = 0;
    long long lnum=(long long)num;
    
    for(answer=0;answer<500;answer++) {
        if(lnum==1) break;
        
        if(lnum%2==0) {
            lnum/=2;
        } else {
            lnum=(lnum*3)+1;
        }
    }
    
    if(answer==500) answer=-1;
    
    return answer;
}