class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0, arr[3] = {-1, -1, -1};

        for(int i = 0;i<n;i++){
            arr[s[i] - 'a'] = i;
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                cnt += (1 + min(min(arr[1], arr[2]), arr[0]));
            }
        }
        return cnt;
    }
};