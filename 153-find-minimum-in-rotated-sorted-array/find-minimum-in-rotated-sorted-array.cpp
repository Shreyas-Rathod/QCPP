class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid, mini = nums[0];
        while(low < high){
            mid = (low+high)>>1;
            if(nums[mid] < nums[high]) high = mid;
            else low = mid + 1;
        }
        return nums[low];
    }
};