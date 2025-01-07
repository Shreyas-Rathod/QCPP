class Solution {
public:
    string largestOddNumber(string num) {
        string ans, temp;
        int n;
        for(int i = 0;i<num.size();i++){
            temp += num[i];
            n = num[i] - '0';
            if(n%2) ans = temp;
        }
        return ans;
    }
};