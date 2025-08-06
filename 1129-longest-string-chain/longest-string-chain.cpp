class Solution {
public:
    bool check(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        if(n1 == n2 + 1){
            int first = 0;
            int second = 0;
    
            while(first < n1){
                if(second < n2 && s1[first] == s2[second]){
                    first ++;
                    second ++;
                }
                else first ++;
            }
            if(first == n1 && second == n2) return true;
            else return false; 
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(), maxi = 0;
        sort(words.begin(), words.end(), [](const string&a, const string&b){return a.length() < b.length();});
        vector<int> dp(n, 1);
        for(int i = 0;i<n;i++){
            for(int prev = 0;i>prev;prev++){
                if(check(words[i], words[prev]) && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                }
            }
            if(maxi < dp[i]) maxi = dp[i];
        }

        return maxi;
    }
};