/*
    +1점
    a와b의 대소관계를 비교하고 for문으로 모든 정수를 더해준다.
*/
long long solution(int a, int b) {
    long long answer = 0;
    int start, end;
    
    if(a>b) {
        start=b;
        end=a;
    } else {
        start=a;
        end=b;
    }
    
    for(int i=start;i<=end;i++) {
        answer+=i;
    }
    
    return answer;
}