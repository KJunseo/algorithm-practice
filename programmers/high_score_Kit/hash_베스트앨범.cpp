/*
    장르는 키 값이 여러 번 중복 되므로, 장르 당 토탈 플레이시간을 알아내기 위해 unordered_map을 사용했다.
    벡터를 사용해서 해당 곡의 고유번호, 장르, 플레이 시간을 한 단위로 합쳤다.(다른 사람의 풀이를 보니 이것도 unordered_map으로 합칠 수도 있었다.)
    그 후, 토탈 플레이시간과, 해당 곡 정보를 둘 다, 플레이 시간을 기준으로 정렬하였고,
    장르당 두개씩 출력하게 하였다.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair <pair <string, int>, int> a, pair <pair <string, int>, int> b) {
    if(a.first.second>b.first.second) return true;
    return false;
}

bool compare2(pair<string, int> a, pair<string, int> b) {
    if(a.second > b.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector <pair <pair <string, int>, int> > p; // unordered_map<string, vector<pair<int, int> > > p; 로도 할 수 있다.
    unordered_map <string, int> total;

    for(int i=0;i<genres.size();i++) {
        p.push_back(make_pair(make_pair(genres[i],plays[i]),i)); // p[genres[i]].push_back(make_pair(plays[i],i));
        total[genres[i]]+=plays[i];
    }

    vector <pair<string, int> > temp;

    for(auto elem : total) {
        temp.push_back(make_pair(elem.first, elem.second));
    }

    sort(p.begin(), p.end(), compare);
    sort(temp.begin(), temp.end(), compare2);

    for(int j=0;j<temp.size();j++) {
        int cnt=0;  
        for(int i=0;i<p.size();i++) {
            if(temp[j].first==p[i].first.first) {
                if(cnt<2) {
                    answer.push_back(p[i].second);
                    cnt++;
                } else {
                    break;
                }
            }  
        }        
    }

    return answer;
}