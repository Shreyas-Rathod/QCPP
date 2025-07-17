class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        
        int n = nums.size();

        int canRemove = 0;
        for(int i = 0, j = n/2; i < n/2 && j < n; ++j) {
            if(nums[i] < nums[j]) {
                canRemove += 2;
                i++;
            }
        }
        return n - canRemove;
    }
};