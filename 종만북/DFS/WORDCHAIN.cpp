/*
    오일러 서킷&트레일에 대해 알게되었다.
    모든 간선을 한 번씩 거쳐 시작점(도착점)으로 돌아오는 경로이다.

    이를 위해서는 서킷인 경우 모든 정점이 짝수점이어야하며
    트레일인 경우는 시작점은 들어오는 점이 1작고, 나가는 점이 1 커야한다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C;
int n;
vector<vector<int> > adj; // 그래프의 인접 행렬 표현. adj[i][j] = i와 j 사이의 간선의 수
vector<string> graph[26][26]; // graph[i][j] = i로 시작해서 j로 끝나는 단어의 목록
vector<int> indegree; // i로 시작하는 단어의 수
vector<int> outdegree; // i로 끝나는 단어의 수

void makeGraph(const vector<string>& words) {

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            graph[i][j].clear();
        }
    }

    adj = vector<vector<int> >(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);

    // 각 단어를 그래프에 추가한다.
    for(int i = 0; i < words.size(); i++) {
        int a = words[i][0] - 'a'; // 첫 번째 글자
        int b = words[i][words[i].size()-1] - 'a'; // 두 번째 글자
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}

// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산
void getEulerCircuit(int here, vector<int>& circuit) {
    for(int there = 0; there < adj.size(); there++) {
        while(adj[here][there] > 0) {
            adj[here][there]--; // 간선을 지운다
            getEulerCircuit(there, circuit);
        }
    }

    circuit.push_back(here);
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다.
vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;

    // 먼저 트레일을 찾아본다(시작점이 존재하는 경우)
    for(int i = 0; i < 26; i++) {
        if(outdegree[i] == indegree[i]+1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    // 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
    for(int i = 0; i < 26; i++) {
        if(outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    // 모두 실패할 경우 빈 배열을 반환
    return circuit;
}

// 현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다.
bool checkEuler() {
    // 예비 시작점과 끝점의 수
    int plus1 = 0, minus1 = 0;
    for(int i = 0; i < 26; i++) {
        int delta = outdegree[i] - indegree[i];

        // 모든 정점의 차수는 -1, 1, 0 중에 하나여야 한다.
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }

    // 시작점과 끝 점은 각 하나씩 있거나 하나도 없어야 한다.
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

int main(void) {

    cin.sync_with_stdio(false);
    cin >> C;

    for(int tc = 0; tc < C; tc++) {
        cin >> n;

        vector<string> words(n);
        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }

        makeGraph(words);

        // 차수가 맞지 않으면 실패
        if(!checkEuler()) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // 오일러 서킷이나 경로를 찾기 
        vector<int> circuit = getEulerTrailOrCircuit();

        // 모든 간선을 방문하지 못했으면 실패
        if(circuit.size() != words.size() + 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환
        reverse(circuit.begin(), circuit.end());
        
        string ret;
        for(int i = 1; i < circuit.size(); i++) {
            int a = circuit[i-1], b = circuit[i];
            cout << graph[a][b].back() << " ";
            graph[a][b].pop_back();
        }
        cout << "\n";
    }

    return 0;
}