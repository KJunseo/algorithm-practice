#include <iostream>

using namespace std;

const char UPPERCASE [] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
const char LOWERCASE [] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

int main(void) {
    string word;
    getline(cin, word);

    string ret = "";
    for(int i = 0; i < word.length(); i++) {
        if(isalpha(word[i])) {
            if(isupper(word[i])) {
                ret += UPPERCASE[word[i] - 65];
            } else {
                ret += LOWERCASE[word[i] - 97];
            }
        } else {
            ret += word[i];
        }
    }

    cout << ret << "\n";


    return 0;
}