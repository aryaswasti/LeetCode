class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> seen;
        int longestPalindrome = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(seen.find(s[i]) == seen.end())
                seen.insert(s[i]);
            else
            {
                seen.erase(s[i]);
                longestPalindrome+=2;
            }
        }
        
        if(seen.size()>=1)
            return longestPalindrome+1;
        
        return longestPalindrome;
    }
};