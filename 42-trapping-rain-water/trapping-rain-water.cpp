class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), count = 0;
        vector<int>next(n, 0);
        vector<int>prev(n, 0);
        prev[0] = height[0];
        next[n-1] = height[n-1];

        for(int i = 0;i<n;i++){
            if(i > 0) prev[i] = max(prev[i-1], height[i]);
            if(n-1 > i) next[n-i-2] = max(next[n-i-1], height[n-i-2]);
        }

        for(int i = 0;i<n;i++){
            count += min(prev[i], next[i])-height[i];
        }

        return count;
    }
};