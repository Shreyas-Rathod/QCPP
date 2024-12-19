class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), currmin = nums[k], l = k, r = k, maxsum = nums[k];
        while(l > 0 || r < n-1){
            if(l == 0 || (r+1 < n && nums[r+1] > nums[l-1])) r++;
            else l--;
            currmin = min(currmin, min(nums[r], nums[l]));
            maxsum = max(maxsum, currmin*(r-l+1));
        }
        return maxsum;
    }
};