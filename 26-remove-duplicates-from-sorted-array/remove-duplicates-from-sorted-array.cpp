class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replace = 1, n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i-1] == nums[i]) continue;
            else{
                nums[replace] = nums[i];
                replace++;
            }
        }
        return replace;
    }
};