class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 1, right = *max_element(nums.begin(), nums.end()), mid;
        int sum = 0;

        auto fun = [&](int x){
            sum = 0;
            for(int &i : nums) sum += (i+x-1)/x;
            return sum<=threshold;
        };

        while(left<=right){
            mid = (left+right)/2;
            if(fun(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};