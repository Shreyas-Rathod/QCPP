class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), op1, op2;
        vector<int>curr(2, 0), front1(2, 0), front2(2, 0);
        
        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                if(buy == 0){
                    op1 = max(front1[0], front1[1] - prices[i]);
                }
                if(buy == 1){
                    op1 = max(front1[1], front2[0] + prices[i]);
                }
                curr[buy] = op1;
            }
            front2 = front1;
            front1 = curr; 
        }

        return curr[0];
    }
};