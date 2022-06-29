/*
    기준선을 1번 인덱스부터 그으면서 한 칸씩 증가시켜가며,
     선에 따라 왼편에 올 수 있는 경우의 수를 배열에 담아, 
     오른편과 비교하여 업데이트 하는 식으로 구현하려 했으나 실패했다.

     먼저 누적합을 구한다. 누적합을 구하면 만약 4~6 합을 구하고 싶다면, sum[6]-sum[3]을 해주면 된다. 
     그 후, 첫 번째 아들에게 줄 쿠키를 고른다. sum[m]을 선택한 경우, 1~m까지의 합이 들어있으며,
     두 번째 아들은 m+1부터 시작해야한다. sum[m+1] 에서 첫 번째 아들의 누적합을 빼주면, 두 번째 아들의 쿠키 수가 나온다.
     첫 번째 아들도 1부터 시작하지 않을 수 있으므로, sum[m]에서 제일 처음 요소부터 하나 씩 빼주면서 비교해준다.

     간단해보이는 문제였는데 어려웠다..
*/
class 쿠키구입 {
    int [] sum = new int[2001]; // 누적합을 저장할 배열 

    public int solution(int[] cookie) {
        int answer = 0;
        
        // 누적합을 저장해둔다.
        for(int i=0;i<cookie.length;i++) {
            sum[i+1] = sum[i]+cookie[i];
        }

        for(int i=1;i<cookie.length;i++) {
            int first = sum[i]; // 첫 번째 아들의 쿠키 수(1~m)

            for(int j=i+1;j<=cookie.length;j++) {
                int second = sum[j]-first; // 두 번째 아들의 쿠키 수(m+1 ~ )

                if(answer>=second || second>first) continue;

                // 첫 번째 아들의 쿠키수가 무조건 1부터 시작하는 건 아니므로 한 바구니씩 빼면서 비교 
                for(int k=0;k<i;k++) { 
                    if(second==first-sum[k]) {
                        if(answer<second) {
                            answer=second;
                            break;
                        }
                    }
                }
            }
        }

        return answer;
    }
}
