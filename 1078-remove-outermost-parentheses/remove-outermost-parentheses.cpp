class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        string container;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                if(!container.empty()) res.push_back('(');
                container.push_back('(');
            }
            else{
                container.pop_back();
                if(!container.empty()) res.push_back(')');
            }
        }

        return res;
    }
};