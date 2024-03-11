#include <string>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int optr = 0;
        
        for(int i = 0; i < order.size(); i++) {
            char currentChar = order[i];
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == currentChar) {
                    swap(s[optr], s[j]);
                    optr++;
                }
            }
        }
        
        return s;
    }
};
