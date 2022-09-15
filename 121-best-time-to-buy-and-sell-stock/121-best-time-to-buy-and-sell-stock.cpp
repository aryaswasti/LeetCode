class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int left = 0;
        int right = 1;
        
        while(left<prices.size() && right<prices.size())
        {
            if(prices[left] >= prices[right])
            {
                left = right;
                right++;
            }
            else
            {
                prof = max(prof, prices[right]-prices[left]);
                right++;
            }
        }
        return prof;
    }
};