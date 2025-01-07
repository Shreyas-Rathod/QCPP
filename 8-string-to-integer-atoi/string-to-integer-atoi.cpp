class Solution {
public:
    int recur(string s, int i, int sign, long long res){
        if(i >= s.size() || !isdigit(s[i])) return res*sign;
        res = res*10 + s[i] - '0';
        if(res*sign <= INT_MIN) return INT_MIN;
        if(res*sign >= INT_MAX) return INT_MAX;
        return recur(s, i+1, sign, res);
    }
    int myAtoi(string s) {

        size_t start = s.find_first_not_of(" ");
        if(start == string::npos) return 0;
        s = s.substr(start);
        if(s.empty()) return 0;
        int sign = 1, index = 0;
        if(s[0] == '-') sign = -1, index = 1;
        else if(s[0] == '+') index = 1; 
        return recur(s, index, sign, 0);
    }
};