class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ostr, estr, maxstr;
        auto ispalin = [&](int left, int right){
            while(left>=0 && right<n && s[left] == s[right]) left--, right++;
            return s.substr(left+1, right - left - 1);
        };

        for(int i = 0;i<n;i++){
            ostr = ispalin(i, i);
            estr = ispalin(i, i+1);
            if(ostr.size() > maxstr.size()) maxstr = ostr;
            if(estr.size() > maxstr.size()) maxstr = estr;
        }

        return maxstr;
    }
};