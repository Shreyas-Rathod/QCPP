class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp = 1, cnt = 0;
        if(n<=0) return false;
        for(int i = 0;i<32;i++){
            if(temp & n){
                if(cnt > 0) return false;
                cnt++;
            }
            temp <<= 1;
        }
        return true;
    }
};