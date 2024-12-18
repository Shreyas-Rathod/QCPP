class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maxsum = INT_MIN, cntsum = 0;
        for(int i = 0;i<n;i++){
            cntsum += nums[i];
            maxsum = max(maxsum, cntsum);
            if(cntsum < 0) cntsum = 0;
        }
        return maxsum;
    }
};