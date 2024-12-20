class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-2;
        while(i >= 0){
            if(nums[i] >= nums[i+1]) i--;
            else{
                int j = n-1;
                while(i!=j && nums[i] >= nums[j]) j--;
                swap(nums[i], nums[j]);
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if(i != -1) return;
        reverse(nums.begin(), nums.end());
    }
};