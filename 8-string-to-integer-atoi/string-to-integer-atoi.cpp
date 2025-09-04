class Solution {
public:
    int fun(string s, int index, int sign, long long res){
        if(index >= s.size() || !isdigit(s[index])) return res*sign;
        res = res*10 + s[index] - '0';
        if(res*sign <= INT_MIN) return INT_MIN;
        if(res*sign >= INT_MAX) return INT_MAX; 

        return fun(s, index + 1, sign, res);

    }
    int myAtoi(string s) {
        size_t i = s.find_first_not_of(" ");
        if(i == string :: npos) return 0;
        s = s.substr(i);
        if(s.empty()) return 0;

        int index = 0, sign = 1;
        if(s[0] == '+') index++;
        else if(s[0] == '-') index++, sign = -1;

        return fun(s, index, sign, 0);

    }
};