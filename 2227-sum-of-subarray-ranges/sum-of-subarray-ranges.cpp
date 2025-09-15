class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>min_prev(n, -1), max_prev(n, -1);
        vector<int>min_nxt(n, n), max_nxt(n, n);
        stack<int>st1, st2;
        long long count = 0, minl, minr, maxl, maxr, diff1 = 0, diff2 = 0;

        for(int i = n-1;i>=0;i--){
            while(!st1.empty() && nums[i] >= nums[st1.top()]) st1.pop();
            while(!st2.empty() && nums[i] <= nums[st2.top()]) st2.pop();
            if(!st1.empty()) min_nxt[i] = st1.top();
            if(!st2.empty()) max_nxt[i] = st2.top();
            st1.push(i);
            st2.push(i);
        }

        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();

        for(int i = 0;i<n;i++){
            while(!st1.empty() && nums[i] < nums[st1.top()]) st1.pop();
            while(!st2.empty() && nums[i] > nums[st2.top()]) st2.pop();
            if(!st1.empty()) min_prev[i] = st1.top();
            if(!st2.empty()) max_prev[i] = st2.top();
            st1.push(i);
            st2.push(i);
        }

        for(int i = 0;i<n;i++){
            minl = i - min_prev[i];
            maxr = max_nxt[i] - i;
            minr = i - min_nxt[i];
            maxl = max_prev[i] - i;
            diff1 = (long long)(diff1 + (long long)nums[i]*(minl*maxr));
            diff2 = (long long)(diff2 + (long long)nums[i]*(minr*maxl));
        }

        return diff2 - diff1;
    }
};