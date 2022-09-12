class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> strack;
        unordered_map<char, char> ttrack;
        
        for(int i=0; i<s.length(); i++)
        {
            if(strack.find(s[i]) != strack.end())
            {
                if(strack[s[i]] != t[i])
                    return false;
            }
            
            else if(ttrack.find(t[i]) != ttrack.end())
            {
                if(ttrack[t[i]] != s[i])
                    return false;
            }
            
            else
            {
                strack[s[i]] = t[i];
                ttrack[t[i]] = s[i];
            }
        }
        return true;
    }
};