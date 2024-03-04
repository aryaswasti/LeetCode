class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxScore = 0; // Keep track of the maximum score obtained at any point.
        int left = 0;
        int right = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());

        while (left <= right) {
            if (power >= tokens[left]) { // Can play the token face-up
                power -= tokens[left++];
                maxScore = max(maxScore, ++score);
            } else if (score > 0) { // Can't play the current token face-up, but can play one face-down
                power += tokens[right--];
                score--;
            } else {
                break; // Can't play face-up or face-down, so exit
            }
        }

        return maxScore;
    }
};
