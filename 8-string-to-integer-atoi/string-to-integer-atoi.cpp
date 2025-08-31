class Solution {
public:
    int fun(string s, int i, int sign, long long res){
        if(i >= s.size() || !isdigit(s[i])) return res*sign;
        res = res*10 + s[i] - '0';
        if(res*sign >= INT_MAX) return INT_MAX;
        if(res*sign <= INT_MIN) return INT_MIN;
        return fun(s, i+1, sign, res);
    };
    int myAtoi(string s) {
        size_t i = s.find_first_not_of(" ");
        if(i == string::npos) return 0;
        s = s.substr(i);
        if(s.empty()) return 0;

        int index = 0, sign = 1;
        if(s[0] == '-') sign = -1, index++;
        else if(s[0] == '+') index++;

        return fun(s, index, sign, 0);
    }
};