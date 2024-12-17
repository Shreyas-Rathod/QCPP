class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > nums[(i+1)%n]) index++;
        }
        if(index <= 1) return true;
        return false;
    }
};