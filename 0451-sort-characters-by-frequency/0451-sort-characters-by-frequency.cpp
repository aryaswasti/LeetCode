class Solution {
public:
    string frequencySort(string s) {
        //store count of digits and letters
        //here index of vector represent ASCII value of character
        vector<int> chars(128, 0);
        
        //store count of character in "chars" w.r.t. their ascii value
        for(int i = 0; i < s.size(); i++){
            chars[s[i]]++;
        }
        
        //"ans" will store final answer
        string ans = "";
        
        //loop till sum of all characters is zero
        while(accumulate(chars.begin(), chars.end(), 0) > 0){
            //get position of highest count of character
            int pos = distance(chars.begin(), max_element(chars.begin(), chars.end()));
            //if count of character > 0 => add it to the string
            if (chars[pos] > 0){
                //string(char[pos], pos) => string(number of times to repeat character, which character to repeat)
                //pos - makes a string of pos(ASCII value of character)
                //char[pos] - multiply it by count of the character.
                ans += string(chars[pos], pos);
                //initialise count of that letter to 0 so in next iteration max character is next maximum value
                chars[pos] = 0;
            }
        }
        //return answer
        return ans;
    }
};