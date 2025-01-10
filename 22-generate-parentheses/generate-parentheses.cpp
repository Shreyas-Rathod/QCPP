class Solution {
public:
    void genfun(int n, int left, int right, string s, vector<string>&res){
        if(s.size()==2*n) {res.push_back(s);return;}
        if(left<n) genfun(n, left+1, right, s+'(', res);
        if(right<left) genfun(n, left, right+1, s+')', res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        genfun(n, 0, 0, "", res);
        return res;
    }
};