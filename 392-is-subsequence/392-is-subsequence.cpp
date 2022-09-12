class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptrs = 0;
        int ptrt = 0;
        
        while(ptrs < s.length() and ptrt < t.length())
        {
            if(s[ptrs] == t[ptrt])
                ++ptrs;
            
            ++ptrt;
        }
        
        if(ptrs == s.length())
            return true;
        
        return false;
    }
};