/*
    백준에서 풀어봤던 문제였다.
    그 때 푼 것처럼 다 벡터에 넣고 계산하려 했으나 실패했다..

    수학 문제였다. 라운드가 올라갈 때마다 번호는 (자신+1)/2가 된다. 
    같은 번호에서 만나면 대진을 하는 것이다.
*/
int solution(int n, int a, int b) {
    int round = 0;

    while(n) {
        round++;
        
        a=(a+1)/2;
        b=(b+1)/2;
        
        if(a==b) break;
        
        n/=2;
    }    
    
    return round;
}