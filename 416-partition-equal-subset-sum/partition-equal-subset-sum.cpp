class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0, n = nums.size();
        for(int i = 0;i<n;i++) target += nums[i];

        if(target%2) return false;

        target /= 2;

        vector<bool>prev(target+1, false), curr(target+1, false);
        prev[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int i = 1;i<n;i++){
            curr[0] = true;
            for(int k = 1;k<=target;k++){
                bool ntaken = prev[k];
                bool taken = false;
                if(nums[i] <= k) taken = prev[k-nums[i]];
                curr[k] = ntaken || taken;
            }
            prev = curr;
        }

        return curr[target];
    }
};