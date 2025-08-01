class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prev(2, 0), curr(2, 0);
        prev[0] = prev[1] = 0;

        for(int i = n-1;i>=0;i--){
            curr[0] = max(prices[i] + prev[1], prev[0]);
            curr[1] = max(prev[0] - prices[i], prev[1]);
            prev = curr;
        }

        return curr[1];
    }
};