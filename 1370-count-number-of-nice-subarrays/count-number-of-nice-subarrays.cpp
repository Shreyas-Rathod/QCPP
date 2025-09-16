class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), start = 0, res = 0, rescnt = 0, temp = 0;

        for(int end = 0;end<n;end++){
            if(nums[end]%2) temp++;
            while(start < end && (nums[start] % 2 == 0 || temp > k)){
                if(nums[start]%2){
                    rescnt = 0;
                    temp--;
                }
                else{
                    rescnt++;
                }
                start++;
            }
            if(temp == k) res += (1 + rescnt);
        }

        return res;
    }
};