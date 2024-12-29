class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-2, mid;
        if(n == 1) return 0;
        if(nums[low-1] > nums[low]) return low-1;
        if(nums[high] < nums[high+1]) return high+1;

        while(low <= high){
            mid = (low+high)>>1;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        return mid;
    }
};