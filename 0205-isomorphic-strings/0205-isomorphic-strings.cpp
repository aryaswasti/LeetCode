class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //track "s" string corresponding characters in "t"
        unordered_map<char, char> strack;
        //if character in "t" is found => true
        //for new "s" character: check if the corresdonding letter in "t" "already used for other letter?
        unordered_map<char, bool> ttrack;
        
        //iterate over "s"
        for(int i=0; i<s.length(); i++)
        {
            //character found is not new
            if(strack.find(s[i]) != strack.end())
            {
                //check(strack) corresponding charecter of s[i]: t => check with t[i]
                //not equal => return false
                if(strack[s[i]] != t[i])
                    return false;
            }
            //check if there is another corresponding letter of t found earlier
            else if(ttrack[t[i]])
            {
                //multiple refernce of t character to different character in s => return false
                return false;
            }
            //element found for first time
            else
            {
                //add "s" element and corresponding "t" element
                strack[s[i]] = t[i];
                //set "t" character as true(seen before)
                ttrack[t[i]] = true;
            }
        }
        //all wrong checks passed in loop => hence valid isomorphic strings
        return true;
    }
};