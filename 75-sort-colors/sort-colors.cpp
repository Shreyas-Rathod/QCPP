class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc = -1, n = nums.size(), tc = n;
        for(int i = 0;i<n;i++) if(!nums[i]) swap(nums[i], nums[++zc]);
        for(int i = n-1;i>zc;i--) if(nums[i] == 2) swap(nums[i], nums[--tc]); 
    }
};