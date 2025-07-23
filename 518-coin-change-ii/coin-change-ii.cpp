class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), total = 0;
        
        if(!amount) return 1;
        vector<unsigned long long>prev(amount + 1, 0);

        for(int i = 0;i<=amount;i++){
            prev[i] = (i%coins[0] == 0);
        }

        for(int i = 1;i<n;i++){
            for(int k = coins[i];k<=amount;k++){
                prev[k] += prev[k-coins[i]];
            }
        }

        return prev[amount];

    }
};