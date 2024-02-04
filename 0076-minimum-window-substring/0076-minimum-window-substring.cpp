class Solution {    
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size() || s == "" || t == ""){
            return "";
        }
        
        if(s == t){
            return s;
        }
        
        vector<int> umapT(128, 0);
        
        for(char c : t){
            umapT[c]++;
        }
        
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int startPos = 0;
        int count = t.size();
        
        while(right < s.size()){
            if(umapT[s[right++]]-- > 0){
                count--;
            } 
            
            while(count == 0) {
                if(right-left < minLen) {
                startPos = left;
                    minLen = right - left;
                }

                if (umapT[s[left++]]++ == 0) {
                    count++;
                }
            }
            
        }
        
        return minLen == INT_MAX ? "" : s.substr(startPos, minLen);
    }
};