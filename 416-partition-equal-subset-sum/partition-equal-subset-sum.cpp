class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;

        for(int i = 0;i<n;i++) target += nums[i];
        if(target%2) return false;
        int tar = target/2;

        vector<bool>prev(tar+1, false), curr(tar+1, false);
        prev[0] = true;
        
        for(int i = 0;i<n;i++) if(nums[0] <= tar) prev[nums[0]] = true;

        for(int i = 1;i<n;i++){
            curr[0] = true;
            for(int sum = 1;sum<=tar;sum++){
                bool nottaken = prev[sum], taken = false;
                if(nums[i] <= sum) taken = prev[sum-nums[i]];
                curr[sum] = nottaken || taken;
            }
            prev = curr;
        }

        return prev[tar];
    }
};