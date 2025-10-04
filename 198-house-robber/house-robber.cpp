class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), taken, nottaken, res0, res1;
        res0 = nums[0];
        if(n == 1) return res0;
        res1 = max(res0, nums[1]);
        for(int i = 2;i<n;i++){
            taken = nums[i] + res0;
            res0 = res1;
            res1 = max(taken, res0);
        }

        return res1;
    }
};