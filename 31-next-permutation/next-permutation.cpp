class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return;

        // 1) Find first index i from the right where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        if (i >= 0) {
            // 2) Find rightmost j > i with nums[j] > nums[i]
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) j--;
            // 3) Swap pivot with that element
            swap(nums[i], nums[j]);
        }

        // 4) Reverse the suffix to get the smallest arrangement
        reverse(nums.begin() + i + 1, nums.end());
    }
};
