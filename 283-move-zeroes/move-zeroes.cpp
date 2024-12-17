class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), temp = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0) nums[temp++] = nums[i];
        }
        while(temp < n) nums[temp++] = 0;
    }
};