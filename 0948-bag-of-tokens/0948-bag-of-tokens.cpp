class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //keep track of current score
        int score = 0;
        // Keep track of the maximum score obtained at any point.
        int maxScore = 0; 
        
        //we sort so selection of values is optimal
        sort(tokens.begin(), tokens.end());
        //left will always point to smallest non-used token for using in case to increase score
        int left = 0;
        //right will always point to larget non-used token which can be used in case of increasing power
        int right = tokens.size() - 1;

        while (left <= right) {
            //check if we can increase score
            if (power >= tokens[left]) { 
                //decrease power by lowest token(left)
                power -= tokens[left++];
                //check if it is overall maximum score and update maxScore
                maxScore = max(maxScore, ++score);
            
            //check if score is >= 1 so it can be used for increasing power
            } else if (score >= 1) { 
                //add power of maximum token(right)
                power += tokens[right--];
                //decrease score as it is used to increase power
                score--;
                
            //if can't play both ways, exit loop
            } else {
                break; 
            }
        }

        //return maxScore
        return maxScore;
    }
};
