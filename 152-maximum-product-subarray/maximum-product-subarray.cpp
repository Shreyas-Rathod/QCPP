class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN, pre = 1, post = 1;
        for(int i = 0;i<n;i++){
            if(pre == 0) pre = 1;
            if(post == 0) post = 1;
            pre *= nums[i];
            post *= nums[n-i-1];
            res = max(res, max(pre, post));
        }
        return res;
    }
};