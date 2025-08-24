class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1, mid;
        while(low <= high){
            mid = (low + high) >> 1;
            if(low == high) return nums[mid];
            if(mid%2){
                if(mid + 1 < n && nums[mid] == nums[mid+1]) high = mid - 1;
                else if(mid - 1 >= 0 && nums[mid] == nums[mid-1]) low = mid + 1;
                else return nums[mid];
            }
            else{
                if(mid + 1 < n && nums[mid] == nums[mid+1]) low = mid + 2;
                else if(mid - 1 >= 0 && nums[mid] == nums[mid-1]) high = mid - 2;
                else return nums[mid];
            }
        }

        return nums[mid];
    }
};