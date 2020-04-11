#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;
    unordered_map <string, int> um;
    unordered_map <string, bool> checked;
    string temp;
    
    for(int i=0;i<id_list.size();i++) {
        stringstream ss(id_list[i]);
        
        while(ss>>temp) {
            um[temp]=k;
            checked[temp]=false;
        }
    }
    
    for(int i=0;i<id_list.size();i++) {
        stringstream ss(id_list[i]);
        
        while(ss>>temp) {
            if(!checked[temp] && um[temp]!=0) {
                um[temp]--;
                answer++;
                checked[temp]=true;
            }
        }
        for(auto it=checked.begin();it!=checked.end();it++) {
            checked[it->first]=false;
        }
    }
    
    return answer;
}