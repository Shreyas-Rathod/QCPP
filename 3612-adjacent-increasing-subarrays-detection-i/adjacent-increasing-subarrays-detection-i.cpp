class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(2*k > n) return false;

        int prevcnt = 0, currcnt = 1;

        for(int i = 1;i<n;i++){
            if(nums[i-1] < nums[i]) currcnt++;
            else prevcnt = currcnt, currcnt = 1;
            if((currcnt >= k && prevcnt >= k) || currcnt == 2*k) return true;
        }

        return false;
    }
};