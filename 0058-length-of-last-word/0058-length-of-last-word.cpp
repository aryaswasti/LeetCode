class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' ') {
                while( i >= 0 && s[i] != ' '){
                    count++;
                    i--;
                }
                return count;
            }
        }
        
        return count;
    }
};