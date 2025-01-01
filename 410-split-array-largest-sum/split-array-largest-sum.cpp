class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0), mid, cnt;
        int n = nums.size();
        long long sum;

        auto check = [&](int x){
            cnt = 1, sum = 0;
            for(int i = 0;i<n;i++){
                if(sum + nums[i] <= x) sum += nums[i];
                else cnt++, sum = nums[i];
            }
            return cnt <= k;
        };
        while(low <= high){
            mid = (low+high)>>1;
            if(check(mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};