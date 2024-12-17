class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc = -1, tc = nums.size(), n = tc;
        for(int i = 0;i<n;i++) if(nums[i]==0) swap(nums[i], nums[++zc]);
        for(int i = n-1;i>zc;i--) if(nums[i]==2) swap(nums[i], nums[--tc]);
    }
};