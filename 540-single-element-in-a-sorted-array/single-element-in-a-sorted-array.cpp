class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid;
        while(low<=high){
            mid = (high + low)/2;
            if(low == high) return nums[mid];
            if(mid%2){
                if(nums[mid-1] == nums[mid]) low = mid + 1;
                else if(nums[mid+1] == nums[mid]) high = mid - 1;
                else return nums[mid];
            }else{
                if(nums[mid-1] == nums[mid]) high = mid - 2;
                else if(nums[mid+1] == nums[mid]) low = mid + 2;
                else return nums[mid];
            }
        }
        return -1;
    }
};