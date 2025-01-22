class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int count = 0, n = arr.size(),mod = 1e9+7;
        long long left, right;
        vector<int>pse(n, 0), nse(n, 0);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        for(int i = 0;i<n;i++){
            left = i - pse[i];
            right = nse[i] - i;
            count = (count + (arr[i]*(left*right)%mod)%mod)%mod;
        }
        return count;
    }
};