class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prev_cnt = 0, curr_cnt = 1, res = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]) curr_cnt++;
            else prev_cnt = curr_cnt, curr_cnt = 1;
            res = max(res, max(curr_cnt >> 1, min(prev_cnt, curr_cnt)));
        }

        return res;
    }
};