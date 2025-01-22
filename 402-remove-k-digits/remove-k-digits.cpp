class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
            while(k>0 && !st.empty() && num[i]-'0' < st.top()-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string str;
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        while(!str.empty() && str.back() == '0') str.pop_back();
        reverse(str.begin(), str.end());
        if(str.empty()) return "0";
        return str;
    }
};