class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int res0 = nums[0];
        int res1 = max(nums[1], res0);
        int newn = 0;

        for(int i = 2;i<n;i++){
            newn = max(res1, nums[i] + res0);
            res0 = res1;
            res1 = newn;
        }
        
        return max(res0, res1);
    }
};