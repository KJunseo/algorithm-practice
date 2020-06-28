/*
    +3점을 받았다.
    소수가 나와서 바로 에라토스테네스의 체를 사용하였다.
*/
int solution(int n) {
    int answer=0;
    int array[n+1]; // 소수를 판별할 범위만큼 배열 할당 
    
    // 자기 자신으로 초기화
    for(int i=2;i<=n;i++) {
        array[i]=i;
    }
    
    for(int i=2;i<=n;i++) {
        if(array[i]==0) continue; // 이미 지워진 수 건너뛰기 

        // 특정 수의 배수에 해당하는 숫자 모두 삭제
        for(int j=2*i;j<=n;j+=i) {
            array[j]=0;
        }
    }
    
    for(int i=2;i<=n;i++) {
        if(array[i]!=0) answer++;
    }
    
    return answer;
}