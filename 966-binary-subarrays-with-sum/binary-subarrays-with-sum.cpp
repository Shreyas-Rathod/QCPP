class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), start = 0, res = 0, presum = 0, rescnt = 0;

        for(int end = 0;end<n;end++){
            presum += nums[end];
            while(start < end && (nums[start] == 0 || presum > goal)){
                if(nums[start]) rescnt = 0;
                else rescnt++;
                presum -= nums[start++];
            }
            if(presum == goal) res += 1 + rescnt;
        }

        return res;
    }
};