class Solution {
public:
    bool ispalin(string s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        } 
        return true;    
    }
    void genfun(string s, vector<vector<string>>&res, vector<string>&temp, int index){
        if(index == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = index;i<s.size();i++){
            if(ispalin(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                genfun(s, res, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        genfun(s, res, temp, 0);
        return res;
    }
};