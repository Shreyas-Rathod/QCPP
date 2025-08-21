class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1, mid;
        while(low <= high){
            mid = (low + high)>>1;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]) high = mid;
                else low = mid + 1;
            }
            else{
                if(nums[mid] <= target && target <= nums[high]) low = mid;
                else high = mid - 1;
            }
        }

        return -1;
    }
};