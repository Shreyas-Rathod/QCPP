class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i-nums[i] > 1 || i-nums[i] < -1) return false;
        }
        return true;
    }
};