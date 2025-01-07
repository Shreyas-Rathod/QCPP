class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), i;
        long long count = 0, temp = 1, limit = 1e9+7;

        for(i = 1;i<n;i++){
            if(s[i-1] == s[i]) temp++;
            else{
                count += (temp*(temp+1))/2;
                temp = 1;
            }
        }
        count += (temp*(temp+1))/2;
        return (int)(count%limit);
    }
};