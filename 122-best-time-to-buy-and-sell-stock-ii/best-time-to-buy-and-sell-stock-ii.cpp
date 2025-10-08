class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max_sum = 0;
        vector<int>prev(2, 0), curr(2, 0);
        int prev0 = 0, prev1 = 0, curr0 = 0, curr1 = 0;
        for(int i = n-1;i>=0;i--){
            curr0 = max(prev0, prices[i] + prev1);
            curr1 = max(prev1, prev0 - prices[i]);
            prev0 = curr0;
            prev1 = curr1;
        }

        return curr1;
    }
};