class Solution {
public:
    bool ispalin(string s, int f, int e){
        while(f <= e){
            if(s[f++] != s[e--]) return false;
        }
        return true;
    }

    void fun(string s, int idx, vector<string>&temp, vector<vector<string>>&res){
        if(idx == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = idx;i<s.size();i++){
            if(ispalin(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                fun(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>temp;
        vector<vector<string>>res;
        
        fun(s, 0, temp, res);

        return res;
    }
};