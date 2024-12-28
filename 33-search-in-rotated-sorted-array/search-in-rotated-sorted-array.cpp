class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid, pi = 0;
        while(low<=high){
            mid = (low+high)>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[high]){
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
            else{
                if(nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};