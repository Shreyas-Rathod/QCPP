class Solution {
public:
    void genfun(string digits, vector<string>&mem, vector<string>&res, string str, int k){
        if(k==digits.size()){
            if(digits.size()==0) return;
            res.push_back(str);
            return;
        }
        int temp = digits[k] - '2';
        for(int i = 0;i<mem[temp].size();i++){
            genfun(digits, mem, res, str+mem[temp][i], k+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>mem = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;

        genfun(digits, mem, res, "", 0);
        return res;
    }
};