class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long left, right, count = 0;
        stack<int>st;
        vector<int>pre(n, -1);
        vector<int>nxt(n, n);

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) nxt[i] = st.top();
            st.push(i); 
        }

        while(!st.empty()) st.pop();

        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if(!st.empty()) pre[i] = st.top();
            st.push(i); 
        }

        for(int i = 0;i<n;i++){
            left = i - pre[i];
            right = nxt[i] - i;
            count = (count + (arr[i]*(right*left)%mod)%mod)%mod;
        }

        return count;

    }
};