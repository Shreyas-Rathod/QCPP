class Solution {
public:
    int climbStairs(int n) {
        vector<int>res(n, 0);
        for(int i = 0;i<n;i++) res[i] = i+1;
        for(int i = 3;i<n;i++) res[i] = res[i-1] + res[i-2];
        return res[n-1];
    }
};