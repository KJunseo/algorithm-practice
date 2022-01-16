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
| 17 | [스택 수열](https://www.acmicpc.net/problem/1874) | [풀이](./스택/스택수열_1874.java) | Silver3 | Accepted | 2022.01.12 | 2022.01.19 |
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
