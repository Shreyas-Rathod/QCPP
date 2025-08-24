class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x; 
        int i = 2;
        while(i <= x/i) i++;
        return i-1;
    }
};
