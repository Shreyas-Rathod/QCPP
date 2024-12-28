class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while(low <= high){
            mid = (low + high) >> 1;
            if(nums[mid] == target || nums[low] == target || nums[high] == target) return true;
            else if(nums[low] == nums[high]) low++, high--;
            else if(nums[mid] <= nums[high]){
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
            else{
                if(nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
};