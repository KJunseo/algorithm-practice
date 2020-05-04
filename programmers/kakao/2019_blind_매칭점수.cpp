/*
    html을 정확히 분해하는 것이 중요한 문제였다.
    id, url, basic(기본 점수), link 를 가진 구조체를 만들어
    html을 분해하여 각각 구조체를 채워준 후, 계산 후 정렬하여, 가장 앞의 요소의 인덱스를 return하였다.
    시간을 굉장히 많이 투자해서 풀어냈다고 생각했는데 결국 정확성 테스트에서 55점 밖에 얻지 못했다...

    정규표현식을 이용하거나, 문자열 처리 로직을 구현하여,
    a태그와 meta태그를 분해하여, URL과 링크 URL을 찾는다.
    HTML문서를 검사하여 검색어를 찾는다.

    정규표현식은 뭔지 몰랐지만, 구현은 올바르게 한 것 같은데 어디서 잘못된 지 잘 모르겠다.
    아마 url을 찾는 부분을 잘못한 것 같다. 무조건 6번째 줄에 content에 있다고 생각했는데 그게 아닌 것 같다.
    언제쯤 이런 문제를 쉽게 풀 수 있을까..
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Page {
    int id; // 인덱스
    int basic, link;
    double score;
};

bool compare(Page &a, Page &b) {
    if(a.score==b.score) return a.id<b.id;
    return a.score>b.score;
}

int solution(string word, vector<string> pages) {
    int wordsize=word.size();
    map<string, int> pagehash; // url : index
    vector<Page> pagelist;

    transform(word.begin(), word.end(), word.begin(), ::tolower); // word 소문자로 변경

    for(int i=0;i<pages.size();i++) {
        string& s = pages[i]; // s하나로 접근하기 위함 

        transform(s.begin(), s.end(), s.begin(), ::tolower); // html 소문자로 변환 

        int mid=0;
        int pleft=0;
        int pright;
        // url이 meta태그 밖에 있다면(mid<=pleft) 다시 찾아야함 
        while(mid<=pleft) {
            pleft=s.find("<meta", pleft+1); // meta 태그의 시작 위치를 저장 
            pright=s.find(">", pleft); // meta 태그의 끝 위치를 저장
            mid=s.rfind("https://", pright); // 끝에서부터 url 찾음
        }
        pright=s.find("\"", mid); // "를 만나면 url의 마지막
        string url=s.substr(mid, pright-mid);

        pleft=s.find("<body>", pright); //url 이후부터 다시 탐색하여 <body> 태그 탐색
        int basic=0;

        for(int start=pleft;;) {
            start=s.find(word, start+1); // 문자열을 계속 돌면서 find 해주기 위해 start+1

            if(start==string::npos) break; // 문자열의 끝인 경우

            if(!isalpha(s[start-1]) && !isalpha(s[start+wordsize])) { // 찾은 문자열의 앞 문자와 뒷 문자가 알파벳이 아닌 경우 
                basic++;
                start+=wordsize; // 단어 다음부터 다시 검색 
            }
        }

        int link=0;
        for(int start=pleft;;) { // body 부터 다시 탐색 
            start=s.find("<a href", start+1);

            if(start==string::npos) break; // 못 찾은 경우

            link++;
        }

        pagehash[url]=i; // url : index
        pagelist.push_back({i, basic, link, (double)basic});
    }

    for(int i=0;i<pages.size();i++) {
        string& s=pages[i];

        for(int pleft=0, pright=0;;) {
            pleft=s.find("<a href", pright); // a태그 탐색 

            if(pleft==string::npos) break;

            pleft=s.find("https://", pleft); // url의 시작위치 저장 
            pright=s.find("\"", pleft);

            string linkurl=s.substr(pleft, pright-pleft);

            map<string, int>::iterator it=pagehash.find(linkurl);
            if(it!=pagehash.end()) { // key에 해당하는 값을 찾았으면
                pagelist[it->second].score+=(double)pagelist[i].basic/pagelist[i].link;
            }

        }
    }

    sort(pagelist.begin(), pagelist.end(), compare);

    return pagelist.front().id;
}



// 실패한 풀이(정확성 55)
/*#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Page {
    int id;
    string url;
    int basic;
    vector<string> link;
};

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second>b.second) return true;
    else if(a.second==b.second){
        if(a.first<b.first) return true;
        return false;
    }
    return false;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<Page> p;
    unordered_map<int, double> score;
    
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for(int i=0;i<pages.size();i++) {
        stringstream ss(pages[i]);
        string token;
        string url="";
        int basic=0;
        vector<string> link;
        
        int cnt=0;
        while(getline(ss, token, '\n')) {
            
            transform(token.begin(), token.end(), token.begin(), ::tolower);
            
            if(cnt==3){
                int length=token.length()-(token.find("content")+9)-3;
                url = token.substr(token.find("content")+9, length);
            }
            
            if(token.find("<a href")!=-1) {
                string temp="";
                int idx=token.find("<a href")+9;
                for(int i=idx;i<token.length();i++) {
                    if(token[i]=='"') break;
                    temp+=token[i];
                }
                link.push_back(temp);
            }
            
            if(cnt>=6) {
                int idx=0;
                string temp="";
                for(int i=0;i<token.length();i++) {
                    if(isalpha(token[i])){
                        temp+=token[i];         
                    } else {
                        if(temp==word) {
                            basic++;
                        }
                        temp="";
                    }
                    if(i==token.length()-1) {
                        if(temp==word) {
                            basic++;
                        }
                    }
                }
            }
            cnt++;
        }
        p.push_back({i, url, basic, link});
    }
    
    for(int i=0;i<p.size();i++) {
        string url = p[i].url;
        int id=p[i].id;
        score[id]=p[i].basic;
            
        for(int j=0;j<p.size();j++) {
            for(int k=0;k<p[j].link.size();k++) {
                if(url==p[j].link[k]) {
                    double sum=score[id];
                    sum+=(double)p[j].basic/(double)p[j].link.size();
                    score[id]=sum;
                }
            }
        }
    }
    
    vector<pair<int, double> > result;
    for (auto it=score.begin();it!=score.end();it++) {
        result.push_back(make_pair(it->first, it->second));
    }
    
    sort(result.begin(), result.end(), compare);
    
    answer=result.front().first;
    
    return answer;
}*/