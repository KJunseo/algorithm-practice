## 바킹독님 실전 알고리즘

[바킹독님의 실전 알고리즘](https://blog.encrypted.gg/category/%EA%B0%95%EC%A2%8C/%EC%8B%A4%EC%A0%84%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98?page=2) 커리큘럼을 따라가보며 코딩테스트 준비하기

- 시작일: 2022.01.07
- 언어: Java
- [문제집](https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md)
- 강의 듣고 관련 연습문제 3 ~ 5개 풀고 넘어가기(연습 문제 + 기본 문제✔)
- 모든 강의 다 듣고 난 후, 남은 문제들 풀기
- 한 문제에 1시간 이상 쓰지 않기
- 시간복잡도를 생각한 후 풀기
  - 시간 제한이 1초 -> 컴퓨터는 1초에 대략 3-5억 개 정도의 연산을 처리
  - 공간복잡도는 거의 신경쓰지 않아도 됨.(512MB = 1.2억개의 int 선언 가능 -> 크기가 5억인 배열 사용 불가능)

### 입력 값에 따른 허용 시간복잡도
<img width="632" alt="스크린샷 2022-01-06 오후 4 21 50" src="https://user-images.githubusercontent.com/45876793/148344669-cceb9357-8b87-4c5b-a16b-a42a9f2f26b5.png">

### 문제 풀이 기록표
> State
> - Master: 한 번에 문제 풀이 완료. 다시 풀 필요 없음
> - Accepted: 문제를 풀긴 했지만 찝찝한 경우. 1주일 뒤에 다시 풀기
> - Fail: 문제를 못 풀어서 풀이를 참고한 경우. 다음날 다시 풀기(다시 풀어서 맞은 경우 문제 이름 앞에 * 표시)

| No | Problem | Explanation | Difficult | State | First Solving Date | Next Solving Date |
|:------:|:---------:|:---------:|:-----------:|:-----------:|:-----------:|:-----------:|
| 1 | [X보다 작은 수](https://www.acmicpc.net/problem/10871) | [풀이](./기초코드작성요령/X보다작은수_10871.java) | Bronze3 | Master | 2022.01.07 | - |
| 2 | [윤년](https://www.acmicpc.net/problem/2753) | [풀이](./기초코드작성요령/윤년_2753.java) | Bronze4 | Master | 2022.01.07 | - |
| 3 | [대표값2](https://www.acmicpc.net/problem/2587) | [풀이](./기초코드작성요령/대표값2_2587.java) | Bronze2 | Master | 2022.01.07 | - |
| 4 | [숫자](https://www.acmicpc.net/problem/10093) | [풀이](./기초코드작성요령/숫자_10093.java) | Bronze2 | Master | 2022.01.07 | - |
| 5 | [카드 역배치](https://www.acmicpc.net/problem/10804) | [풀이](./기초코드작성요령/카드역배치_10804.java) | Bronze2 | Master | 2022.01.07 | - |
| 6 | [빠른 A+B](https://www.acmicpc.net/problem/15552) | [풀이](./기초코드작성요령/빠른AplusB_15552.java) | Bronze2 | Master | 2022.01.07 | - |
| 7 | [알파벳 개수](https://www.acmicpc.net/problem/10808) | [풀이](./배열/알파벳개수_10808.java) | Bronze2 | Master | 2022.01.08 | - |
| 8 | [숫자의 개수](https://www.acmicpc.net/problem/10808) | [풀이](./배열/숫자의개수_2577.java) | Bronze2 | Master | 2022.01.08 | - |
| 9 | [방 번호](https://www.acmicpc.net/problem/1475) | [풀이](./배열/방번호_1475.java) | Silver5 | Master | 2022.01.08 | - |
| 10 | [개수 세기](https://www.acmicpc.net/problem/10807) | [풀이](./배열/개수세기_10807.java) | Bronze2 | Master | 2022.01.08 | - |
| 11 | [두 수의 합](https://www.acmicpc.net/problem/3273) | [풀이](./배열/두수의합_3273.java) | Silver3 | Master | 2022.01.08 | - |
| 12 | [*에디터](https://www.acmicpc.net/problem/1406) | [풀이](./연결리스트/에디터_1406.java) | Silver3 | Master | 2022.01.10 | 2022.01.11 |
| 13 | [키로거](https://www.acmicpc.net/problem/5397) | [풀이](./연결리스트/키로거_5397.java) | Silver3 | Master | 2022.01.10 | - |
| 14 | [요세푸스 문제](https://www.acmicpc.net/problem/1158) | [풀이](./연결리스트/요세푸스문제_1158.java) | Silver5 | Master | 2022.01.10 | - |
| 15 | [스택](https://www.acmicpc.net/problem/10828) | [풀이](./스택/스택_10828.java) | Silver4 | Master | 2022.01.12 | - |
| 16 | [제로](https://www.acmicpc.net/problem/10773) | [풀이](./스택/제로_10773.java) | Silver4 | Master | 2022.01.12 | - |
| 17 | [*스택 수열](https://www.acmicpc.net/problem/1874) | [풀이](./스택/스택수열_1874.java) | Silver3 | Master | 2022.01.12 | 2022.01.19 |
| 18 | [탑](https://www.acmicpc.net/problem/2493) | [풀이](./스택/탑_2493.java) | Gold5 | Master | 2022.01.12 | - |
| 19 | [*옥상 정원 꾸미기](https://www.acmicpc.net/problem/6198) | [풀이](./스택/옥상정원꾸미기_6198.java) | Gold5 | Master | 2022.01.12 | 2022.01.13 |
| 20 | [큐](https://www.acmicpc.net/problem/10845) | [풀이](./큐/큐_10845.java) | Silver4 | Master | 2022.01.13 | - |
| 21 | [큐](https://www.acmicpc.net/problem/18258) | [풀이](./큐/큐2_18258.java) | Silver4 | Master | 2022.01.13 | - |
| 22 | [카드2](https://www.acmicpc.net/problem/2164) | [풀이](./큐/카드2_2164.java) | Silver4 | Master | 2022.01.13 | - |
| 23 | [덱](https://www.acmicpc.net/problem/10866) | [풀이](./덱/덱_10866.java) | Silver4 | Master | 2022.01.13 | - |
| 24 | [회전하는 큐](https://www.acmicpc.net/problem/1021) | [풀이](./덱/회전하는큐_1021.java) | Silver4 | Master | 2022.01.13 | - |
| 25 | [*AC](https://www.acmicpc.net/problem/5430) | [풀이](./덱/AC_5430.java) | Gold5 | Master | 2022.01.13 | 2022.01.14 |
| 26 | [균형잡힌 세상](https://www.acmicpc.net/problem/4949) | [풀이](./스택/균형잡힌세상_4949.java) | Silver4 | Master | 2022.01.14 | - |
| 27 | [좋은 단어](https://www.acmicpc.net/problem/3986) | [풀이](./스택/좋은단어_3986.java) | Silver4 | Master | 2022.01.14 | - |
| 28 | [괄호](https://www.acmicpc.net/problem/9012) | [풀이](./스택/괄호_9012.java) | Silver4 | Master | 2022.01.14 | - |
| 29 | [쇠막대기](https://www.acmicpc.net/problem/10799) | [풀이](./스택/쇠막대기_10799.java) | Silver3 | Master | 2022.01.15 | - |
| 30 | [*괄호의 값](https://www.acmicpc.net/problem/2504) | [풀이](./스택/괄호의값_2504.java) | Silver2 | Master | 2022.01.15 | 2022.01.16 |
| 31 | [그림](https://www.acmicpc.net/problem/1926) | [풀이](./BFS/그림_1926.java) | Silver1 | Master | 2022.01.16 | - |
| 32 | [미로탐색](https://www.acmicpc.net/problem/2178) | [풀이](./BFS/미로탐색_2178.java) | Silver1 | Master | 2022.01.16 | - |
| 33 | [*토마토](https://www.acmicpc.net/problem/7576) | [풀이](./BFS/토마토_7576.java) | Silver1 | Master | 2022.01.16 | 2022.01.17 |
| 34 | [*불](https://www.acmicpc.net/problem/4179) | [풀이](./BFS/불_4179.java) | Gold4 | Master | 2022.01.17 | 2022.01.19 |
| 35 | [숨바꼭질](https://www.acmicpc.net/problem/1697) | [풀이](./BFS/숨바꼭질_1697.java) | Silver1 | Master | 2022.02.21 | - |
| 36 | [유기농 배추](https://www.acmicpc.net/problem/1012) | [풀이](./BFS/유기농배추_1012.java) | Silver2 | Master | 2022.02.21 | - |
| 37 | [적록 색약](https://www.acmicpc.net/problem/10026) | [풀이](./BFS/적록색약_10026.java) | Gold5 | Master | 2022.02.22 | - |
| 38 | [토마토](https://www.acmicpc.net/problem/7569) | [풀이](./BFS/토마토_7569.java) | Gold5 | Master | 2022.02.22 | - |
| 39 | [나이트의 이동](https://www.acmicpc.net/problem/7562) | [풀이](./BFS/나이트의이동_7562.java) | Silver2 | Master | 2022.02.22 | - |
| 40 | [불](https://www.acmicpc.net/problem/5427) | [풀이](./BFS/불_5427.java) | Gold4 | Master | 2022.02.22 | - |
| 41 | [곱셈](https://www.acmicpc.net/problem/1629) | [풀이](./재귀/곱셈_1629.java) | Silver1 | Master | 2022.02.23 | - |
| 42 | [하노이 탑 이동 순서*](https://www.acmicpc.net/problem/11729) | [풀이](./재귀/하노이탑이동순서_11729.java) | Silver1 | Master | 2022.02.23 | 2022.02.24 |
| 43 | [*Z](https://www.acmicpc.net/problem/1074) | [풀이](./재귀/Z_1074.java) | Silver1 | Master | 2022.02.23 | 2022.02.24 |
| 44 | [재귀함수가 뭔가요?](https://www.acmicpc.net/problem/17478) | [풀이](./재귀/재귀함수가뭔가요_17478.java) | Silver5 | Master | 2022.02.23 | - |
| 45 | [종이의 개수](https://www.acmicpc.net/problem/1780) | [풀이](./재귀/종이의개수_1780.java) | Silver2 | Master | 2022.02.24 | - |
| 46 | [색종이 만들기](https://www.acmicpc.net/problem/2630) | [풀이](./재귀/색종이만들기_2630.java) | Silver3 | Master | 2022.02.24 | - |
| 47 | [쿼드트리](https://www.acmicpc.net/problem/1992) | [풀이](./재귀/쿼드트리_1992.java) | Silver1 | Master | 2022.02.24 | - |
| 48 | [N과 M(1)](https://www.acmicpc.net/problem/15649) | [풀이](./백트래킹/N과M1_15649.java) | Silver3 | Master | 2022.02.25 | - |
| 49 | [*N-Queen](https://www.acmicpc.net/problem/9663) | [풀이](./백트래킹/NQueen_9663.java) | Gold 5 | Master | 2022.02.25 | 2022.03.04 |
| 50 | [부분수열의 합](https://www.acmicpc.net/problem/1182) | [풀이](./백트래킹/부분수열의합_1182.java) | Silver 2 | Master | 2022.02.25 | - |
| 51 | [N과 M(2)](https://www.acmicpc.net/problem/15650) | [풀이](./백트래킹/N과M2_15650.java) | Silver 3 | Master | 2022.03.04. | - |
| 52 | [N과 M(3)](https://www.acmicpc.net/problem/15651) | [풀이](./백트래킹/N과M3_15651.java) | Silver 3 | Master | 2022.03.04. | - |
| 52 | [N과 M(4)](https://www.acmicpc.net/problem/15652) | [풀이](./백트래킹/N과M4_15652.java) | Silver 3 | Master | 2022.03.04. | - |
| 53 | [N과 M(5)](https://www.acmicpc.net/problem/15654) | [풀이](./백트래킹/N과M5_15654.java) | Silver 3 | Master | 2022.03.04. | - |
| 54 | [N과 M(6)](https://www.acmicpc.net/problem/15655) | [풀이](./백트래킹/N과M6_15655.java) | Silver 3 | Master | 2022.03.04. | - |
| 55 | [N과 M(7)](https://www.acmicpc.net/problem/15656) | [풀이](./백트래킹/N과M7_15656.java) | Silver 3 | Master | 2022.03.04. | - |
| 56 | [N과 M(8)](https://www.acmicpc.net/problem/15657) | [풀이](./백트래킹/N과M8_15657.java) | Silver 3 | Master | 2022.03.05. | - |
| 57 | [N과 M(9)](https://www.acmicpc.net/problem/15663) | [풀이](./백트래킹/N과M9_15663.java) | Silver 2 | Master | 2022.03.05. | - |
| 58 | [N과 M(10)](https://www.acmicpc.net/problem/15664) | [풀이](./백트래킹/N과M10_15664.java) | Silver 2 | Master | 2022.03.05. | - |
| 59 | [N과 M(11)](https://www.acmicpc.net/problem/15665) | [풀이](./백트래킹/N과M11_15665.java) | Silver 2 | Master | 2022.03.06. | - |
| 60 | [N과 M(12)](https://www.acmicpc.net/problem/15666) | [풀이](./백트래킹/N과M12_15666.java) | Silver 2 | Master | 2022.03.06. | - |
| 61 | [로또](https://www.acmicpc.net/problem/6603) | [풀이](./백트래킹/로또_6603.java) | Silver 2 | Master | 2022.03.06. | - |
| 62 | [*감시](https://www.acmicpc.net/problem/15683) | [풀이](./시뮬레이션/감시_15683.java) | Gold 5 | Master | 2022.03.08. | 2022.03.09. |
| 63 | [스티커 붙이기](https://www.acmicpc.net/problem/18808) | [풀이](./시뮬레이션/스티커붙이기_18808.java) | Gold 3 | Master | 2022.03.09. | - |
| 64 | [*2048 (EASY)](https://www.acmicpc.net/problem/12100) | [풀이](./시뮬레이션/EASY2048_12100.java) | Gold 2 | Master | 2022.03.10. | 2022.03.11. |
| 65 | [치킨 배달](https://www.acmicpc.net/problem/15686) | [풀이](./시뮬레이션/치킨배달_15686.java) | Gold 5 | Master | 2022.03.14. | - |
| 66 | [Puyo Puyo](https://www.acmicpc.net/problem/11559) | [풀이](./시뮬레이션/PuyoPuyo_11559.java) | Gold 4 | Master | 2022.03.15. | - |
| 67 | [톱니바퀴](https://www.acmicpc.net/problem/14891) | [풀이](./시뮬레이션/톱니바퀴_14891.java) | Gold 5 | Master | 2022.03.16. | - |
| 68 | [주사위 굴리기](https://www.acmicpc.net/problem/14499) | [풀이](./시뮬레이션/주사위굴리기_14499.java) | Gold 4 | Master | 2022.03.17. | - |
| 69 | [동전 0](https://www.acmicpc.net/problem/11047) | [풀이](./그리디/동전0_11047.java) | Silver 3 | Master | 2022.03.21. | - |
| 70 | [1로 만들기](https://www.acmicpc.net/problem/1463) | [풀이](./DP/일로만들기_1463.java) | Silver 3 | Master | 2022.03.21. | - |
| 71 | [트럭](https://www.acmicpc.net/problem/13335) | [풀이](./시뮬레이션/트럭_13335.java) | Silver 1 | Master | 2022.03.21. | - |
| 72 | [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095) | [풀이](./DP/일이삼더하기_9095.java) | Silver 3 | Master | 2022.03.22. | - |
| 73 | [연결 요소의 개수](https://www.acmicpc.net/problem/11724) | [풀이](./그래프/연결요소의개수_11724.java) | Silver 2 | Master | 2022.03.22. | - |
| 74 | [Maaaaaaaaaze](https://www.acmicpc.net/problem/16985) | [풀이](./시뮬레이션/Maaaaaaaaaze_16985.java) | Gold 3 | Master | 2022.03.22. | - |
