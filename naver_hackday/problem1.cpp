#include <string>
#include <vector>

using namespace std;

string solution(int n, vector<vector<int>> delivery) {
    string answer = "";
    char temp[n];
    vector <int> o;
    
    for(int i=0;i<delivery.size();i++) {
        if(delivery[i][2]==1) {
            o.push_back(delivery[i][0]);
            o.push_back(delivery[i][1]);
            temp[delivery[i][0]]='O';
            temp[delivery[i][1]]='O';
        } 
    }
    
    for(int i=0;i<o.size();i++) {
        int num = o[i];
        for(int j=0;j<delivery.size();j++) {
            if(delivery[j][2]!=1) {
                if(delivery[j][0]==num || delivery[j][1]==num) {
                    if(delivery[j][0]!=num) {
                        temp[delivery[j][0]]='X';
                    } else if(delivery[j][1]!=num) {
                        temp[delivery[j][1]]='X';
                    }
                }                
            }
        }
    }
    
    for(int i=1;i<n+1;i++) {
        if(temp[i]=='O') answer+='O';
        else if(temp[i]=='X') answer+='X';
        else answer+='?';
    }
    
    return answer;
}