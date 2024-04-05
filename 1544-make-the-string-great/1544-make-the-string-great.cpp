class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1){
            return s;
        }
        
        int i = 0;
        int j = 1;
        
        while(i<s.size() && j<s.size()){
            if(s[i] == s[j]+32 || s[i]+32 == s[j]){
                s.erase(s.begin()+i);
                s.erase(s.begin()+j-1);
                i = 0;
                j = 1;
            } else {
                i++;
                j++;
            }
        }
        return s;
    }
};