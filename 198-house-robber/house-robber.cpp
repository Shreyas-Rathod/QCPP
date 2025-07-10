class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>res(n, 0);
        res[0] = nums[0];
        res[1] = max(nums[1], res[0]);

        for(int i = 2;i<n;i++){
            res[i] =  max(res[i-1], nums[i] + res[i-2]);
        }
        
        return max(res[n-1], res[n-2]);
    }
};