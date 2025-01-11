class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start^goal;
        int cnt = 0;
        for(int i = 0;i<32;i++){
            if(res & (1<<i)) cnt++;
        }
        return cnt;
    }
};