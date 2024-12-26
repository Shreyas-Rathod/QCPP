class Solution {
public:
    void merge(vector<int>&nums, int left, int right, int mid){
        vector<int>temp;
        int l = left, r = mid + 1;
        
        while(l<=mid && r<=right){
            if(nums[l] > nums[r]) temp.push_back(nums[r++]);
            else temp.push_back(nums[l++]);
        }
        while(l<=mid) temp.push_back(nums[l++]);
        while(r<=right) temp.push_back(nums[r++]);

        for(int i = left;i<=right;i++) nums[i] = temp[i-left];
    }

    int count(vector<int>&nums, int left, int right, int mid){
        int cnt = 0, r = mid+1;
        for(int i = left;i<=mid;i++){
            while(r<=right && nums[i]>(long long)2*nums[r]) r++;
            cnt += (r-mid-1);
        }
        return cnt;
    }

    int mergesort(vector<int>&nums, int l, int r){
        int cnt = 0;
        if(l<r){
            int mid = (l+r)/2;
            cnt += mergesort(nums, l, mid);
            cnt += mergesort(nums, mid+1, r);
            cnt += count(nums, l, r, mid);
            merge(nums, l, r, mid);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n-1);
    }
};