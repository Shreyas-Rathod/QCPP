class Solution {
public:
    int cob(vector<int>& nums, int st, int end){
        int n = end - st + 1;
        if(n == 1) return nums[st];
        int res0 = nums[st];
        int res1 = max(nums[st+1], res0);
        int newn = 0;

        for(int i = st + 2;i<=end;i++){
            newn = max(res1, nums[i] + res0);
            res0 = res1;
            res1 = newn;
        }

        return max(res0, res1);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        return max(cob(nums, 0, n-2), cob(nums, 1, n-1));
    }
};