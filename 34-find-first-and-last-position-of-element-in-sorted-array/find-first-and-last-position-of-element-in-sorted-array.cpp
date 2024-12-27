class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1, mid;
        vector<int>res = {-1, -1};

        while(low <= high){
            mid = (low+high)>>1;
            if(nums[mid] == target) res[1] = mid, low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        low = 0, high = n-1;
        while(low <= high){
            mid = (low+high)>>1;
            if(nums[mid] == target) res[0] = mid, high = mid - 1;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return res;
    }
};