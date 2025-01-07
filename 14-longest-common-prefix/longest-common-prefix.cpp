class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), j = 0;
        string str = strs[0];
        for(int i = 1;i<n;i++){
            j = 0;
            if(strs[i].size() == 0) return "";
            else{
                while(strs[i][j] == str[j] && j<str.size() && j<strs[i].size()) j++;
                str.erase(str.begin() + j, str.end());
            } 
        }
        return str;
    }
};