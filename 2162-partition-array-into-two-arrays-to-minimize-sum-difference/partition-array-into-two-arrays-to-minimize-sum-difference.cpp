class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        int half = n/2;
        int halfMask = (1<<(n/2)) - 1;

        vector<vector<int>>left(half+1), right(half+1);
        for(int mask = 0; mask <= halfMask; ++mask) {
            int s1 = 0, s2 = 0, cnt = 0;
            for(int i = 0; i < half; ++i) {
                if((mask >> i) & 1) {
                    cnt++;
                    s1 += nums[i];
                    s2 += nums[i+half];
                } else {
                    s1 -= nums[i];
                    s2 -= nums[i+half];
                }
            }
            left[cnt].push_back(s1);
            right[cnt].push_back(s2);
        }

        for(int i = 0; i <= half; ++i) {
            sort(left[i].begin(), left[i].end());
            sort(right[i].begin(), right[i].end());
        }

        int ans = 1e9;
        for(int len1 = 0; len1 <= half; ++len1) {
            for(int num1 : left[len1]) {
                int len2 = half - len1;
                auto it = lower_bound(right[len2].begin(), right[len2].end(), -num1);
                if(it == right[len2].end()) {
                    it = prev(it);
                }
                ans = min(ans, abs(num1+*it));
                if(it != right[len2].begin()) {
                    it = prev(it);
                    ans = min(ans, abs(num1+*it));
                }
            }
        }
        return ans;
    }
};