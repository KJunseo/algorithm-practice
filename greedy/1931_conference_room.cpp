#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second==b.second) return a.first > b.first;
    else return a.second > b.second;
}

vector <pair<int, int> > a;
int main(void) {
    int num;
    int start, end;
    int count=0;
    scanf("%d", &num);

    for(int i=0;i<num;i++) {
        scanf("%d %d", &start, &end);
        a.push_back(make_pair(start,end));
    }

    sort(a.begin(), a.end(), compare);

    int e = a[num-1].second;
    a.pop_back();
    count++;

    for(int i=a.size()-1;i>=0;i--) {
        if(a[i].first>=e) {
            count++;
            e=a[i].second;
        } 
        a.pop_back();
    }

    printf("%d", count);

    return 0;
}