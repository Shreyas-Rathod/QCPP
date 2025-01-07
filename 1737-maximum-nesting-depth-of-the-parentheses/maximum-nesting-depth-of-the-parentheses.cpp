class Solution {
public:
    int maxDepth(string s) {
        vector<char>st;
        int maxcount = 0, tpcount = 0, n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                tpcount++;
                st.push_back(s[i]);
            }
            else if(s[i] == ')'){
                maxcount = max(maxcount, tpcount);
                tpcount--;
                st.pop_back();
            }
        }
        return maxcount;
    }
};