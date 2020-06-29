/*
    +1점 
    accumulate로 합을 구하고 사이즈로 나누었다.
*/
#include <numeric>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    
    double sum=accumulate(arr.begin(), arr.end(), 0);
    
    return sum/(double)arr.size();
}