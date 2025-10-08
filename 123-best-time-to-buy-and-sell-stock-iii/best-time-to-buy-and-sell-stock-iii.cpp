class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    curr[buy][cap] = buy ? max(prev[buy][cap], prev[1-buy][cap]-prices[i]) : max(prev[buy][cap], prev[1-buy][cap-1]+prices[i]);
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};