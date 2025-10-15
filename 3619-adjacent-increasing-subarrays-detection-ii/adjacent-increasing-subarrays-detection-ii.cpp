class Solution {
public:
    bool check(vector<int>&nums, int k){
        int n = nums.size();
        if(2*k > n) return false;
        int prev_cnt = 0, curr_cnt = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]) curr_cnt++;
            else prev_cnt = curr_cnt, curr_cnt = 1;
            if((curr_cnt >= k && prev_cnt >= k) || curr_cnt >= 2*k) return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n, mid;
        while(low <= high){
            mid = (low + high) >> 1;
            if(check(nums, mid)) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }
};