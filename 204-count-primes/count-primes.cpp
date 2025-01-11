class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<bool>check(n-2, 1);
        int cnt=0;
        for(int i = 0;i<n-2;i++){
            if(check[i]){
                for(int j = i;j<n-2;j+=(i+2)) check[j] = 0;
                cnt++;
            }
        }
        return cnt;
    }
};